#pragma once
#include "../ObjectManager.h"


class CPlayer : public CObjectManager
{
public:
	CPlayer();
	CPlayer(const CPlayer&);
	~CPlayer();

	void Initialize() override;
	void Release();

	void Update(float _fTickTime) override;
	void Render (HDC _mem1dc, HDC _mem2dc) override;
	//void Render2(HWND _hwnd, RECT _rect) override;
	void PlayAction(int _keyValue) override;

	int GetSlotKeyValue(int _key);
	POINT GetPosition() { return m_nowPosition; }
	void SetPosition(POINT _position) { m_nowPosition = _position; }

private:
	void SetGravity(float _fTickTime);

public:
	float m_accelY = 0.0f;
private:
	HBITMAP spriteAtlas = NULL;

	POINT m_nowPosition = POINT();
	

	//ePlayerState m_eState;

	INT m_TEST_MAP_HEIGHT = 600;
	float m_fTime = 0.0f;

private:
	
	int m_Dir = 1;
};

