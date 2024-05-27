#include "Player.h"

CPlayer::CPlayer()
{
	m_nowPosition = POINT{ 300, 100 };
	m_accelY = 3.0f;
	ChangeState(PlayerJump::Instance(), this);
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

	
}

void CPlayer::Release()
{
}

void CPlayer::Update(float _fTime)
{
	m_nowState->Update(_fTime);
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

	switch (m_eState)
	{
	case IDLE:
		TextOut(_mem1dc, 10, 10, TEXT("IDLE"), 4);
		break;
	case WALK:
		TextOut(_mem1dc, 10, 10, TEXT("WALK"), 4);
		break;
	case JUMP:
		TextOut(_mem1dc, 10, 10, TEXT("JUMP"), 4);
		break;
	default:
		break;
	}
	
	TCHAR str[128];
	SetTextAlign(_mem1dc, TA_LEFT);
	wsprintf(str, TEXT("accel : %f"), m_accelY);
	TextOut(_mem1dc, 10, 30, str, lstrlen(str));

	wsprintf(str, TEXT("pos : %d"), m_nowPosition.y);
	TextOut(_mem1dc, 10, 50, str, lstrlen(str));
}

int CPlayer::GetSlotKeyValue(int _key)
{
	return 0;
}

void CPlayer::SetGravity(float _fTickTime)
{
	
}

void CPlayer::PlayAction(int _keyValue)
{
	m_nowState->PlayAction(_keyValue);
}