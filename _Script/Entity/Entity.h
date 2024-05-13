#pragma once
#include "../Engine/Render.h"
#include "Object/ObjectManager.h"
#include "UI/UIManager.h"

class CEntity : public CRender
{
public:
	CEntity();
	CEntity(const CEntity&);
	~CEntity();

	void Initialize(int _screenWidth, int _screenHeight);
	void Release();

	void Update(bool _keyboardState[256]);
	void Render(HWND _hwnd, RECT _rect);

	void ProcessKeyInput(int _key);
private:

private:
	CObjectManager* m_CObjectManager;
	CUIManager* m_CUIManager;

	CKeyconfig* m_CKeyconfig;
	CFileRead* m_CFileRead;
};