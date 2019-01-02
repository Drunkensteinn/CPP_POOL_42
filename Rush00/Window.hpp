/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:07:29 by ablizniu          #+#    #+#             */
/*   Updated: 2018/10/07 14:30:17 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WINDOW_CLASS_HPP
# define WINDOW_CLASS_HPP

#include <iostream>
#include "ncurses.h"

class Window
{
private:
	int MapX;
	int MapY;
public:
	Window(void);
	~Window(void);

	Window & operator = (Window const & rhs);

	Window(Window const & cpy);

	void set_MapX(int x);
	void set_MapY(int y);

	int get_MapX(void);
	int get_MapY(void);

	void initNcurses(void);
	void drawBorders(void);
	void initColors(void);
};

#endif
