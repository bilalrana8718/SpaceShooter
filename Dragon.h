#ifndef DRAGON_H_
#define DRAGON_H_

#include "pch.h"
using namespace sf;

class Dragon : public Enemy
{
public:
    
    Dragon();
    Dragon(float xx,float yy,float p);
    ~Dragon();
   
    void move();
    void set_sprite(std::string png_path);
    void fire(float& i,bool& check);
    
};


#endif /* Dragon_H_ */