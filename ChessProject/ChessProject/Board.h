#pragma once
#include "Soldier.h"
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
	char* getFirstMsg() const;
	vector <Soldier*> getBoard() const;
	
private:
	vector <Soldier*> _board;
	string* charBoard;
	bool _currentColor; // white - false, black - true
};