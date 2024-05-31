#pragma once
#define SAFE_DELETE(p)		 if(p){p->Release(); delete p;  p = 0;}
#define SAFE_DELETE_ARRAY(p) if(p){delete[] p; p = 0;}
//--------------------------------------

//--------------------------------------
//--------------------------------------

#define KEYDOWN(key) GetAysncKeyState(int) & 0x8000
#define SINGLETON(type)\
static type* GetInstance()\
{\
	static type manager;\
	return &manager;\
}

typedef struct __tagPOINT
{
	float x;
	float y;

	//__tagPOINT(int _x,  int _y) { this->x = _x; this->y = _y; }
	__tagPOINT() : x(0.0f), y(0.0f) {};
	__tagPOINT(float _x, float _y) : x(_x), y(_y) {};
	/*bool operator==(POSITION& rhs)
	{
		return this->x == rhs.x &&
			   this->y == rhs.y;
	}
	bool operator!=(POSITION& rhs)
	{
		return this->x != rhs.x ||
			   this->y != rhs.y;
	}*/
}POSITION;