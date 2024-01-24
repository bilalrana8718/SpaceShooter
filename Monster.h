#ifndef MONSTER_H_
#define MONSTER_H_

#include "pch.h"
using namespace sf;

class Monster : public Enemy
{
public:
    
    Monster();
    Monster(float xx,float yy,float p);
    ~Monster();
   
    void move();
    void set_sprite(std::string png_path);
    void fire(float& i,bool& check);
    
};



#endif /* Monster_H_ */