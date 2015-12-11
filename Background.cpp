/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Background.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 21:16:46 by fmorales          #+#    #+#             */
/*   Updated: 2015/12/11 06:00:06 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <curses.h>
#include "Background.hpp"
#include "stuff.hpp"

Background::Background(int x_max, int y_max)
{
	this->tabx = new int[30];
	this->taby = new int[30];
	int i;
	i = 0;
	while (i < 30)
	{
		this->tabx[i] = rand() % (x_max);
		this->taby[i] = rand() % (y_max);
		i++;
	}
	this->xmax = x_max;
	this->ymax = y_max;
};

Background::~Background( void ){
};

void    Background::move( void )
{
	for (int i = 0; i < 30; i++)
	{
		this->taby[i] = this->taby[i] + 1;
		if (this->taby[i] >= ymax)
			this->taby[i] = 0;
	}
}

void	Background::refresh(void) {

	attron(COLOR_PAIR(3));
	for (int i = 0; i < 30; i++)
	{
		if (this->taby[i] > (ymax/10) && this->taby[i] < (ymax - 3))
			mvprintw(this->taby[i], this->tabx[i], ".");
	}
	attroff(COLOR_PAIR(3));
}
