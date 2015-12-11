/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 21:19:18 by fmorales          #+#    #+#             */
/*   Updated: 2015/12/11 06:00:13 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include <iostream>
# include <iomanip>
# include <cstdlib>

class Player {

protected:
	std::string name;
	int posX;
	int posY;
	int maxX;
	int maxY;
	int score;
	int life;
	int level;
	// int AP;
	// AWeapon* weapon;
	// Enemy* enemy;

public:
	Player(void);
	Player(std::string const & name);
	~Player(void);
	Player(Player const & src);
	Player & operator=(Player const & src);
	std::string virtual getName(void) const;
	void setPosX(int x);
	void setPosY(int y);
	void setMaxX(int x);
	void setMaxY(int y);
	void setScore(int y);
	void setLife(int y);
	void setLevel(int y);
	int getMaxX(void) const;
	int getMaxY(void) const;
	int getPosX(void) const;
	int getPosY(void) const;
	int getScore(void) const;
	int getLife(void) const;
	int getLevel(void) const;
	void hit(void);
	// void recoveryAP(void);
	// int getAP(void) const ;
	// void equip(AWeapon* weapon);
	// void attack(Enemy* enemy);
	// AWeapon* getWeapon(void) const;
};

// std::ostream & operator<<(std::ostream & o, Player & src);

#endif
