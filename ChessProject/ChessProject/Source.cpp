/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project, 
in order to read and write information from and to the Backend
*/

#include "Rook.h"
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
	Board board(false);
	char answer[2];
	char msgToGraphics[1024] = "################################################################";
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
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE
	board.getFirstMsg(msgToGraphics);
	p.sendMessageToGraphics(msgToGraphics);   // send the board string
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
				board.updateCharBoard();
				board.setColor();
			}
			answer[0] = e;
		}
		strcpy_s(msgToGraphics, answer); // msgToGraphics should contain the result of the operation
		
		/******* JUST FOR EREZ DEBUGGING ******/
		//int r = rand() % 10; // just for debugging......
		//msgToGraphics[0] = (char)(1 + '0');
		//msgToGraphics[1] = 0
		/******* JUST FOR EREZ DEBUGGING ******/	
		p.sendMessageToGraphics(msgToGraphics);   
		msgFromGraphics = p.getMessageFromGraphics();
	}
	p.close();
}