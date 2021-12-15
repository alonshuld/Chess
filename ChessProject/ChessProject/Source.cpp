/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/

#include "Board.h"
#include "Pipe.h"
#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::string;


void main()
{
	srand(time_t(NULL));
	Board tempBoard(true);
	Board board(true);
	char answer[2];
	char msgToGraphics[1024] = "RRRKQRRRRRRRRRRR################################rrrrrrrrrrrkqrrr";
	Pipe p;
	bool isConnect = p.connect();
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return;
		}
	}
	answer[1] = NULL;
	board.getStartColor(msgToGraphics);
	p.sendMessageToGraphics(msgToGraphics);   
	string msgFromGraphics = p.getMessageFromGraphics();
	
	while (msgFromGraphics != "quit")
	{
		try 
		{
			board.getSoldierInIndex(FrontedText::getXorY(msgFromGraphics, 0), FrontedText::getXorY(msgFromGraphics, 1))->isValidMove(msgFromGraphics, board.getCharBoard(), board.getColor());
		}
		catch (const char e)
		{
			if (e == VALID)
			{
				tempBoard = board;
				tempBoard.killSoldier(msgFromGraphics);
				tempBoard.updateCharBoard();
			}
			answer[0] = e;
		}
		if (answer[0] == VALID)
		{
			try
			{
				tempBoard.isInChess();
			}
			catch (const char e)
			{
				answer[0] = e;
			}
			if (answer[0] != WILL_BE_OWN_CHECK)
			{
				board.killSoldier(msgFromGraphics);
				board.updateCharBoard();
				try
				{
					board.isInChess();
				}
				catch (const char e)
				{
					answer[0] = e;
				}
				board.setColor();
			}
		}
		strcpy_s(msgToGraphics, answer); 
		
		/******* JUST FOR EREZ DEBUGGING ******/
		//int r = rand() % 10; // just for debugging......
		//msgToGraphics[0] = (char)(1 + '0');
		//msgToGraphics[1] = 0;
		/******* JUST FOR EREZ DEBUGGING ******/	
		p.sendMessageToGraphics(msgToGraphics);   
		msgFromGraphics = p.getMessageFromGraphics();
	}
	p.close();
}