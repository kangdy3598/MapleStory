#pragma once
#define SAFE_DELETE(p)		 if(p){p->Release(); delete p;  p = 0;}
#define SAFE_DELETE_ARRAY(p) if(p){delete[] p; p = 0;}
//--------------------------------------

//--------------------------------------
#define KEY_NUM_UI_INVENTORY 0
#define KEY_NUM_UI_SKILL 1
#define KEY_NUM_UI_KEYCONFIG 2

#define KEY_NUM_ACTION_PICKUP 3
#define KEY_NUM_ACTION_JUMP 4
//--------------------------------------

#define KEYDOWN(key) GetAysncKeyState(int) & 0x8000
#define SINGLETON(type)\
static type* GetInstance()\
{\
	static type manager;\
	return &manager;\
}
