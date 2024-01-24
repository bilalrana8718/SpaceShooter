/*#include "Fire.h"
#include "pch.h"
Fire::Fire()
{
      this->x=340;this->y=600;
}

Fire::Fire(std::string png_path,float xx, float yy)
{
    addon_tex.loadFromFile(png_path);
    addon.setTexture(addon_tex);
    addon.setPosition(x,y);
    addon.setScale(0.5,0.5);
    this->num = 3;
    this->x = xx;
    this->y = yy;
}


Fire::~Fire()
{
}

void Fire::move()
{
    float delta_x=0,delta_y=1;
    delta_x*=speed;
    delta_y*=speed;
    addon.move(delta_x, delta_y);
}
/*
void Fire::set_sprite(std::string png_path)
{
    addon_tex.loadFromFile(png_path);
    addon.setTexture(addon_tex);
    addon.setPosition(x,y);
    addon.setScale(0.5,0.5);
}
*/
//Fire* add_fire = new Fire("img/PNG/Power-ups/powerupYellow_bolt.png",30,340);
