#include "Board.h"
#include <iostream>

Board::Board(const bool startColor)
{
	this->charBoard = new string[LENGTH];
	this->_currentColor = startColor;
	this->_board = { new Rook('a', '1', 'r', true), new Rook('b', '1', 'r', true),new Rook('c', '1', 'r', true),new Rook('d', '1', 'r', true),new Rook('e', '1', 'r', true),new Rook('f', '1', 'r', true),new Rook('g', '1', 'r', true), new Rook('h', '1', 'r', true),
		new Rook('a', '2', 'r', true), new Rook('b', '2', 'r', true),new Rook('c', '2', 'r', true),new Rook('d', '2', 'r', true),new Rook('e', '2', 'r', true),new Rook('f', '2', 'r', true),new Rook('g', '2', 'r', true),new Rook('h', '2', 'r', true)
	, new Rook('a', '7', 'R', false), new Rook('b', '7', 'R', false),new Rook('c', '7', 'R', false),new Rook('d', '7', 'R', false),new Rook('e', '7', 'R', false),new Rook('f', '7', 'R', false),new Rook('g', '7', 'R', false),new Rook('h', '7', 'R', false)
	, new Rook('a', '8', 'R', false), new Rook('b', '8', 'R', false),new Rook('c', '8', 'R', false),new Rook('d', '8', 'R', false),new Rook('e', '8', 'R', false),new Rook('f', '8', 'R', false),new Rook('g', '8', 'R', false),new Rook('h', '8','R' , false)};
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
	for (int counter = ZERO; counter < LENGTH; counter++)
	{
		this->charBoard[counter] = "########";
	}
	for (int counter = ZERO; counter < this->_board.size(); counter++)
	{
		this->charBoard[this->_board[counter]->turnCordToInt(this->_board[counter]->getY())][this->_board[counter]->turnCordToInt(this->_board[counter]->getX())] = this->_board[counter]->getName();
	}
}

void Board::setColor()
{
	this->_currentColor = !this->_currentColor;
}

Soldier* Board::getSoldierInIndex(char x, char y) const
{
	for (int counter = 0; counter < this->_board.size(); counter++)
		if (this->_board[counter]->getX() == x && this->_board[counter]->getY() == y)
			return this->_board[counter];
}

void Board::killSoldier(const string cords)
{
	if (this->getSoldierInIndex(cords[0], cords[1]) == this->getSoldierInIndex(cords[2], cords[3]) &&
		getSoldierInIndex(cords[0], cords[1])->getColor() != this->getSoldierInIndex(cords[2], cords[3])->getColor())
	{
		this->_board.erase(std::remove(this->_board.begin(), this->_board.end(), this->getSoldierInIndex(cords[2], cords[3])), this->_board.end());
		delete this->getSoldierInIndex(cords[2], cords[3]);
	}
}

void Board::getFirstMsg(char* msg) const
{
	int msgCounter = 0;
	for (int counter = LENGTH - ONE; counter >= ZERO; counter--)
	{
		for (int secCounter = LENGTH - ONE; secCounter >= ZERO; secCounter--)
		{
			msg[msgCounter] = this->charBoard[counter][secCounter];
			msgCounter++;
		}
	}
	msg[64] = int(this->_currentColor) + ASCII_NUMBERS;
}

vector<Soldier*> Board::getBoard() const
{
	return this->_board;
}

void Board::printBoard() const
{
	for (int counter = ZERO; counter < LENGTH; counter++)
	{
		for (int secCounter = ZERO; secCounter < LENGTH; secCounter++)
			std::cout << this->charBoard[counter][secCounter];
		std::cout << "" << std::endl;
	}
}
