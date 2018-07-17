#include "Player.hpp"

Player::Player(void)
{
	return;
}

Player::Player(WINDOW * win, Vector position, std::string ship){

    this->curwin = win;
    this->position = position;
	int x;
	int y;
	getmaxyx(this->curwin, y, x);
	this->maxPostion.setX(x);
	this->maxPostion.setY(y);    
	keypad(this->curwin, true);
    this->_ship = ship;
}

Player::Player(Player const & src)
{
	this->curwin = src.curwin;
    this->position = src.position;
    this->maxPostion = src.maxPostion;
    this->_ship = src._ship;
}

Player & Player::operator=(Player const & rhs)
{
	this->curwin = rhs.curwin;
    this->position = rhs.position;
    this->maxPostion = rhs.maxPostion;
    this->_ship = rhs._ship;

	return (*this);
}

Player::~Player(void)
{
	return;
}

void Player::moveup(){

     for (int i = 0; i < _ship.length(); i++)
     {
        mvwaddch(curwin, this->position.getY(), this->position.getX() + i, ' ');
     }
    wmove(curwin, this->position.getY(), this->position.getX());
    //mvwaddstr(curwin, _y_location, _x_location, "");
    int sum ;
	sum = this->position.getY();
	sum--;
	this->position.setY(sum);
	if(this->position.getY() < 1)
		this->position.setY(1);

}

void Player::movedown(){

     for (int i = 0; i < _ship.length(); i++)
     {
        mvwaddch(curwin, this->position.getY(), this->position.getX() + i, ' ');
     }
    wmove(curwin, this->position.getY(), this->position.getX());
    //mvwaddstr(curwin, _y_location, _x_location, "");
   int sum;
	sum =  this->position.getY(); 
	sum++;
	this->position.setY(sum);
	if(this->position.getY() > this->maxPostion.getY() - 2)
		this->position.setY(this->maxPostion.getY() - 2);

}

void Player::moveleft(){

    for (int i = 0; i < _ship.length(); i++)
     {
        mvwaddch(curwin, this->position.getY(), this->position.getX() + i, ' ');
     }
    wmove(curwin, this->position.getY(), this->position.getX());
   int sum;
	sum = this->position.getX();
	sum -= 1;
	this->position.setX(sum);
	if(this->position.getX() < 1)
		this->position.setX(1);
}

void Player::moveright(){

    for (int i = 0; i < _ship.length(); i++)
     {
        mvwaddch(curwin, this->position.getY(), this->position.getX() + i, ' ');
     }
    wmove(curwin, this->position.getY(), this->position.getX());
   // mvwaddstr(curwin, _y_location, _x_location, "");
    int sum;
	sum = this->position.getX();
	sum += 1;
	this->position.setX(sum);
	if(this->position.getX() > this->maxPostion.getX() - 2)
		this->position.setX(this->maxPostion.getX() - 2);

}

int Player::getmove(){
    int choice = wgetch(curwin);
    switch(choice)
    {
        case KEY_UP:
            moveup();
            break;
        case KEY_DOWN:
            movedown();
            break;
        case KEY_LEFT:
            moveleft();
            break;
        case KEY_RIGHT:
            moveright();
            break;
            default:
            break;
    }
    return choice;
}

 void Player::display(){
     //loop
     mvwaddstr(curwin, this->position.getY(), this->position.getX(), _ship.c_str());
 }
  


