/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam  <angonyam @42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:19:22 by omeyer            #+#    #+#             */
/*   Updated: 2018/06/10 11:33:15 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
#define BULLET_HPP

#include <ncurses.h>
#include <iostream>
#include "Vector.hpp"

class Bullet
{
	private:
			char shape;
			Vector position;
			Vector velocity;
			WINDOW * curwin;
			bool isActive;

	public:

			Bullet(void);
			Bullet(WINDOW * win, Vector position, Vector velocity, char shape);
			Bullet(Bullet const & src);
			Bullet & operator=(Bullet const & rhs);
			~Bullet(void);

			bool getIsAcitve(void) const;
			void setIsAcitve(bool active);
			void setShape(char shape);
			char getShape(void) const;
			void setPostion(Vector position);
			Vector getPosition(void) const;
			void setVelocity(Vector velocity);
			Vector getVelocity(void) const;
			Vector movement(void);//for now its assumed to be player bullet only

			void display(void);
			void clear(void);

};

#endif


			