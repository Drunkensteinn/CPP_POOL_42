/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:57:11 by ablizniu          #+#    #+#             */
/*   Updated: 2018/10/07 20:14:58 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameRush.hpp"
#include "EnemyObj.hpp"

GameRush game;

WINDOW *stdscr;

int main()
{

	game.start();
	return 0;
}


void draw_window(int MapX, int MapY)
{
	int x;
	int y;
	clear();
	for (x = 0; x < MapX; x++)
	{
		y = MapY-1;
		mvprintw(y, x, "-");
		y = 0;
		mvprintw(y, x, "-");
	}
	for (y = 0; y < MapY; y++)
	{
		x = MapX - 1;
		mvprintw(y, x, "|");
		x = 0;
		mvprintw(y, x, "|");
	}
	refresh();
}


//std::cout << before << std::endl;
// Create add new Enemy

//h.move_Enemy();
//		ship.write_the_plane();
//
//
////		while (probezhatsta po enemy)
////		{
////			// Move all Enemy
////			// Proverka na vrezanie z player
////		}
//

