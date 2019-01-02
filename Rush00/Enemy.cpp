/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:24:11 by ablizniu          #+#    #+#             */
/*   Updated: 2018/10/09 13:17:43 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "EnemyObj.hpp"
#include "BulletObj.hpp"
#include "Bullets.hpp"

FILE *f;

EnemyObj *Enemy::list = nullptr;

Enemy::Enemy(Enemy const &copy)
{
	*this = copy;
}

Enemy &Enemy::operator=(Enemy const &member)
{
	this->list = member.list;
	return (*this);
}

void Enemy::add_enemy()
{
	EnemyObj *tmp;

	tmp = Enemy::list;
	if (tmp == NULL)
	{
		tmp = new EnemyObj();
		tmp->next = NULL;
		Enemy::list = tmp;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new EnemyObj();
		tmp->next->prev = tmp;
		tmp->next->next = nullptr;
	}

}

void Enemy::move_enemy()
{
	EnemyObj *tmp;

	tmp =  Enemy::list;
	while (tmp)
	{
		tmp->move();
		tmp = tmp->next;
	}
}

Enemy::Enemy()
{

}


Enemy::~Enemy()
{
}

void Enemy::checkPlayerLife(Plane const &member)
{
	EnemyObj *tmp;

	tmp =  Enemy::list;
	while (tmp)
	{
		if (tmp->get_EnemyObj_x() == member.plane_x && tmp->get_EnemyObj_y() == member.plane_y + 1)
		{
			clear();
			endwin();
			std::cout << "you lost" << std::endl;
			exit(0);
		}
		tmp = tmp->next;
	}
}


void Enemy::draw_enemy()
{
	EnemyObj *tmp;

	tmp =  Enemy::list;
	while (tmp)
	{
		if (tmp->get_EnemyObj_y() >= 1)
			mvwprintw(stdscr,tmp->get_EnemyObj_y(),tmp->get_EnemyObj_x() , "#");
//		else if (tmp->get_EnemyObj_x() <= 0)
//			remove_enemy(&Enemy::list,tmp);
		tmp = tmp->next;
	}
}

void Enemy::remove_enemy(EnemyObj **head, EnemyObj *tmp)
{
	EnemyObj *temp;
//	EnemyObj *next_after;
//	EnemyObj *buff;
//	EnemyObj *buff_prev;
//
//	if ((*head)->get_EnemyObj_x() == tmp->get_EnemyObj_x() && (*head)->get_EnemyObj_y() == tmp->get_EnemyObj_y())
//	{
//		while ((*head) == tmp)
//		{
//			temp = (*head);
//			(*head) = (*head)->next;
//			(*head)->prev = NULL;
//			delete temp;
//		}
//	}
//	next_after = (*head);
//	next_after = next_after->next;
//	next_after->prev = (*head);
//	while (next_after)
//	{
//		if (next_after->get_EnemyObj_x() == tmp->get_EnemyObj_x() && next_after->get_EnemyObj_y() == tmp->get_EnemyObj_y())
//		{
//			buff = next_after;
//			buff_prev = next_after->prev;
//			next_after = next_after->next;
//			next_after->prev = buff_prev;
//			delete(buff);
//		}
//		next_after = next_after->next;
//	}

	temp = (*head);

	while (temp)
	{
		if (temp->get_EnemyObj_x() == tmp->get_EnemyObj_x() && temp->get_EnemyObj_y() == tmp->get_EnemyObj_y())
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete(tmp);
		}
		temp = temp->next;
	}

}

		//	EnemyObj *next_after_head;
//	EnemyObj *head_of_list;
//
//	while (next_after->get_EnemyObj_x() == tmp->get_EnemyObj_x() && (*head)->get_EnemyObj_y() == tmp->get_EnemyObj_y())
//	{
//		head_of_list = (*head);
//		(*head) = (*head)->next;
//		delete(head_of_list);
//	}
//	head_of_list = (*head)->next;
//	while (head_of_list && head_of_list->next)
//	{
//		if ((head_of_list)->get_EnemyObj_x() == tmp->get_EnemyObj_x() && (head_of_list)->get_EnemyObj_y() == tmp->get_EnemyObj_y())
//		{
//			next_after_head = head_of_list;
//			head_of_list = head_of_list->next;
//			delete(next_after_head);
//		}
//		next_after_head = NULL;
//		if (head_of_list->next)
//			head_of_list = head_of_list->next;
//	}

void Enemy::check_enemy_and_bullets(Enemy const &member)
{
	BulletObj *tmp;
	EnemyObj *tmp1;
	int zglyshka;



	f = fopen("log.txt","w");
	zglyshka = 0;
	if (!member.list)
		return;
	tmp =  Bullets::list;
	while (tmp != NULL)
	{
		tmp1 = member.list;
		while(tmp1 != NULL)
		{
			if (tmp->get_BulletObj_y() == tmp1->get_EnemyObj_y() && tmp->get_BulletObj_x() == tmp1->get_EnemyObj_x())
			{
				Enemy::remove_enemy(&member.list, tmp1);
				break;

			}
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}

}
