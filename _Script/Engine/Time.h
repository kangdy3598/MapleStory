#pragma once

class CTime
{
public:
	CTime();
	CTime(const CTime&);
	~CTime();

	void Initialize();
	void Release();
	void Update();

	float GetTime();

private:
	INT64 m_frequency = 0;
	float m_ticksPerMS = 0;
	INT64 m_startTime = 0;
	float m_frameTime = 0;
};