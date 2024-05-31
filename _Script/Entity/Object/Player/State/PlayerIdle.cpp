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
	/*if (CInput::GetInstance()->GetKeyDown(VK_LEFT) ||
		CInput::GetInstance()->GetKeyDown(VK_RIGHT))
		ob->ChangeState(PlayerWalk::Instance(), ob);*/

	if (CInput::GetInstance()->GetKeyState(VK_LEFT) == KeyState::KEY_PRESSED ||
		CInput::GetInstance()->GetKeyState(VK_RIGHT) == KeyState::KEY_PRESSED)
		ob->ChangeState(PlayerWalk::Instance(), ob);

	//if (CInput::GetInstance()->GetKeyDown(VK_UP))
	//{
	//	((CPlayer*)ob)->m_accelY = -8.5f;
	//	ob->ChangeState(PlayerJump::Instance(), ob);
	//}

	
	Deceleration_X();
}

void PlayerIdle::Exit()
{
}

void PlayerIdle::PlayAction(int _key)
{
	if (_key == SLOT_ACTION_JUMP)
	{
		((CPlayer*)ob)->m_accelY = -8.5f;
		ob->ChangeState(PlayerJump::Instance(), ob);
	}
	/*if(CInput::GetInstance()->GetKeyDown(VK_LEFT) ||
	   CInput::GetInstance()->GetKeyDown(VK_RIGHT))
		ob->ChangeState(PlayerWalk::Instance(), ob);*/

	/*if (CInput::GetInstance()->GetKeyDown(VK_UP))
	{
		((CPlayer*)ob)->m_accelY = -10;
		ob->ChangeState(PlayerJump::Instance(), ob);
	}*/
}

void PlayerIdle::Deceleration_X()
{
	if (((CPlayer*)ob)->m_accelX > 0.01f)
		((CPlayer*)ob)->m_accelX *= 0.9f;
	else

	{
		((CPlayer*)ob)->m_moveDir = 0;
		((CPlayer*)ob)->m_accelX = 0;
	}
}
