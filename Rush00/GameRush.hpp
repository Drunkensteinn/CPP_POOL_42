/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GameRush.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:00:25 by ablizniu          #+#    #+#             */
/*   Updated: 2018/10/07 22:11:19 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GAMERUSH_HPP
#define GAMERUSH_HPP

#include <unistd.h>
#include "Window.hpp"

#define KEY_Q  113


class GameRush
{
public:
	GameRush();
	GameRush(GameRush const &copy);
	virtual ~GameRush();

	static int size_y;
	static int size_x;

	void start();
	int get_size_x();
	int get_size_y();

	GameRush &operator=(GameRush const &member);

};


void draw_window(int MapX, int MapY);

#endif
