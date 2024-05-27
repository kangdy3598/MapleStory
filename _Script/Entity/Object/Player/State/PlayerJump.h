#pragma once
#include "../../StateManager.h"

class PlayerJump : public CStateManager
{
private:
    POINT m_PlayerPosition = POINT();

private:
    void MoveHorizon(int _dir);
public:
    //CObjectManager* p = nullptr;
    static PlayerJump* Instance()
    {
        static PlayerJump* instance = new PlayerJump();
        return instance;
    }
    virtual void Enter();
    virtual void Update(float _fTickTime);
    virtual void Exit();

    void PlayAction(int _key) override;

    void SetGravity(float _fTickTime);
};