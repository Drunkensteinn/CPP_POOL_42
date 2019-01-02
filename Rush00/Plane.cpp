/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Plane.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:25:19 by ablizniu          #+#    #+#             */
/*   Updated: 2018/10/09 12:10:51 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zconf.h>
#include <sys/param.h>
#include "Plane.hpp"

int Plane::plane_x = 20;
int Plane::plane_y = GameRush::size_y / 2;

Plane::Plane()
{
	ship();
}

//Plane::Plane(int x, int y)
//{
//	ship();
//
//}

Plane::~Plane()
{
	int i = 0;
	while (i < 3)
	{
		delete(plane_figure[i]);
		i++;
	}
	delete(plane_figure);
}


Plane::Plane(Plane const &copy)
{
	*this = copy;
}

Plane &Plane::operator=(Plane const &member)
{
	plane_x = member.plane_x;
	plane_y = member.plane_y;
	return (*this);
}

void Plane::set_plain_x(int i)
{
	this->plane_x = i;
}
void Plane::set_plain_y(int i)
{
	this->plane_y = i;
}

int Plane::get_plane_x(void)const
{
	return this->plane_x;
}

int Plane::get_plane_y(void)const
{
	return this->plane_y;
}

char **Plane::get_figure() const
{
	return (this->plane_figure);
}

void Plane::set_figure(char **member)
{
	this->plane_figure = member;
}


void Plane::ship()
{
	char **ship = new char*[3];
	for (int i = 0; i < 3; i++)
		ship[i] = new char[2];
	ship[0][0] = '#';ship[0][1] = 0;
	ship[1][0] = '#';ship[2][0] = 0;
	ship[2][0] = '#';
	ship[1][1] = '#';
	set_figure(ship);
}

void Plane::write_the_plane()
{
	int x = get_plane_x();
	int y = get_plane_y();
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
			mvwprintw(stdscr,y + i, x + j , &get_figure()[i][j]);
	}
}

void		Plane::plane_up()
{
	if (this->plane_y > 1)
		this->plane_y--;

}
void		Plane::plane_down()
{
	if (this->plane_y < GameRush::size_y - 4)
		this->plane_y++;

}
void		Plane::plane_left()
{
	if (this->plane_x > 2)
		this->plane_x--;

}
void		Plane::plane_right()
{
	if (this->plane_x < GameRush::size_x - 4)
		this->plane_x++;

}