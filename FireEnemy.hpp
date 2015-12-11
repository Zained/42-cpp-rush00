/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FireEnemy.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 21:18:25 by fmorales          #+#    #+#             */
/*   Updated: 2015/12/11 06:00:11 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIREENEMY_H
# define FIREENEMY_H
# include <iostream>
# include <iomanip>
# include <cstdlib>
# include "Fire.hpp"

class FireEnemy : public Fire {

protected:
	int posX;
	int posY;
	int maxX;
	int maxY;
	int exist;
	// int damage
	// int AP;
	// AWeapon* weapon;
	// Enemy* enemy;

public:
	FireEnemy(void);
	// FireEnemy(int x, int y);
	~FireEnemy(void);
	FireEnemy(FireEnemy const & src);
	FireEnemy & operator=(FireEnemy const & src);
	void setPosX(int x);
	void setPosY(int y);
	void setMaxX(int x);
	void setMaxY(int y);
	void setExist(int y);
	int getMaxX(void) const;
	int getMaxY(void) const;
	int getPosX(void) const;
	int getPosY(void) const;
	int getExist(void) const;
	// void attack(Enemy const & src);
	// void recoveryAP(void);
	// int getAP(void) const ;
	// void equip(AWeapon* weapon);
	// void attack(Enemy* enemy);
	// AWeapon* getWeapon(void) const;
};

#endif
