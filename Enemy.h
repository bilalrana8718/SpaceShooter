#ifndef ENEMY_H_
#define ENEMY_H_

#include "pch.h"
#include "Bomb.h"

using namespace sf;

class Enemy
{
   // protected:
   
public:
    Sprite enmy;
    Texture enmyTex;

    int enemy_number;
    float x, y;
    float speed = 0.05;
    float points,bomb_time =3,bomb_timer=0;
    bool hit=false,bomb_yes=false;
    Bomb* bomb;

    Enemy();
    Enemy(float xx,float yy,float p);
    ~Enemy();
   
    virtual void move() =0;
    virtual void set_sprite(std::string png_path);
    virtual void fire(float& i,bool &yes) = 0;
   
};



#endif /* Enemy_H_ */