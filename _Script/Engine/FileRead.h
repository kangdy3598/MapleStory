#pragma once
#include "../stdafx.h"
#include "Render.h"
#include <string>

using namespace std;
class CFileRead
{
public:
	CFileRead();
	CFileRead(const CFileRead&);
	~CFileRead();

	void Initialize(LPCWSTR _FilePath);
	void Release();

	void SetSpriteInfo(SpriteInfo* sprInfo, std::string fileName);

private:
	void SetCursorByName(std::string findName);
	INT SetValue();

private:
	

	HANDLE _handle = 0;
	DWORD dwRead = 0;
	CHAR chBuffer = 0;
	BOOL bResult = 0;
	std::string str = "";

	std::string spriteInfoNameTag[6] = { "\"x\": " ,
										 "\"y\": " ,
										 "\"w\": " ,
										 "\"h\": " ,
									  	 "\"a\": " ,
										 "\"b\": " , };
};

