#pragma once
#include "../stdafx.h"

struct SpriteInfo
{
	POINT spritePosition; // 실제 위치
	POINT intervalMainPos; // main position과 얼마만큼 떨어져 있는가
	POINT spriteFrame; // png파일에서 위치
	POINT spriteSize; // 이미지 너비/높이
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
