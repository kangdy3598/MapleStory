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
	void Render(POSITION _playerPos, HDC _mem1dc, HDC _mem2dc);

	void SetActiveTogle(bool _value) { m_bIsActive = _value; }
private:

private:

	int m_spriteWidth = 0;
	int m_spriteHeight = 0;

	bool m_bIsActive;
	HBITMAP m_spriteAtlas = 0;
};

