/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam  <angonyam @42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 12:05:34 by omeyer            #+#    #+#             */
/*   Updated: 2018/06/10 17:27:08 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"

Bullet::Bullet(void)
{
	return;
}

Bullet::Bullet(WINDOW * win, Vector position, Vector velocity, char shape)
{
	this->curwin = win;
	this->position = position;
	this->velocity = velocity;
	this->shape = shape;
	this->isActive = true;
}

Bullet::Bullet(Bullet const & src)
{
	this->curwin = src.curwin;
	this->position = src.getPosition();
	this->velocity = src.getVelocity();
	this->shape = src.getShape();
}

Bullet & Bullet::operator=(Bullet const & rhs)
{
	this->curwin = rhs.curwin;
	this->position = rhs.getPosition();
	this->velocity = rhs.getVelocity();
	this->shape = rhs.getShape();
	this->isActive = rhs.isActive;

	return (*this);
}

Bullet::~Bullet(void)
{
	
	return;
}

void Bullet::setShape(char shape)
{
	this->shape = shape;
}

char Bullet::getShape(void) const
{
	return (this->shape);
}

void Bullet::setPostion(Vector position)
{
	this->position = position;
}

Vector Bullet::getPosition(void) const
{
	return (this->position);
}

void Bullet::setVelocity(Vector velocity)
{
	this->velocity = velocity;
}

Vector Bullet::getVelocity(void) const
{
	return (this->velocity);
}

Vector Bullet::movement(void)
{
	//this->position = this->position - this->velocity;
	this->position.setY(this->position.getY() - 1);
	return (this->position);
}

bool Bullet::getIsAcitve(void) const
{
	return this->isActive;
}

void Bullet::setIsAcitve(bool active)
{
	this->isActive = active;
}

void Bullet::display(void)
{
	mvwaddch(this->curwin, this->position.getY(), this->position.getX() + 3, ' ');
	mvwaddch(this->curwin, this->position.getY() - 1, this->position.getX() + 3, this->shape);
}

void Bullet::clear(void)
{
	mvwaddch(this->curwin, this->position.getY(), this->position.getX() + 3, ' ');
}