#include <ncurses.h>
#include <iostream>
#include <string>
#include <ctime>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Bullet.hpp"
#include "unistd.h"

#define BLUE_BLACK 1
int     main(int argc, char **argv){

// Ncureses start
initscr();
initscr();

cbreak();
curs_set(0);

//get screan size
int _Max_y, _Max_x;

getmaxyx(stdscr, _Max_y, _Max_x);
//create a window for our input

int height, width, start_y, start_x;
height = 60;
width = 200;
start_y = 30;
start_x = 20;

WINDOW * Playerwin = newwin(height, width, (_Max_y/2) - start_y, start_x);
nodelay(Playerwin,true);
box(Playerwin, '+', '=');
refresh();
wrefresh(Playerwin);

start_color();

init_pair(BLUE_BLACK, COLOR_BLUE, COLOR_BLACK);
std::string ship = "oo(^)oo";
std::string enemyship = "<<(0)>>";
//attron(COLOR_PAIR(1));
//init_pair(ship, COLOR_GREEN, COLOR_BLACK);
srand(time(NULL));
int x_random = 0;
////////////////////////////////////////////////////////////////////////
Vector * initPlayerPos = new Vector(55,100);
Player * p = new Player(Playerwin, *initPlayerPos, ship);
///////////////////////////////////////////////////////////////////////
Enemy band[10];
int enemyIndex = 0;

 
//////////////////////////////////////////////////////////////////////
Bullet cartridge[50];
Vector *speed = new Vector(0,1);
int cartridgeIndex = 0;
int input = 0;


int spawnCount = 0;
int j = 0;
do
{
////////////////////////////////////////////////////////////////////////////////////////////////
wmove(Playerwin, 1,1);
wprintw(Playerwin, "Score: %d", spawnCount);
	///////////////////////////////////////////////////////////////////////////////////////////////

	if (spawnCount == 600){
		spawnCount = 0;
	}
	if (spawnCount % 600 == 0)
	{
		for (int k = 0; k < 10; k++)
		{
			x_random = (rand() % 180 + 5);
			int y_random = (rand() % 15 + 2);
			Enemy * e = new Enemy(Playerwin, y_random, x_random , enemyship);
			band[k] = *e;
		}
	}
//if (spawnCount % 50 == 0)
	{
		if (band[j].getY() > 57)
		{
			band[j].setIsAcitve(false);
			band[j].clear();
		}
		
		if (band[j].getIsAcitve())
		{
			band[j].movedown();
			band[j].display();
		}
	}
	
	j++;
		if (j == 10)
			j = 0;
	spawnCount++;
	
	//////////////////////////////////////////////////////////////////////////////////////////
	input = p->getmove();	
	if (input == 'x')
	{
		wrefresh(Playerwin);
    	wbkgd(Playerwin ,COLOR_PAIR(BLUE_BLACK));
		return (0);
	}

	/////////////////////////////////////////////////////////////////////////////////////////////
	if (input == ' ')
	{
		if (cartridgeIndex == 50)
			cartridgeIndex = 0;
		Bullet *projectTile = new Bullet(Playerwin, p->position, *speed,'!');
		cartridge[cartridgeIndex] = *projectTile;
		delete projectTile;
		cartridgeIndex++;
	}

	for (int x = 0; x < 50; x++)
	{
		if (cartridge[x].getIsAcitve() == true)
    {
    	cartridge[x].movement();
		if (cartridge[x].getPosition().getY() < 2)
		{
			cartridge[x].clear();
			cartridge[x].setIsAcitve(false);
		}			
		else
			cartridge[x].display();
    }
	}
	for (int i = 0; i < 50; i++)
	{
		for (int p = 0; p < 10; p++)
		{
			
			if (band[p].getX() == cartridge[i].getPosition().getX() && band[p].getY() == cartridge[i].getPosition().getY())
			{
				wmove(Playerwin, 1,1);
				wprintw(Playerwin,"Enemy = %d | Bullet = %d", band[p].getX(), cartridge[i].getPosition().getX());
				
				band[j].setIsAcitve(false);
				band[j].clear();
				cartridge[p].clear();
				cartridge[p].setIsAcitve(false);
			}
		}
	}

	
		for (int g = 0; g < 10; g++)
		{
			
			if (band[g].getX() == p->position.getX() && band[g].getY() == p->position.getY())
			{
				return (0);
			}
		}
	


	
	  	/*i++;
		if (i == 50)
		i = 0;*/
	//////////////////////////////////////////////////////////////////////////////////////////////
	p->display();
      
	usleep(20000);
    wrefresh(Playerwin);
    wbkgd(Playerwin ,COLOR_PAIR(BLUE_BLACK));
}while(1);

getch();
endwin();

return (0);

}