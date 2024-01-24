#include "pch.h"



Beta::Beta() : Invader()
{
}
Beta::Beta(float xx,float yy, float p,float num) : Invader(xx,yy,p,num)
{
}
Beta::~Beta()
{
}

void Beta::move()
{
      float delta_x=-1,delta_y=0;
    delta_x*=speed;
    delta_y*=speed;
    enmy.move(delta_x,delta_y);

    if(enmy.getPosition().x < 0)
{
	enmy.setPosition(750,enmy.getPosition().y);
}
if(enmy.getPosition().x > 750)
{
	enmy.setPosition(0,enmy.getPosition().y);
}
}

void Beta::set_sprite(std::string png_path)
{
    enmyTex.loadFromFile(png_path);
    enmy.setTexture(enmyTex);
    enmy.setPosition(x,y);
    enmy.setScale(0.5,0.5);
}
