/*#include "Danger.h"
#include "pch.h"
Danger::Danger()
{
      this->x=340;this->y=600;
}

Danger::Danger(std::string str,float xx, float yy) 
{
    this->num = 2;
     addon_tex.loadFromFile(str);
    addon.setTexture(addon_tex);
    addon.setPosition(x,y);
    addon.setScale(0.5,0.5);
   
    this->x = xx;
    this->y = yy;
}

Danger::~Danger()
{
}

void Danger::move()
{
    float delta_x=0,delta_y=1;
    delta_x*=speed;
    delta_y*=speed;
    addon.move(delta_x, delta_y);
}

//Danger* add_danger = new Danger("img/PNG/Power-ups/bolt_bronze.png",-30,340);
*/