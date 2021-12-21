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
	char msgToGraphics[1024] = "RNBKQBNRPPPPPPPP################################pppppppprnbkqbnr";
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
	board.getStartColor(msgToGraphics);
	p.sendMessageToGraphics(msgToGraphics);   
	string msgFromGraphics = p.getMessageFromGraphics();
	while (msgFromGraphics != "quit")
	{
		board.boardMenu(&tempBoard, answer, msgFromGraphics);
		strcpy_s(msgToGraphics, answer);
		p.sendMessageToGraphics(msgToGraphics);   
		msgFromGraphics = p.getMessageFromGraphics();
	}
	p.close();
}