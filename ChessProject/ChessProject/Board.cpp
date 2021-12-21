#include "Board.h"
#include <iostream>

/*
this function will create a board
input: startColor
output: none
*/
Board::Board(const bool startColor)
{
	this->_charBoard = new string[LENGTH];
	this->_currentColor = startColor;
	this->_board = { new Rook('a', '1', 'r', true), new Knight('b', '1', 'n', true),new Bishop('c', '1', 'b', true),new King('d', '1', 'k', true),new Queen('e', '1', 'q', true),new Bishop('f', '1', 'b', true),new Knight('g', '1', 'n', true), new Rook('h', '1', 'r', true),
		new Pawn('a', '2', 'p', true), new Pawn('b', '2', 'p', true),new Pawn('c', '2', 'p', true),new Pawn('d', '2', 'p', true),new Pawn('e', '2', 'p', true),new Pawn('f', '2', 'p', true),new Pawn('g', '2', 'p', true),new Pawn('h', '2', 'p', true)
	, new Pawn('a', '7', 'P', false), new Pawn('b', '7', 'P', false),new Pawn('c', '7', 'P', false),new Pawn('d', '7', 'P', false),new Pawn('e', '7', 'P', false),new Pawn('f', '7', 'P', false),new Pawn('g', '7', 'P', false),new Pawn('h', '7', 'P', false)
	, new Rook('a', '8', 'R', false), new Knight('b', '8', 'N', false),new Bishop('c', '8', 'B', false),new King('d', '8', 'K', false), new Queen('e', '8', 'Q', false),new Bishop('f', '8', 'B', false),new Knight('g', '8', 'N', false),new Rook('h', '8','R' , false)};
	this->updateCharBoard();
}

/*
this function will distruct board object
input: none
output: none
*/
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
	delete[]this->_charBoard;
}

/*
this function will add a rook soldier to the board
input: none
output: none
*/
void Board::addSoldier()
{
	this->_board.push_back(new Rook('b', '8', 'R', false));
}

/*
this function will return the current player color 
input: none
output: none
*/
bool Board::getColor() const
{
	return this->_currentColor;
}

/*
this function will be used as the function that receive all the important data to the fronted part
input: temp, answer, msgFrom
output: none
*/
void Board::boardMenu(Board* temp, char* answer, const string msgFrom)
{
	answer[ONE] = NULL;
	try
	{
		this->getSoldierInIndex(FrontedText::getXorY(msgFrom, ZERO), FrontedText::getXorY(msgFrom, ONE))->isValidMove(msgFrom, this->getCharBoard(), this->getColor());
	}
	catch (const char e)
	{
		if (e == VALID)
		{
			temp->operator=(*this);
			temp->killSoldier(msgFrom);
			temp->updateCharBoard();
		}
		answer[ZERO] = e;
	}
	if (answer[ZERO] == VALID)
	{
		try
		{
			temp->isInChess();
		}
		catch (const char e)
		{
			answer[ZERO] = e;
		}
		if (answer[ZERO] != WILL_BE_OWN_CHECK)
		{
			this->killSoldier(msgFrom);
			this->updateCharBoard();
			try
			{
				this->isInChess();
			}
			catch (const char e)
			{
				answer[ZERO] = e;
			}
			this->setColor();
		}
		else
		{
			if (temp->getBoard().size() < this->getBoard().size()) // making sure tempBoard and board have the same amount of soldiers, if own chess happened Board will have 1 soldier more than tempBoard and it might cause to access of an unexisting item in temp board
				temp->addSoldier();
		}
	}
}

/*
this function will return the char board
input: none
output: the char board
*/
string* Board::getCharBoard() const
{
	return this->_charBoard;
}

