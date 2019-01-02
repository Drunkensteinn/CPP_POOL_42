/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:23:58 by ablizniu          #+#    #+#             */
/*   Updated: 2018/10/09 12:33:38 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "GameRush.hpp"
#include "EnemyObj.hpp"
#include "Plane.hpp"

class Enemy
{
public:
	static EnemyObj *list;
	Enemy();
	Enemy(Enemy const &copy);
	~Enemy();

	Enemy &operator=(Enemy const &member);

	void	draw_enemy();
	void	checkPlayerLife(Plane const &member);
	void	check_enemy_and_bullets(Enemy const &member);
//	void 	checkPlayerLife(Plane const &member);
	void 	remove_enemy(EnemyObj **head ,EnemyObj *tmp);
	void	move_enemy();
	void	add_enemy();

};


#endif