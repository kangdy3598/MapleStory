#pragma once
#include "../../stdafx.h"
#include "StateManager.h"

class CObjectManager
{
public:
	CObjectManager();
	CObjectManager(const CObjectManager&);
	~CObjectManager();

	virtual void Initialize() = 0;
	void Release();

	virtual void Update() = 0;
	virtual void Render(HDC mem1dc, HDC mem2dc) = 0;
	void PlayAction(int _keyValue);
	void ChangeState(CStateManager* _stateManager, CObjectManager* _obj);

private:

public:
	int m_screenWidth = 0;
	int m_screenHeight = 0;

protected:
	CStateManager* m_nowState = nullptr;

private:
};