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

void CEntity::Initialize(HWND _hwnd, RECT _rect, int _screenWidth, int _screenHeight)
{
	m_screenWidth = _screenWidth;
	m_screenHeight = _screenHeight;

	m_CFileRead = new CFileRead;
	if (!m_CFileRead)
		return;
	m_CFileRead->Initialize(L"_Data/MainBar.txt");

	m_CObjectManager = new CPlayer;
	if (!m_CObjectManager)
		return;

	m_CObjectManager->Initialize();
	
	m_CUIManager = new CUIManager;
	if (!m_CUIManager)
		return;

	m_CUIManager->Initialize(GetDC(_hwnd), _screenWidth, _screenHeight, m_CFileRead, m_CKeyconfig);

	
}

void CEntity::Release()
{
	/*ReleaseDC(m_hwnd, m_hdc);
	DeleteDC(mem1dc);
	DeleteObject(hBit1);*/

	SAFE_DELETE(m_CObjectManager);
	SAFE_DELETE(m_CUIManager);
}

void CEntity::Update(bool _keyboardState[256], float _fTickTime)
{
	m_CUIManager->Update(_keyboardState, _fTickTime);
	m_CObjectManager->Update(_keyboardState, _fTickTime);
}

void CEntity::Render(HWND _hwnd, RECT _rect)
{
	// ¡Ú
	m_hdc = GetDC(_hwnd);
	mem1dc = CreateCompatibleDC(m_hdc);
	mem2dc = CreateCompatibleDC(mem1dc);

	if(!hBit1)
	hBit1 = CreateCompatibleBitmap(m_hdc, _rect.right, _rect.bottom);

	oldBit1 = (HBITMAP)SelectObject(mem1dc, hBit1);
	FillRect(mem1dc, &_rect, (HBRUSH)GetStockObject(WHITE_BRUSH));

	m_CUIManager->Render(mem1dc, mem2dc);
	m_CObjectManager->Render(mem1dc, mem2dc);
	
	BitBlt(m_hdc, 0, 0, _rect.right, _rect.bottom, mem1dc, 0, 0, SRCCOPY);

	SelectObject(mem1dc, oldBit1);
	SelectObject(mem2dc, oldBit2);

	DeleteDC(mem2dc);
	DeleteDC(mem1dc);
}

void CEntity::ProcessKeyInput(int _key)
{
	int keyValue = m_CKeyconfig->GetSlotNum(_key);

	m_CUIManager->EnableUI(keyValue);
	m_CObjectManager->PlayAction(keyValue);
}

void CEntity::ProcessMouseMove(WORD mouseX, WORD mouseY)
{
	m_CUIManager->CheckMouseOver(mouseX, mouseY);
}

void CEntity::ProcessMouseDown(WORD mouseX, WORD mouseY)
{
	m_CUIManager->CheckMouseClicked(mouseX, mouseY);
}
