#include "Queen.h"

/*
this function will creat Queen soldier
input: x, y, name, color
output: none
*/
Queen::Queen(const char x, const char y, const char name, const bool color) : Bishop(x, y, name, color)
{
}

/*
this function will be used as a Queen dtor
input: none
output: none
*/
Queen::~Queen()
{
}

/*
this function will check if the soldier is making a valid move or not
input: cords, board, currentColor
output: none
*/
void Queen::isValidMove(const string cords, const string* board, const bool currentColor)
{
    char newX = FrontedText::getXorY(cords, TWO);
    char newY = FrontedText::getXorY(cords, THREE);
    char currentX = this->getX();
    char currentY = this->getY();
    try
    {
        this->Bishop::isValidMove(cords, board, currentColor);
    }
    catch (const char e)
    {
        if (e == VALID)
        {
            throw moveException::validMove();
        }
        else if (((currentX == newX && currentY != newY) || (currentX != newX && currentY == newY)) && e == INVALID_MOVE)
        {
			checkIfDestNotOwn(newX, newY, board);
			checkIfNotRunOver(turnCordToInt(currentX), turnCordToInt(currentY), newX, newY, board);
        }
		else
		{
			throw e;
		}
    }
}


/*
this function will check if the soldier isnt running over other soldier while moving
input: startX, startY, x, y, board
output: none
*/
void Queen::checkIfNotRunOver(const int startX, const int startY, const char x, const char y, const string* board)
{
	int indexX = turnCordToInt(x);
	int indexY = turnCordToInt(y);
	if (indexX == startX)
	{
		if (startY > indexY)
		{
			for (int i = indexY + ONE; i < startY; i++)
				if (board[i][startX] != '#')
					throw moveException::invalidMove();
		}
		else
		{
			for (int i = startY + ONE; i < indexY; i++)
				if (board[i][startX] != '#')
					throw moveException::invalidMove();
		}
	}
	else
	{
		if (startX > indexX)
		{
			for (int i = indexX + ONE; i < startX; i++)
				if (board[startY][i] != '#')
					throw moveException::invalidMove();
		}
		else
		{
			for (int i = startX + ONE; i < indexX; i++)
				if (board[startY][i] != '#')
					throw moveException::invalidMove();
		}
	}
    throw moveException::validMove();
}
