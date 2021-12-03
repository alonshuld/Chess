#include "Soldier.h"
#include <iostream>

Soldier::Soldier(const char x, const char y, const char name, const bool color) : _color(color), _name(name)
/*
* Ctor for soldier
* Input: x, y, name of the soldier and color
* Output: none
*/
{
	checkIfCordsValid(x, y);
	setCords(x, y);
}

Soldier::~Soldier()
/*
* Dtor of the rook
* Input: none
* Output: none
*/
{
}

char Soldier::getX() const
/*
* Get the x of the soldier
* Input: none
* Output: the x of the soldier
*/
{
	return this->_x;
}

char Soldier::getY() const
/*
* Get the y of the soldier
* Input: none
* Output: the y of the soldier
*/
{
	return this->_y;
}

void Soldier::checkIfColorIsRight(const char x, const char y, const string* board, const bool color)
/*
* Checks if the color is right
* Input: x, y, the board and the color
* Output: none
*/
{
	if (this->_color != color)
		throw moveException::checkSourceSoldier();
}

void Soldier::checkIfDestNotOwn(const char x, const char y, const string* board) const
/*
* 
*/
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
/*
* get the name of the soldier
* Input: none
* Output: the name of the soldier
*/
{
	return this->_name;
}

bool Soldier::colorOfSoldier(const char x, const char y, const string* board) const
/*
* get the color of the soldier
* Input: x, y and the board
* Output: the color
*/
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
/*
* turn the cord to a number
* Input: cord
* Output: the number
*/
{
	if ('a' <= cord && cord <= 'h')
		return ((int)cord) - ASCII_LETTERS;
	return ((int)cord) - ASCII_NUMBERS - ONE; // -1 because we return index and the y cords of the board starts at 1
}

bool Soldier::operator==(const Soldier& other)
/*
* Operand == that checks the x and the y of the soldiers
*/
{
	if (this->_x == other._x && this->_y == other._y)
		return true;
	return false;
}

bool Soldier::getColor() const
/*
* Get the color of the soldier
* Input: none
* Output: the color
*/
{
	return this->_color;
}

void Soldier::setCords(const char x, const char y)
/*
* set the cords of the soldier
* Input: x and y
* Output: none
*/
{
	this->_x = x;
	this->_y = y;
}
