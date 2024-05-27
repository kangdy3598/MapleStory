#pragma once
//#include "../../../../stdafx.h"
#include "../Player.h"
#include "../../StateManager.h"


void PlayerJump::Enter()
{
	ob->ChangeState(eStateList::JUMP);

	m_PlayerPosition = ((CPlayer*)ob)->GetPosition();
}

void PlayerJump::Update(float _fTickTime)
{
	SetGravity(_fTickTime);
}

void PlayerJump::Exit()
{
}

void PlayerJump::MoveHorizon(int _dir)
{
	
}


void PlayerJump::PlayAction(int _key)
{
	
}

void PlayerJump::SetGravity(float _fTickTime)
{
	((CPlayer*)ob)->m_accelY += 0.35f;
	m_PlayerPosition.y += ((CPlayer*)ob)->m_accelY;
	((CPlayer*)ob)->SetPosition(m_PlayerPosition);

	if (m_PlayerPosition.y > 600)
	{
		m_PlayerPosition.y = 600;
		((CPlayer*)ob)->SetPosition(m_PlayerPosition);
		ob->ChangeState(PlayerIdle::Instance(), ob);
	}

	
		
}
