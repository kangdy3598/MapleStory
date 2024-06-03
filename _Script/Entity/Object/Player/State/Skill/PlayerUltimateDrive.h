#pragma once
#include "../../../StateManager.h"

class PlayerUltimateDrive : public CStateManager
{
public:
    //CObjectManager* p = nullptr;

    static PlayerUltimateDrive* Instance()
    {
        static PlayerUltimateDrive* instance = new PlayerUltimateDrive();
        return instance;
    }
    virtual void Enter();
    virtual void Update(float _fTickTime);
    virtual void Exit();

    void PlayAction(int _key) override;
};