// 1. 자식 클래스에서 반드시 부모 클래스의 헤더 파일을 포함할 것 (전방 선언 불가)  

#pragma once

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

#include <stdint.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

#include <vector>

#include "pch.h"
#include "Entity/UI/InputKeyDefine.h"
#include "Entity/Object/Player/State/PlayerIdle.h"
#include "Entity/Object/Player/State/PlayerWalk.h"
#include "Entity/Object/Player/State/PlayerJump.h"