/*
this function will delete specific soldier from the board if needed
input: cords
output: none
*/
void Board::killSoldier(const string cords)
{
	Soldier* sourceSoldier = this->getSoldierInIndex(cords[ZERO], cords[ONE]);
	if (this->_charBoard[cords[THREE] - ASCII_NUMBERS - ONE][cords[TWO] - ASCII_LETTERS] != '#')
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

/*
this function will get the board kings and update both pointers with their address
input: currentKing otherKing
output: none
*/
void Board::getKings(Soldier* currentKing, Soldier* otherKing) const
{
	for (int i = ZERO; i < this->_board.size(); i++)
	{
		if (this->_board[i]->getName() == 'K' || this->_board[i]->getName() == 'k')
			if (this->_board[i]->getColor() == this->_currentColor)
			{
				currentKing->operator=(*this->_board[i]);
			}
			else
			{
				otherKing->operator=(*this->_board[i]);
			}
	}
}

/*
this function will check if chess occured on the board
input: none
output: none
*/
void Board::isInChess()
{
	string cords = "";
	King currentKing('a', '1', 'k', false);
	King otherKing('a', '1', 'k', false);
	getKings(&currentKing, &otherKing);
	char currentKingX = currentKing.getX();
	char currentKingY = currentKing.getY();
	char otherKingX = otherKing.getX();
	char otherKingY = otherKing.getY();
	for (int i = ZERO; i < this->_board.size(); i++)
	{
		cords = "";
		cords += this->_board[i]->getX();
		cords += this->_board[i]->getY();
		if (this->_currentColor != this->_board[i]->getColor())
		{
			cords += currentKingX;
			cords += currentKingY;
			try
			{
				this->_board[i]->isValidMove(cords, this->_charBoard, !this->_currentColor);
			}
			catch (const char e)
			{
				if (e == '0')
					throw moveException::checkOwnCheck();
			}
		}
		else
		{
			cords += otherKingX;
			cords += otherKingY;
			try
			{
				this->_board[i]->isValidMove(cords, this->_charBoard, this->_currentColor);
			}
			catch (const char e)
			{
				if (e == '0')
					throw moveException::check();
			}
		}
	}
}

/*
this function will copy one board to another
input: other
output: the new board
*/
Board& Board::operator=(const Board& other)
{
	this->_currentColor = other._currentColor;
	for (int i = ZERO; i < other._charBoard->length(); i++)
	{
		this->_charBoard[i] = other._charBoard[i];
	}
	for (int i = ZERO; i < other._board.size(); i++)
	{
		this->_board[i]->operator=(*other._board[i]);
	}
	return *this;
}

/*
this function will update the char board 
input: none
output: none
*/
void Board::updateCharBoard()
{
	for (int counter = ZERO; counter < LENGTH; counter++)
	{
		this->_charBoard[counter] = "########";
	}
	for (int counter = ZERO; counter < this->_board.size(); counter++)
	{
		this->_charBoard[this->_board[counter]->turnCordToInt(this->_board[counter]->getY())][this->_board[counter]->turnCordToInt(this->_board[counter]->getX())] = this->_board[counter]->getName();
	}
}

/*
this function will set the board current color 
input: none
output: none
*/
void Board::setColor()
{
	this->_currentColor = !this->_currentColor;
}

/*
this function will return a specific soldier from the board
input: x, y
output: soldier
*/
Soldier* Board::getSoldierInIndex(char x, char y) const
{
	for (int counter = ZERO; counter < this->_board.size(); counter++)
		if (this->_board[counter]->getX() == x && this->_board[counter]->getY() == y)
			return this->_board[counter];
	if (this->_charBoard[y - ASCII_NUMBERS - ONE][x - ASCII_LETTERS] == '#')
		throw moveException::checkSourceSoldier();
}

/*
this function will get the start color from the user
input: msg
output: none
*/
void Board::getStartColor(char* msg)
{
	int color = 0;
	std::cout << "Which color would you like to start? white - 0, black - any number" << std::endl;
	std::cin >> color;
	this->_currentColor = bool(color);
	msg[LENGTH*LENGTH] = int(this->_currentColor) + ASCII_NUMBERS;
}

/*
this function will return the soldier board
input: none
output: the soldier vector
*/
vector<Soldier*> Board::getBoard() const
{
	return this->_board;
}