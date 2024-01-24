#include "pch.h"


Dragon::Dragon()
{
}
Dragon::Dragon(float xx,float yy, float p)
{
    this->x = xx;
    this->y = yy;
    this->points = p;
    this->enmy.setPosition(x,y);
}
Dragon::~Dragon()
{
}

void Dragon::move()
{
    float delta_x,delta_y;
    this->speed = 0.12;
    if(enmy.getPosition().y < 100)
    {
        delta_x=0,delta_y=1;
        delta_x*=speed;
        delta_y*=speed;
        enmy.move(delta_x,delta_y);
    }
}

void Dragon::set_sprite(std::string png_path)
{
    enmyTex.loadFromFile(png_path);
    enmy.setTexture(enmyTex);
    enmy.setPosition(x,y);
    enmy.setScale(0.75,0.75);
}
void Dragon::fire(float& i,bool& check)
{   
   
    // this->bomb_time = 1;
	// if(i>bomb_time && !check)
	// {
		check = true;
		bomb = new Bomb("img/PNG/Effects/fire06.png",enmy.getPosition().x+50,enmy.getPosition().y+160);
	// }
    // if(i>bomb_time+1)
    // {
    //     i = 0;
    // }
    // if(i<bomb_time)
    // {
    //     this->bomb_yes = false;
    // }
	
}

