/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angonyam  <angonyam @42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:33:26 by omeyer            #+#    #+#             */
/*   Updated: 2018/06/10 14:46:06 by angonyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

class Vector
{
	private:
			int x;
			int y;

	public:

			Vector(void);
			Vector(int x, int y);
			Vector(Vector const & src);
			Vector & operator=(Vector const & rhs);
			Vector & operator+(Vector const & rhs);
			Vector & operator-(Vector const & rhs);
			~Vector(void);

			void setX(int x);
			int getX(void) const;
			void setY(int y);
			int getY(void) const;

			Vector addition(Vector a, Vector b);
			Vector subtraction(Vector a, Vector b);
};

#endif