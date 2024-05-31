#pragma once
#include "../../StateManager.h"

class PlayerWalk : public CStateManager
{
private:
    float m_minMoveSpeed = 1.75f;
    float m_maxMoveSpeed = 2.25f;
    POINT m_PlayerPosition = POINT();

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