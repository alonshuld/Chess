#pragma once
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
	void getFirstMsg(char* msg) const;
	vector <Soldier*> getBoard() const;
	Soldier* getSoldierInIndex(char x, char y) const;
	void killSoldier(const string cords);

protected:
	void printBoard() const;

private:
	vector <Soldier*> _board;
	string* charBoard;
	bool _currentColor; // white - false, black - true
};