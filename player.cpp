#include "pch.h"

Player::Player(std::string png_path)
{

tex.loadFromFile(png_path);
sprite.setTexture(tex);
x=340;y=700;
sprite.setPosition(x,y);
sprite.setScale(0.75,0.75);
f =false;


expo_tex.loadFromFile("img/PNG/Damage/playerShip1_damage2.png");
expo_Sprite.setTexture(expo_tex);
expo_Sprite.setPosition(1000,200);
expo_Sprite.setScale(0.75,0.75);
}


void Player::fire(float& i,float& fire_timer,bool &yes,float& n,float& powerup_timer)
{
	if(i>n)
	{
		yes= true;
		i=0;
		if(fire_timer > 5 && tilt == 0)
		player_bullet = new Bullet("img/PNG/Lasers/laserGreen09.png",sprite.getPosition().x,sprite.getPosition().y);
		else if(fire_timer <= 5)
		{
		player_bullet = new Bullet("img/PNG/Effects/fire16.png",sprite.getPosition().x,sprite.getPosition().y);
		player_bullet->bull_tex.loadFromFile("img/PNG/Effects/fire16.png");
    	player_bullet->bull.setTexture(player_bullet->bull_tex);
        player_bullet->bull.setScale(2,2);
		}

		if(powerup_timer < 5)
		{
			for(int h=0; h<7; h++)
		{
			p_bullet[h] = new Bullet("img/PNG/Lasers/laserGreen09.png",sprite.getPosition().x,sprite.getPosition().y);		
		}
		//powerup_timer = 0;
		}

	}
	f = true;
	
}
void Player::fire2(float& i,float& powerup_timer,bool &yes)
{
	
		yes= true;
			i=0;
		if(powerup_timer > 5)
		{
			for(int h=0; h<7; h++)
		{
			p_bullet[h] = new Bullet("img/PNG/Lasers/laserGreen09.png",sprite.getPosition().x,sprite.getPosition().y);		
		}
		powerup_timer = 0;
		}
	
		
		//player_bullet = new Bullet("img/PNG/Lasers/laserGreen09.png",sprite.getPosition().x,sprite.getPosition().y);
		
	f = true;
	
}
void Player::seven_fire(bool& powerup_fire,float& powerup_timer)
{
	//if(powerup_timer < 5)
    if(powerup_fire)
    {
            this->p_bullet[0]->move(0,-1);
            this->p_bullet[1]->move(0.15,-1);
            this->p_bullet[2]->move(0.3,-1);
            //this->p_bullet[2]->move(0.4,-1);
            //this->p_bullet[2]->move(0.4,-1);
            this->p_bullet[3]->move(0.45,-1);
            this->p_bullet[4]->move(-0.15,-1);
            this->p_bullet[5]->move(-0.3,-1);
            this->p_bullet[6]->move(-0.45,-1);
            if(powerup_timer > 5)
            powerup_fire = false;
    }
}
void Player::move(std::string s){

float delta_x=0,delta_y=0;
if(s=="l")
delta_x = -1;
	//move the player left
else if(s=="r")
delta_x = 1;
	//move the player right
if(s=="u")
	delta_y=-1;
else if(s=="d")
	delta_y=1;
if(s=="rt")
{
	delta_y=-0.25;
	delta_x=0.25;
	
}	
if(s=="lt")
{
	delta_y=-0.25;
	delta_x=-0.25;
	
}	

delta_x*=speed;
delta_y*=speed;


sprite.move(delta_x, delta_y);

if(sprite.getPosition().x < 0)
{
	sprite.setPosition(750,sprite.getPosition().y);
}
if(sprite.getPosition().x > 750)
{
	sprite.setPosition(0,sprite.getPosition().y);
}
if(sprite.getPosition().y > 700)
{
	sprite.setPosition(sprite.getPosition().x , 700);
}
if(sprite.getPosition().y < 0)
{
	sprite.setPosition(sprite.getPosition().x , 700);
}

}

void Player::set_sprite(std::string png_path)
{
	this->tex.loadFromFile(png_path);
    sprite.setTexture(tex);
    sprite.setScale(0.75,0.75);
}
