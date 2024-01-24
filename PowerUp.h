#ifndef PowerUp_H_
#define PowerUp_H_

#include "pch.h"

using namespace sf;

class PowerUp : public AddOns
{
public:

        PowerUp();
        PowerUp(std::string str,float xx,float yy);
    ~   PowerUp();
  
         virtual void move();
         virtual void set_sprite(std::string png_path);

};

PowerUp::PowerUp()
{
      this->x=340;this->y=600;
}

PowerUp::PowerUp(std::string str,float xx, float yy)
{
    this->num = 1;
       addon_tex.loadFromFile(str);
    addon.setTexture(addon_tex);
    addon.setPosition(x,y);
    addon.setScale(0.85,0.85);
   
    this->x = xx;
    this->y = yy;

}

PowerUp::~PowerUp()
{
}

void PowerUp::move()
{
    float delta_x=0,delta_y=1;
    delta_x*=speed;
    delta_y*=speed;
    addon.move(delta_x, delta_y);
}

void PowerUp::set_sprite(std::string png_path)
{
    addon_tex.loadFromFile(png_path);
    addon.setTexture(addon_tex);
    addon.setPosition(x,y);
    addon.setScale(0.85,0.85);
}
//PowerUp* add_power = new PowerUp("img/PNG/Power-ups/powerupGreen_bolt.png",-30,340,0.05);
#endif /* PowerUp_H_ */