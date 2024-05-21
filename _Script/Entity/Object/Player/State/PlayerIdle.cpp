#pragma once
#include "../Player.h"
#include "PlayerIdle.h"

void PlayerIdle::Enter()
{
}

void PlayerIdle::Update()
{
	ob->ChangeState(PlayerWalk::Instance(), ob);
}

void PlayerIdle::Exit()
{
}