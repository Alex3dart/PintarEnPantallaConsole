#pragma once

#include "PlayerStatBox_t.h"



#define ENTER printf("\xA")



struct Game_t
{

	Game_t(PlayerStatBox_t* player1, PlayerStatBox_t* player2);

	void draw();

private:
	enum EStatus
	{
		Presentation,
		Resolucion,
	};

	EStatus status;

	PlayerStatBox_t* m_player1;
	PlayerStatBox_t* m_player2;
};