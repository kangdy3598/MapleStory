#pragma once
#include "../stdafx.h"
enum
{
	KEYBOARD_NONE = 0,
	KEYBOARD_DOWN,
	KEYBOARD_ING,
	KEYBOARD_UP
};

class CInput
{
public:
	CInput();
	CInput(const CInput&);
	~CInput();

	SINGLETON(CInput);

	bool Initialize();
	void Release();
	void Update(); //

	bool GetKeyDown(unsigned int _key);
	bool GetKeyUp(unsigned int _key);
	bool GetKey(unsigned int _key);
	//void KeyDownNextFrame();
	
	bool* GetKeyState();
private:
	
private:
	int m_screenWidth = 0;
	int m_screenHeight = 0;

	bool m_keyboardState[256] = { 0, };
	bool m_bIsDown;
};
