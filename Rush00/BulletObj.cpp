/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BulletObj.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 22:30:36 by ablizniu          #+#    #+#             */
/*   Updated: 2018/10/07 23:01:38 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GameRush.hpp"
#include "BulletObj.hpp"
#include "Plane.hpp"


BulletObj::BulletObj()
{
	this->BulletObj_figure = '#';
	this->BulletObj_x = Plane::plane_x + 2;
	this->BulletObj_y = Plane::plane_y + 1;
}

BulletObj::~BulletObj()
{}


BulletObj::BulletObj(BulletObj const &copy)
{
	*this = copy;
}

BulletObj &BulletObj::operator=(BulletObj const &member)
{
	BulletObj_x = member.BulletObj_x;
	BulletObj_y = member.BulletObj_y;
	return (*this);
}


int BulletObj::get_BulletObj_x(void)
{
	return this->BulletObj_x;
}

int BulletObj::get_BulletObj_y(void)
{
	return this->BulletObj_y;
}

void BulletObj::move()
{
	this->BulletObj_x = this->BulletObj_x + 1;
}

char BulletObj::get_figure(void)
{
	return (this->BulletObj_figure);
}


//void BulletObj::write_the_BulletObj()
//{
//	int x = get_BulletObj_x() - 1;
//	int y = get_BulletObj_y();
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 2; j++)
//			mvprintw(y + i, x + j , &get_figure()[i][j]);
//	}
////	set_Bullet_x(x);
////	set_Bullet_y(y);
//
//}

//void Bullet::move_Bullet()
//{
//	enemy1 = new Bullet(get_size_x(), get_size_y());
//	enemy1->set_Bullet_x(get_size_x() - 5);
//	enemy1->set_Bullet_y(rand()%(get_size_y()));
//	enemy1->write_the_Bullet();
////	while (enemy1->get_Bullet_x() > 0)
////	{
//		enemy1->write_the_Bullet();
//		set_Bullet_x(get_Bullet_x() - 1);
//		clear();
//		refresh();
//	}