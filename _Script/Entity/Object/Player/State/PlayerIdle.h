#pragma once
#include "../../StateManager.h"

class PlayerIdle : public CStateManager
{
public:
    //CObjectManager* p = nullptr;
    
    static PlayerIdle* Instance()
    {
        static PlayerIdle* instance = new PlayerIdle();
        return instance;
    }
    virtual void Enter();
    virtual void Update();
    virtual void Exit();
};