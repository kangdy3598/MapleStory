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
	POINT slotPosition = POINT();
	int keyValue = -1;			   // 해당 키의 번호
	SpriteInfo* spriteInfo = nullptr;   // 키 이미지 정보
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

	// _key값으로 몇번째 Slot인지 확인합니다.
	int GetSlotNum(int _KeyValue);

	// 해당 UI를 활성화/비활성화 시킵니다.
	void SetEnable();

	// 마우스 입력을 처리 합니다.
	void CheckMouseOver(WORD mouseX, WORD mouseY);
	void CheckMouseClicked(WORD mouseX, WORD mouseY);

private:

	// 모든 키 값을 초기 설정 합니다.
	void InitKeyValue();

	//
	void BindNewKeyValue(int _bindingKeyValue);

	// 슬롯을 새로운 키에 바인딩 시킵니다.
	bool BindNewKeyValue(KeyInfo*, SlotInfo*);
	
	// 배경 이미지와 키 이미지 위치를 조정 합니다.
	void SetCenterPosition(SpriteInfo* _spriteInfo);

	// 슬롯 위치를 키 값에 맞게 조정 합니다.
	void SetSlotPosition(SlotInfo* _slotInfo);
	
	// 파일을 읽어 배경/키/슬롯의 스프라이트 정보를 저장합니다.
	void InitSpriteInfo_BackGround(CFileRead* _CFileRead);
	void InitSpriteInfo_Key(CFileRead* _CFileRead);
	void InitSpriteInfo_Slot(CFileRead* _CFileRead);

	// 배경/키/슬롯을 그립니다.
	void Render_BackGround(HDC _mem1dc, HDC _mem2dc);
	void Render_Key(HDC _mem1dc, HDC _mem2dc);
	void Render_Slot(HDC _mem1dc, HDC _mem2dc);

	// 마우스 위치와 제일 가까운 키/슬롯을 찾습니다.
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

