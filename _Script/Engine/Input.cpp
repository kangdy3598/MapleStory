#include "Input.h"

CInput::CInput()
{
	m_bIsDown = false;
}

CInput::CInput(const CInput&)
{
	m_bIsDown = false;
}

CInput::~CInput()
{
}

bool CInput::Initialize()
{
	return true;
}

void CInput::Release()
{
}

void CInput::Update()
{
}

bool CInput::GetKeyDown(unsigned int _key)
{
	if (GetAsyncKeyState(_key) & 0x0001)
		return true;

	else
		return false;
}

bool CInput::GetKeyUp(unsigned int _key)
{
	if ((GetAsyncKeyState(_key) & 0x8000) == 0x8000 && !m_bIsDown)
	{
		m_bIsDown = true;
	}
		
	
	if ((GetAsyncKeyState(_key) & 0x8001) == 0x0000 && m_bIsDown)
	{
		m_bIsDown = false;
		return true;
	}

	else
		return false;
}

bool CInput::GetKey(unsigned int _key)
{
	if ((GetAsyncKeyState(_key) & 0x8000))
		return true;
	
	else
		return false;
}

bool* CInput::GetKeyState()
{
	return m_keyboardState;
}

