#pragma once
#include <string>
using std::string;

class FrontedText 
{
public:
	FrontedText();
	~FrontedText();
	static char getXorY(const string cords, const int index);
};