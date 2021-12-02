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
	Board board(true);
	char answer[2];
	answer[1] = NULL;

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
	
	
	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE
	strcpy_s(msgToGraphics, board.getFirstMsg()); // just example...
	
	p.sendMessageToGraphics(msgToGraphics);   // send the board string
	string msgFromGraphics = p.getMessageFromGraphics();
	
	while (msgFromGraphics != "quit")
	{
		try 
		{
			board.getBoard()[3]->isValidMove(msgFromGraphics, board.getCharBoard(), board.getColor());
		}
		catch(const char e)
		{
			if(e == VALID)
				board.updateCharBoard();
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