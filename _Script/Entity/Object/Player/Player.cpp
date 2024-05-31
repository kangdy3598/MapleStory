#include "Player.h"

CPlayer::CPlayer()
{
	m_nowPosition = POSITION( 1000, 100);
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

void CPlayer::Update(bool _keyboardState[256], float _fTime)
{ 
	m_nowPosition.x += m_accelX * m_moveDir * _fTime / 10;
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

	std::wstring posx = std::to_wstring(m_nowPosition.x);
	std::wstring posy = std::to_wstring(m_nowPosition.y);
	std::wstring xyPosText = L"좌표 : " + posx + L", " + posy;   // x, y

	TextOut(_mem1dc, 10, 30, xyPosText.c_str(), xyPosText.size());
	//=============================================================

	std::wstring accelx = std::to_wstring(m_accelX);
	std::wstring accely = std::to_wstring(m_accelY);
	std::wstring accelText = L"가속 : " + accelx + L", " + accely;   // x, y

	TextOut(_mem1dc, 10, 50, accelText.c_str(), accelText.size());
	//=============================================================
	std::wstring frame = std::to_wstring(m_fTime);
	std::wstring frameText = L"프레임 :  " + frame;

	TextOut(_mem1dc, 10, 70, frameText.c_str(), frameText.size());

	/*WCHAR str[100];
	wsprintf(str, TEXT("프레임 : %d"), m_fTime);
	TextOut(_mem1dc, 10, 50, str, lstrlen(str));*/
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