#ifndef BOMB_H_
#define BOMB_H_

#include "pch.h"
using namespace sf;

class Bomb
{
public:
    Sprite bomb_sprite;
    Texture bomb_tex;
    float x,y;
    float speed = 0.20;
    bool f = false;

    Bomb();
    Bomb(std::string png_path,float xx,float yy);
    ~Bomb();
   
    void move();
    void move(float getx,float gety);
    void set_sprite(std::string str,float xx,float yy);
   
};

// Bomb::Bomb()
// {
//     bomb_tex.loadFromFile("img/ufoRed.png");
//     bomb_sprite.setTexture(bomb_tex);
//     this->x=340;this->y=600;
//     bomb_sprite.setPosition(x,y);
//     bomb_sprite.setScale(0.75,0.75);
// }


// Bomb::Bomb(std::string png_path,float xx,float yy)
// {
//     bomb_tex.loadFromFile(png_path);
//     bomb_sprite.setTexture(bomb_tex);
//     this->x=xx+20;this->y=yy;
//     bomb_sprite.setPosition(x,y);
//     bomb_sprite.setScale(0.70,0.70);
//     f = true;
// }

// Bomb::~Bomb()
// {
//   //  delete this;
// }

// void Bomb::move()
// {
//     float delta_x=0,delta_y=1;
//     delta_x*=speed;
//     delta_y*=speed;

//     bomb_sprite.move(delta_x, delta_y);

//     if(bomb_sprite.getPosition().y > 780)
//      this->f = false;
    
// }

// void Bomb::move(float getx,float gety)
// {
//     this->bomb_sprite.move(getx,gety);   
// }

// void Bomb::set_sprite(std::string png_path,float xx,float yy)
// {
//      bomb_tex.loadFromFile(png_path);
//     bomb_sprite.setTexture(bomb_tex);
//     bomb_sprite.setPosition(x,y);
//     bomb_sprite.setScale(xx,yy);
// }

#endif /* Bomb_H_ */