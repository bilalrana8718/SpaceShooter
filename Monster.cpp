#include "pch.h"


Monster::Monster()
{
}
Monster::Monster(float xx,float yy, float p)
{
    this->x = xx;
    this->y = yy;
    this->points = p;
    this->enmy.setPosition(x,y);
}
Monster::~Monster()
{
}

void Monster::move()
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
    if(this->enemy_number == 0)
    {
        if(enmy.getPosition().y > 100 && enmy.getPosition().x > 60 && enmy.getPosition().y <= 212)
    {
    delta_x = -1; delta_y = 0.4;
    delta_x*=speed;
    delta_y*=speed;
    enmy.move(delta_x,delta_y);
    }
    if(enmy.getPosition().y >= 212 && enmy.getPosition().x < 600 && enmy.getPosition().y < 400)
    {
    delta_x = 1; delta_y = 0.25;
    delta_x*=speed;
    delta_y*=speed;
    enmy.move(delta_x,delta_y);
    }
    }
    if(this->enemy_number == 1)
    {
        if(enmy.getPosition().y > 100 && enmy.getPosition().x < 700 && enmy.getPosition().y <= 212)
    {
    delta_x = 1; delta_y = 0.4;
    delta_x*=speed;
    delta_y*=speed;
    enmy.move(delta_x,delta_y);
    }
    if(enmy.getPosition().y >= 212 && enmy.getPosition().x > 60 && enmy.getPosition().y < 400)
    {
    delta_x = -1; delta_y = 0.25;
    delta_x*=speed;
    delta_y*=speed;
    enmy.move(delta_x,delta_y);
    }
    }

}

void Monster::set_sprite(std::string png_path)
{
    enmyTex.loadFromFile(png_path);
    enmy.setTexture(enmyTex);
    enmy.setPosition(x,y);
    enmy.setScale(0.75,0.75);
}
void Monster::fire(float& i,bool& check)
{   
   
    this->bomb_time = 1;
	if(i>bomb_time)
	{
       // int xi = rand()%2;
		check = true;
		//i=xi;
		bomb = new Bomb("img/PNG/Lasers/laserRed12.png",enmy.getPosition().x+60,enmy.getPosition().y+170);
        this->bomb->set_sprite("img/PNG/Lasers/laserRed12.png",1,7);
	}
    if(i>bomb_time+2)
    {
        i = 0;
    }
    if(i<bomb_time)
    {
        this->bomb_yes = false;
    }
	
}

