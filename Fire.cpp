/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fire.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 21:17:35 by fmorales          #+#    #+#             */
/*   Updated: 2015/12/11 06:00:09 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fire.hpp"
#include "Enemy.hpp"

Fire::Fire(void) { return ;}


Fire::Fire(int x, int y) : posX(x), posY(y), exist(0) { return ;}

// Fire::Fire(int hp, std::string const & type) : hp(hp), type(type) { return; }

Fire::~Fire(void) { return ;}

// Fire::Fire(Fire const & src) {
// 	*this = src;
// 	return ;
// }

Fire & Fire::operator=(Fire const & src) {
	this->posX = src.getPosX();
	// this->score = src.score;
	// this->type = src.type;
	return (*this);
}

void Fire::setPosX(int x) {
	this->posX = x;
	return ;
}

void Fire::setPosY(int y) {
	this->posY = y;
	return ;
}

void Fire::setMaxX(int x) {
	this->maxX = x;
	return ;
}

void Fire::setMaxY(int y) {
	this->maxY = y;
	return ;
}

void Fire::setExist(int y) {
	this->exist = y;
	return ;
}

int Fire::getPosX(void) const {
	return this->posX;
}

int Fire::getPosY(void) const {
	return this->posY;
}

int Fire::getMaxX(void) const {
	return this->maxX;
}

int Fire::getMaxY(void) const {
	return this->maxY;
}

int Fire::getExist(void) const {
	return this->exist;
}
