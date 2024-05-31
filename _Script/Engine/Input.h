#pragma once
#include "../stdafx.h"
enum KeyState
{
	KEY_NONE = 0,
	KEY_DOWN,
	KEY_PRESSED,
	KEY_UP
};

enum KeyValue
{
	F1 = 0, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,

	A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
	
	OEM_1, // ;
	OEM_2, // ?
	OEM_3, // ~
	OEM_4, // [
	OEM_5, // £Ü
	OEM_6, // ]
	OEM_7, // "
	OEM_8, // +
	OEM_9, // -
	OEM_10,// <
	OEM_11,// >
	//VK_OEM_1 : ;
	//VK_OEM_2 : /?
	//VK_OEM_3 : ~
	//VK_OEM_4 : [
	//VK_OEM_5 : \
	//VK_OEM_6 : ]
	//VK_OEM_7 : "
	//VK_OEM_PLUS   : +=
	//VK_OEM_MINUS  : -_
	//VK_OEM_COMMA  : ,<
	//VK_OEM_PERIOD : .>

	TAB, ESC, CONTROL,
	SHIFT, ALT, SPACE,
	INS, DEL, HOM, END, PGU, PGD,

	LEFT,RIGHT,UP,DOWN,
	COUNT
};

struct tagKeyState
{
	tagKeyState()
	{
		eKeyState = KEY_NONE;
		bIsPressed = false;
	}

	tagKeyState(KeyState _keyState, bool _isPressed)
	{
		eKeyState = _keyState;
		bIsPressed = _isPressed;
	}

	~tagKeyState(){}

	KeyState eKeyState;
	bool bIsPressed;
};

class CInput
{
public:
	CInput();
	CInput(const CInput&);
	~CInput();

	SINGLETON(CInput);

	void Initialize();
	void Release();
	void Update();

	bool GetKeyDown(unsigned int _key);
	bool GetKeyDown(KeyValue _key);
	bool GetKeyUp(unsigned int _key);
	bool GetKey(unsigned int _key);

	KeyState GetKeyState(unsigned int _key);
	KeyState GetKeyState(KeyValue _key);
private:
	
private:
	int m_arrKey[COUNT] =
	{ VK_F1, VK_F2, VK_F3, VK_F4, VK_F5, VK_F6,
	  VK_F7, VK_F8, VK_F9, VK_F10, VK_F11, VK_F12,

      'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
	  'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',

	  VK_OEM_1, VK_OEM_2, VK_OEM_3, VK_OEM_4, VK_OEM_5, VK_OEM_6, VK_OEM_7,
	  VK_OEM_PLUS, VK_OEM_MINUS, VK_OEM_COMMA, VK_OEM_PERIOD,

	  VK_TAB, VK_ESCAPE, VK_CONTROL, VK_SHIFT, VK_MENU, VK_SPACE,

	  VK_INSERT, VK_DELETE, VK_HOME, VK_END, VK_PRIOR, VK_NEXT,

	  VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN
	};

	std::vector<tagKeyState> vecKey;
};
