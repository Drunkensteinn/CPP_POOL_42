/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyObj.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:39:10 by ablizniu          #+#    #+#             */
/*   Updated: 2018/10/07 21:25:24 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMYOBJ_HPP
#define ENEMYOBJ_HPP

#include "GameRush.hpp"

class EnemyObj
{
private:
	int EnemyObj_x;
	int EnemyObj_y;
	char EnemyObj_figure;
public:
	static EnemyObj *list;
	EnemyObj();
	EnemyObj(EnemyObj const &copy);
	virtual ~EnemyObj();

	EnemyObj &operator=(EnemyObj const &member);

	int 		get_EnemyObj_x(void);
	int 		get_EnemyObj_y(void);
	char		get_figure(void);

	void		move();


	EnemyObj	*prev;
	EnemyObj	*next;
};


#endif