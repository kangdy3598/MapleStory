#pragma once
#include "../stdafx.h"

struct SpriteInfo
{
	POINT spritePosition; // ���� ��ġ
	POINT intervalMainPos; // main position�� �󸶸�ŭ ������ �ִ°�
	POINT spriteFrame; // png���Ͽ��� ��ġ
	POINT spriteSize; // �̹��� �ʺ�/����
};

class CRender // : public cameraclass
{
public:
	CRender();
	CRender(const CRender&);
	~CRender();

	void Initialize();
	void Release();

	void StartRender(HWND _hwnd, RECT _rect);
	void EndRender(HWND _hwnd);


private:


protected:
	int m_screenWidth = 0;
	int m_screenHeight = 0;

	HDC m_hdc = nullptr;
	PAINTSTRUCT m_ps = {};
	HDC mem1dc = 0, mem2dc = 0;
	HBITMAP hBit1 = 0, hBit2 = 0, oldBit1 = 0, oldBit2 = 0;
};
