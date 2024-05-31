#pragma once
//#include "../../../../stdafx.h"
#include "../Player.h"
#include "../../StateManager.h"


void PlayerWalk::Enter()
{
	ob->ChangeState(eStateList::WALK);
	//m_PlayerPosition = ((CPlayer*)ob)->GetPosition();
	((CPlayer*)ob)->m_accelX = m_minMoveSpeed;
}

void PlayerWalk::Update(float _fTickTime)
{
	if (((CPlayer*)ob)->m_accelX < m_maxMoveSpeed)
	{
		((CPlayer*)ob)->m_accelX *= 1.01f;
	}

	else if (((CPlayer*)ob)->m_accelX > m_maxMoveSpeed - 0.0001f)
	{
		((CPlayer*)ob)->m_accelX = m_maxMoveSpeed;
	}
	//============================================

	/*if (CInput::GetInstance()->GetKey(VK_LEFT))
		((CPlayer*)ob)->m_moveDir = -1;

	else if (CInput::GetInstance()->GetKey(VK_RIGHT))
		((CPlayer*)ob)->m_moveDir = 1;*/

	if (CInput::GetInstance()->GetKeyState(VK_LEFT) == KeyState::KEY_PRESSED)
		((CPlayer*)ob)->m_moveDir = -1;

	if	(CInput::GetInstance()->GetKeyState(VK_RIGHT) == KeyState::KEY_PRESSED)
		((CPlayer*)ob)->m_moveDir = 1;

	/*if(CInput::GetInstance()->GetKeyUp(VK_LEFT) ||
	   CInput::GetInstance()->GetKeyUp(VK_RIGHT))
		ob->ChangeState(PlayerIdle::Instance(), ob);*/

	if (CInput::GetInstance()->GetKeyState(VK_LEFT) == KeyState::KEY_UP ||
		CInput::GetInstance()->GetKeyState(VK_RIGHT) == KeyState::KEY_UP)
		ob->ChangeState(PlayerIdle::Instance(), ob);

}

void PlayerWalk::Exit()
{
	
}

void PlayerWalk::MoveVertical(int _dir)
{
	/*m_PlayerPosition.x += ((CPlayer*)ob)->m_accelX * _dir;
	((CPlayer*)ob)->SetPosition(m_PlayerPosition);*/
}


void PlayerWalk::PlayAction(int _key)
{
	if (_key == SLOT_ACTION_JUMP)
	{
		((CPlayer*)ob)->m_accelY = -8.5f;
		ob->ChangeState(PlayerJump::Instance(), ob);
	}
}