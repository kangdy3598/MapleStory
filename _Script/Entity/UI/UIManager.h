#pragma once
#include "../../stdafx.h"
#include "Keyconfig.h"
#include "SkillWindow.h"

class CUIManager
{
public:
	CUIManager();
	CUIManager(const CUIManager&);
	~CUIManager();

	void Initialize(int _screenWidth, int _screenHeight, CFileRead* m_CFileRead, CKeyconfig*& _CKeyconfig);
	void Release();

	void Update(bool _keyboardState[256]);
	void Render(HDC mem1dc, HDC mem2dc);

	int GetSlotKeyValue(int _key);
	void EnableUI(int _key);
	void CheckMouseOver(WORD mouseX, WORD mouseY);
	void CheckMouseClicked();
public:

private:
	CKeyconfig* m_CKeyconfig;
	CSkillWindow* m_CSkillWindow;

	HBITMAP spriteAtlas = NULL;
	LPCSTR m_FilePath;
};

