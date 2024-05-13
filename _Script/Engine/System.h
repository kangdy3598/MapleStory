#pragma once
#include "../stdafx.h"
#include "Input.h"
#include "../Entity/Entity.h"

class CSystem
{
public:
	CSystem();
	CSystem(const CSystem&);
	~CSystem();

	bool Initialize();
	void Release();
	void Run();

	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);
private:
	bool Update();
	void InitializeWindows(int&, int&);
	void ShowWindows();
	void ShutdownWindows();

private:
	HINSTANCE m_hInstance = NULL;
	HWND m_hwnd = NULL;

	LPCWSTR m_applicationName = L"";
	BOOL FULL_SCREEN = FALSE;

	CInput* m_CInput;
	CEntity* m_CEntity;
};

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
static CSystem* m_system = nullptr;
