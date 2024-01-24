#include "pch.h"


Invader::Invader() : Enemy()
{
}
Invader::Invader(float xx,float yy, float p,float num)
{
     this->x=xx;this->y=yy;
    this->points = p;
    this->bomb_time = num;
}
Invader::~Invader()
{
}

void Invader::move()
{
    float delta_x=0,delta_y=-1;
    delta_x*=speed;
    delta_y*=speed;
    enmy.move(delta_x,delta_y);
}

void Invader::set_sprite(std::string png_path)
{
    enmyTex.loadFromFile(png_path);
    enmy.setTexture(enmyTex);
    enmy.setPosition(x,y);
    enmy.setScale(0.5,0.5);
}

void Invader::fire(float& i,bool& check)
{
	if(i>bomb_time)
	{
        int xi = rand()%2;
		check = true;
		i=xi;
		bomb = new Bomb("img/enemy_laser.png",enmy.getPosition().x,enmy.getPosition().y);
	}
	
}
