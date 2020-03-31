#include "Game.h"
#include "rlutil.h"
#include "PlayerStatBox_t.h"
#include <ctime>
#include <cstdlib>


using namespace rlutil;

Game_t::Game_t() : m_arrowStatus(EarrowStatus(Vacia)), m_status(EStatus(Presentation)), m_player1(1,40,10,8,8), m_player2(1,40,10,8,8)
	
{
	srand(time(NULL));

	saveDefaultColor();

}



void Game_t::init()
{
	int i = 0;


	while (true)
	{

		switch (m_status)
		{
			case EStatus::Presentation:
				setArrow(EarrowStatus::Vacia);
				generateCharacter();
				m_status = EStatus::Resolucion;
				break;
			case EStatus::Resolucion:
				m_status = EStatus::Presentation;
				if(rand() % 10 > 5)
				{
					//PLayer1 
					setArrow(EarrowStatus::Left);
				}

				else
				{
					setArrow(EarrowStatus::Right);
					//Player2 Won
				}
				break;
			default:
				break;
		}
		cls();
		draw();

		i= getkey();
	}
}
void Game_t ::setArrow(EarrowStatus status)
{

	m_arrowStatus = status;

}

void Game_t::generateCharacter()
{

	m_player1.generateName();
	m_player1.generateStats();

	m_player2.generateName();
	m_player2.generateStats();

}
void Game_t::draw()
{

	m_player1.draw(40,10);
	m_player2.draw(60, 10);

	if(m_arrowStatus!=Vacia)
	{
		locate(52, 14);

		for(int i=0;i<5;i++)
		{
			printf("-");
		}

		if(m_arrowStatus==EarrowStatus::Left)
		{
			locate(51, 14);
			printf("<");
		}
		else
		{
			locate(56, 14);
			printf(">");
		}
	}

}
