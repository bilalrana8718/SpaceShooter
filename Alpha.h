#ifndef ALPHA_H_
#define ALPHA_H_

#include "pch.h"

using namespace sf;

class Alpha : public Invader
{
public:
    
    Alpha();
    Alpha(float xx,float yy,float p,float num);
    ~Alpha();
   
    void move();
    void set_enmy(std::string png_path);
};


   
#endif /* Alpha_H_ */