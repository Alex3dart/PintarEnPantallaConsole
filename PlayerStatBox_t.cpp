#include <cstdio>
#include <cstring>

#include "PlayerStatBox_t.h"
#include "rlutil.h"

using namespace rlutil;

const char* statNames[] = {
	"FUE", "DES", "CON", "INT", "SAB", "CAR"
};

#define NL printf("\n")

#define V printf("\xBA")
#define H printf("\xCD")
#define RT printf("\xBB")
#define RB printf("\xBC")
#define LT printf("\xC9")
#define LB printf("\xC8")




PlayerStatBox_t::PlayerStatBox_t(int color, const char* name, int x, int y, int w, int h)
	: m_x{ x }, m_y{ y }, m_w{ w }, m_h{ h }, m_color{ color }
{

	strcpy(&m_name[0], name);


}

void PlayerStatBox_t::draw()
{
	drawBox();

	setColor(RED);
	locate(m_x + 2, m_y +  1);

	const char* names[] = { "dragon", "troll", "guerrero", "mago" };

	int nombreAleatorio = rand() % 4;
	printf(names[nombreAleatorio]);



	for (int i = 0; i < 6; i++)
	{
		int statsRandom = rand() % 15;

		drawStat((EStats)i, statsRandom+3, i);

	}

}


void PlayerStatBox_t::draw(int x, int y)
{
	m_x = x;
	m_y = y;
	draw();


}

void PlayerStatBox_t::drawStat(EStats statIndex, int value, int order)
{
	locate(m_x + 2, m_y + order + 2);

	setColor(YELLOW);
	printf("%s: ", statNames[statIndex]);
	setColor(GREEN);
	printf("%d", value);

	resetColor();
}

void PlayerStatBox_t::drawBox()
{
	int x = m_x, y = m_y;

	setColor(m_color);
	locate(x, y);




	LT;
	for (int i = 0; i < m_w; i++) H;
	RT;
	locate(x, ++y);
	for (int i = 0; i < m_h; i++)
	{
		V;
		for (int j = 0; j < m_w; j++)
			printf(" ");
		V;
		locate(x, ++y);
	}
	LB;
	for (int i = 0; i < m_w; i++) H;
	RB;

	resetColor();

	
}