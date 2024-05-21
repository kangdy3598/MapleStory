#include "ObjectManager.h"

CObjectManager::CObjectManager()
{
}

CObjectManager::CObjectManager(const CObjectManager&)
{
}

CObjectManager::~CObjectManager()
{
}

void CObjectManager::Initialize()
{
}

void CObjectManager::Release()
{
	//SAFE_DELETE(m_CPlayer);
}

void CObjectManager::Render(HDC mem1dc, HDC mem2dc)
{
}

void CObjectManager::PlayAction(int _keyValue)
{
	//m_CPlayer->PlayAction(_keyValue);
}

void CObjectManager::ChangeState(CStateManager* _stateManager, CObjectManager* _obj)
{
	if (m_nowState != nullptr)
		m_nowState->Exit();

	m_nowState = _stateManager;
	m_nowState->ob = _obj;
	m_nowState->Enter();
}

