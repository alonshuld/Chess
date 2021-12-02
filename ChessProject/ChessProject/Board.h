#pragma once
#include "Soldier.h"
#include "Rook.h"
#include <vector>
#define LENGTH 8
#define ONE 1
#define ZERO 0

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
	void printBoard() const;
	vector <Soldier*> getBoard() const;
	Soldier* getSoldierInIndex(char x, char y) const;
	
private:
	vector <Soldier*> _board;
	string* charBoard;
	bool _currentColor; // white - false, black - true
};