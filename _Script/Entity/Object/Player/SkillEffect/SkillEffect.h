#pragma once
#include "../../../../stdafx.h"

class CSkillEffect
{
public:
	CSkillEffect();
	CSkillEffect(const CSkillEffect&);
	~CSkillEffect();

	void Initialize(int _screenWidth, int _screenHeight, HBITMAP _spriteAtlas);
	void Release();

	void Update(bool _keyboardState[256]);
	void Render(HDC _mem1dc, HDC _mem2dc);

private:

private:
	bool m_bIsActive;
	HBITMAP m_spriteAtlas = 0;
};

