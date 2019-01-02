/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameRush.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:00:37 by ablizniu          #+#    #+#             */
/*   Updated: 2018/10/09 12:09:45 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameRush.hpp"
#include "EnemyObj.hpp"
#include "Enemy.hpp"
#include "Bullets.hpp"
#include "Plane.hpp"

int GameRush::size_y = 0;
int GameRush::size_x = 0;

GameRush::GameRush()
{
}


GameRush::~GameRush()
{
}

GameRush::GameRush(GameRush const &copy)
{
	*this = copy;
}

GameRush &GameRush::operator=(GameRush const &member)
{
	this->size_y = member.size_y;
	return (*this);
}

void GameRush::start()
{
	const int clocksPerFrame = 100000 / 4 ;
	clock_t after, before;
	int h, w;
	int keycode;
	stdscr = initscr();
	keypad(stdscr, true);
	getmaxyx(stdscr, h, w);
	GameRush::size_x = w;
	GameRush::size_y = h;
	Plane player;
	Enemy p;
	Bullets b;
	player.set_plain_x(w/ 4 - 1);
	player.set_plain_y(h/ 2 - 1);

	refresh();

	noecho();
	curs_set(0);
	refresh();
	nodelay(stdscr, TRUE);
	refresh();
	while ((keycode = getch()) != KEY_Q)
	{
		before = clock();
		player.write_the_plane();
		if (rand()%GameRush::size_x < GameRush::size_x / 10)
			p.add_enemy();
		p.move_enemy();
		p.draw_enemy();
		b.move_bullets();
		b.draw_bullets();
		p.checkPlayerLife(player);
		p.check_enemy_and_bullets(p);
		switch (keycode)
		{
			case KEY_DOWN:
			{
				player.plane_down();
				break;
			}
			case 32:
			{
				b.add_bullets();
				break ;
			}
			case KEY_UP:
			{
				player.plane_up();
				break;
			}
			case KEY_LEFT:
			{
				player.plane_left();
				break;
			}
			case KEY_RIGHT:
			{
				player.plane_right();
				break;
			}
		}
		refresh();
		after = clock();
		if (after - before < clocksPerFrame)
			usleep(clocksPerFrame - after + before);
		draw_window(w,h);
	}
	clear();
	endwin();
}

int GameRush::get_size_x()
{
	return (this->size_x);
}
int GameRush::get_size_y()
{
	return (this->size_y);
}