#include "Keyconfig.h"

CKeyconfig::CKeyconfig()
{
	m_screenWidth = 0;
	m_screenHeight = 0;
	
	m_bIsActive = false;
	memset(m_BackSprite, 0, sizeof(m_BackSprite));
	//m_SlotInfo = new SlotInfo[SLOTSIZE];
}

CKeyconfig::CKeyconfig(const CKeyconfig&)
{
	m_screenWidth = 0;
	m_screenHeight = 0;

	m_bIsActive = false;
	memset(m_BackSprite, 0, sizeof(m_BackSprite));
	//m_SlotInfo = new SlotInfo[SLOTSIZE];
}

CKeyconfig::~CKeyconfig()
{
}

//========================================================================

void CKeyconfig::Initialize(HDC _hdc, int _screenWidth, int _screenHeight, HBITMAP _spriteAtlas, CFileRead* m_CFileRead)
{
	m_screenWidth = _screenWidth;
	m_screenHeight = _screenHeight;
	m_MainPosition = POINT{ m_screenWidth / 2, m_screenHeight / 2 };

	m_spriteAtlas = _spriteAtlas;

	for (int i = 0; i < m_KeySize; i++)
	{
		m_KeyInfo[i].spriteInfo = &m_KeySprite[i];
	}
	
	for (int i = 0; i < m_SlotSize; i++)
	{
		m_SlotInfo[i].spriteInfo = &m_SlotSprite[i];
	}

	InitKeyValue();
	InitSpriteInfo_BackGround(m_CFileRead);
	InitSpriteInfo_Key(m_CFileRead);
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
	Render_Key(_mem1dc, _mem2dc);
	Render_Slot(_mem1dc, _mem2dc);
}

int CKeyconfig::GetSlotNum(int _KeyValue)
{
	for (int i = 0; i < SLOTSIZE; i++)
	{
		if (m_SlotInfo[i].keyValue == _KeyValue)
			return i;
	}

	return -1;
}

void CKeyconfig::SetEnable()
{
	m_bIsActive ^= TRUE;
}

//========================================================================

//InitSpriteInfo
void CKeyconfig::InitSpriteInfo_BackGround(CFileRead* _CFileRead)
{
	for (int i = 0; i < m_BackSize; i++)
	{
		_CFileRead->SetSpriteInfo(&m_BackSprite[i],
			"KeyConfigBack" + std::to_string(i + 1) + ".png");

		SetCenterPosition(&m_BackSprite[i]);
	}
}
void CKeyconfig::InitSpriteInfo_Key(CFileRead* _CFileRead)
{
	for (int i = 0; i < m_KeySize; i++)
	{
		_CFileRead->SetSpriteInfo(&m_KeySprite[i],
			"Key" + std::to_string(i) + ".png");

		SetCenterPosition(&m_KeySprite[i]);
		
		m_KeyInfo[i].slotPosition =
			_CFileRead->SetKeySlotPosition("Key" + std::to_string(i) + ".png");
	}
}
void CKeyconfig::InitSpriteInfo_Slot(CFileRead* _CFileRead)
{
	for (int i = 0; i < m_SlotSize; i++)
	{
		_CFileRead->SetSpriteInfo(&m_SlotSprite[i],
			"icon" + std::to_string(i+1) + ".png");
		SetSlotPosition(&m_SlotInfo[i]);
	}
}

