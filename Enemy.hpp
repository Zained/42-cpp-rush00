/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 21:17:14 by fmorales          #+#    #+#             */
/*   Updated: 2015/12/11 06:00:08 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H
# include <iostream>
# include <iomanip>
# include <cstdlib>

class Enemy {

protected:
	std::string name;
	std::string name2;
	int posX;
	int posY;
	int maxX;
	int maxY;
	int score;
	int life;
	int exist;
	int color;
	// int AP;
	// AWeapon* weapon;
	// Enemy* enemy;

public:
	Enemy(void);
	// Enemy(std::string const & name);
	~Enemy(void);
	Enemy(Enemy const & src);
	Enemy(std::string const & name1, std::string const & name2, int color);
	Enemy & operator=(Enemy const & src);
	void setPosX(int x);
	void setPosY(int y);
	void setMaxX(int x);
	void setMaxY(int y);
	void setExist(int y);
	void setColor(int color);
	void setName(std::string const & name);
	void setName2(std::string const & name2);
	int getMaxX(void) const;
	int getMaxY(void) const;
	int getPosX(void) const;
	int getPosY(void) const;
	int getExist(void) const;
	int getColor(void) const;
	// void attack(Player const & src);
	std::string getName(void) const;
	std::string	getName2(void) const;
};

#endif
