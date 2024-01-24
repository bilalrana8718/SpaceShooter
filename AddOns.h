#ifndef ADDONS_H_
#define ADDONS_H_

#include "pch.h"

 using namespace sf;

class AddOns
{
public:
      Sprite addon;
    Texture addon_tex;
    int num;
    float x, y;
    float speed = 0.2;
    bool addon_made=false;

      //  AddOns();
      //  AddOns(float xx,float yy);
   // ~   AddOns();
  
 virtual void move() = 0;
  virtual void set_sprite(std::string png_path) = 0;

};
#endif /* ADDONS_H_ */