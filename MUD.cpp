#include <cstdio>

#include "Game.h"
#include "PlayerStatBox_t.h"
#include "rlutil.h"




using namespace rlutil;



int main(int argc, char** argv)
{


	PlayerStatBox_t* misa = new PlayerStatBox_t(1, "Misa", 0, 0, 10, 8);
	PlayerStatBox_t* abadol = new PlayerStatBox_t(1, "Abadol", 0, 0, 10, 8);



	Game_t game(misa, abadol);

	game.draw();

	while (true)
	{

		int fase=0;

		if (getkey() == ENTER && (fase == 0))
		{
			int randomWinner = rand() % 2;

			if (randomWinner == 1)
			{

				locate(53, 15);
				printf("----->");
				fase = 1;

			}
			else if (randomWinner == 2)
			{
				locate(53, 15);
				printf("<-----");
				fase = 1;
			}
			
			if (getkey() == ENTER && (fase == 1))
			{
				cls();
				game.draw();
			}


		}

	}
	





	delete misa, abadol;

	char* d;
	scanf("%d", &d);
	
}

