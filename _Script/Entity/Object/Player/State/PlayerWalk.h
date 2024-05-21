#pragma once
#include "../../StateManager.h"

class PlayerWalk : public CStateManager
{
public:
    //CObjectManager* p = nullptr;
    static PlayerWalk* Instance()
    {
        static PlayerWalk* instance = new PlayerWalk();
        return instance;
    }
    virtual void Enter();
    virtual void Update();
    virtual void Exit();
};