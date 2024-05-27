#include "../stdafx.h"
#include "Time.h"

CTime::CTime()
{
}

CTime::CTime(const CTime&)
{
}

CTime::~CTime()
{
}

void CTime::Initialize()
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&m_frequency);
	if (!m_frequency)
	{
		return;
	}

	m_ticksPerMS = (float)(m_frequency / 1000);
	QueryPerformanceCounter((LARGE_INTEGER*)&m_startTime);
}

void CTime::Release()
{
}

void CTime::Update()
{
	INT64 currentTime = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime);

	float timeDifference = (float)(currentTime - m_startTime);
	m_frameTime = timeDifference / m_ticksPerMS;

	m_startTime = currentTime;
}

float CTime::GetTime()
{
	return m_frameTime;
}