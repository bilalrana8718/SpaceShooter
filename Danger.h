#ifndef DANGER_H_
#define DANGER_H_

#include "pch.h"

using namespace sf;

class Danger : public AddOns
{
public:

        Danger();
        Danger(std::string str,float xx,float yy);
    ~   Danger();
  
         virtual void move();
         virtual void set_sprite(std::string png_path);

};

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
    addon.setScale(0.85,0.85);
   
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
void Danger::set_sprite(std::string png_path)
{
    addon_tex.loadFromFile(png_path);
    addon.setTexture(addon_tex);
    addon.setPosition(x,y);
    addon.setScale(0.85,0.85);
}
#endif /* Fire_H_ */