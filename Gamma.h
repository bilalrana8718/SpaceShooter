#ifndef GAMMA_H_
#define GAMMA_H_

#include "pch.h"
using namespace sf;

class Gamma : public Invader
{
public:
    
    Gamma();
    Gamma(float xx,float yy,float p,float num);
    ~Gamma();
   
    void move();
    void set_sprite(std::string png_path);
};

//Gamma* c = new Gamma(290,140,30,2);
//Gamma* c2 = new Gamma(62,220,30,2);

#endif /* Gamma_H_ */