//SettingKeyValue
void CKeyconfig::InitKeyValue()
{
	m_SlotInfo[SLOT_WINDOW_ITEM].keyValue = VK_F5;
	m_SlotInfo[SLOT_WINDOW_SKILL].keyValue = VK_F4;
	m_SlotInfo[SLOT_WINDOW_KEYCONFIG].keyValue = VK_F3;
	m_SlotInfo[SLOT_ACTION_PICKUP].keyValue = VK_F2;// KEY_A;
	m_SlotInfo[SLOT_ACTION_JUMP].keyValue = VK_ESCAPE;
	
	
	////////////////////////////////////////////////////////////
	m_KeyInfo[0].keyValue = VK_ESCAPE;
	m_KeyInfo[1].keyValue = VK_F1;
	m_KeyInfo[2].keyValue = VK_F2;
	m_KeyInfo[3].keyValue = VK_F3;
	m_KeyInfo[4].keyValue = VK_F4;
	m_KeyInfo[5].keyValue = VK_F5;
	m_KeyInfo[6].keyValue = VK_F6;
	m_KeyInfo[7].keyValue = VK_F7;
	m_KeyInfo[8].keyValue = VK_F8;
	m_KeyInfo[9].keyValue = VK_F9;
	m_KeyInfo[10].keyValue = VK_F10;
	m_KeyInfo[11].keyValue = VK_F11;
	m_KeyInfo[12].keyValue = VK_F12;
	////////////////////////////////////////////////////////////

	/*for (int i = 13; i <= 25; i++) m_KeyInfo[i].keyValue = 35 + i;
	m_KeyInfo[0].keyValue = VK_OEM_3;
	m_KeyInfo[24].keyValue = VK_OEM_PLUS;
	m_KeyInfo[25].keyValue = VK_OEM_MINUS;

	m_KeyInfo[60].keyValue = VK_SHIFT;
	m_KeyInfo[61].keyValue = VK_MENU;
	m_KeyInfo[62].keyValue = VK_SPACE;

	m_KeyInfo[63].keyValue = VK_INSERT;
	m_KeyInfo[64].keyValue = VK_HOME;
	m_KeyInfo[65].keyValue = VK_PRIOR;

	m_KeyInfo[66].keyValue = VK_DELETE;
	m_KeyInfo[67].keyValue = VK_END;
	m_KeyInfo[68].keyValue = VK_PRIOR;*/

	for (int i = 0; i < m_SlotSize; i++)
	{
		BindNewKeyValue(m_SlotInfo[i].keyValue);
	}
}
void CKeyconfig::BindNewKeyValue(int _bindingKeyValue)
{
	for (int i = 0; i < m_KeySize; i++)
	{
		if (m_KeyInfo[i].keyValue == _bindingKeyValue)
		{
			m_KeyInfo[i].isKeyBinding = true;
			return;
		}

	}
}
bool CKeyconfig::BindNewKeyValue(KeyInfo* _keyInfo, SlotInfo* _slotInfo)
{
	if (_keyInfo->isKeyBinding)
		return false;

	_keyInfo->isKeyBinding = true;
	_slotInfo->keyValue = _keyInfo->keyValue;

	return true;
}

//SettingPosition
void CKeyconfig::SetCenterPosition(SpriteInfo* _spriteInfo)
{
	_spriteInfo->spritePosition = m_MainPosition;

	_spriteInfo->spritePosition.x += _spriteInfo->intervalMainPos.x;
	_spriteInfo->spritePosition.y += _spriteInfo->intervalMainPos.y;
}
void CKeyconfig::SetSlotPosition(SlotInfo* _slotInfo)
{
	for (int i = 0; i < m_KeySize; i++)
	{
		if (m_KeyInfo[i].keyValue == _slotInfo->keyValue)
		{
			_slotInfo->spriteInfo->spritePosition.x
				= m_MainPosition.x + m_KeyInfo[i].slotPosition.x;
			_slotInfo->spriteInfo->spritePosition.y
				= m_MainPosition.y + m_KeyInfo[i].slotPosition.y;
		}
	}
}

