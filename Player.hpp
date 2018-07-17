#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <ncurses.h>
#include <iostream>
#include "Vector.hpp"
#include "Bullet.hpp"

class Player 
{
	private:
			
			Vector maxPostion;
			std::string _ship;
			WINDOW * curwin;

    public:
			Vector position;
			Player(void);
			Player(Player const & src);
			Player(WINDOW * win, Vector position, std::string ship);
			Player & operator=(Player const & rhs);
			~Player(void);

			

			void moveup(void);
			void movedown(void);
			void moveleft(void);
			void moveright(void);

			int getmove(void);
			void display(void);
			void shoot(void);

};

#endif
