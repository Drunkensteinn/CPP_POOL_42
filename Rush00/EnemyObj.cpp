/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyObj.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:39:52 by ablizniu          #+#    #+#             */
/*   Updated: 2018/10/08 17:26:10 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EnemyObj.hpp"

EnemyObj::EnemyObj()
{
	//srand(time(0));
	this->EnemyObj_figure = '#';
	this->EnemyObj_x = (GameRush::size_x - 5);
	this->EnemyObj_y = std::rand() % (GameRush::size_y - 1);

//	printf("111 %d\n", this->EnemyObj_y);
}

EnemyObj::~EnemyObj()
{}


EnemyObj::EnemyObj(EnemyObj const &copy)
{
	*this = copy;
}

EnemyObj &EnemyObj::operator=(EnemyObj const &member)
{
	EnemyObj_x = member.EnemyObj_x;
	EnemyObj_y = member.EnemyObj_y;
	return (*this);
}


int EnemyObj::get_EnemyObj_x(void)
{
	return this->EnemyObj_x;
}

int EnemyObj::get_EnemyObj_y(void)
{
	return this->EnemyObj_y;
}

void EnemyObj::move()
{
	this->EnemyObj_x = this->EnemyObj_x - 1;
}

char EnemyObj::get_figure(void)
{
	return (this->EnemyObj_figure);
}


//void EnemyObj::write_the_EnemyObj()
//{
//	int x = get_EnemyObj_x() - 1;
//	int y = get_EnemyObj_y();
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 2; j++)
//			mvprintw(y + i, x + j , &get_figure()[i][j]);
//	}
////	set_Enemy_x(x);
////	set_Enemy_y(y);
//
//}

//void Enemy::move_Enemy()
//{
//	enemy1 = new Enemy(get_size_x(), get_size_y());
//	enemy1->set_Enemy_x(get_size_x() - 5);
//	enemy1->set_Enemy_y(rand()%(get_size_y()));
//	enemy1->write_the_Enemy();
////	while (enemy1->get_Enemy_x() > 0)
////	{
//		enemy1->write_the_Enemy();
//		set_Enemy_x(get_Enemy_x() - 1);
//		clear();
//		refresh();
//	}