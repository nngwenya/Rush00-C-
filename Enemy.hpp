#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <ncurses.h>
#include <iostream>

class Enemy {
    public:
        Enemy();
        Enemy( Enemy const & player);
		Enemy & operator=(Enemy const & rhs);
        Enemy(WINDOW * win, int y, int x, std::string str);
        ~Enemy();

        void movedown();
        void setIsAcitve(bool active);
		bool getIsAcitve(void) const;
        int getmove();
        void display();
		int getY();
		int getX();
		void clear(void);

        unsigned int rendomsponing(std::string & target);

        private:
            int _x_location, _y_location, _Max_x, _Max_y;
            std::string _ship;
            WINDOW * curwin;
			bool isActive;
           
};

#endif