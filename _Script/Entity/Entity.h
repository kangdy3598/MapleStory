#pragma once
#include "../Engine/Render.h"
#include "Object/Player/Player.h"
#include "UI/UIManager.h"

class CEntity /*: public CRender*/
{
public:
	CEntity();
	CEntity(const CEntity&);
	~CEntity();

	void Initialize(HWND _hwnd, RECT _rect, int _screenWidth, int _screenHeight);
	void Release();

	void Update(bool _keyboardState[256], float _fTickTime);
	void Render(HWND _hwnd, RECT _rect);

	void ProcessKeyInput(int _key);
	void ProcessMouseMove(WORD mouseX, WORD mouseY);
	void ProcessMouseDown(WORD mouseX, WORD mouseY);

private:
	int m_screenWidth = 0;
	int m_screenHeight = 0;

private:
	CObjectManager* m_CObjectManager;
	CUIManager* m_CUIManager;

	CKeyconfig* m_CKeyconfig;
	CFileRead* m_CFileRead;

	RECT m_rect;
	HDC m_hdc = nullptr;
	PAINTSTRUCT m_ps = {};
	HDC mem1dc = 0, mem2dc = 0;
	HBITMAP hBit1 = 0, hBit2 = 0, oldBit1 = 0, oldBit2 = 0;
};