//Render
void CKeyconfig::Render_BackGround(HDC _mem1dc, HDC _mem2dc)
{
	//BitBlt(_mem1dc, 0, 0, 1988, 512, _mem2dc, 0, 0, SRCCOPY);
	
	for (int i = 0; i < m_BackSize; i++)
	{
		BitBlt(_mem1dc,
			m_BackSprite[i].spritePosition.x - m_BackSprite[i].spriteSize.x / 2,
			m_BackSprite[i].spritePosition.y - m_BackSprite[i].spriteSize.y / 2,
						m_BackSprite[i].spriteSize.x,	  m_BackSprite[i].spriteSize.y,
			   _mem2dc, m_BackSprite[i].spriteFrame.x,    m_BackSprite[i].spriteFrame.y,
			   SRCCOPY);
	}
}
void CKeyconfig::Render_Key(HDC _mem1dc, HDC _mem2dc)
{
	for (int i = 0; i < m_KeySize; i++)
	{
		BitBlt(_mem1dc,
			m_KeySprite[i].spritePosition.x - m_KeySprite[i].spriteSize.x / 2,
			m_KeySprite[i].spritePosition.y - m_KeySprite[i].spriteSize.y / 2,
			m_KeySprite[i].spriteSize.x,     m_KeySprite[i].spriteSize.y,
			_mem2dc, m_KeySprite[i].spriteFrame.x  , m_KeySprite[i].spriteFrame.y,
			SRCCOPY);
	}
}
void CKeyconfig::Render_Slot(HDC _mem1dc, HDC _mem2dc)
{
	for (int i = 0; i < m_SlotSize; i++)
	{
		BitBlt(_mem1dc,
			m_SlotSprite[i].spritePosition.x - m_SlotSprite[i].spriteSize.x / 2,
			m_SlotSprite[i].spritePosition.y - m_SlotSprite[i].spriteSize.y / 2,
			m_SlotSprite[i].spriteSize.x, m_SlotSprite[i].spriteSize.y,
			_mem2dc, m_SlotSprite[i].spriteFrame.x, m_SlotSprite[i].spriteFrame.y,
			SRCCOPY);
	}
}

//CheckMouse
void CKeyconfig::CheckMouseOver(WORD mouseX, WORD mouseY)
{
	if (m_nowClickedSlot)
	{
		m_nowClickedSlot->spriteInfo->spritePosition.x = mouseX;
		m_nowClickedSlot->spriteInfo->spritePosition.y = mouseY;
		return;
	}

	//m_nowMouseOverSlot = FindSlotByMouse(mouseX, mouseY);
	
}
void CKeyconfig::CheckMouseClicked(WORD mouseX, WORD mouseY)
{
	if (m_nowClickedSlot)
	{
		KeyInfo* clickKey = FindKeyByMouse(mouseX, mouseY);
		if (!clickKey || !clickKey->keyValue)
			return;

		if (!BindNewKeyValue(clickKey, m_nowClickedSlot))
			return;

		m_SlotInfo[m_nowClickedSlotNum].spriteInfo->spritePosition.x
			= m_MainPosition.x + clickKey->slotPosition.x;

		m_SlotInfo[m_nowClickedSlotNum].spriteInfo->spritePosition.y
			= m_MainPosition.y + clickKey->slotPosition.y;
		
		m_nowClickedSlot = nullptr;
	}
		
		
	else
	{
		//FindSlotByMouse(mouseX, mouseY)->keyValue = -1;
		FindKeyByMouse(mouseX, mouseY)->isKeyBinding = false;
		m_nowClickedSlot = FindSlotByMouse(mouseX, mouseY);
	}
		
}

//FindByMouse
SlotInfo* CKeyconfig::FindSlotByMouse(WORD mouseX, WORD mouseY)
{
	for (int i = 0; i < m_SlotSize; i++)
	{
		int positionX = m_SlotSprite[i].spritePosition.x;
		int positionY = m_SlotSprite[i].spritePosition.y;

		int sizeX = m_SlotSprite[i].spriteSize.x;
		int sizeY = m_SlotSprite[i].spriteSize.y;

		bool value = true;
		value &= mouseX >= positionX - sizeX/2  && mouseX <= positionX + sizeX/2;
		value &= mouseY >= positionY - sizeY/2  && mouseY <= positionY + sizeY/2;

		if (value)
		{
			m_nowClickedSlotNum = i;
			return &m_SlotInfo[i];
		}
			
	}
	return nullptr;
}
KeyInfo* CKeyconfig::FindKeyByMouse(WORD mouseX, WORD mouseY)
{
	for (int i = 0; m_KeySize; i++)
	{
		int positionX = m_KeySprite[i].spritePosition.x;
		int positionY = m_KeySprite[i].spritePosition.y;

		int sizeX = m_KeySprite[i].spriteSize.x;
		int sizeY = m_KeySprite[i].spriteSize.y;

		bool value = true;
		value &= mouseX >= positionX - sizeX/2 && mouseX <= positionX + sizeX/2;
		value &= mouseY >= positionY - sizeY/2 && mouseY <= positionY + sizeY/2;

		if (value)
		{
			return &m_KeyInfo[i];
		}

	}
	return nullptr;
}

