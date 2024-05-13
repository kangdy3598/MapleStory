#include "../../stdafx.h"
#include "ObjectManager.h"

CObjectManager::CObjectManager()
{
	m_CPlayer = nullptr;
}

CObjectManager::CObjectManager(const CObjectManager&)
{
	m_CPlayer = nullptr;
}

CObjectManager::~CObjectManager()
{
}

void CObjectManager::Initialize()
{
	m_CPlayer = new CPlayer;
	if (!m_CPlayer)
		return;
	m_CPlayer->Initialize();
}

void CObjectManager::Release()
{
	SAFE_DELETE(m_CPlayer);
}

void CObjectManager::Update()
{

}

void CObjectManager::Render(HWND hwnd, RECT rect)
{

}

void CObjectManager::PlayAction(int _keyValue)
{
	m_CPlayer->PlayAction(_keyValue);
}

