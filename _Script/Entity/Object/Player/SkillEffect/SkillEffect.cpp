#include "SkillEffect.h"

CSkillEffect::CSkillEffect()
{
	m_bIsActive = false;
}

CSkillEffect::CSkillEffect(const CSkillEffect&)
{
	m_bIsActive = false;
}

CSkillEffect::~CSkillEffect()
{
}

void CSkillEffect::Initialize(int _screenWidth, int _screenHeight, HBITMAP _spriteAtlas)
{
	m_spriteAtlas = _spriteAtlas;
}

void CSkillEffect::Release()
{
}

void CSkillEffect::Update(bool _keyboardState[256])
{
}

void CSkillEffect::Render(POSITION _playerPos, HDC _mem1dc, HDC _mem2dc)
{
	if (!m_bIsActive)
		return;

	HBITMAP oldBit1 = (HBITMAP)SelectObject(_mem2dc, m_spriteAtlas);
	BitBlt(_mem1dc, 
		_playerPos.x - 98 / 2 + (-1015 / 2),
		_playerPos.y - 75 / 2 + (-677/ 2),
		1015, 677,
		_mem2dc, 0, 0,
		SRCCOPY);
}
