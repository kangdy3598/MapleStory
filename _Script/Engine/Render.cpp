#include "Render.h"

CRender::CRender()
{
}

CRender::CRender(const CRender&)
{
}

CRender::~CRender()
{
}

void CRender::Initialize()
{
}

void CRender::Release()
{
}

void CRender::StartRender(HWND _hwnd, RECT _rect)
{
	m_hdc = BeginPaint(_hwnd, &m_ps);
	mem1dc = CreateCompatibleDC(m_hdc);
	mem2dc = CreateCompatibleDC(mem1dc);

	if (hBit1 == NULL)
		hBit1 = CreateCompatibleBitmap(m_hdc, _rect.right, _rect.bottom);

	oldBit1 = (HBITMAP)SelectObject(mem1dc, hBit1);
	FillRect(mem1dc, &_rect, (HBRUSH)GetStockObject(WHITE_BRUSH));
}

void CRender::EndRender(HWND _hwnd)
{
	SelectObject(mem1dc, oldBit1);
	SelectObject(mem2dc, oldBit2);

	DeleteDC(mem2dc);
	DeleteDC(mem1dc);
	EndPaint(_hwnd, &m_ps);
}
