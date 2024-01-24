#ifndef Lives_H_
#define Lives_H_

#include "pch.h"

using namespace sf;

class Lives : public AddOns
{
public:

        Lives();
        Lives(std::string str,float xx,float yy);
    ~   Lives();
  
         virtual void move();
         virtual void set_sprite(std::string png_path);

};

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
    addon.setScale(0.8,0.80);
   
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

void Lives::set_sprite(std::string png_path)
{
    addon_tex.loadFromFile(png_path);
    addon.setTexture(addon_tex);
    addon.setPosition(x,y);
    addon.setScale(0.85,0.85);
}
#endif /* Lives_H_ */