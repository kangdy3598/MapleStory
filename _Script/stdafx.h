// 1. �ڽ� Ŭ�������� �ݵ�� �θ� Ŭ������ ��� ������ ������ �� (���� ���� �Ұ�)  

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
