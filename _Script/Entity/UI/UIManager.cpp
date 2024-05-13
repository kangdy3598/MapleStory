#include "UIManager.h"

CUIManager::CUIManager()
{
	m_CKeyconfig = nullptr;
	m_CSkillWindow = nullptr;
	m_FilePath = "_Data\\MainBar.bmp";
}

CUIManager::CUIManager(const CUIManager&)
{
	m_CKeyconfig = nullptr;
	m_CSkillWindow = nullptr;
	m_FilePath = "_Data\\MainBar.bmp";
}

CUIManager::~CUIManager()
{
}

void CUIManager::Initialize(int _screenWidth, int _screenHeight, CFileRead* m_CFileRead, CKeyconfig*& _CKeyconfig)
{
	spriteAtlas = (HBITMAP)LoadImageA(nullptr, m_FilePath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	if (!spriteAtlas)
	{
		MessageBox(0, L"파일 읽기에 실패 했습니다. : MainBar.bmp", 0, 0);
		return;
	}
	
	m_CKeyconfig = new CKeyconfig;
	if (!m_CKeyconfig)
	{
		return;
	}
	m_CKeyconfig->Initialize(_screenWidth, _screenHeight, spriteAtlas, m_CFileRead);
	_CKeyconfig = m_CKeyconfig;

	m_CSkillWindow = new CSkillWindow;
	if (!m_CSkillWindow)
	{
		return;
	}
	m_CSkillWindow->Initialize(_screenWidth, _screenHeight, spriteAtlas);

	
}

void CUIManager::Release()
{
	SAFE_DELETE(m_CKeyconfig);
}

void CUIManager::Update(bool _keyboardState[256])
{
	m_CKeyconfig->Update(_keyboardState);
}

void CUIManager::Render(HDC mem1dc, HDC mem2dc)
{
	//★ : UI 레이어 순서 설정할 것
	m_CKeyconfig->Render(mem1dc, mem2dc);
	m_CSkillWindow->Render(mem1dc, mem2dc);
}

int CUIManager::GetSlotKeyValue(int _key)
{
	return m_CKeyconfig->GetSlotKeyValue(_key);
}

void CUIManager::EnableUI(int _keyValue)
{
	switch (_keyValue)
	{
	case SLOT_WINDOW_KEYCONFIG:
		m_CKeyconfig->SetEnable();
		break;
	case SLOT_WINDOW_SKILL:
		m_CSkillWindow->SetEnable();
		break;
	default:
		break;
	}
}
