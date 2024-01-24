#include "pch.h"


Enemy::Enemy()
{
    this->x=340;this->y=600;
    this->points = 0;
}


Enemy::Enemy(float xx,float yy, float p)
{
    this->x=xx;this->y=yy;
    this->points = p;
}

Enemy::~Enemy()
{
  //  delete this;
}

void Enemy::set_sprite(std::string png_path)
{
    enmyTex.loadFromFile(png_path);
    enmy.setTexture(enmyTex);
    enmy.setPosition(x,y);
    enmy.setScale(0.5,0.5);
}

