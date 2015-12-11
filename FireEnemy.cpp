/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FireEnemy.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 21:18:13 by fmorales          #+#    #+#             */
/*   Updated: 2015/12/11 06:00:10 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FireEnemy.hpp"

FireEnemy::FireEnemy(void) { return ;}

FireEnemy::~FireEnemy(void) { return ;}

FireEnemy::FireEnemy(FireEnemy const & src) {
	*this = src;
	return ;
}

FireEnemy & FireEnemy::operator=(FireEnemy const & src) {
	this->posX = src.getPosX();
	return (*this);
}

void FireEnemy::setPosX(int x) {
	this->posX = x;
	return ;
}

void FireEnemy::setPosY(int y) {
	this->posY = y;
	return ;
}

void FireEnemy::setMaxX(int x) {
	this->maxX = x;
	return ;
}

void FireEnemy::setMaxY(int y) {
	this->maxY = y;
	return ;
}

void FireEnemy::setExist(int y) {
	this->exist = y;
	return ;
}

int FireEnemy::getPosX(void) const {
	return this->posX;
}

int FireEnemy::getPosY(void) const {
	return this->posY;
}

int FireEnemy::getMaxX(void) const {
	return this->maxX;
}

int FireEnemy::getMaxY(void) const {
	return this->maxY;
}

int FireEnemy::getExist(void) const {
	return this->exist;
}
