#ifndef INVADER_H_
#define INVADER_H_

#include "pch.h"
using namespace sf;

class Invader : public Enemy
{
public:
    
    Invader();
    Invader(float xx,float yy,float p,float num);
    ~Invader();
   
    void move();
    void set_sprite(std::string png_path);
    void fire(float& i,bool &yes);
};

#endif /* Invader_H_ */