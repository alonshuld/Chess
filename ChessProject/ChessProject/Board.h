#pragma once
#include "Pawn.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Rook.h"
#include <vector>

using std::vector;

class Board 
{
public:
	Board(const bool startColor);
	~Board();
	void addSoldier();
	bool getColor() const;
	void boardMenu(Board* temp, char* answer, const string msgFrom);
	string* getCharBoard() const;
	void updateCharBoard();
	void setColor();
	void getStartColor(char* msg);
	vector <Soldier*> getBoard() const;
	Soldier* getSoldierInIndex(char x, char y) const;
	void killSoldier(const string cords);
	void isInChess();
	Board& operator=(const Board& other);
	void getKings(Soldier* currentKing, Soldier* otherKing) const;

private:
	vector <Soldier*> _board;
	string* _charBoard;
	bool _currentColor; // white - false, black - true
};