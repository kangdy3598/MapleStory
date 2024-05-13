#include "stdafx.h"
#include "Engine/System.h"

int APIENTRY wWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow)
{
	CSystem* System = new CSystem;
	if (!System)
		return -1;

	if (System->Initialize())
		System->Run();

	SAFE_DELETE(System);
	return 0;
}