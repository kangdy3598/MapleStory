#pragma once
#include "../../stdafx.h"
#include "../../Engine/Render.h"

class CSkillWindow
{
public:
	CSkillWindow();
	CSkillWindow(const CSkillWindow&);
	~CSkillWindow();

	void Initialize(int _screenWidth, int _screenHeight, HBITMAP _spriteAtlas);
	void Release();

	void Update(bool _keyboardState[256]);
	void Render(HDC _mem1dc, HDC _mem2dc);

	void SetEnable();
private:

private:
	bool m_bIsActive;
	HBITMAP m_spriteAtlas = 0;
};

