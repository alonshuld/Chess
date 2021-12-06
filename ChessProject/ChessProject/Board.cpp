#include "Board.h"
#include <iostream>

Board::Board(const bool startColor)
{
	this->charBoard = new string[LENGTH];
	this->_currentColor = startColor;
	this->_board = { new Rook('a', '1', 'r', true), new Rook('b', '1', 'r', true),new Rook('c', '1', 'r', true),new King('d', '1', 'k', true),new Rook('e', '1', 'r', true),new Rook('f', '1', 'r', true),new Rook('g', '1', 'r', true), new Rook('h', '1', 'r', true),
		new Rook('a', '2', 'r', true), new Rook('b', '2', 'r', true),new Rook('c', '2', 'r', true),new Rook('d', '2', 'r', true),new Rook('e', '2', 'r', true),new Rook('f', '2', 'r', true),new Rook('g', '2', 'r', true),new Rook('h', '2', 'r', true)
	, new Rook('a', '7', 'R', false), new Rook('b', '7', 'R', false),new Rook('c', '7', 'R', false),new Rook('d', '7', 'R', false),new Rook('e', '7', 'R', false),new Rook('f', '7', 'R', false),new Rook('g', '7', 'R', false),new Rook('h', '7', 'R', false)
	, new Rook('a', '8', 'R', false), new Rook('b', '8', 'R', false),new Rook('c', '8', 'R', false),new King('d', '8', 'K', false), new Rook('e', '8', 'R', false),new Rook('f', '8', 'R', false),new Rook('g', '8', 'R', false),new Rook('h', '8','R' , false)};
	this->updateCharBoard();
}

Board::~Board()
{
	if (this->_board.size() > ZERO)
	{
		for (int counter = ZERO; counter < this->_board.size(); counter++)
		{
			delete this->_board[counter];
		}
		this->_board.clear();
	}
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

void Board::killSoldier(const string cords)
{
	Soldier* sourceSoldier = this->getSoldierInIndex(cords[ZERO], cords[ONE]);
	if (this->charBoard[cords[THREE] - ASCII_NUMBERS - ONE][cords[TWO] - ASCII_LETTERS] != '#')
	{
		Soldier* delSoldier = this->getSoldierInIndex(cords[TWO], cords[THREE]); // getSoldier check if a soldier is # and throw exception if it does, only the source cannot be '#' so we declarer it inside the if
		if (sourceSoldier->getColor() != delSoldier->getColor())
		{
			this->_board.erase(std::remove(this->_board.begin(), this->_board.end(), delSoldier), this->_board.end());
			delete delSoldier;
		}
	}
	sourceSoldier->setCords(cords[TWO], cords[THREE]);
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
	for (int counter = ZERO; counter < this->_board.size(); counter++)
		if (this->_board[counter]->getX() == x && this->_board[counter]->getY() == y)
			return this->_board[counter];
	if (this->charBoard[y - ASCII_NUMBERS - ONE][x - ASCII_LETTERS] == '#')
		throw moveException::checkSourceSoldier();
}

void Board::getStartColor(char* msg)
{
	int color = 0;
	std::cout << "Which color would you like to start? white - 0, black - any number" << std::endl;
	std::cin >> color;
	this->_currentColor = bool(color);
	msg[LENGTH*LENGTH] = int(this->_currentColor) + ASCII_NUMBERS;
}

vector<Soldier*> Board::getBoard() const
{
	return this->_board;
}
