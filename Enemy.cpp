#include "Enemy.hpp"
#include "unistd.h"

Enemy::Enemy(){

}
Enemy::Enemy (WINDOW * win, int y, int x, std::string str){

    curwin = win;
    _y_location = y;
    _x_location = x;
    getmaxyx(curwin, _Max_y, _Max_x);
    keypad(curwin, true);
    _ship = str;
	this->isActive = true;

}

Enemy & Enemy::operator=(Enemy const & rhs)
{
	this->curwin = rhs.curwin;
	this->_y_location= rhs._y_location;
	this->_x_location = rhs._x_location;
	this->_ship = rhs._ship;
	this->isActive = rhs.isActive;

	return (*this);
}



Enemy::~Enemy(){

}

void Enemy::clear(void)
{
	for (int i = 0; i < _ship.length(); i++)
     {
        mvwaddch(curwin, _y_location, _x_location + i, ' ');
     }	
}

void Enemy::movedown(){
 
     for (int i = 0; i < _ship.length(); i++)
     {
        mvwaddch(curwin, _y_location, _x_location + i, ' ');
     }	
	_y_location = _y_location + 1;
    //usleep(100000);
    
}

bool Enemy::getIsAcitve(void) const
{
	return this->isActive;
}

void Enemy::setIsAcitve(bool active)
{
	this->isActive = active;
}

 void Enemy::display(){
	 
	
      mvwaddstr(curwin, _y_location, _x_location, _ship.c_str());
 }

int Enemy::getY()
{
	return this->_y_location;
}

int Enemy::getX()
{
	return this->_x_location;
}


