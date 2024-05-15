#pragma once
#include "../stdafx.h"
#include "Input.h"
#include "../Entity/Entity.h"

// 자식 클래스에서 반드시 부모 클래스의 헤더 파일을 포함할 것 (전방 선언 불가)
// 자식이 부모 꺼를 사용할 수 있다.(상속성)
// 부모가 자식 꺼를 사용할 수 있다.(다형성)
//uml 기호

// 사람 <-> 학생 <-> 학생회 : Is-A
// #include : Has-A (다중 상속의 오류를 막기 위해)         
class CSystem /*상속할 부모는 public로 할 것 */
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
