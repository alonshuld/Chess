#pragma once
#include <string>
#include "FrontedText.h"
#include "moveExceptions.h"
#define ASCII_LETTERS 97
#define ASCII_NUMBERS 48
#define ONE 1

class Soldier 
{
public:
	Soldier(const char x, const char y, const char name, const bool color);
	~Soldier();
	char getX() const; 
	char getY() const;
	void checkIfDestNotOwn(const char x, const char y, const string* board) const;
	void checkIfNotSameIndex(const char x, const char y) const;
	void checkIfCordsValid(const char x, const char y) const;
	bool colorOfSoldier(const char x, const char y, const string* board) const; // get the color of a soldier using x and y
	virtual void checkIfNotRunOver(const int startX, const int startY, const char x, const char y, const string* board) const = 0;
	virtual void isValidMove(const string cords, const string* board) = 0; // uses frontedText to get x and y
	int turnCordToInt(const char cord) const; // use this function to convert x or y to index so isValidMove() can use it on the char** from board
	
protected:
	void setCords(const char x, const char y); // if cords are valid this function will update them

private:
	char _x;
	char _y;
	char _name;
	bool _color;
};