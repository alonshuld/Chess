#include "Soldier.h"

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

bool Soldier::colorOfSoldier(const char x, const char y, const char** board) const
{
	if ('A' <= board[turnCordToInt(x)][turnCordToInt(y)] && board[turnCordToInt(x)][turnCordToInt(y)] <= 'Z')
		return false;
	return true;
}

int Soldier::turnCordToInt(const char cord) const
{
	if ('a' <= cord || cord <= 'g')
		return ((int)cord) - ASCII_LETTERS;
	return ((int)cord) - ASCII_NUMBERS - ONE; // -1 because we return index and the y cords of the board starts at 1
}

void Soldier::setCords(const char x, const char y)
{
	this->_x = x;
	this->_y = y;
}
