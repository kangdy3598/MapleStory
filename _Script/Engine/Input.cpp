#include "Input.h"

CInput::CInput()
{
}

CInput::CInput(const CInput&)
{
}

CInput::~CInput()
{
}

void CInput::Initialize()
{
	for (int i = 0; i < COUNT; i++)
	{
		vecKey.push_back(tagKeyState());
	}
}

void CInput::Release()
{
}

void CInput::Update()
{
	for (int i = 0; i < COUNT; i++)
	{
		if(GetAsyncKeyState(m_arrKey[i]) & 0x8000)
		{
			if (vecKey[i].bIsPressed)
				vecKey[i].eKeyState = KEY_PRESSED;
			else
			{
				vecKey[i].eKeyState = KEY_DOWN;
				vecKey[i].bIsPressed = true;
			}	
		}
		else
		{
			if (vecKey[i].bIsPressed)
			{
				vecKey[i].eKeyState = KEY_UP;
				vecKey[i].bIsPressed = false;
			}
				
			else
			{
				vecKey[i].eKeyState = KEY_NONE;
			}
		}
	}
}

bool CInput::GetKeyDown(unsigned int _key)
{
	for (int i = 0; i < COUNT; i++)
	{
		if (m_arrKey[i] == _key)
		{
			if (vecKey[i].eKeyState == KEY_DOWN)
				return true;
		}
	}

	return false;
}

bool CInput::GetKeyDown(KeyValue _key)
{
	if (vecKey[_key].eKeyState == KEY_DOWN)
		return true;
	else
		return false;
}

bool CInput::GetKeyUp(unsigned int _key)
{
	for (int i = 0; i < COUNT; i++)
	{
		if (m_arrKey[i] == _key)
		{
			if (vecKey[i].eKeyState == KEY_UP)
				return true;
			else
				return false;
		}
	}

	return false;

}

bool CInput::GetKey(unsigned int _key)
{
	for (int i = 0; i < COUNT; i++)
	{
		if (m_arrKey[i] == _key)
		{
			if (vecKey[i].eKeyState == KEY_PRESSED)
				return true;
		}
	}

	return false;
}

KeyState CInput::GetKeyState(unsigned int _key)
{
	for (int i = 0; i < COUNT; i++)
	{
		if (m_arrKey[i] == _key)
		{
			return vecKey[i].eKeyState;
		}
	}
}

