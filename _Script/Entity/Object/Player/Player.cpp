#include "Player.h"

CPlayer::CPlayer()
{
	m_nowPosition = POINT{ 300, 100 };
}

CPlayer::CPlayer(const CPlayer&)
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Initialize()
{
	LPCSTR m_FilePath = "_Data\\Player.bmp";
	spriteAtlas = (HBITMAP)LoadImageA(nullptr, m_FilePath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	if (!spriteAtlas)
	{
		MessageBox(0, L"파일 읽기에 실패 했습니다. : Player.bmp", 0, 0);
		return;
	}
	
	ChangeState(PlayerIdle::Instance(), this);
}

void CPlayer::Release()
{
}

void CPlayer::Update()
{
	m_nowState->Update();
}

void CPlayer::Render(HDC _mem1dc, HDC _mem2dc)
{
	HBITMAP oldBit1 = (HBITMAP)SelectObject(_mem2dc, spriteAtlas);
	BitBlt(_mem1dc, 
		m_nowPosition.x - 98 / 2,
		m_nowPosition.y - 75 / 2,
		98, 75,
		_mem2dc, 0, 0,
		SRCCOPY);
}

int CPlayer::GetSlotKeyValue(int _key)
{
	return 0;
}

void CPlayer::PlayAction(int _keyValue)
{
	
}
