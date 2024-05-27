#pragma once
#include "../../StateManager.h"

class PlayerWalk : public CStateManager
{
private:
    POINT m_PlayerMoveSpeed = POINT{ 5,1 };
    POINT m_PlayerPosition = POINT();
    bool m_down = false;
private:
    void MoveVertical(int _dir);
public:
    //CObjectManager* p = nullptr;
    static PlayerWalk* Instance()
    {
        static PlayerWalk* instance = new PlayerWalk();
        return instance;
    }
    virtual void Enter();
    virtual void Update(float _fTickTime);
    virtual void Exit();

    void PlayAction(int _key) override;
};