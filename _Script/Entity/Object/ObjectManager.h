#pragma once
#include "../../stdafx.h"
#include "StateManager.h"

enum eStateList
{
	IDLE,
	WALK,
	JUMP,
	END
};

class CObjectManager
{
public:
	CObjectManager();
	CObjectManager(const CObjectManager&);
	~CObjectManager();

	virtual void Initialize() = 0;
	void Release();

	virtual void Update(float _fTickTime) = 0;
	virtual void Render(HDC mem1dc, HDC mem2dc) = 0;
	//virtual void Render2(HWND _hwnd, RECT _rect) = 0;
	virtual void PlayAction(int _keyValue);
	void ChangeState(CStateManager* _stateManager, CObjectManager* _obj);
	void ChangeState(eStateList _state);
private:

public:
	int m_screenWidth = 0;
	int m_screenHeight = 0;

protected:
	CStateManager* m_nowState = nullptr;
	eStateList m_eState;
private:
};