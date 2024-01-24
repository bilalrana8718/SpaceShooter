#ifndef BETA_H_
#define BETA_H_

#include "pch.h"
using namespace sf;

class Beta : public Invader
{
public:
    
    Beta();
    Beta(float xx,float yy,float p,float num);
    ~Beta();
   
    void move();
    void set_sprite(std::string png_path);
};

#endif /* Beta_H_ */