#include "Pawn.h"

Pawn::Pawn(const char x, const char y, const char name, const bool color) : Soldier(x, y, name, color), _firstMove(true)
{
}

Pawn::~Pawn()
{
}

void Pawn::isValidMove(const string cords, const string* board, const bool currentColor)
{
	char newX = FrontedText::getXorY(cords, TWO);
	char newY = FrontedText::getXorY(cords, THREE);
	char currentX = this->getX();
	char currentY = this->getY();
	checkIfCordsValid(newX, newY);
	checkIfSourceIsRight(board, currentColor);
	checkIfNotSameIndex(newX, newY);
	checkIfDestNotOwn(newX, newY, board);
	if ((!this->getColor() && (newY == currentY - ONE && currentX == newX) || (this->_firstMove && newY == currentY - TWO) || (board[turnCordToInt(newY)][turnCordToInt(newX)] != '#' && (newX == currentX + ONE && newY == currentY - ONE || newX == currentX - ONE && newY == currentY - ONE)))
		|| this->getColor() && (newY == currentY + ONE && currentX == newX) || ((this->_firstMove && newY == currentY + TWO) || (board[turnCordToInt(newY)][turnCordToInt(newX)] != '#' && (newX == currentX + ONE && newY == currentY + ONE || newX == currentX - ONE && newY == currentY + ONE))))
	{
		checkIfNotRunOver(turnCordToInt(currentX), turnCordToInt(currentY), newX, newY, board);
	}
	else
	{
		throw moveException::invalidMove();
	}
	this->_firstMove = false;
	throw moveException::validMove();
}

void Pawn::checkIfNotRunOver(const int startX, const int startY, const char x, const char y, const string* board) const
{
	int newY = turnCordToInt(y);
	int newX = turnCordToInt(x);
	if ((this->getColor() && startY + ONE == newY && startX == newX && board[newY][newX] != '#' || (startY + TWO == newY && startX == newX && board[newY][newX] != '#' && board[newY - ONE][newX] != '#'))
		|| (!this->getColor() && startY - ONE == newY && startX == newX && board[newY][newX] != '#' || (startY - TWO == newY && startX == newX && board[newY][newX] != '#' && board[newY + ONE][newX] != '#')))
	{
		throw moveException::invalidMove();
	}
}
