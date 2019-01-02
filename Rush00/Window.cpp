/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:08:08 by ablizniu          #+#    #+#             */
/*   Updated: 2018/10/07 17:20:14 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.hpp"

Window::Window()
{
//	initNcurses();
//	initColors();
//	drawBorders();
}

Window::~Window() {
	nodelay(stdscr, FALSE);
	getch();
	endwin();
}

Window::Window(Window const & cpy)
{
	(void)cpy;
	return;
}

Window & Window::operator = (Window const & rhs)
{
	(void)rhs;
	return *this;
}

void Window::initNcurses()
{
	refresh();
	getmaxyx(stdscr,MapY,MapX);
}

void Window::initColors()
{
	start_color();
	init_pair(1, 8, COLOR_BLACK);
	init_pair(2, 8, 8);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	init_pair(4, 167, COLOR_BLACK);
	init_pair(5, 28, COLOR_BLACK);
	init_pair(6, 160, COLOR_BLACK);
	init_pair(10, COLOR_GREEN, COLOR_BLACK);
	init_pair(11, COLOR_BLACK, COLOR_GREEN);
	init_pair(12, COLOR_BLACK, COLOR_BLUE);
	init_pair(13, COLOR_BLACK, COLOR_RED);
	init_pair(14, COLOR_BLACK, COLOR_CYAN);
	init_pair(15, COLOR_BLACK, 8);
	init_pair(20, COLOR_BLUE, COLOR_BLACK);
	init_pair(30, COLOR_RED, COLOR_BLACK);
	init_pair(40, COLOR_CYAN, COLOR_BLACK);
}

void Window::drawBorders()
{
	unsigned int x;
	unsigned int y;
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
	set_MapX(MapX);
	set_MapY(MapY);
}

void Window::set_MapX(int x)
{
	this->MapX = x;
}

void Window::set_MapY(int y)
{
	this->MapY = y;
}

int Window::get_MapX(void)
{
	return (this->MapX);
}

int Window::get_MapY(void)
{
	return (this->MapY);
}

