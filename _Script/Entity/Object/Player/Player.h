#pragma once
#include "../../../stdafx.h"
#include "../../UI/InputKeyDefine.h"
class CPlayer
{
public:
	CPlayer();
	CPlayer(const CPlayer&);
	~CPlayer();

	void Initialize();
	void Release();

	void Update(bool _keyboardState[256]);
	void Render(HDC mem1dc, HDC mem2dc);

	int GetSlotKeyValue(int _key);
	void PlayAction(int _keyValue);
public:

private:

};

