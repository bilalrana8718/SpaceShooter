#ifndef BULLET_H_
#define BULLET_H_

#include "pch.h"
using namespace sf;

class Bullet
{
public:
    Sprite bull;
    Texture bull_tex;
    float x,y;
    float speed = 0.5;
    bool f = false;

    Bullet();
    Bullet(std::string png_path,float xx,float yy);
    ~Bullet();
   
    void move();
    void move(float xx,float yy);
    void render (RenderWindow* window);
};


 #endif /* BULLET_H_ */