/*#include "Lives.h"
#include "pch.h"
Lives::Lives()
{
      this->x=340;this->y=600;
}

Lives::Lives(std::string str,float xx, float yy) 
{
    this->num = 0;
      addon_tex.loadFromFile(str);
    addon.setTexture(addon_tex);
    addon.setPosition(x,y);
    addon.setScale(0.5,0.5);
   
    this->x = xx;
    this->y = yy;
}

Lives::~Lives()
{
}

void Lives::move()
{
    float delta_x=0,delta_y=1;
    delta_x*=speed;
    delta_y*=speed;
    addon.move(delta_x, delta_y);
}

//Lives* add_life = new Lives("img/PNG/Power-ups/pill_green.png",-30,340);
*/