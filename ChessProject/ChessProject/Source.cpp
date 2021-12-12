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
	Board board(true);
	char answer[2];
	char msgToGraphics[1024] = "RRRKRRRRRRRRRRRR################################rrrrrrrrrrrkrrrr";
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
		catch (const char e) // add temp board that checks if is in own check and if it is it wont kill the soldier and if it isnt it will kill the soldier on the main board
		{
			/*
			Message from Daniel: you're probably right :) 
			I'm not sure there is a simpler way to do this, I'll keep thinking about it tho.
			You should do everything on the temp board, than if there is an own check dont update the main board and copy main to temp, if there isnt than you can update it. 
			Basically what you wrote yourself :)
			*/
			if (e == VALID)
			{
				board.killSoldier(msgFromGraphics);
				board.updateCharBoard();
			}
			answer[0] = e;
		}
		if (answer[0] == VALID)
		{
			try
			{
				board.isInChess(); 
			}
			catch (const char e)
			{
				answer[0] = e;
			}
			if(answer[0] != WILL_BE_OWN_CHECK)
				board.setColor();
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