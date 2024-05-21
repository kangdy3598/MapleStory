#pragma once
#include "../ObjectManager.h"

class CPlayer : public CObjectManager
{
public:
	CPlayer();
	CPlayer(const CPlayer&);
	~CPlayer();

	void Initialize();
	void Release();

	void Update() override;
	void Render (HDC _mem1dc, HDC _mem2dc) override;

	int GetSlotKeyValue(int _key);
	void PlayAction(int _keyValue);
	
public:

private:
	HBITMAP spriteAtlas = NULL;

	POINT m_nowPosition = POINT();
};

