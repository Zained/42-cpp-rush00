/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 21:19:47 by fmorales          #+#    #+#             */
/*   Updated: 2015/12/11 06:00:03 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stuff.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "sys/time.h"
#include "Fire.hpp"
#include "Background.hpp"
#include "FireEnemy.hpp"


void ft_move_right_enemy(Enemy *b, int *direction, int level) {

	int i = 0;
	int difficulty = level * (ARMY / 10);
	while (i < difficulty)
		i++;
	i--;
	if (b[i].getPosY() + 7 > b[i].getMaxY() && *direction == 0) {
		i = 0;
		while (i < difficulty) {
			b[i].setPosX(b[i].getPosX() + 1);
			i++;
		}
		*direction = 1;
		return ;
	}
	i = 0;
	if (b[i].getPosY() - 5 <= 0 && *direction == 1) {
		i = 0;
		while (i < difficulty) {
			b[i].setPosX(b[i].getPosX() + 1);
			i++;
		}
		*direction = 0;
		return ;
	}
	i = 0;
	while(i < difficulty) {
		if (*direction == 1)
			b[i].setPosY(b[i].getPosY() - 2);
		else
			b[i].setPosY(b[i].getPosY() + 2);
		i++;
	}
}


void ft_display_enemy(Enemy *b, t_win *w, int difficulty) {
	int i = 0;
	while(i < difficulty) {
		if (b[i].getExist() == 1) {
				wattron(w->win, COLOR_PAIR(b[i].getColor()));
				mvwprintw(w->win, b[i].getPosX(), b[i].getPosY(), b[i].getName2().c_str());
				mvwprintw(w->win, b[i].getPosX() - 1, b[i].getPosY(), b[i].getName().c_str());
				wattroff(w->win, COLOR_PAIR(b[i].getColor()));
		}
		i++;
	}
	return ;
}

void ft_display_fire(Fire *x, t_win *w) {
	int i = 0;
	while (i < SCUD) {
		if (x[i].getExist() == 1) {
			wattron(w->win, COLOR_PAIR(4));
			mvwprintw(w->win, x[i].getPosX(), x[i].getPosY(), "|");
			wattroff(w->win, COLOR_PAIR(4));
		}
		i++;
	}
	return ;
}

void ft_display_fire_enemy(FireEnemy *p, t_win *w) {
	int i = 0;
	while (i < KRR) {
		if (p[i].getExist() == 1) {
			wattron(w->win, COLOR_PAIR(1));
			mvwprintw(w->win, p[i].getPosX(), p[i].getPosY(), "o");
			wattroff(w->win, COLOR_PAIR(1));
		}
		i++;
	}
	return ;
}

void ft_display_ship(t_win *w, int x_1, int y_1) {
	wattron(w->win, COLOR_PAIR(7));
	mvwprintw(w->win, x_1, y_1, "/.\\");
	mvwprintw(w->win, x_1 + 1, y_1 - 2, "//- -\\\\");
	mvwprintw(w->win, x_1 + 2, y_1 - 3, "|--| |--|");
	wattroff(w->win, COLOR_PAIR(7));
}

void ft_display_clear(t_win *w) {
	char tab[LINES * COLS + 1];

	tab[LINES * COLS] = 0;
	memset(tab, ' ', LINES * COLS);
	mvwprintw(w->win, 0, 0, "%s", tab);
}

void ft_display_planet(t_win *w,  int i) {

	wattron(w->win, COLOR_PAIR(3));
	mvwprintw(w->win, 0 + i, 5, "	                                             ___ ");
	mvwprintw(w->win, 1 + i, 5, "                                             ,o88888 ");
	mvwprintw(w->win, 2 + i, 5, "                                          ,o8888888\' ");
	mvwprintw(w->win, 3 + i, 5, "                    ,:o:o:oooo.        ,8O88Pd8888\" ");
	mvwprintw(w->win, 4 + i, 5, "                ,.::.::o:ooooOoOoO. ,oO8O8Pd888'\" ");
	mvwprintw(w->win, 5 + i, 5, "              ,.:.::o:ooOoOoOO8O8OOo.8OOPd8O8O\" ");
	mvwprintw(w->win, 6 + i, 5, "             , ..:.::o:ooOoOOOO8OOOOo.FdO8O8\" ");
	mvwprintw(w->win, 7 + i, 5, "            , ..:.::o:ooOoOO8O888O8O,COCOO\" ");
	mvwprintw(w->win, 8 + i, 5, "           , . ..:.::o:ooOoOOOO8OOOOCOCO\" ");
	mvwprintw(w->win, 9 + i, 5, "            . ..:.::o:ooOoOoOO8O8OCCCC\"o ");
	mvwprintw(w->win, 10 + i, 5, "               . ..:.::o:ooooOoCoCCC\"o:o ");
	mvwprintw(w->win, 11 + i, 5, "               . ..:.::o:o:,cooooCo\"oo:o: ");
	mvwprintw(w->win, 12 + i, 5, "            `   . . ..:.:cocoooo\"\'o:o:::\'");
	mvwprintw(w->win, 13 + i, 5, "            .`   . ..::ccccoc\"\'o:o:o:::\' ");
	mvwprintw(w->win, 14 + i, 5, "           :.:.    ,c:cccc\"\':.:.:.:.:.\' ");
	mvwprintw(w->win, 15 + i, 5, "         ..:.:\"\'`::::c:\"\'..:.:.:.:.:.\' ");
	mvwprintw(w->win, 16 + i, 5, "       ...:.\'.:.::::\"'    . . . . .\' ");
	mvwprintw(w->win, 17 + i, 5, "      .. . ....:.\"\' `   .  . . \'\' ");
	mvwprintw(w->win, 18 + i, 5, "    . . . ....\"\' ");
	mvwprintw(w->win, 19 + i, 5, "    .. . .\"\'");
	mvwprintw(w->win, 20 + i, 5, "  . ");
	wattroff(w->win, COLOR_PAIR(3));

	return;
}

void ft_init(int level, Enemy *b, Fire *x, FireEnemy *p, Enemy *e) {

(void)x;
(void)p;
	int next_line = 0;
	int half_line = 0;
	int random = 0;
	int	i = 0;
	int	y;
	int difficulty = level * (ARMY / 10);
	while (i < difficulty) {
		y = 0;
		if (y < WAVE && i < difficulty) {
			next_line++;
			if (next_line % 2 == 0)
				half_line = 5;
			else
				half_line = 0;
			while (y < WAVE && i < difficulty) {
				b[i].setPosX(15 - (next_line * 2));
				b[i].setPosY(10 * (y + 1) - half_line);
				b[i].setMaxX(LINES - 3);
				b[i].setMaxY((COLS - 2) - half_line);
				random = std::rand() % 2;
				b[i].setExist(random);
				random = std::rand() % 3;
				b[i].setName(e[random].getName());
				b[i].setName2(e[random].getName2());
				b[i].setColor(e[random].getColor());
				i++;
				y++;
			}
		}
	}
	i = 0;
	while (i < SCUD) {
		x[i].setExist(0);
		i++;
	}
	while (i < KRR) {
		p[i].setExist(0);
		i++;
	}

}

int main()
{
	t_win w;

	int c;
	int g = 0;
	int direction = 0;
	int index = 0;
	int index_2 = 0;
	std::srand(std::time(NULL));
	initscr();
	start_color();
	init_color(COLOR_BLUE, 0, 0, 1000);
	init_color(COLOR_CYAN, 600, 0, 800);
	init_color(COLOR_RED, 800, 0, 0);
	init_color(COLOR_WHITE, 1000, 1000, 1000);
	init_color(COLOR_YELLOW, 250, 195, 145); //light brown color
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	curs_set(0);
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	// srand(NULL);
	Player a;
	int difficulty = 0;
	// Enemy b;
	int i = 0;
	// int wave = 5;
	// int y = 0;
	// int next_line = 0;
	// int half_line = 0;
	// if (a.getLevel() == 0)
	// 	ARMY = 5;

	Enemy b[ARMY];
	Fire x[SCUD];
	FireEnemy p[KRR];
	Background back(COLS, LINES);
	Enemy	e[3] = { Enemy("{@@}", "/''\\", 6), Enemy("dOOb", "^/\\^", 2), Enemy("/MM\\", "\\~~/", 4)};

	while (i < SCUD) {
		x[i].setExist(0);
		i++;
	}
	i = 0;
	while (i < KRR) {
		p[i].setExist(0);
		i++;
	}
	i = 0;

	ft_init(1, b, x, p, e);

	index = 0;
	w.win = subwin(stdscr, LINES * 0.9, COLS, LINES * 0.1, 0);
	w.score = subwin(stdscr, LINES * 0.1, COLS, 0, 0);
	wattron(w.win, COLOR_PAIR(4));
	wattron(w.score, COLOR_PAIR(4));
	box(w.win, ACS_VLINE, ACS_HLINE);
	box(w.score, ACS_VLINE, ACS_HLINE);
	wattroff(w.score, COLOR_PAIR(4));
	wattroff(w.win, COLOR_PAIR(4));
	a.setPosX(LINES - 10);
	a.setPosY(COLS / 2);
	a.setMaxX(LINES - 1);
	a.setMaxY(COLS - 3);
	a.setScore(0);
	a.setLife(3);
	a.setLevel(0);

	wattron(w.score, COLOR_PAIR(1));
	mvwprintw(w.score, 1, 5, "SCORE : ");
	std::string score_display = std::to_string(a.getScore());
	mvwprintw(w.score, 1, 14, score_display.c_str());
	mvwprintw(w.score, 2, 5, "TIME : ");

	mvwprintw(w.score, 1, COLS - 15, "LIFE : ");
	std::string life_display = std::to_string(a.getLife());
	mvwprintw(w.score, 1, COLS - 8, life_display.c_str());
	mvwprintw(w.score, 2, COLS - 16, "LEVEL : ");
	wattroff(w.score, COLOR_PAIR(1));

	ft_display_ship(&w, a.getPosX(), a.getPosY());
	ft_display_enemy(b, &w, difficulty);
	// mvwprintw(w.win, a.getPosX(), a.getPosY(), "/.\\");
	// wrefresh(w.win);

	struct timeval t;
	struct timezone z;
	long int ut = t.tv_sec * 1000 + t.tv_usec / 1000;
	long int ut2 = t.tv_sec * 1000 + t.tv_usec / 1000;
	long int ut3 = t.tv_sec * 1000 + t.tv_usec / 1000;
	long int ut4 = t.tv_sec * 1000 + t.tv_usec / 1000;

	wattron(w.score, COLOR_PAIR(1));
	std::string time_display = std::to_string(ut);
	mvwprintw(w.win, 10, 10, time_display.c_str());
	// ut += 1000;
	std::string time2_display = std::to_string(ut);
	mvwprintw(w.win, 11, 10, time2_display.c_str());
	wattroff(w.score, COLOR_PAIR(1));
	wrefresh(w.win);
	// sleep(5);
	// int wave = 0;
	i = 10;
	int n_time = time(NULL);
	int m_time = time(NULL);
	time_t timer;
	time_t buf;
	time(&buf);
	time(&timer);
	int seconds = 0;
	while (1) {

		int y = 0;
		difficulty = (a.getLevel() + 1) * (ARMY / 10);
		while (y < SCUD) {
			i = 0;
			while (i < difficulty) {
				if (b[i].getPosY() == x[y].getPosY() && b[i].getPosX() == x[y].getPosX() && b[i].getExist() == 1 && x[y].getExist() == 1) {
					x[y].setExist(0);
					b[i].setExist(0);
					a.setScore(a.getScore() + 10); }
				else if (b[i].getPosY() - 1 == x[y].getPosY() && b[i].getPosX()  == x[y].getPosX() && b[i].getExist() == 1 && x[y].getExist() == 1) {
					x[y].setExist(0);
					b[i].setExist(0);
					a.setScore(a.getScore() + 10); }
				else if (b[i].getPosY() + 4 == x[y].getPosY() && b[i].getPosX() == x[y].getPosX() && b[i].getExist() == 1 && x[y].getExist() == 1) {
					x[y].setExist(0);
					b[i].setExist(0);
					a.setScore(a.getScore() + 10); }
				else if (b[i].getPosY() + 3 == x[y].getPosY() && b[i].getPosX() == x[y].getPosX() && b[i].getExist() == 1 && x[y].getExist() == 1) {
					x[y].setExist(0);
					b[i].setExist(0);
					a.setScore(a.getScore() + 10); }
				else if (b[i].getPosY() + 2 == x[y].getPosY() && b[i].getPosX() == x[y].getPosX() && b[i].getExist() == 1 && x[y].getExist() == 1) {
					x[y].setExist(0);
					b[i].setExist(0);
					a.setScore(a.getScore() + 10); }
				else if (b[i].getPosY() + 1 == x[y].getPosY() && b[i].getPosX() == x[y].getPosX() && b[i].getExist() == 1 && x[y].getExist() == 1) {
					x[y].setExist(0);
					b[i].setExist(0);
					a.setScore(a.getScore() + 10); }
				i++;
			}
			y++;
		}
		i = 0;
		while (i < KRR) {
			if (p[i].getPosY() == a.getPosY() && p[i].getPosX() == a.getPosX()) {
				if (m_time < time(NULL)) {
					a.setLife(a.getLife() - 1);
					p[i].setExist(0);
					m_time = time(NULL);
					m_time += 1;
				}
			}
			if (p[i].getPosY() == a.getPosY() + 1 && p[i].getPosX() == a.getPosX()) {
				if (m_time < time(NULL)) {
					a.setLife(a.getLife() - 1);
					p[i].setExist(0);
					m_time = time(NULL);
					m_time += 1;
				}
			}
			if (p[i].getPosY() == a.getPosY() + 2 && p[i].getPosX() == a.getPosX()) {
				if (m_time < time(NULL)) {
					a.setLife(a.getLife() - 1);
					p[i].setExist(0);
					m_time = time(NULL);
					m_time += 1;
				}
			}
			if (p[i].getPosY() == a.getPosY() - 1 && p[i].getPosX() == a.getPosX() + 1) {
				if (m_time < time(NULL)) {
					a.setLife(a.getLife() - 1);
					p[i].setExist(0);
					m_time = time(NULL);
					m_time += 1;
				}
			}
			if (p[i].getPosY() == a.getPosY() + 1 && p[i].getPosX() == a.getPosX() + 1) {
				if (m_time < time(NULL)) {
					a.setLife(a.getLife() - 1);
					p[i].setExist(0);
					m_time = time(NULL);
					m_time += 1;
				}
			}
			if (p[i].getPosY() == a.getPosY() + 2 && p[i].getPosX() == a.getPosX() + 1) {
				if (m_time < time(NULL)) {
					a.setLife(a.getLife() - 1);
					p[i].setExist(0);
					m_time = time(NULL);
					m_time += 1;
				}
			}
			if (p[i].getPosY() == a.getPosY() + 3 && p[i].getPosX() == a.getPosX() + 1) {
				if (m_time < time(NULL)) {
					a.setLife(a.getLife() - 1);
					p[i].setExist(0);
					m_time = time(NULL);
					m_time += 1;
				}
			}
			i++;
		}
		mvwprintw(w.score, 1, COLS - 8, "%d", a.getLife());
		mvwprintw(w.score, 2, COLS - 8, "%d", a.getLevel());
		time(&timer);
		seconds = difftime(timer, buf);
		mvwprintw(w.score, 2,  14, "%d", seconds);
		wrefresh(w.score);
		i = 0;
		int lose = 0;
		while (i < difficulty) {
			if (b[i].getPosY() == a.getPosY() && b[i].getPosX() == a.getPosX() && b[i].getExist() == 1) {
				a.setLife(0);
				lose = 1;
			}
			else if (b[i].getPosY() + 1 == a.getPosY() && b[i].getPosX() == a.getPosX() && b[i].getExist() == 1) {
				a.setLife(0);
				lose = 1;
			}
			else if (b[i].getPosY() + 2 == a.getPosY() && b[i].getPosX() == a.getPosX() && b[i].getExist() == 1) {
				a.setLife(0);
				lose = 1;
			}
			else if (b[i].getPosY() + 3 == a.getPosY() && b[i].getPosX() == a.getPosX() && b[i].getExist() == 1) {
				a.setLife(0);
				lose = 1;
			}
			else if (b[i].getPosY() + 4 == a.getPosY() && b[i].getPosX() == a.getPosX() && b[i].getExist() == 1) {
				a.setLife(0);
				lose = 1;
			}
			else if (b[i].getPosY() - 1 == a.getPosY() && b[i].getPosX()  == a.getPosX() && b[i].getExist() == 1) {
				a.setLife(0);
				lose = 1;
			}
			else if (b[i].getPosY() - 2 == a.getPosY() && b[i].getPosX()  == a.getPosX() && b[i].getExist() == 1) {
				a.setLife(0);
				lose = 1;
			}
			else if (b[i].getPosX()  == LINES - 5 && b[i].getExist() == 1) {
				lose = 1;
			}
			i++;
		}
		i = 0;
		if (a.getLife() == 0) {
			lose = 1;
		}
		if (lose == 1) {
			ft_display_clear(&w);
			wattron(w.win, COLOR_PAIR(1));
			mvwprintw(w.win, LINES / 3, COLS / 2 - 4, "GAME OVER");
			mvwprintw(w.win, LINES / 3 + 2, COLS / 2 - 8, "Try again? [y/n]");
			wattroff(w.win, COLOR_PAIR(1));
			wrefresh(w.win);
			while (1) {
				if ((c = getch()) != ERR) {
					if (c == 121) {
						mvwprintw(w.win, LINES / 3 + 5, COLS / 2 - 9, "Please insert credit");
						wrefresh(w.win);
					}
					if (c == 110 || c == 27) {
						endwin();
						std::exit(0);
					}
				}
			}
		}
		i = 0;
		while (i < difficulty) {
			if (b[i].getExist() == 1 && b[i].getPosY() == a.getPosY()) {
				if (n_time < time(NULL)) {
					p[index_2] = FireEnemy();
					p[index_2].setPosX(b[i].getPosX() + 1);
					p[index_2].setPosY(b[i].getPosY());
					p[index_2].setExist(1);
					n_time = time(NULL);
					// n_time += 2;
					index_2++;
				}
			}
			i++;
		}
		i = 0;
		int win_level = 1;

		while (i < difficulty)
		{
			if (b[i].getExist() == 1)
				win_level = 0;
			i++;
		}
		if (win_level == 1) {
			a.setLevel(a.getLevel() + 1);
			ft_display_clear(&w);
			mvwprintw(w.win, LINES / 3, COLS / 2 - 4, "WIN");
			mvwprintw(w.win, LINES / 3 + 2, COLS / 2 - 12, "Next Level? [y/n]");
			wrefresh(w.win);
			while (1) {
				if ((c = getch()) != ERR) {
					if (c == 121) {
						ft_init((a.getLevel() + 1), b, x, p, e);
						a.setPosX(LINES - 10);
						a.setPosY(COLS / 2);
						a.setMaxX(LINES - 1);
						a.setMaxY(COLS - 3);
						a.setLife(3);
						break ;
					}
					if (c == 110 || c == 27) {
						endwin();
						std::exit(0);
					}
				}
			}
		}
		gettimeofday(&t, &z);
		if (ut3 + 2000 < t.tv_sec * 1000 + t.tv_usec / 1000) {
			ut3 = t.tv_sec * 1000 + t.tv_usec / 1000;
			g++;
			if (g == 40)
				g = 0;
		}
		if (ut4 + 10 < t.tv_sec * 1000 + t.tv_usec / 1000) {
			ut4 = t.tv_sec * 1000 + t.tv_usec / 1000;
			// back.move();
			ft_display_clear(&w);
			// ft_display_planet(&w, g);
			ft_display_planet(&w, g);
			back.refresh();
			wattron(w.win, COLOR_PAIR(4));
			box(w.win, ACS_VLINE, ACS_HLINE);
			wattroff(w.win, COLOR_PAIR(4));
			ft_display_enemy(b, &w, difficulty);
			ft_display_fire(x, &w);
			ft_display_fire_enemy(p, &w);
			ft_display_ship(&w, a.getPosX(), a.getPosY());
			wrefresh(w.win);
		}
		if (ut + 400 - ((a.getLevel() + 1) * 100) < t.tv_sec * 1000 + t.tv_usec / 1000) {
			ut = t.tv_sec * 1000 + t.tv_usec / 1000;
			ft_move_right_enemy(b, &direction, a.getLevel() + 1);
			wattron(w.win, COLOR_PAIR(4));
			box(w.win, ACS_VLINE, ACS_HLINE);
			wattroff(w.win, COLOR_PAIR(4));
			ft_display_enemy(b, &w, difficulty);
			ft_display_fire(x, &w);
			ft_display_ship(&w, a.getPosX(), a.getPosY());
			// g++;
			std::string score_display = std::to_string(a.getScore());
			mvwprintw(w.score, 1, 14, score_display.c_str());
			wrefresh(w.score);
			wrefresh(w.win);
		}
		if (ut2 + 150 < t.tv_sec * 1000 + t.tv_usec / 1000) {
			ut2 = t.tv_sec * 1000 + t.tv_usec / 1000;
			i = 0;
			back.move();
			while (i < SCUD) {
				x[i].setPosX(x[i].getPosX() - 1);
				i++;
			}
			i = 0;
			while (i < KRR) {
					p[i].setPosX(p[i].getPosX() + 1);
				i++;
			}
			wattron(w.win, COLOR_PAIR(4));
			box(w.win, ACS_VLINE, ACS_HLINE);
			wattroff(w.win, COLOR_PAIR(4));
			ft_display_enemy(b, &w, difficulty);
			ft_display_fire(x, &w);
			ft_display_ship(&w, a.getPosX(), a.getPosY());
			wrefresh(w.win);
		}
		if ((c = getch()) != ERR) {
			if (c == 27) {
				endwin();
				std::exit(0);
			}
			if (c == KEY_LEFT) {
				if (a.getPosY() > 2)
					a.setPosY(a.getPosY() - 3);
			}
			if (c == KEY_RIGHT) {
				if (a.getPosY() < a.getMaxY())
					a.setPosY(a.getPosY() + 3);
			}
			if (c == KEY_UP) {
				if (a.getPosX() - 5 > 0)
					a.setPosX(a.getPosX() - 2);
			}
			if (c == KEY_DOWN) {
				if (a.getPosX() + 5 < a.getMaxX())
					a.setPosX(a.getPosX() + 2);
			}
			if (c == 32) {
				if (index == 199)
					index = 0;
				x[index] = Fire();
				x[index].setPosX(a.getPosX() - 1);
				x[index].setPosY(a.getPosY() + 1);
				x[index].setExist(1);
				index++;
			}
			if (c == 78) {
				index = 0;
				int lines = LINES - 5;
				int cols = COLS;
				while (index < 200 && lines > 0 && cols > 0){
					mvwprintw(w.score, 2, COLS / 2 - 7, "ATTAQUE NANA !");
					wrefresh(w.score);
					x[index] = Fire();
					x[index].setPosX(lines);
					x[index].setPosY(cols);
					x[index].setExist(1);
					cols--;
					index++;
					if (index == 199)
						index = 0;
				}
			}
			wrefresh(w.win);
			c = 0;
		}
	}
	return 0;
}
