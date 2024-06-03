#pragma once
#include "../../Player.h"
#include "PlayerUltimateDrive.h"

void PlayerUltimateDrive::Enter()
{
	ob->ChangeState(eStateList::SKILL_ULTIMATE);
	((CPlayer*)ob)->GetSkillEffect()->SetActiveTogle(true);
}

void PlayerUltimateDrive::Update(float _fTickTime)
{
	
}

void PlayerUltimateDrive::Exit()
{
}

void PlayerUltimateDrive::PlayAction(int _key)
{
	if (_key == SLOT_ACTION_PICKUP)
	{
		ob->ChangeState(PlayerIdle::Instance(), ob);
		((CPlayer*)ob)->GetSkillEffect()->SetActiveTogle(false);
	}
}

