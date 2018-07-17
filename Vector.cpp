/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam  <angonyam @42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:53:25 by omeyer            #+#    #+#             */
/*   Updated: 2018/06/10 09:36:31 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"

Vector::Vector(void)
{
	this->x = 0;
	this->y = 0;
}

Vector::Vector(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vector::Vector(Vector const & src)
{
	this->x = src.getX();
	this->y = src.getY();
}

Vector & Vector::operator=(Vector const & rhs)
{
	this->x = rhs.x;
	this->y = rhs.y;

	return (*this);
}

Vector & Vector::operator+(Vector const & rhs)
{
	this->x = this->x + rhs.x;
	this->y = this->y + rhs.y;

	return (*this);
}

Vector & Vector::operator-(Vector const & rhs)
{
	this->x = this->x - rhs.x;
	this->y = this->y - rhs.y;

	return (*this);
}

Vector::~Vector(void)
{
	return;
}

void Vector::setX(int x)
{
	this->x = x;
}

int Vector::getX(void) const
{
	return (this->x);
}

void Vector::setY(int y)
{
	this->y = y;
}

int Vector::getY(void) const
{
	return (this->y);
}

Vector addition(Vector a, Vector b)
{
	Vector sum;
	sum.setX(a.getX() + b.getX());
	sum.setY(a.getY() + b.getY());
	
	return (sum);		
}
Vector subtraction(Vector a, Vector b)
{
	Vector sum;
	sum.setX(a.getX() - b.getX());
	sum.setY(a.getY() - b.getY());
	
	return (sum);		
}