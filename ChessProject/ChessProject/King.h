#include "Soldier.h"

class King : public Soldier
{
public:
	King(const char x, const char y, const char name, const bool color);
	~King();
	void isValidMove(const string cords, const string* board, const bool currentColor);
	void checkIfNotRunOver(const int startX, const int startY, const char x, const char y, const string* board) const;
};