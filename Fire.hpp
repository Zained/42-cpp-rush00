/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 21:17:52 by fmorales          #+#    #+#             */
/*   Updated: 2015/12/11 06:00:09 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRE_H
# define FIRE_H
# include <iostream>
# include <iomanip>
# include <cstdlib>

class Fire{

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
	Fire(void);
	Fire(int x, int y);
	~Fire(void);
	Fire(Fire const & src);
	Fire & operator=(Fire const & src);
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
