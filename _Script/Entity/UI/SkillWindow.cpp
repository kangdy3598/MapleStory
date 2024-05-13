#include "SkillWindow.h"

CSkillWindow::CSkillWindow()
{
	m_bIsActive = false;
}

CSkillWindow::CSkillWindow(const CSkillWindow&)
{
	m_bIsActive = false;
}

CSkillWindow::~CSkillWindow()
{
}

void CSkillWindow::Initialize(int _screenWidth, int _screenHeight, HBITMAP _spriteAtlas)
{
	m_spriteAtlas = _spriteAtlas;
}

void CSkillWindow::Release()
{
}

void CSkillWindow::Update(bool _keyboardState[256])
{
}

void CSkillWindow::Render(HDC _mem1dc, HDC _mem2dc)
{
	if (!m_bIsActive)
		return;

	//HBITMAP oldBit1 = (HBITMAP)SelectObject(_mem2dc, m_spriteAtlas);
	Rectangle(_mem1dc, 50, 50, 180, 180);
	//BitBlt(_mem1dc, 0, 0, 1988, 512, _mem2dc, 0, 0, SRCCOPY);
}

void CSkillWindow::SetEnable()
{
	m_bIsActive ^= TRUE;
}
