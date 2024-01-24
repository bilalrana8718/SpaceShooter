#ifndef PLAYER_H_
#define PLAYER_H_

#include <SFML/Graphics.hpp>
#include<string.h>
#include "Bullet.h"
#include "AddOns.h"
#include "Lives.h"
#include "Danger.h"
#include "PowerUp.h"
#include "Fire.h"

using namespace sf;
class Player{
public:
Texture tex, expo_tex;
Sprite sprite,expo_Sprite;
float speed=0.3;
int x,y;
Bullet* player_bullet;
Bullet** p_bullet = new Bullet*[7];
AddOns** addon_arr = new AddOns* [4];

bool f,hit=false;
int score=0,lives=3,tilt=0;

Player(std::string png_path);

void fire(float& i,float& fire_timer,bool &yes,float& n,float& powerup_timer);

void fire2(float& i,float& powerup_timer,bool &yes);

void seven_fire(bool& powerup_fire,float& powerup_timer);

 void move(std::string s);


void set_sprite(std::string png_path);

};


#endif /* PLAYER_H_ */