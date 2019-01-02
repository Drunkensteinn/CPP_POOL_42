/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BulletObj.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 22:30:12 by ablizniu          #+#    #+#             */
/*   Updated: 2018/10/07 22:41:10 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BULLETOBJ_HPP
#define BULLETOBJ_HPP

#include "GameRush.hpp"

class BulletObj
{
private:
	int BulletObj_x;
	int BulletObj_y;
	char BulletObj_figure;
public:
	static BulletObj *list;
	BulletObj();
	BulletObj(BulletObj const &copy);
	virtual ~BulletObj();

	BulletObj &operator=(BulletObj const &member);

	int 		get_BulletObj_x(void);
	int 		get_BulletObj_y(void);

	char		get_figure(void);

	void		move();


	BulletObj	*prev;
	BulletObj	*next;
};

#endif