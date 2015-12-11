/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/08 21:17:02 by fmorales          #+#    #+#             */
/*   Updated: 2015/12/11 06:00:07 by mdriay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(void) : name("\\x|x/") { return ;}


Enemy::~Enemy(void) { return ;}

Enemy::Enemy(std::string const & name1, std::string const & name2, int color) : name(name1), name2(name2)
{
	this->color = color;
	return ;
}


Enemy & Enemy::operator=(Enemy const & src) {
	this->score = src.score;
	// this->type = src.type;
	return (*this);
}

void Enemy::setColor(int color) {
	this->color = color;
	return ;
}

void Enemy::setPosX(int x) {
	this->posX = x;
	return ;
}

void Enemy::setPosY(int y) {
	this->posY = y;
	return ;
}

void Enemy::setMaxX(int x) {
	this->maxX = x;
	return ;
}

void Enemy::setMaxY(int y) {
	this->maxY = y;
	return ;
}

void Enemy::setExist(int y) {
	this->exist = y;
	return ;
}

void Enemy::setName(std::string const & name) {
	this->name = name;
}

void Enemy::setName2(std::string const & name2) {
	this->name2 = name2;
}

std::string	Enemy::getName2(void) const {
	return this->name2;
}

int Enemy::getPosX(void) const {
	return this->posX;
}

int Enemy::getPosY(void) const {
	return this->posY;
}

int Enemy::getMaxX(void) const {
	return this->maxX;
}

int Enemy::getMaxY(void) const {
	return this->maxY;
}

int Enemy::getExist(void) const {
	return this->exist;
}

int Enemy::getColor(void) const {
	return this->color;
}

std::string Enemy::getName(void) const {
	return this->name;
}
