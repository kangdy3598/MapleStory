#pragma once
#include "../../stdafx.h"
#include "../../Engine/FileRead.h"
#include "../../Engine/Render.h"
#include "InputKeyDefine.h"

// 점프, 키설정, npc대화, 스킬창

struct SlotInfo
{
	int keyValue; // 이 키를 누르면 해당 슬롯의 액션이 실행
	SpriteInfo* spriteInfo; // 슬롯 아이콘 이미지 정보 (png 파일 frame, size, worldPos)
};

struct KeyInfo
{
	bool isKeyBinding = false; // 해당 키에 슬롯이 바인딩 되어 있는가 
	int keyValue = 0;			   // 해당 키의 번호
	SpriteInfo* spriteInfo = nullptr;   // 키 이미지 정보
};

class CKeyconfig
{
public:
	CKeyconfig();
	CKeyconfig(const CKeyconfig&);
	~CKeyconfig();

	void Initialize(int _screenWidth, int _screenHeight, HBITMAP _spriteAtlas, CFileRead* m_CFileRead);
	void Release();
	
	void Update(bool _keyboardState[256]);
	void Render(HDC _mem1dc, HDC _mem2dc);

	// _key값으로 몇번째 Slot인지 확인합니다.
	int GetSlotKeyValue(int _key);
	void SetEnable();
	void CheckMouseOver(WORD mouseX, WORD mouseY);
private:
	void SetInitKeyValue();
	void SetCenterPosition(SpriteInfo* _spriteInfo);

	void InitSpriteInfo_BackGround(CFileRead* m_CFileRead);
	void InitSpriteInfo_Icon(CFileRead* m_CFileRead);
	void InitSpriteInfo_Slot(CFileRead* m_CFileRead);

	void Render_BackGround(HDC _mem1dc, HDC _mem2dc);
	void Render_Icon(HDC _mem1dc, HDC _mem2dc);
	void Render_Slot(HDC _mem1dc, HDC _mem2dc);

	
private:

	int m_screenWidth;
	int m_screenHeight;
	POINT* m_MainPosition;

	bool m_bIsActive;
	HBITMAP m_spriteAtlas = 0;
	
	SpriteInfo m_BackSprite[3];
	int m_BackSpriteSize = 3;
	
	KeyInfo m_KeyInfo[70];
	SpriteInfo m_KeySprite[70];
	int m_KeySpriteSize = 10;

	SlotInfo m_SlotInfo[4];
	SpriteInfo m_SlotSprite[4];
	int m_SlotSpriteSize = 4;
};

