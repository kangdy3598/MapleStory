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

void CInput::KeyDown(unsigned int _key)
{
	//m_keyboardState[key] = KEYBOARD_DOWN;
	m_keyboardState[_key] = true;
}

void CInput::KeyUp(unsigned int _key)
{
	m_keyboardState[_key] = false;
}

bool* CInput::GetKeyState()
{
	return m_keyboardState;
}

