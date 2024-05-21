#include "FileRead.h"

CFileRead::CFileRead()
{
}

CFileRead::CFileRead(const CFileRead&)
{

}

CFileRead::~CFileRead()
{
}

void CFileRead::Initialize(LPCWSTR _FilePath)
{
	_handle = CreateFile(_FilePath, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
}

void CFileRead::Release()
{
	CloseHandle(_handle);
}

void CFileRead::SetSpriteInfo(SpriteInfo* sprInfo, std::string fileName)
{
	SetCursorByName(fileName);
	SetCursorByName("\"frame\":");

	SetCursorByName(spriteInfoNameTag[0]);
	sprInfo->spriteFrame.x = SetValue();
	
	SetCursorByName(spriteInfoNameTag[1]);
	sprInfo->spriteFrame.y = SetValue();

	SetCursorByName(spriteInfoNameTag[2]);
	sprInfo->spriteSize.x = SetValue();

	SetCursorByName(spriteInfoNameTag[3]);
	sprInfo->spriteSize.y = SetValue();

	SetCursorByName(spriteInfoNameTag[4]);
	sprInfo->intervalMainPos.x = SetValue();

	SetCursorByName(spriteInfoNameTag[5]);
	sprInfo->intervalMainPos.y = SetValue();
}

void CFileRead::SetCursorByName(std::string findName)
{
	// findName 마지막 문자 다음에 커서가 간다.
	size_t size = findName.size();
	str = "";
	// 파일에서 한 글자씩 읽어오기
	while (true)
	{
		if (str == findName)
			break;

		bResult = ReadFile(_handle, &chBuffer, 1, &dwRead, NULL);
		if (!bResult || dwRead == 0)
			break;

		if (chBuffer == '\0' || chBuffer == '\r' ||
			chBuffer == '\t' || chBuffer == '\n')
			continue;

		str += chBuffer;
		if (str.size() > size)
		{
			str = str.substr(1, str.size() - 1);
		}
	}
}

INT CFileRead::SetValue()
{
	str = "";
	while (true)
	{
		bResult = ReadFile(_handle, &chBuffer, 1, &dwRead, NULL);
		if (!bResult || dwRead == 0)
			break;

		if (chBuffer == ',')
			break;

		str += chBuffer;
	}
	if (str.size() > 0)
		return std::stoi(str);

	else
		return -1;
}

