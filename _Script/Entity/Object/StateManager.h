#pragma once
#include "../../stdafx.h"
//#include "../Object/ObjectManager.h"

class CObjectManager;
class CStateManager
{
public:

	CObjectManager* ob = nullptr;
	
	virtual ~CStateManager() {}

	virtual void Enter() = 0;

	virtual void Update() = 0;

	virtual void Exit() = 0;

};