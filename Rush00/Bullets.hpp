/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullets.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:10:15 by ablizniu          #+#    #+#             */
/*   Updated: 2018/10/08 19:06:20 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLETS_HPP
#define BULLETS_HPP

#include "BulletObj.hpp"
#include "Enemy.hpp"
#include "BulletObj.hpp"
#include "EnemyObj.hpp"
#include "Plane.hpp"

class Bullets
{
public:
	static BulletObj *list;
	Bullets();
	Bullets(Bullets const &copy);
	~Bullets();

	Bullets &operator=(Bullets const &member);

	void	draw_bullets();
	void 	move_bullets();
	static void	remove_(BulletObj *tmp);
	void	add_bullets();

};

#endif
