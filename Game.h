#pragma once

#include "PlayerStatBox_t.h"



#define ENTER printf("\xA")



struct Game_t
{

private:
	enum EarrowStatus
	{
		Left,
		Right,
		Vacia
	};
public:		

	Game_t();


	void init();

private:
	void generateCharacter();
	void draw();
	void setArrow(EarrowStatus status);

private:
	enum EStatus
	{
		Presentation,
		Resolucion,
	};
	
	EStatus m_status;
	EarrowStatus m_arrowStatus;
	PlayerStatBox_t m_player1;
	PlayerStatBox_t m_player2;
};