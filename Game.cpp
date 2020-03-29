#include "Game.h"
#include "rlutil.h"




Game_t::Game_t(PlayerStatBox_t* player1, PlayerStatBox_t* player2)
	: m_player1{ player1 }, m_player2{ player2 }
{

	rlutil::saveDefaultColor();

}


void Game_t::draw()
{

	m_player1->draw(40,10);
	m_player2->draw(60, 10);

}
