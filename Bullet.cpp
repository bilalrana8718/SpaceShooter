#include "pch.h"


Bullet::Bullet()
{
    bull_tex.loadFromFile("img/PNG/Lasers/laserBlue01.png");
    bull.setTexture(bull_tex);
    this->x=340;this->y=600;
    bull.setPosition(x,y);
    bull.setScale(0.75,0.75);
}

Bullet::Bullet(std::string png_path,float xx,float yy)
{
    bull_tex.loadFromFile(png_path);
    bull.setTexture(bull_tex);
    this->x=xx+33;this->y=yy-15;
    bull.setPosition(x,y);
    bull.setScale(0.75,0.75);
    f = true;
}

Bullet::~Bullet()
{
  //  delete this;
}

void Bullet::move()
{
    float delta_x=0,delta_y=-1;
    delta_x*=speed;
    delta_y*=speed;

    bull.move(delta_x, delta_y);

    if(bull.getPosition().y < 0)
     this->f = false;
    
}

void Bullet::move(float xx, float yy)
{
    float delta_x=xx,delta_y=yy;
    delta_x*=speed;
    delta_y*=speed;

    bull.move(delta_x, delta_y);
}

void Bullet::render(RenderWindow *window)
{
    window->draw(this->bull);
}
 
