#ifndef Fire_H_
#define Fire_H_

#include "pch.h"
#include "AddOns.h"

using namespace sf;

class Fire : public AddOns
{
public:

        Fire();
        Fire(std::string str,float xx,float yy);
    ~   Fire();
  
         virtual void move();
         virtual void set_sprite(std::string png_path);

};

Fire::Fire()
{
      this->x=340;this->y=600;
}

Fire::Fire(std::string png_path,float xx, float yy)
{
    addon_tex.loadFromFile(png_path);
    addon.setTexture(addon_tex);
    addon.setPosition(x,y);
    addon.setScale(0.85,0.85);
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
void Fire::set_sprite(std::string png_path)
{
    addon_tex.loadFromFile(png_path);
    addon.setTexture(addon_tex);
    addon.setPosition(x,y);
    addon.setScale(0.85,0.85);
}



#endif /* Fire_H_ */