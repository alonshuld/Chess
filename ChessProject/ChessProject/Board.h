#pragma once
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
	bool getColor() const;
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
	string* charBoard;
	bool _currentColor; // white - false, black - true
};