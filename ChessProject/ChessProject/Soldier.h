#pragma once
#include <string>
#include "FrontedText.h"
#include "moveExceptions.h"
#define LENGTH 8
#define ZERO 0
#define THREE 3
#define TWO 2
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
	bool operator==(const Soldier& other);
	bool getColor() const;
	char getName() const;
	bool colorOfSoldier(const char x, const char y, const string* board) const; // get the color of a soldier using x and y
	virtual void checkIfNotRunOver(const int startX, const int startY, const char x, const char y, const string* board) const = 0;
	virtual void isValidMove(const string cords, const string* board, const bool currentColor) = 0; // uses frontedText to get x and y
	int turnCordToInt(const char cord) const; // use this function to convert x or y to index so isValidMove() can use it on the char** from board
	void setCords(const char x, const char y); // if cords are valid this function will update them

protected:
	void checkIfSourceIsRight(const string* board, const bool color);
	void checkIfDestNotOwn(const char x, const char y, const string* board) const;
	void checkIfNotSameIndex(const char x, const char y) const;
	void checkIfCordsValid(const char x, const char y) const;

private:
	char _x;
	char _y;
	char _name;
	bool _color;
};