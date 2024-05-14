#include "Entity.h"

CEntity::CEntity()
{
	m_CFileRead = nullptr;
	m_CObjectManager = nullptr;
	m_CUIManager = nullptr;
	m_CKeyconfig = nullptr;
}

CEntity::CEntity(const CEntity&)
{
	m_CFileRead = nullptr;
	m_CObjectManager = nullptr;
	m_CUIManager = nullptr;
	m_CKeyconfig = nullptr;
}

CEntity::~CEntity()
{
}

void CEntity::Initialize(int _screenWidth, int _screenHeight)
{
	m_CFileRead = new CFileRead;
	if (!m_CFileRead)
		return;
	m_CFileRead->Initialize(L"_Data/MainBar.txt");

	m_CObjectManager = new CObjectManager;
	if (!m_CObjectManager)
		return;

	m_CObjectManager->Initialize();

	m_CUIManager = new CUIManager;
	if (!m_CUIManager)
		return;

	m_CUIManager->Initialize(_screenWidth, _screenHeight, m_CFileRead, m_CKeyconfig);
}

void CEntity::Release()
{
	SAFE_DELETE(m_CObjectManager);
	SAFE_DELETE(m_CUIManager);
}

void CEntity::Update(bool _keyboardState[256])
{
	m_CUIManager->Update(_keyboardState);
}

void CEntity::Render(HWND _hwnd, RECT _rect)
{
	StartRender(_hwnd, _rect);

	m_CUIManager->Render(mem1dc, mem2dc);
	BitBlt(m_hdc, 0, 0, _rect.right, _rect.bottom, mem1dc, 0, 0, SRCCOPY);

	EndRender(_hwnd);
}

void CEntity::ProcessKeyInput(int _key)
{
	int keyValue = m_CKeyconfig->GetSlotKeyValue(_key);

	m_CUIManager->EnableUI(keyValue);
	m_CObjectManager->PlayAction(keyValue);
}

void CEntity::ProcessMouseMove(WORD mouseX, WORD mouseY)
{
	m_CUIManager->CheckMouseOver(mouseX, mouseY);
}
