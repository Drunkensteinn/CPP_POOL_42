/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Plane.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:22:08 by ablizniu          #+#    #+#             */
/*   Updated: 2018/10/07 22:34:45 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_HPP
#define PLANE_HPP

#include <iostream>
#include "GameRush.hpp"

class Plane
{
private:
	char **plane_figure;
public:
	Plane();
	Plane(int x, int y);
	Plane(Plane const &copy);
	virtual ~Plane();

	Plane &operator=(Plane const &member);

	static int plane_x;
	static int plane_y;

	void		ship();
	void		write_the_plane();

	int get_plane_x(void)const;
	int get_plane_y(void)const;
	void set_plain_x(int);
	void set_plain_y(int);

	void		plane_up();
	void		plane_down();
	void		plane_left();
	void		plane_right();


	void		move_plane();
	char		**get_figure()const;

	void set_figure(char **);
};


#endif
