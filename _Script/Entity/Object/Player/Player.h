#pragma once
#include <string>
#include "SkillEffect/SkillEffect.h"
#include "../ObjectManager.h"


class CPlayer : public CObjectManager
{
public:
	CPlayer();
	CPlayer(const CPlayer&);
	~CPlayer();

	void Initialize() override;
	void Release();

	void Update(bool _keyboardState[256], float _fTickTime) override;
	void Render (HDC _mem1dc, HDC _mem2dc) override;
	//void Render2(HWND _hwnd, RECT _rect) override;
	void PlayAction(int _keyValue) override;

	int GetSlotKeyValue(int _key);
	POSITION GetPosition() { return m_nowPosition; }
	void SetPosition(POSITION _position) { m_nowPosition = _position; }

	CSkillEffect* GetSkillEffect() { return m_skillEffect; }
private:
	void ShowTextPlayerInfo(HDC _mem1dc);
	void SetGravity(float _fTickTime);

public:
	POSITION m_nowPosition = POSITION();
	float m_accelX = 0.0f;
	float m_accelY = 0.0f;
	int m_moveDir = 0;

private:
	HBITMAP spriteAtlas = NULL;
	CSkillEffect* m_skillEffect = nullptr;
	
	float m_fTime = 0.0f;
};

