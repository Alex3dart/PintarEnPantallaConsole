#pragma once

struct PlayerStatBox_t {

	enum EStats { FUE, DES, CON, INT, SAB, CAR };
	


	PlayerStatBox_t(int color, int x, int y, int w, int h);

	void draw();


	void draw(int x, int y);


	void drawStat(EStats statIndex, int order);
	void drawBox();

	void generateStats();

	void generateName();

private:
	int m_x, m_y;
	int m_w, m_h;
	int m_color;

	char m_name[12];
	int m_stats[6];
};