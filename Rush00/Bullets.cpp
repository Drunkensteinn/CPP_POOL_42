/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullets.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:10:46 by ablizniu          #+#    #+#             */
/*   Updated: 2018/10/08 19:08:03 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullets.hpp"
#include "Enemy.hpp"
#include "BulletObj.hpp"
#include "GameRush.hpp"
#include "Plane.hpp"


BulletObj *Bullets::list = nullptr;

Bullets::Bullets(Bullets const &copy)
{
	*this = copy;
}

Bullets &Bullets::operator=(Bullets const &member)
{
	this->list = member.list;
	return (*this);
}

void Bullets::add_bullets()
{
	BulletObj *tmp;

	tmp = Bullets::list;
	if (tmp == NULL)
	{
		tmp = new BulletObj();
		tmp->next = NULL;
		Bullets::list = tmp;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new BulletObj();
		tmp->next->prev = tmp;
		tmp->next->next = nullptr;
	}

}

void Bullets::move_bullets()
{
	BulletObj *tmp;

	tmp = this->list;
	while (tmp)
	{
		tmp->move();
		tmp = tmp->next;
	}
}

Bullets::Bullets()
{


}


Bullets::~Bullets()
{

}



void Bullets::draw_bullets()
{
	BulletObj *tmp;

	tmp = this->list;
	while (tmp)
	{
		if (tmp->get_BulletObj_x() < GameRush::size_x + 1)
			mvwprintw(stdscr,tmp->get_BulletObj_y(),tmp->get_BulletObj_x() , "*");
		tmp = tmp->next;
	}
}

void Bullets::remove_(BulletObj *tmp)
{
	tmp->next->prev = tmp->prev;
	tmp->prev->next = tmp->next;
	delete(tmp);
}

