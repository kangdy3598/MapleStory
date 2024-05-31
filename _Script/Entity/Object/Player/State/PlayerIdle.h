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
    virtual void Update(float _fTickTime);
    virtual void Exit();

    void PlayAction(int _key) override;

    void Deceleration_X();
};