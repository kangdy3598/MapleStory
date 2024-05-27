#pragma once
#include "../../stdafx.h"
#include "../../Engine/Input.h"
//#include "../Object/ObjectManager.h"

class CObjectManager;
class CStateManager
{
public:

	CObjectManager* ob = nullptr;
	
	virtual ~CStateManager() {}

	virtual void Enter() = 0;

	virtual void Update(float _fTickTime) = 0;

	virtual void Exit() = 0;

	virtual void PlayAction(int _key) {}

};