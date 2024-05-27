#pragma once
//#include "../../../../stdafx.h"
#include "../Player.h"
#include "../../StateManager.h"


void PlayerWalk::Enter()
{
	ob->ChangeState(eStateList::WALK);
	m_PlayerPosition = ((CPlayer*)ob)->GetPosition();
}

void PlayerWalk::Update(float _fTickTime)
{
	if (CInput::GetInstance()->GetKey(VK_LEFT))
		MoveVertical(-1);

	if (CInput::GetInstance()->GetKey(VK_DOWN))
		MoveVertical(1);

	if(CInput::GetInstance()->GetKeyUp(VK_LEFT) ||
		CInput::GetInstance()->GetKeyUp(VK_RIGHT))
		ob->ChangeState(PlayerIdle::Instance(), ob);
}

void PlayerWalk::Exit()
{
}

void PlayerWalk::MoveVertical(int _dir)
{
	m_PlayerPosition.x += m_PlayerMoveSpeed.x * _dir;
	((CPlayer*)ob)->SetPosition(m_PlayerPosition);
}


void PlayerWalk::PlayAction(int _key)
{
	if (CInput::GetInstance()->GetKey(VK_LEFT))
		MoveVertical(-1);

	if (CInput::GetInstance()->GetKey(VK_DOWN))
		MoveVertical(1);

	/*if(CInput::GetInstance()->GetKeyUp(VK_LEFT) ||
		CInput::GetInstance()->GetKeyUp(VK_RIGHT))
		ob->ChangeState(PlayerIdle::Instance(), ob);*/
}