#include "Soldier.h"
#include <iostream>

/*
this function will create a soldier
input: x, y, name, color
output: none
*/
Soldier::Soldier(const char x, const char y, const char name, const bool color) : _color(color), _name(name)
{
	setCords(x, y);
}

/*
this fucntion will be used as a soldier dtor
input: none
output: none
*/
Soldier::~Soldier()
{
}

/*
this function will return the soldier's x cord
input: none
output: the soldier x cord
*/
char Soldier::getX() const
{
	return this->_x;
}

/*
this function will return the soldier's y cord
input: none
output: the soldier y cord
*/
char Soldier::getY() const
{
	return this->_y;
}

/*
this function will check if its the player's turn
input: board, color
output: none
*/
void Soldier::checkIfSourceIsRight(const string* board, const bool color)
{
	if (this->_color != color)
		throw moveException::checkSourceSoldier();
}

/*
this function will check if the dest place not contains own soldier
input: x, y, board
output: none
*/
void Soldier::checkIfDestNotOwn(const char x, const char y, const string* board) const
{
	if (this->_color == colorOfSoldier(x, y, board))
		throw moveException::checkDestSoldier();
}

/*
this function will check if the soldier isnt trying to move to it's current place
input: x, y
output: none
*/
void Soldier::checkIfNotSameIndex(const char x, const char y) const
{
	if (x == this->_x && y == this->_y)
		throw moveException::sameCords();
}

/*
this function will check if the soldier isnt trying to move to none existing cords
input: x, y
output: none
*/
void Soldier::checkIfCordsValid(const char x, const char y) const
{
	if ((x < 'a' || x > 'h') || (y < '1' || y > '8'))
		throw moveException::checkIndex();
}

/*
this function will return the soldier's name 
input: none
output: the name
*/
char Soldier::getName() const
{
	return this->_name;
}

/*
this function will check if a soldier is the same soldier as another
input: other
output: if its like the other soldier or not
*/
bool Soldier::operator==(const Soldier& other)
{
	if (this->_x == other._x && this->_y == other._y)
		return true;
	return false;
}

/*
this function will copy one soldier to another
input: other
output: the new copied soldier
*/
Soldier& Soldier::operator=(const Soldier& other)
{
	if (this != &other)
	{
		this->_color = other._color;
		this->_x = other._x;
		this->_y = other._y;
		this->_name = other._name;
	}
	return *this;
}

/*
this function will return the soldier's color
inpuot: none
output: the color
*/
bool Soldier::getColor() const
{
	return this->_color;
}

/*
this function will return the color of a soldier by it's index
input: x, y, board
output: the color of a soldier by it's index
*/
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

/*
this function will turn a cord to index
input: cord
output: the cord as index
*/
int Soldier::turnCordToInt(const char cord) const
{
	if ('a' <= cord && cord <= 'h')
		return ((int)cord) - ASCII_LETTERS;
	return ((int)cord) - ASCII_NUMBERS - ONE; // -1 because we return index and the y cords of the board starts at 1
}

/*
this function will set the soldier's cords
input: x, y
output: none
*/
void Soldier::setCords(const char x, const char y)
{
	checkIfCordsValid(x, y);
	this->_x = x;
	this->_y = y;
}
