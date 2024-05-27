#pragma once
#include "../Player.h"
#include "PlayerIdle.h"

void PlayerIdle::Enter()
{
	ob->ChangeState(eStateList::IDLE);

	((CPlayer*)ob)->m_accelY = 0;
}

void PlayerIdle::Update(float _fTickTime)
{
	if (CInput::GetInstance()->GetKeyDown(VK_LEFT) ||
		CInput::GetInstance()->GetKeyDown(VK_RIGHT))
		ob->ChangeState(PlayerWalk::Instance(), ob);

	if (CInput::GetInstance()->GetKeyDown(VK_UP))
	{
		((CPlayer*)ob)->m_accelY = -10;
		ob->ChangeState(PlayerJump::Instance(), ob);
	}
}

void PlayerIdle::Exit()
{
}

void PlayerIdle::PlayAction(int _key)
{
	if(CInput::GetInstance()->GetKeyDown(VK_LEFT) ||
	   CInput::GetInstance()->GetKeyDown(VK_RIGHT))
		ob->ChangeState(PlayerWalk::Instance(), ob);

	if (CInput::GetInstance()->GetKeyDown(VK_UP))
	{
		((CPlayer*)ob)->m_accelY = -10;
		ob->ChangeState(PlayerJump::Instance(), ob);
	}
}