#include "System.h"

CSystem::CSystem()
{
	//m_CInput = nullptr;
	m_CEntity = nullptr;
	m_CTime = nullptr;
}

CSystem::CSystem(const CSystem&)
{
	//m_CInput = nullptr;
	m_CEntity = nullptr;
	m_CTime = nullptr;
}

CSystem::~CSystem()
{
}

bool CSystem::Initialize()
{
	m_CInput = new CInput;
	if (!m_CInput) return false;
	
	m_CEntity = new CEntity;
	if (!m_CEntity) return false;
	
	m_CTime = new CTime;
	if (!m_CTime) return false;

	int screenWidth = 0;
	int screenHeight = 0;

	InitializeWindows(screenWidth, screenHeight);
	
	RECT rect;
	GetClientRect(m_hwnd, &rect);

	CInput::GetInstance()->Initialize();
	m_CEntity->Initialize(m_hwnd, rect, screenWidth, screenHeight);
	m_CTime->Initialize();

	ShowWindows();

	return true;
}

void CSystem::Release()
{
	//SAFE_DELETE(m_CInput);
	SAFE_DELETE(m_CEntity);
	//SAFE_DELETE(m_CTime);

	ShutdownWindows();
}

void CSystem::Run()
{
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			if (!Update())
			{
				MessageBox(m_hwnd, L"Frame Processing Failed", L"Error", MB_OK);
				break;
			}
		}
	}
}

bool CSystem::Update()
{
	RECT rect;
	GetClientRect(m_hwnd, &rect);

	m_CTime->Update();
	
	CInput::GetInstance()->Update();
	m_CEntity->Update(nullptr, m_CTime->GetTime());
	m_CEntity->Render(m_hwnd, rect);

	return true;
}

LRESULT CALLBACK CSystem::MessageHandler(HWND hwnd, UINT umsg, WPARAM wparam, LPARAM lparam)
{
	switch (umsg)
	{
	case WM_KEYDOWN:
		//m_CInput->SetKey((unsigned int)wparam);
		m_CEntity->ProcessKeyInput((unsigned int)wparam);
		//InvalidateRect(hwnd, NULL, FALSE);
		break;

	case WM_KEYUP:
		//m_CInput->KeyUp((unsigned int)wparam);
		//InvalidateRect(hwnd, NULL, FALSE);
		break;

	case WM_MOUSEMOVE:
		m_CEntity->ProcessMouseMove(LOWORD(lparam), HIWORD(lparam));
		InvalidateRect(hwnd, NULL, FALSE);
		break;

	case WM_LBUTTONDOWN:
		m_CEntity->ProcessMouseDown(LOWORD(lparam), HIWORD(lparam));
		InvalidateRect(hwnd, NULL, FALSE);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, umsg, wparam, lparam);
}

void CSystem::InitializeWindows(int& screenWidth, int& screenHeight)
{
	m_system = this;
	m_hInstance = GetModuleHandle(NULL);
	m_applicationName = L"MapleStory_JinHillah";

	WNDCLASSEX wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = m_hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm = wc.hIcon;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = m_applicationName;
	wc.cbSize = sizeof(WNDCLASSEX);

	RegisterClassEx(&wc);

	screenWidth = GetSystemMetrics(SM_CXSCREEN);
	screenHeight = GetSystemMetrics(SM_CYSCREEN);

	int posX = 0;
	int posY = 0;

	if (FULL_SCREEN)
	{
		DEVMODE dmScreenSettings;
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);
		dmScreenSettings.dmPelsWidth = (unsigned long)screenWidth;
		dmScreenSettings.dmPelsHeight = (unsigned long)screenHeight;
		dmScreenSettings.dmBitsPerPel = 32;
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN);
	}
	else
	{
		screenWidth = 1366;
		screenHeight = 768;

		posX = (GetSystemMetrics(SM_CXSCREEN) - screenWidth) / 2;
		posY = (GetSystemMetrics(SM_CYSCREEN) - screenHeight) / 2;
	}

	DWORD style = WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
	m_hwnd = CreateWindowEx(WS_EX_APPWINDOW, m_applicationName, m_applicationName,
		style, posX, posY, screenWidth, screenHeight,
		NULL, NULL, m_hInstance, NULL);
}

void CSystem::ShowWindows()
{
	ShowWindow(m_hwnd, SW_SHOW);
	SetForegroundWindow(m_hwnd);
	SetFocus(m_hwnd);
}

void CSystem::ShutdownWindows()
{
	if (FULL_SCREEN)
	{
		ChangeDisplaySettings(NULL, 0);
	}

	DestroyWindow(m_hwnd);
	m_hwnd = NULL;

	UnregisterClass(m_applicationName, m_hInstance);
	m_hInstance = NULL;

	m_system = NULL;
}

/////윈도우 메시지///////////////////////////////////////////////////////////////////////////////////////////
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}

	case WM_CLOSE:
	{
		PostQuitMessage(0);
		return 0;
	}

	default:
	{
		return m_system->MessageHandler(hwnd, iMessage, wParam, lParam);
	}
	}
}
