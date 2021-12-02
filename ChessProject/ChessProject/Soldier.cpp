#include "Soldier.h"
#include <iostream>

Soldier::Soldier(const char x, const char y, const char name, const bool color) : _color(color), _name(name)
{
	checkIfCordsValid(x, y);
	setCords(x, y);
}

Soldier::~Soldier()
{
}

char Soldier::getX() const
{
	return this->_x;
}

char Soldier::getY() const
{
	return this->_y;
}

void Soldier::checkIfColorIsRight(const char x, const char y, const string* board, const bool color)
{
	if (this->_color != color)
		throw moveException::checkSourceSoldier();
}

void Soldier::checkIfDestNotOwn(const char x, const char y, const string* board) const
{
	if (this->_color == colorOfSoldier(x, y, board))
		throw moveException::checkDestSoldier();
}

void Soldier::checkIfNotSameIndex(const char x, const char y) const
{
	if (x == this->_x && y == this->_y)
		throw moveException::sameCords();
}

void Soldier::checkIfCordsValid(const char x, const char y) const
{
	if ((x < 'a' || x > 'h') || (y < '1' || y > '8'))
		throw moveException::checkIndex();
}

char Soldier::getName() const
{
	return this->_name;
}

bool Soldier::colorOfSoldier(const char x, const char y, const string* board) const
{
	int xIndex = turnCordToInt(x);
	int yIndex = turnCordToInt(y);
	char check = board[yIndex][xIndex];
	if ('A' <= board[yIndex][xIndex] && board[yIndex][xIndex] <= 'Z')
		return false;
	else if ('a' <= board[yIndex][xIndex] && board[yIndex][xIndex] <= 'z')
		return true;
	return !this->_color;
}

int Soldier::turnCordToInt(const char cord) const
{
	if ('a' <= cord && cord <= 'h')
		return ((int)cord) - ASCII_LETTERS;
	return ((int)cord) - ASCII_NUMBERS - ONE; // -1 because we return index and the y cords of the board starts at 1
}

void Soldier::setCords(const char x, const char y)
{
	this->_x = x;
	this->_y = y;
}
