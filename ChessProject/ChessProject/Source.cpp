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
	int size;
	char answer[2];
	char msgToGraphics[1024] = "RNBKQBNRRRRRRRRR################################rrrrrrrrrnbkqbnr";
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
	answer[ONE] = NULL;
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
				size = tempBoard.getBoard().size();
				tempBoard = board;
				tempBoard.killSoldier(msgFromGraphics);
				tempBoard.updateCharBoard();
			}
			answer[ZERO] = e;
		}
		if (answer[ZERO] == VALID)
		{
			try
			{
				tempBoard.isInChess();
			}
			catch (const char e)
			{
				answer[ZERO] = e;
			}
			if (answer[ZERO] != WILL_BE_OWN_CHECK)
			{
				board.killSoldier(msgFromGraphics);
				board.updateCharBoard();
				try
				{
					board.isInChess();
				}
				catch (const char e)
				{
					answer[ZERO] = e;
				}
				board.setColor();
			}
			else
			{
				if (tempBoard.getBoard().size() < size) // making sure tempBoard and board have the same amount of soldiers, if own chess happened Board will have 1 soldier more than tempBoard and it might cause to access of an unexisting item in temp board
					tempBoard.addSoldier();
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