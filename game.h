#ifndef GAME_H_
#define GAME_H_

#include "pch.h"

using namespace std;
const char title[] = "EVERSPACE 2";
//const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Game
{
public:

Sprite background,l_vel,l_ves,GameOver; //Game background sprite
Texture bg_texture,level_tex,lives_tex,gameOver_tex;
Player* p; //player 
// add other game attributes
Enemy** enemy;

//AddOns** addon_arr = new AddOns* [4];

int en_num = 6,en_counter=0;
bool en_y = false,player_d = false,powerup_fire=false,mon_check= false,don_check=false;
int level = 1,l_counter=1;
float timer_enemy=0,timer1_enemy=0,don_timer=0,don2_timer = 0;
bool yes= false,level_change=false,level_change2=true;
float randBomb_timer =0,randAddon_timer=0,fire_timer = 6,powerup_timer=0;
string playername = "";
bool pause = false,expo = false,expo_once=false;
float expo_timer =0;
bool anime =false,anime_once =false;
float anime_timer = 0;
//Addons
Lives* add_life = new Lives("img/PNG/Power-ups/pill_green.png",-30,340);
Danger* add_danger = new Danger("img/PNG/Power-ups/bolt_bronze.png",-30,340);
PowerUp* add_power = new PowerUp("img/PNG/Power-ups/powerupGreen_bolt.png",-30,340);
Fire* add_fire = new Fire("img/PNG/Power-ups/powerupYellow_bolt.png",30,340);

//Enemies
Gamma* g1 = new Gamma(850,300,30,2);
Gamma* g2 = new Gamma(-70,300,30,2);
Gamma* c = new Gamma(290,140,30,2);
Gamma* c2 = new Gamma(62,220,30,2);
Beta* b = new Beta(180,140,20,3);
Beta* b2 = new Beta(180,220,20,3);
Beta* b3 = new Beta(510,140,20,3);
Beta* b4 = new Beta(510,220,20,3);
Alpha* a = new Alpha(70,150,10,1);
Alpha* a2 = new Alpha(285,230,10,1);
Alpha* a3 = new Alpha(400,150,10,1);
Alpha* a4 = new Alpha(400,230,10,1);
Alpha* a5 = new Alpha(70,150,10,1);
Alpha* a6 = new Alpha(285,230,10,1);
Alpha* a7 = new Alpha(400,150,10,1);
Alpha* a8 = new Alpha(400,230,10,1);
Monster* mons = new Monster(340,0,40);
Enemy* monster = mons;
Dragon* don = new Dragon(340,0,50);
Enemy* dragon = don;

Game();

void start_game();
void game_over(std::string name);
void filehandle(std::string name);
//void gamestate_save();
//Game gamestate_read();

void create_Enemy(bool& s,int level,bool& level_change2);
void got_hit(Enemy** & enemy,int& en_counter,bool& change);
void got_hit2(Enemy** & enemy,int& en_counter,bool& change);
void player_got_hit(Player* & p,Enemy**& enemy);
void player_expo();
void monster_hit();
void check_level(int& level,int& en,bool & level_change2,bool& change);
void level_base(int& level,float& n);
void level_animation();

void appearMonster(bool& mon_check);
void create_addons(float& timer,bool& addon_yes);
void get_addons(float& fire_timer,float& timer,float& powerup_timer);
void fire_dragon(float& i,bool& check);
void appeardragon(bool& don_check);



};

 #endif /* Game_H_ */