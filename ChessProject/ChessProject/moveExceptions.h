#pragma once
#define VALID '0'
#define CHECK_OCCURRED '1'
#define SOLDIER_DOESNT_EXIST '2'
#define SOLDIER_EXIST '3'
#define WILL_BE_OWN_CHECK '4'
#define INVALID_INDEX '5'
#define INVALID_MOVE '6'
#define SAME_CORDS '7'

class moveException 
{
public:
	static char validMove() 
	{
		return VALID;
	}
	static char check()
	{
		return CHECK_OCCURRED;
	}
	static char checkSourceSoldier()
	{
		return SOLDIER_DOESNT_EXIST;
	}
	static char checkDestSoldier()
	{
		return SOLDIER_EXIST;
	}
	static char checkOwnCheck()
	{
		return WILL_BE_OWN_CHECK;
	}
	static char checkIndex()
	{
		return INVALID_INDEX;
	}
	static char invalidMove()
	{
		return INVALID_MOVE;
	}
	static char sameCords()
	{
		return SAME_CORDS;
	}
};