#include "Keyconfig.h"

CKeyconfig::CKeyconfig()
{
	m_screenWidth = 0;
	m_screenHeight = 0;

	m_bIsActive = false;
	m_MainPosition = nullptr;
	memset(m_BackSprite, 0, sizeof(m_BackSprite));
	//m_SlotInfo = new SlotInfo[SLOTSIZE];
}

CKeyconfig::CKeyconfig(const CKeyconfig&)
{
	m_screenWidth = 0;
	m_screenHeight = 0;

	m_bIsActive = false;
	m_MainPosition = nullptr;
	memset(m_BackSprite, 0, sizeof(m_BackSprite));
	//m_SlotInfo = new SlotInfo[SLOTSIZE];
}

CKeyconfig::~CKeyconfig()
{
}

void CKeyconfig::Initialize(int _screenWidth, int _screenHeight, HBITMAP _spriteAtlas, CFileRead* m_CFileRead)
{
	m_screenWidth = _screenWidth;
	m_screenHeight = _screenHeight;

	m_spriteAtlas = _spriteAtlas;

	m_KeyInfo->spriteInfo = m_KeySprite;
	m_SlotInfo->spriteInfo = m_SlotSprite;

	SetInitKeyValue();

	InitSpriteInfo_BackGround(m_CFileRead);
	InitSpriteInfo_Icon(m_CFileRead);
	InitSpriteInfo_Slot(m_CFileRead);
}

void CKeyconfig::Release()
{
	//SAFE_DELETE_ARRAY(m_SlotInfo);
}

void CKeyconfig::Update(bool _keyboardState[256])
{
	//m_MainPosition->x = 100;
}

void CKeyconfig::Render(HDC _mem1dc, HDC _mem2dc)
{
	if (!m_bIsActive)
		return;

	HBITMAP oldBit1 = (HBITMAP)SelectObject(_mem2dc, m_spriteAtlas);
	Render_BackGround(_mem1dc, _mem2dc);
	Render_Icon(_mem1dc, _mem2dc);
	Render_Slot(_mem1dc, _mem2dc);
}

int CKeyconfig::GetSlotKeyValue(int _key)
{
	for (int i = 0; i < SLOTSIZE; i++)
	{
		if (m_SlotInfo[i].keyValue == _key)
			return i;
	}

	return -1;
}

void CKeyconfig::SetEnable()
{
	m_bIsActive ^= TRUE;
}

void CKeyconfig::InitSpriteInfo_BackGround(CFileRead* m_CFileRead)
{
	for (int i = 0; i < m_BackSpriteSize; i++)
	{
		m_CFileRead->SetSpriteInfo(&m_BackSprite[i],
			"KeyConfigBack" + std::to_string(i + 1) + ".png");

		SetCenterPosition(&m_BackSprite[i]);
	}
}

void CKeyconfig::InitSpriteInfo_Icon(CFileRead* m_CFileRead)
{
	for (int i = 0; i < m_KeySpriteSize; i++)
	{
		m_CFileRead->SetSpriteInfo(&m_KeySprite[i],
			"Key" + std::to_string(i) + ".png");
		SetCenterPosition(&m_KeySprite[i]);
	}
}

void CKeyconfig::InitSpriteInfo_Slot(CFileRead* m_CFileRead)
{
	for (int i = 0; i < 4; i++)
	{
		m_CFileRead->SetSpriteInfo(&m_SlotSprite[i],
			"icon" + std::to_string(i+1) + ".png");
		SetCenterPosition(&m_SlotSprite[i]);
	}
}

void CKeyconfig::SetInitKeyValue()
{
	m_SlotInfo[SLOT_WINDOW_KEYCONFIG].keyValue = VK_OEM_5;
	m_SlotInfo[SLOT_WINDOW_SKILL].keyValue = KEY_A;
	m_SlotInfo[SLOT_ACTION_JUMP].keyValue = KEY_F;
}

void CKeyconfig::SetCenterPosition(SpriteInfo* _spriteInfo)
{
	POINT position = POINT{ m_screenWidth / 2, m_screenHeight / 2 };
	position.x -= _spriteInfo->spriteSize.x / 2;
	position.y -= _spriteInfo->spriteSize.y / 2;

	_spriteInfo->spritePosition.x = position.x;
	_spriteInfo->spritePosition.y = position.y;

	_spriteInfo->spritePosition.x += _spriteInfo->intervalMainPos.x;
	_spriteInfo->spritePosition.y += _spriteInfo->intervalMainPos.y;
	
		
}

void CKeyconfig::Render_BackGround(HDC _mem1dc, HDC _mem2dc)
{
	//BitBlt(_mem1dc, 0, 0, 1988, 512, _mem2dc, 0, 0, SRCCOPY);
	
	for (int i = 0; i < m_BackSpriteSize; i++)
	{
		BitBlt(_mem1dc, m_BackSprite[i].spritePosition.x, m_BackSprite[i].spritePosition.y,
						m_BackSprite[i].spriteSize.x,	  m_BackSprite[i].spriteSize.y,
			   _mem2dc, m_BackSprite[i].spriteFrame.x,    m_BackSprite[i].spriteFrame.y,
			   SRCCOPY);
	}
}

void CKeyconfig::Render_Icon(HDC _mem1dc, HDC _mem2dc)
{
	for (int i = 0; i < m_KeySpriteSize; i++)
	{
		BitBlt(_mem1dc, m_KeySprite[i].spritePosition.x, m_KeySprite[i].spritePosition.y,
						m_KeySprite[i].spriteSize.x,     m_KeySprite[i].spriteSize.y,
				_mem2dc, m_KeySprite[i].spriteFrame.x  , m_KeySprite[i].spriteFrame.y,
			SRCCOPY);
	}
}

void CKeyconfig::Render_Slot(HDC _mem1dc, HDC _mem2dc)
{
	for (int i = 0; i < 4; i++)
	{
		BitBlt(_mem1dc, m_SlotSprite[i].spritePosition.x, m_SlotSprite[i].spritePosition.y,
			m_SlotSprite[i].spriteSize.x, m_SlotSprite[i].spriteSize.y,
			_mem2dc, m_SlotSprite[i].spriteFrame.x, m_SlotSprite[i].spriteFrame.y,
			SRCCOPY);
	}
}

void CKeyconfig::CheckMouseOver(WORD mouseX, WORD mouseY)
{
	int positionX = m_SlotSprite[0].spritePosition.x;
	int positionY = m_SlotSprite[0].spritePosition.y;

	int sizeX = m_SlotSprite[0].spriteSize.x;
	int sizeY = m_SlotSprite[0].spriteSize.y;

	if (mouseX > positionX - sizeX && mouseX < positionX + sizeX &&
		mouseY > positionY - sizeY && mouseY < positionY + sizeY)
		











}


