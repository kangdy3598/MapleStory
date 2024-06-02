#pragma once
#include "../../stdafx.h"
#include "../../Engine/FileRead.h"
#include "../../Engine/Render.h"
#include "InputKeyDefine.h"

// ����, Ű����, npc��ȭ, ��ųâ
struct SlotInfo
{
	int keyValue; // �� Ű�� ������ �ش� ������ �׼��� ����
	SpriteInfo* spriteInfo; // ���� ������ �̹��� ���� (png ���� frame, size, worldPos)
};

struct KeyInfo
{
	bool isKeyBinding = false; // �ش� Ű�� ������ ���ε� �Ǿ� �ִ°� 
	POINT slotPosition = POINT();
	int keyValue = -1;			   // �ش� Ű�� ��ȣ
	SpriteInfo* spriteInfo = nullptr;   // Ű �̹��� ����
};

class CKeyconfig
{
public:
	CKeyconfig();
	CKeyconfig(const CKeyconfig&);
	~CKeyconfig();

	void Initialize(HDC _hdc, int _screenWidth, int _screenHeight, HBITMAP _spriteAtlas, CFileRead* m_CFileRead);
	void Release();
	
	void Update(bool _keyboardState[256]);
	void Render(HDC _mem1dc, HDC _mem2dc);

	// _key������ ���° Slot���� Ȯ���մϴ�.
	int GetSlotNum(int _KeyValue);

	// �ش� UI�� Ȱ��ȭ/��Ȱ��ȭ ��ŵ�ϴ�.
	void SetEnable();

	// ���콺 �Է��� ó�� �մϴ�.
	void CheckMouseOver(WORD mouseX, WORD mouseY);
	void CheckMouseClicked(WORD mouseX, WORD mouseY);

private:

	// ��� Ű ���� �ʱ� ���� �մϴ�.
	void InitKeyValue();

	//
	void BindNewKeyValue(int _bindingKeyValue);

	// ������ ���ο� Ű�� ���ε� ��ŵ�ϴ�.
	bool BindNewKeyValue(KeyInfo*, SlotInfo*);
	
	// ��� �̹����� Ű �̹��� ��ġ�� ���� �մϴ�.
	void SetCenterPosition(SpriteInfo* _spriteInfo);

	// ���� ��ġ�� Ű ���� �°� ���� �մϴ�.
	void SetSlotPosition(SlotInfo* _slotInfo);
	
	// ������ �о� ���/Ű/������ ��������Ʈ ������ �����մϴ�.
	void InitSpriteInfo_BackGround(CFileRead* _CFileRead);
	void InitSpriteInfo_Key(CFileRead* _CFileRead);
	void InitSpriteInfo_Slot(CFileRead* _CFileRead);

	// ���/Ű/������ �׸��ϴ�.
	void Render_BackGround(HDC _mem1dc, HDC _mem2dc);
	void Render_Key(HDC _mem1dc, HDC _mem2dc);
	void Render_Slot(HDC _mem1dc, HDC _mem2dc);

	// ���콺 ��ġ�� ���� ����� Ű/������ ã���ϴ�.
	SlotInfo* FindSlotByMouse(WORD mouseX, WORD mouseY);
	KeyInfo* FindKeyByMouse(WORD mouseX, WORD mouseY);
	
	
private:

	int m_screenWidth;
	int m_screenHeight;
	POINT m_MainPosition;

	bool m_bIsActive;
	HBITMAP m_spriteAtlas = 0;
	
	SpriteInfo m_BackSprite[3];
	int m_BackSize = 3;
	
	KeyInfo m_KeyInfo[70];
	SpriteInfo m_KeySprite[70];
	int m_KeySize = 13;

	SlotInfo m_SlotInfo[5];
	SpriteInfo m_SlotSprite[5];
	int m_SlotSize = 5;

	SlotInfo* m_nowClickedSlot = nullptr;
	KeyInfo* m_nowClickedKey = nullptr;
	int m_nowClickedSlotNum = 0;

	SlotInfo* m_nowMouseOverSlot = nullptr;
};

