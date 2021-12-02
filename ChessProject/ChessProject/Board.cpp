#include "Board.h"
#include <iostream>

Board::Board(const bool startColor)
{
	this->charBoard = new string[8];
	this->_currentColor = startColor;
	this->_board = { new Rook('a', '1', 'R', false), new Rook('h', '1', 'R', false), new Rook('h', '8', 'r', true), new Rook('a', '8', 'r', true) };
	this->updateCharBoard();
}

Board::~Board()
{
	delete[]this->charBoard;
}

bool Board::getColor() const
{
	return this->_currentColor;
}

string* Board::getCharBoard() const
{
	return this->charBoard;
}

void Board::updateCharBoard()
{
	for (int counter = 0; counter < 8; counter++)
	{
		this->charBoard[counter] = "########";
	}
	for (int counter = 0; counter < this->_board.size(); counter++)
	{
		std::cout << this->charBoard[counter][counter] << std::endl;
		this->charBoard[this->_board[counter]->turnCordToInt(this->_board[counter]->getY())][this->_board[counter]->turnCordToInt(this->_board[counter]->getX())] = this->_board[counter]->getName();
	}
	for (int counter = 0; counter < 8; counter++)
	{
		for(int i = 0; i < 8; i++)
			std::cout << this->charBoard[counter][i];
		std::cout << "" << std::endl;
	}
}

void Board::setColor()
{
	this->_currentColor = !this->_currentColor;
}

char* Board::getFirstMsg() const
{
	char msg[67];
	msg[66] = NULL;
	for (int counter = 0; counter < 8; counter++)
	{
		for (int secCounter = 0; secCounter < 8; secCounter++)
		{
			msg[counter + secCounter] = this->charBoard[counter][secCounter];
		}
	}
	msg[65] = char(this->_currentColor);
	return msg;
}

vector<Soldier*> Board::getBoard() const
{
	return this->_board;
}
