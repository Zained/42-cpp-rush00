/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Background.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 21:16:35 by fmorales          #+#    #+#             */
/*   Updated: 2015/12/11 06:00:07 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKGROUND_HPP
# define BACKGROUND_HPP
#include <iostream>
#include <curses.h>
#include "stuff.hpp"

class Background
{
public:
    Background(int x_max, int y_max);
    ~Background(void);
    void    move(void);
    void    refresh(void);

private:
    int                *tabx;
    int                *taby;
    int                xmax;
    int                ymax;
	Background( void );
	Background  & operator=( Background const & rhs );
    Background( Background const & src );
};
#endif
