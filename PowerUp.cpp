/*#include "PowerUp.h"
#include "pch.h"
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
    addon.setScale(0.5,0.5);
   
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

//PowerUp* add_power = new PowerUp("img/PNG/Power-ups/powerupGreen_bolt.png",-30,340);
*/