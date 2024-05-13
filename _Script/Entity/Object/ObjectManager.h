#pragma once
#include "Player/Player.h"

class CObjectManager
{
public:
	CObjectManager();
	CObjectManager(const CObjectManager&);
	~CObjectManager();

	void Initialize();
	void Release();

	void Update();
	void Render(HWND hwnd, RECT rect);
	void PlayAction(int _keyValue);

private:

public:
	int m_screenWidth = 0;
	int m_screenHeight = 0;

private:
	CPlayer* m_CPlayer;
};