#include "pch.h"
#include "game.h"
#include <fstream>
#include "AddOns.h"
#include "Lives.h"
#include "Danger.h"
#include "PowerUp.h"
#include "Fire.h"



using namespace std;


Game::Game()
{
p=new Player("img/player_ship.png");
bg_texture.loadFromFile("img/background2.png");
background.setTexture(bg_texture);
background.setScale(0.45, 0.80);

level_tex.loadFromFile("img/PNG/UI/numeral1.png");
l_vel.setTexture(level_tex);
l_vel.setScale(1,1);
l_vel.setPosition(750,10);

lives_tex.loadFromFile("img/PNG/UI/numeral3.png");
l_ves.setTexture(lives_tex);
l_ves.setScale(1,1);
l_ves.setPosition(70,10);

gameOver_tex.loadFromFile("img/pxfuel(1).jpg");
GameOver.setTexture(gameOver_tex);
GameOver.setScale(1,1);

}
///  ///////////////////////////////////////////////////////////////////////////////////////////////
void Game::start_game()
{
    Mouse mouse;
    srand(time(0));
    RenderWindow window(VideoMode(780, 780), title);
    Clock clock;
    float timer=0;
   monster->set_sprite("img/dragon.png");
    float n=2;
    bool addon_yes=false;
    int randomNum = 0;
    Music music;
    music.openFromFile("SkyFire(Title Screen).ogg");
    music.setLoop(true);
    //music.play();

    Font font,font2;
    font.loadFromFile("Debrosee-ALPnL.ttf");
    font2.loadFromFile("JerseyM54.ttf");
    Text playtext;
    playtext.setFont(font);
    playtext.setFillColor(sf::Color::White);
    playtext.setString("Level");
    playtext.setCharacterSize(20);  
    playtext.setPosition(685.f, 7.f); 
    Text playtext1;
    playtext1.setFont(font);
    playtext1.setFillColor(sf::Color::White);
    playtext1.setString("Lives");
    playtext1.setCharacterSize(20);  
    playtext1.setPosition(10.f, 7.f); 
    Text playtext2;
    playtext2.setFont(font);
    playtext2.setFillColor(sf::Color::White);
    playtext2.setString("Score");
    playtext2.setCharacterSize(20);  
    playtext2.setPosition(10.f, 35.f); 
    Text playtext3;
    playtext3.setFont(font2);
    playtext3.setFillColor(sf::Color::White);
    playtext3.setCharacterSize(22);  
    playtext3.setPosition(75.f, 32.f); 

    
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds(); 
        clock.restart();
        timer += time;  
        timer_enemy += time; 
        timer1_enemy += time;
        randBomb_timer += time;
        randAddon_timer += time;
        fire_timer += time;
        powerup_timer += time;
        don_timer += time;
        int newscore = p->score;
        playtext3.setString(to_string(newscore));
       for(int h=0;h<en_num;h++)
        {
            if(en_y)
            enemy[h]->bomb_timer += time;
        } 
        if(mon_check)
        monster->bomb_timer += time;
        if(don_check)
       { dragon->bomb_timer += time;
        don2_timer += time;}
        expo_timer += time;
        anime_timer += time;
        //cout<<time<<endl; 
 

 	Event e;
        while (window.pollEvent(e))
        {  
            //cout<<Mouse::getPosition().x<<" "<<Mouse::getPosition().y<<endl;
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
                window.close(); //close the game  

                 if (e.type == Event::KeyPressed) 
                 {
                     if (e.key.code == Keyboard::Escape)
                     {
                         if(!pause)
                          pause = true;
                           else if(pause)
                             pause = false;
                     }

                 }
                        	    
        }
          
	if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
         {
            p->set_sprite("img/player_ship.png");
               p->move("l");
            //    p->tilt =0;
         }    // Player will move to left
	if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
          {
            p->set_sprite("img/player_ship.png");
              p->move("r");  //player will move to right
            //   p->tilt =0;
          }
	if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
    {
          p->set_sprite("img/player_ship.png");
          p->move("u");
        //   p->tilt =0;
    }
                //playet will move upwards
	if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
    {
        p->set_sprite("img/player_ship.png");
        p->move("d");  //player will move downwards
        // p->tilt =0;
    }
    if (Keyboard::isKeyPressed(Keyboard::Right) && Keyboard::isKeyPressed(Keyboard::Up)) //If left key is pressed
         {
               p->move("rt");
               p->set_sprite("img/right_tilt.png");
            //    p->tilt =1;
         }
    if (Keyboard::isKeyPressed(Keyboard::Left) && Keyboard::isKeyPressed(Keyboard::Up)) //If left key is pressed
        {
           p->move("lt");
           p->set_sprite("img/left_tilt.png");
        //    p->tilt =2;
        }
     if (Keyboard::isKeyPressed(Keyboard::Space))
            {
              // p->fire(timer,fire_timer,yes,n);
            } 
     if (Keyboard::isKeyPressed(Keyboard::Q))
            {
                music.stop();
                window.close();
                this->filehandle(playername);
            } 
            
   
           
if(!pause)      
{ 
	//////////////////////////////////////////////////////////////////////////////////
	/////  Call your functions here            //////////////////////////////////////
    // PLAYER FUNCTIONS /////////////////////////////////////////////////////////////
    
    p->fire(timer,fire_timer,yes,n,powerup_timer);  // Fires the bullets from the player; timer keeps checks after what time bullet is generated
    if(yes)                 // yes is bool which checks if bullet is made 
    {
        p->player_bullet->move();        // moves the bullet
    }
    p->seven_fire(powerup_fire,powerup_timer);

    player_expo();
    //Addons
    if(randAddon_timer > 6)
    {
        randomNum = rand()%4;
    }
    create_addons(randAddon_timer,addon_yes);
    if(addon_yes)
    {
        p->addon_arr[randomNum]->move();
        get_addons(fire_timer,timer,powerup_timer);
    }
    // ENEMY FUNCTIONS ///////////////////////////////////////////////////////////////
   
    if(level_change2)            // this timer keep check that enemy is made only once 
    create_Enemy(en_y,level,level_change2);
    /////////////////////////MONSTER///////////////////////////////////////////////////
    appearMonster(mon_check);
    monster_hit();
    ////////////////////////DRAGON/////////////////////////////////////////////////
    appeardragon(don_check);
    /////////////////////////////////////////////////////////////////////////////////
         // this en_y checks if the enemy is created 
     if(en_y)                       
     {
        for(int h=0;h<en_num;h++)
        {
            enemy[h]->move();
        }
        if(yes)
        got_hit(enemy,en_counter,level_change);                             // checks if enenmy is hit by bullet
        if(powerup_fire)
        got_hit2(enemy,en_counter,level_change);
        
        for(int h=0;h<en_num;h++)
         {
             enemy[h]->fire(enemy[h]->bomb_timer,enemy[h]->bomb_yes);    // Fires the bomb from the enemy; timer keeps checks after what time bomb is generated
            if(enemy[h]->bomb_yes)
            enemy[h]->bomb->move();
         } 
        level_base(level,n);
        player_got_hit(p,enemy);
     }

     cout<< "lives: "<< p->lives<<" Score: "<<p->score<<"  "<<level<<"  "<<l_counter<<"  "<<timer_enemy<<endl;
    
    if(level_change)
    check_level(level,en_counter,level_change2,level_change);

     if(p->lives == 0)
    {
        music.stop();
        window.close();
        this->game_over(this->playername);
    }

    level_animation();
	//////////////////////////////////////////////

	window.clear(Color::Black); //clears the screen
	window.draw(background);  // setting background
   if(!anime)
   {
         if(!expo)
	window.draw(p->sprite);  // setting player on screen
    else
    window.draw(p->expo_Sprite);  
    window.draw(l_vel);
    window.draw(l_ves);
    window.draw(playtext);
    window.draw(playtext1);
    window.draw(playtext2);
    window.draw(playtext3);
    
    if(yes)
    {
        window.draw(p->player_bullet->bull);
    }
    if(powerup_fire)
    {
        for(int h=0;h<7;h++)
        {
            window.draw(p->p_bullet[h]->bull);
        }
    }
    if(en_y)
    {
        for(int h=0;h<en_num;h++)
         {
            if(!(enemy[h]->hit))
             window.draw(enemy[h]->enmy);
         } 

         for(int h=0;h<en_num;h++)
         {
            if(enemy[h]->bomb_yes)
            {
                window.draw(enemy[h]->bomb->bomb_sprite);
            }
         }
    }
    window.draw(l_ves);
    if(addon_yes)
    {
        for(int h =0; h<4; h++)
     {
        {
            window.draw(p->addon_arr[h]->addon);
        }
     }
    }

    if(mon_check)
    {
        window.draw(monster->enmy);    
        if(monster->bomb_yes)
        window.draw(monster->bomb->bomb_sprite);
    }
    if(don_check)
    {
        window.draw(dragon->enmy);
        if(dragon->bomb_yes)
        window.draw(dragon->bomb->bomb_sprite);
    }
   
   }
   else
   {
    window.draw(g1->enmy);
    window.draw(g2->enmy);
   }
    

	window.display();  //Displying all the sprites
   
    }

    }
    music.stop();
}
///  //////////////////////////////////////////////////////////////////////////////////////////////////

 /// ////////////////////////////////////////////////////////////////////////////////////////////
 //--------------------------------------------------------------------------------------------- 
 void Game::create_Enemy(bool& s,int level,bool& level_change2)
    {
          s =true;
        if(level == 1)
        { 
            if(l_counter ==1)
            {
                en_num = 6;
                enemy = new Enemy*[en_num];
                *a = Alpha(70,150,10,5);
                *a2 = Alpha(285,230,10,5);
                *a3 = Alpha(400,150,10,5);
                *a4 = Alpha(400,230,10,5);
                *b = Beta(180,140,20,3);
                *b2 = Beta(180,220,20,3);
                *b3 = Beta(510,140,20,3);
                *b4 = Beta(510,220,20,3);
                *c = Gamma(290,140,30,3);
                *c2 = Gamma(62,220,30,3);
                enemy[0] = a;
                enemy[1] = b;
                enemy[2] = c;
                enemy[3] = a2;
                enemy[4] = b2;
                enemy[5] = c2;
                enemy[0]->set_sprite("img/enemy_1.png");
                enemy[1]->set_sprite("img/enemy_2.png");
                enemy[2]->set_sprite("img/enemy_3.png");
                enemy[3]->set_sprite("img/enemy_1.png");
                enemy[4]->set_sprite("img/enemy_2.png");
                enemy[5]->set_sprite("img/enemy_3.png");

                level_change2 = false;
            }
            else if(l_counter == 2)
            {
                en_num = 5;
                enemy = new Enemy*[en_num];
                *a = Alpha(200,120,10,5);
                *a2 = Alpha(200,280,10,5);
                *a3 = Alpha(480,280,10,5);
                *a4 = Alpha(400,230,10,5);
                *b = Beta(480,270,20,3);
                *b2 = Beta(480,110,20,3);
                *b3 = Beta(510,140,20,3);
                *b4 = Beta(510,220,20,3);
                *c = Gamma(340,200,30,2);
               *c2 = Gamma(62,220,30,2);
                enemy[0] = a;
                enemy[1] = b;
                enemy[2] = c;
                enemy[3] = a2;
                enemy[4] = b2;
               // enemy[5] = c2;
                enemy[0]->set_sprite("img/enemy_1.png");
                enemy[1]->set_sprite("img/enemy_2.png");
                enemy[2]->set_sprite("img/enemy_3.png");
                enemy[3]->set_sprite("img/enemy_1.png");
                enemy[4]->set_sprite("img/enemy_2.png");
               // enemy[5]->set_sprite("img/enemy_3.png");

               level_change2 = false;
            }
            else if(l_counter == 3)
            {
                 en_num = 6;
                enemy = new Enemy*[en_num];
                *a = Alpha(160,130,10,5);
                *a2 = Alpha(330,130,10,5);
                *a3 = Alpha(520,130,10,5);
             //   *a4 = Alpha(400,230,10);
                *b = Beta(430,200,20,3);
                *b2 = Beta(250,200,20,3);
            //    *b3 = Beta(510,140,20);
            //    *b4 = Beta(510,220,20);
                *c = Gamma(340,280,30,2);
            //    *c2 = Gamma(62,220,30);
                enemy[0] = a;
                enemy[1] = b;
                enemy[2] = c;
                enemy[3] = a2;
                enemy[4] = b2;
                enemy[5] = a3;
                enemy[0]->set_sprite("img/enemy_1.png");
                enemy[1]->set_sprite("img/enemy_2.png");
                enemy[2]->set_sprite("img/enemy_3.png");
                enemy[3]->set_sprite("img/enemy_1.png");
                enemy[4]->set_sprite("img/enemy_2.png");
                enemy[5]->set_sprite("img/enemy_1.png");

                level_change2 = false;  
            }
            
        }
        else if(level == 2)
        {  
            if(l_counter ==1)
            {
                 en_num = 8;
            enemy = new Enemy*[en_num];
            *a = Alpha(160,200,10,5);
            *a2 = Alpha(340,210,10,5);
            *a3 = Alpha(520,210,10,5);
            //   *a4 = Alpha(400,230,10);
            *b = Beta(430,280,20,3);
            *b2 = Beta(250,280,20,3);
            *b3 = Beta(250,130,20,3);
            *b4 = Beta(430,130,20,3);
            *c = Gamma(340,360,30,2);
            *c2 = Gamma(340,50,30,2);
            enemy[0] = a;
            enemy[1] = b;
            enemy[2] = c;
            enemy[3] = b4;
            enemy[4] = b2;
            enemy[5] = c2;
            enemy[6] = a3;
            enemy[7] = b3;
           // enemy[8] = b4;
            enemy[0]->set_sprite("img/enemy_1.png");
            enemy[1]->set_sprite("img/enemy_2.png");
            enemy[2]->set_sprite("img/enemy_3.png");
            enemy[3]->set_sprite("img/enemy_2.png");
            enemy[4]->set_sprite("img/enemy_2.png");
            enemy[5]->set_sprite("img/enemy_3.png");
            enemy[6]->set_sprite("img/enemy_1.png");
            enemy[7]->set_sprite("img/enemy_2.png");
           // enemy[8]->set_sprite("img/enemy_2.png");

           level_change2 = false;
            }
           else if (l_counter == 2)
           {
                en_num = 10;
                enemy = new Enemy*[en_num];
                *a = Alpha(280,110,10,5);
                *a2 = Alpha(420,110,10,5);
                *a3 = Alpha(280,300,10,5);
                *a4 = Alpha(420,300,10,5);
                *b = Beta(220,170,20,3);
                *b2 = Beta(480,170,20,3);
                *b3 = Beta(220,240,20,3);
                *b4 = Beta(480,240,20,3);
                *c = Gamma(340,360,30,2);
                *c2 = Gamma(340,60,30,2);
                enemy[0] = a;
                enemy[1] = a2;
                enemy[2] = a3;
                enemy[3] = a4;
                enemy[4] = b;
                enemy[5] = b2;
                enemy[6] = b3;
                enemy[7] = b4;
                enemy[8] = c;
                enemy[9] = c2;
                
                enemy[0]->set_sprite("img/enemy_1.png");
                enemy[1]->set_sprite("img/enemy_1.png");
                enemy[2]->set_sprite("img/enemy_1.png");
                enemy[3]->set_sprite("img/enemy_1.png");
                enemy[4]->set_sprite("img/enemy_2.png");
                enemy[5]->set_sprite("img/enemy_2.png");
                enemy[6]->set_sprite("img/enemy_2.png");
                enemy[7]->set_sprite("img/enemy_2.png");
                enemy[8]->set_sprite("img/enemy_3.png");
                 enemy[9]->set_sprite("img/enemy_3.png");

                 level_change2 = false;
           }
           else if (l_counter == 3)
           {
                en_num = 10;
                enemy = new Enemy*[en_num];
                *a = Alpha(270,110,10,5);
                *a2 = Alpha(430,110,10,5);
                *a3 = Alpha(280,300,10,5);
                *a4 = Alpha(420,300,10,5);
                *b = Beta(210,150,20,3);
                *b2 = Beta(490,150,20,3);
                *b3 = Beta(220,240,20,3);
                *b4 = Beta(480,240,20,3);
                *c = Gamma(340,360,30,2);
                *c2 = Gamma(340,160,30,2);
                enemy[0] = a;
                enemy[1] = a2;
                enemy[2] = a3;
                enemy[3] = a4;
                enemy[4] = b;
                enemy[5] = b2;
                enemy[6] = b3;
                enemy[7] = b4;
                enemy[8] = c;
                enemy[9] = c2;
                
                enemy[0]->set_sprite("img/enemy_1.png");
                enemy[1]->set_sprite("img/enemy_1.png");
                enemy[2]->set_sprite("img/enemy_1.png");
                enemy[3]->set_sprite("img/enemy_1.png");
                enemy[4]->set_sprite("img/enemy_2.png");
                enemy[5]->set_sprite("img/enemy_2.png");
                enemy[6]->set_sprite("img/enemy_2.png");
                enemy[7]->set_sprite("img/enemy_2.png");
                enemy[8]->set_sprite("img/enemy_3.png");
                 enemy[9]->set_sprite("img/enemy_3.png");

                 level_change2 = false;
               
           }
             for(int h=0;h<en_num;h++)
           {
            if(enemy[h]->bomb_yes)
            enemy[h]->bomb->speed = 0.6;
           }
           
        }
        if(level == 3)
        {
            if (l_counter == 1)
           {
            en_num = 9;
            enemy = new Enemy*[en_num];
            *a = Alpha(160,200,10,5);
            *a2 = Alpha(340,210,10,5);
            *a3 = Alpha(520,210,10,5);
            *a4 = Alpha(400,230,10,5);
            *b = Beta(430,280,20,3);
            *b2 = Beta(250,280,20,3);
            *b3 = Beta(250,130,20,3);
            *b4 = Beta(430,130,20,3);
            *c = Gamma(340,360,30,3);
            *c2 = Gamma(340,50,30,3);
            enemy[0] = a;
            enemy[1] = b;
            enemy[2] = c;
            enemy[3] = b4;
            enemy[4] = b2;
            enemy[5] = c2;
            enemy[6] = a3;
            enemy[7] = b3;
            enemy[8] = a2;
            enemy[0]->set_sprite("img/enemy_1.png");
            enemy[1]->set_sprite("img/enemy_2.png");
            enemy[2]->set_sprite("img/enemy_3.png");
            enemy[3]->set_sprite("img/enemy_2.png");
            enemy[4]->set_sprite("img/enemy_2.png");
            enemy[5]->set_sprite("img/enemy_3.png");
            enemy[6]->set_sprite("img/enemy_1.png");
            enemy[7]->set_sprite("img/enemy_2.png");
            enemy[8]->set_sprite("img/enemy_2.png");

            level_change2 = false;
           }
           else if (l_counter == 2)
           {
                en_num = 14;
                enemy = new Enemy*[en_num];
                *a = Alpha(280,110,10,5);
                *a2 = Alpha(420,110,10,5);
                *a3 = Alpha(280,300,10,5);
                *a4 = Alpha(420,300,10,5);
                *a5 = Alpha(310,160,10,5);
                *a6 = Alpha(380,160,10,5);
                *a7 = Alpha(310,240,10,5);
                *a8 = Alpha(380,240,10,5);
                *b = Beta(220,170,20,3);
                *b2 = Beta(480,170,20,3);
                *b3 = Beta(220,240,20,3);
                *b4 = Beta(480,240,20,3);
                *c = Gamma(340,360,30,3);
                *c2 = Gamma(340,60,30,3);
                enemy[0] = a;
                enemy[1] = a2;
                enemy[2] = a3;
                enemy[3] = a4;
                enemy[4] = b;
                enemy[5] = b2;
                enemy[6] = b3;
                enemy[7] = b4;
                enemy[8] = c;
                enemy[9] = c2;
                enemy[10] = a5;
                enemy[11] = a6;
                enemy[12] = a7;
                enemy[13] = a8;
                
                enemy[0]->set_sprite("img/enemy_1.png");
                enemy[1]->set_sprite("img/enemy_1.png");
                enemy[2]->set_sprite("img/enemy_1.png");
                enemy[3]->set_sprite("img/enemy_1.png");
                enemy[4]->set_sprite("img/enemy_2.png");
                enemy[5]->set_sprite("img/enemy_2.png");
                enemy[6]->set_sprite("img/enemy_2.png");
                enemy[7]->set_sprite("img/enemy_2.png");
                enemy[8]->set_sprite("img/enemy_3.png");
                 enemy[9]->set_sprite("img/enemy_3.png");
                 enemy[10]->set_sprite("img/enemy_1.png");
                enemy[11]->set_sprite("img/enemy_1.png");
                enemy[12]->set_sprite("img/enemy_1.png");
                enemy[13]->set_sprite("img/enemy_1.png");

                level_change2 = false;
           }
            else if (l_counter == 3)
           {
                en_num = 14;
                enemy = new Enemy*[en_num];
                *a = Alpha(280,110,10,5);
                *a2 = Alpha(420,110,10,5);
                *a3 = Alpha(280,300,10,5);
                *a4 = Alpha(420,300,10,5);
                *a5 = Alpha(310,160,10,5);
                *a6 = Alpha(380,160,10,5);
                *a7 = Alpha(310,240,10,5);
                *a8 = Alpha(380,240,10,5);
                *b = Beta(220,170,20,3);
                *b2 = Beta(480,170,20,3);
                *b3 = Beta(220,240,20,3);
                *b4 = Beta(480,240,20,3);
                *c = Gamma(340,360,30,2);
                *c2 = Gamma(340,60,30,2);
                enemy[0] = a;
                enemy[1] = a2;
                enemy[2] = a3;
                enemy[3] = a4;
                enemy[4] = b;
                enemy[5] = b2;
                enemy[6] = b3;
                enemy[7] = b4;
                enemy[8] = c;
                enemy[9] = c2;
                enemy[10] = a5;
                enemy[11] = a6;
                enemy[12] = a7;
                enemy[13] = a8;
                
                enemy[0]->set_sprite("img/enemy_1.png");
                enemy[1]->set_sprite("img/enemy_1.png");
                enemy[2]->set_sprite("img/enemy_1.png");
                enemy[3]->set_sprite("img/enemy_1.png");
                enemy[4]->set_sprite("img/enemy_2.png");
                enemy[5]->set_sprite("img/enemy_2.png");
                enemy[6]->set_sprite("img/enemy_2.png");
                enemy[7]->set_sprite("img/enemy_2.png");
                enemy[8]->set_sprite("img/enemy_3.png");
                 enemy[9]->set_sprite("img/enemy_3.png");
                 enemy[10]->set_sprite("img/enemy_1.png");
                enemy[11]->set_sprite("img/enemy_1.png");
                enemy[12]->set_sprite("img/enemy_1.png");
                enemy[13]->set_sprite("img/enemy_1.png");

                level_change2 = false;
           }
        }
        //en_counter = 0;
       
       
    }

    void Game::got_hit(Enemy**& enemy,int& en_counter,bool& change)
    {
        for(int h=0;h<en_num;h++)
        {
            if(enemy[h]->enmy.getPosition().y+30 > p->player_bullet->bull.getPosition().y && enemy[h]->enmy.getPosition().y < p->player_bullet->bull.getPosition().y && p->player_bullet->bull.getPosition().x > enemy[h]->enmy.getPosition().x && p->player_bullet->bull.getPosition().x < enemy[h]->enmy.getPosition().x+55)
            {
                enemy[h]->hit = true;
                en_counter++;
              //  p->player_bullet->bull.setPosition(p->sprite.getPosition().x,p->sprite.getPosition().y);
              if(fire_timer > 5)
               p->player_bullet->bull.setPosition(1000,-20);
                p->score += (level*enemy[h]->points);
                enemy[h]->enmy.setPosition(1000,1000);
            }
        }

        if(en_counter == en_num)
        {
           change = true;
        }
    } 

     void Game::got_hit2(Enemy**& enemy,int& en_counter,bool& change)
    {
        for(int mm=0;mm<7;mm++)
        for(int h=0;h<en_num;h++)
        {
            if(enemy[h]->enmy.getPosition().y+30 > p->p_bullet[mm]->bull.getPosition().y && enemy[h]->enmy.getPosition().y < p->p_bullet[mm]->bull.getPosition().y && p->p_bullet[mm]->bull.getPosition().x > enemy[h]->enmy.getPosition().x && p->p_bullet[mm]->bull.getPosition().x < enemy[h]->enmy.getPosition().x+55)
            {
                enemy[h]->hit = true;
                en_counter++;
              //  p->player_bullet->bull.setPosition(p->sprite.getPosition().x,p->sprite.getPosition().y);
               p->p_bullet[mm]->bull.setPosition(1000,-20);
                p->score += (level*enemy[h]->points);
                enemy[h]->enmy.setPosition(1000,1000);
            }
        }

        if(en_counter == en_num)
        {
           change = true;
        }
    } 

    void Game::player_got_hit(Player* &p, Enemy**& enemy)
    {
      for(int h=0;h<en_num;h++)
        if(enemy[h]->bomb_yes)
        {
           
            if((enemy[h]->bomb->bomb_sprite.getPosition().y > p->sprite.getGlobalBounds().top) &&(enemy[h]->bomb->bomb_sprite.getPosition().y < p->sprite.getPosition().y+100) && (enemy[h]->bomb->bomb_sprite.getPosition().x > p->sprite.getGlobalBounds().left) && (enemy[h]->bomb->bomb_sprite.getPosition().x < p->sprite.getGlobalBounds().left+p->sprite.getGlobalBounds().width))      
            {
                enemy[h]->bomb->bomb_sprite.setPosition(1000,1000);
                p->lives -= 1;
                if(p->lives == 2)
                {
                     lives_tex.loadFromFile("img/PNG/UI/numeral2.png");
                      l_ves.setTexture(lives_tex);
                }
                else if(p->lives == 1)
                {
                    lives_tex.loadFromFile("img/PNG/UI/numeral1.png");
                      l_ves.setTexture(lives_tex);
                }
            
                player_d = true;
                expo = true;
                expo_once =true;
                  expo_timer = 0;
               // p->sprite.setPosition(340,700);
            }
        }
   
        for(int h=0;h<en_num; h++)
        {
            if((enemy[h]->enmy.getGlobalBounds().left < p->sprite.getGlobalBounds().left + p->sprite.getGlobalBounds().width) && (enemy[h]->enmy.getGlobalBounds().left +enemy[h]->enmy.getGlobalBounds().width > p->sprite.getGlobalBounds().left) && (enemy[h]->enmy.getGlobalBounds().top + enemy[h]->enmy.getGlobalBounds().height > p->sprite.getGlobalBounds().top) && (enemy[h]->enmy.getGlobalBounds().top < p->sprite.getGlobalBounds().top + p->sprite.getGlobalBounds().height))
            {
                 p->lives -= 1;
                 if(p->lives == 2)
                {
                     lives_tex.loadFromFile("img/PNG/UI/numeral2.png");
                      l_ves.setTexture(lives_tex);
                }
                else if(p->lives == 1)
                {
                    lives_tex.loadFromFile("img/PNG/UI/numeral1.png");
                      l_ves.setTexture(lives_tex);
                }
                  expo = true;
                  expo_once =true;
                  expo_timer = 0;
                // p->sprite.setPosition(340,700);
            }
        }

        if(monster->bomb->bomb_sprite.getGlobalBounds().left < p->sprite.getGlobalBounds().left + p->sprite.getGlobalBounds().width && monster->bomb->bomb_sprite.getGlobalBounds().left + monster->bomb->bomb_sprite.getGlobalBounds().width > p->sprite.getGlobalBounds().left && monster->bomb->bomb_sprite.getGlobalBounds().top + monster->bomb->bomb_sprite.getGlobalBounds().height > p->sprite.getGlobalBounds().top)
        {
              p->lives -= 1;
                 if(p->lives == 2)
                {
                     lives_tex.loadFromFile("img/PNG/UI/numeral2.png");
                      l_ves.setTexture(lives_tex);
                }
                else if(p->lives == 1)
                {
                    lives_tex.loadFromFile("img/PNG/UI/numeral1.png");
                      l_ves.setTexture(lives_tex);
                }
                  expo = true;
                  expo_once =true;
                  expo_timer = 0;
                // p->sprite.setPosition(340,700);
        }

    }

    void Game::player_expo()
    {
        if(expo)
        {
            if(expo_timer < 0.5 && expo_once)
            {
                 p->expo_Sprite.setPosition(p->sprite.getPosition().x,p->sprite.getPosition().y);
                 expo_once = false;
            }
           
            if(expo_timer > 0.5)
            {
                expo = false;
                p->sprite.setPosition(340,700);
            }
        }
    }

    void Game::monster_hit()
    {
        if(monster->bomb_yes && mon_check)
          if(monster->bomb->bomb_sprite.getGlobalBounds().left < p->sprite.getGlobalBounds().left + p->sprite.getGlobalBounds().width && monster->bomb->bomb_sprite.getGlobalBounds().left + monster->bomb->bomb_sprite.getGlobalBounds().width > p->sprite.getGlobalBounds().left && monster->bomb->bomb_sprite.getGlobalBounds().top + monster->bomb->bomb_sprite.getGlobalBounds().height > p->sprite.getGlobalBounds().top)
        {
              p->lives -= 1;
                 if(p->lives == 2)
                {
                     lives_tex.loadFromFile("img/PNG/UI/numeral2.png");
                      l_ves.setTexture(lives_tex);
                }
                else if(p->lives == 1)
                {
                    lives_tex.loadFromFile("img/PNG/UI/numeral1.png");
                      l_ves.setTexture(lives_tex);
                }
                  expo = true;
                  expo_once =true;
                  expo_timer = 0;
                // p->sprite.setPosition(340,700);
        }

         if(dragon->bomb_yes && don_check)
          if(dragon->bomb->bomb_sprite.getGlobalBounds().left < p->sprite.getGlobalBounds().left + p->sprite.getGlobalBounds().width && dragon->bomb->bomb_sprite.getGlobalBounds().left + dragon->bomb->bomb_sprite.getGlobalBounds().width > p->sprite.getGlobalBounds().left && dragon->bomb->bomb_sprite.getGlobalBounds().top + dragon->bomb->bomb_sprite.getGlobalBounds().height > p->sprite.getGlobalBounds().top)
        {
              p->lives -= 1;
                 if(p->lives == 2)
                {
                     lives_tex.loadFromFile("img/PNG/UI/numeral2.png");
                      l_ves.setTexture(lives_tex);
                }
                else if(p->lives == 1)
                {
                    lives_tex.loadFromFile("img/PNG/UI/numeral1.png");
                      l_ves.setTexture(lives_tex);
                }
                  expo = true;
                  expo_once =true;
                  expo_timer = 0;
                // p->sprite.setPosition(20,700);
        }




    }

    void  Game::check_level(int& level,int& en,bool& level_change2,bool& change)
    {
     
      if(change)
        {
            l_counter++;
            if(l_counter > 3)
            { 
                level+=1; l_counter =1;
                if(level == 2)
                level_tex.loadFromFile("img/PNG/UI/numeral2.png");
                else if(level == 3)
                level_tex.loadFromFile("img/PNG/UI/numeral3.png");
                l_vel.setTexture(level_tex);
                anime = true;
                anime_once = true;
                anime_timer = 0;
            }
            level_change2 = true;
            en = 0;
            change = false;
        }
        if(level>3)
        level =3;
    
    }

    void Game::level_base(int &level, float &n)
    {
         if(level == 2)
         {
               for(int h=0;h<en_num;h++)
           {
            if(enemy[h]->bomb_yes)
            enemy[h]->bomb->speed = 0.25;
            n = 1.75;
            p->player_bullet->speed = 0.6;
           }
         }else if(level == 3)
         {
            for(int h=0;h<en_num;h++)
           {
            if(enemy[h]->bomb_yes)
            enemy[h]->bomb->speed = 0.30;
            n= 1.5;
            p->player_bullet->speed = 0.7;
           }
         }
    }

    void Game::level_animation()
    {
        if(anime)
        {
            {
                if(anime_once)
                {
                    anime_once = false;
                 g1->set_sprite("img/enemy_3.png");
                 g2->set_sprite("img/enemy_3.png");
                }
                g1->enmy.move(-0.5,0);
                g2->enmy.move(0.5,0);
                
            }
          if(g1->enmy.getGlobalBounds().left < g2->enmy.getGlobalBounds().left)
            {
                anime = false;
            }

        }
    }

     void Game::appearMonster(bool& mon_check)
     {
          if(level == 2 && l_counter == 1)
        {
             if(timer1_enemy > 25)
        {
            mon_check = true;
            monster->set_sprite("img/dragon.png");
            timer1_enemy = 0;
            en_y = false;
            if(p->sprite.getPosition().x <340)
            monster->enemy_number = 0;
            if(p->sprite.getPosition().x >340)
             monster->enemy_number = 1;
        }
        if(timer1_enemy > 8 && timer1_enemy < 25)
        {
            if(mon_check)
            {
                p->score += monster->points;
                monster->enmy.setPosition(1920,500);
                monster->bomb->bomb_sprite.setPosition(1920,500);
            }
            mon_check =false;
            en_y = true;
        }
        if(mon_check)
        {
            if(monster->bomb_timer < 1)
            monster->move();
            monster->fire(monster->bomb_timer,monster->bomb_yes);
           
        }
        }
    
     }

    void Game::create_addons(float &timer, bool &addon_yes)
    {
        //int randomNum = rand()%4;
        if(timer > 6)
        {
        addon_yes = true;
       
        float xx = rand()%760;
        // *add_life = Lives("img/PNG/Power-ups/pill_green.png",-30,340);
        p->addon_arr[0] = add_life;
        p->addon_arr[1] = add_power;
        p->addon_arr[2] = add_danger;
        p->addon_arr[3] = add_fire;
        
        *p->addon_arr[0] = Lives("img/PNG/Power-ups/pill_green.png",xx,-20);
        *p->addon_arr[1] = PowerUp("img/PNG/Power-ups/powerupGreen_bolt.png",xx,-30);
        *p->addon_arr[2] = Danger("img/PNG/Power-ups/pill_red.png",xx,-30);
        *p->addon_arr[3] = Fire("img/PNG/Power-ups/bolt_bronze.png",xx,-30);
       // addon_arr[randomNum]->addon_made = true;
       // addon_arr[0]->move();
        p->addon_arr[0]->set_sprite("img/PNG/Power-ups/pill_green.png");
       p->addon_arr[1]->set_sprite("img/PNG/Power-ups/powerupGreen_bolt.png");
       p->addon_arr[2]->set_sprite("img/PNG/Power-ups/pill_red.png");
       p->addon_arr[3]->set_sprite("img/PNG/Power-ups/bolt_bronze.png");
        timer = 0;
       // cout<<"nhi sunta "<<randomNum<<endl;
        }

    }

    void Game::get_addons(float& fire_timer,float& timer,float &powerup_timer)
    {
       for(int h=0; h<4;h++)
       {
        if(p->addon_arr[h]->addon.getGlobalBounds().top + p->addon_arr[h]->addon.getGlobalBounds().height > p->sprite.getGlobalBounds().top  && p->addon_arr[h]->addon.getGlobalBounds().left < p->sprite.getGlobalBounds().left + p->sprite.getGlobalBounds().width && p->addon_arr[h]->addon.getGlobalBounds().left + p->addon_arr[h]->addon.getGlobalBounds().width > p->sprite.getGlobalBounds().left)
        {
            if(h == 0)
            {
                if(p->lives<3)
                p->lives += 1;
                 if(p->lives == 2)
                {
                     lives_tex.loadFromFile("img/PNG/UI/numeral2.png");
                      l_ves.setTexture(lives_tex);
                }
                else if(p->lives == 1)
                {
                    lives_tex.loadFromFile("img/PNG/UI/numeral1.png");
                      l_ves.setTexture(lives_tex);
                }
                 else if(p->lives == 3)
                {
                    lives_tex.loadFromFile("img/PNG/UI/numeral3.png");
                      l_ves.setTexture(lives_tex);
                }
                p->addon_arr[h]->addon.setPosition(1080,1080);
            }
            else if(h == 2)
            {
                p->lives -= 1;
                 if(p->lives == 2)
                {
                     lives_tex.loadFromFile("img/PNG/UI/numeral2.png");
                      l_ves.setTexture(lives_tex);
                }
                else if(p->lives == 1)
                {
                    lives_tex.loadFromFile("img/PNG/UI/numeral1.png");
                      l_ves.setTexture(lives_tex);
                }
                else if(p->lives == 3)
                {
                    lives_tex.loadFromFile("img/PNG/UI/numeral3.png");
                      l_ves.setTexture(lives_tex);
                }
                p->addon_arr[h]->addon.setPosition(1080,-80);
            }
            else if(h == 3)
            {
                p->player_bullet->bull_tex.loadFromFile("img/PNG/Effects/fire16.png");
                p->player_bullet->bull.setTexture(p->player_bullet->bull_tex);
                p->player_bullet->bull.setScale(1.25,1.25);
                 p->addon_arr[h]->addon.setPosition(1080,1080);
                 fire_timer = 0;
                 
            }
            else if(h == 1)
            {
              
               // p->fire2(timer,fire_timer,powerup_fire);
               p->fire2(timer,powerup_timer,powerup_fire);
                p->addon_arr[h]->addon.setPosition(1080,1080);
                 
            }
        }
        else if(h == 2 && p->addon_arr[h]->addon.getPosition().y > 785)
        {
            p->score += 5;
             p->addon_arr[h]->addon.setPosition(1080,-80);
        }
       }
    }

    void Game::fire_dragon(float &i, bool &check)
    {   
        if(don2_timer > 1)
        {
            dragon->bomb_time = 2;
            if(i > dragon->bomb_time)
            {
                dragon->fire(i,check);
                if(p->sprite.getPosition().x > 260 && p->sprite.getPosition().x < 520)
                dragon->bomb->set_sprite("img/PNG/Effects/fire01.png",2,20);
                if(p->sprite.getPosition().x > 0 && p->sprite.getPosition().x < 260)
                {dragon->bomb->set_sprite("img/PNG/Effects/fire01.png",2,20);
                dragon->bomb->bomb_sprite.setRotation(20);}
                if(p->sprite.getPosition().x > 520 && p->sprite.getPosition().x < 780)
                 {dragon->bomb->set_sprite("img/PNG/Effects/fire01.png",2,20);
                dragon->bomb->bomb_sprite.setRotation(-15);} 
            }
              don2_timer = 0;
        }
            if(i> dragon->bomb_time+2)
            {
                i=0;
            }
            if(i< dragon->bomb_time)
            {
                dragon->bomb_yes = false;
            }
          
        
        
    }

    void Game::appeardragon(bool &don_check)
    {
         if(level == 3 && l_counter == 1)
        {
             if(don_timer > 35)
        {
            don_check = true;
            dragon->set_sprite("img/dragon.png");
            don_timer = 0;
            en_y = false;
        }
        if(don_timer > 10 && don_timer < 35)
        {
            if(don_check)
            {
                p->score += dragon->points;
                dragon->enmy.setPosition(1920,500);
                dragon->bomb->bomb_sprite.setPosition(1920,500);
            }
            don_check =false;
            en_y = true;
        }
        if(don_check)
        {
            if(dragon->bomb_timer < 1)
            dragon->move();
            fire_dragon(dragon->bomb_timer,dragon->bomb_yes);
            //dragon->fire(dragon->bomb_timer,dragon->bomb_yes);
           
        }
        }
    }

    void Game::game_over(std::string name)
    {
        this->filehandle(name);
        ////////////////////////////////////////////////////////////////////////////////////////////////////////
          Font font;
    font.loadFromFile("Debrosee-ALPnL.ttf");
    Font font2;
    font2.loadFromFile("JerseyM54.ttf");

    Text playtext;
    playtext.setFont(font);
    playtext.setFillColor(sf::Color::White);
    playtext.setString("Game Over");
    playtext.setCharacterSize(40);  
    playtext.setPosition(280.f, 680.f);

    Text playtext1;
    playtext1.setFont(font);
    playtext1.setFillColor(sf::Color::White);
    playtext1.setString("Score");
    playtext1.setCharacterSize(30);  
    playtext1.setPosition(290.f, 100.f); 
    Text playtext12;
    playtext12.setFont(font2);
    playtext12.setFillColor(sf::Color::White);
    playtext12.setString(to_string(p->score));
    playtext12.setCharacterSize(30);  
    playtext12.setPosition(390.f, 100.f);       
        ////////////////////////////////////////////////////////////////////////////////////////////////////////
         srand(time(0));
        RenderWindow window(VideoMode(780, 780), title);
        Clock clock;
        float timer=0;
        
        while (window.isOpen())
        {
            float time = clock.getElapsedTime().asSeconds(); 
            clock.restart();
            timer += time;  
            //cout<<time<<endl; 
        Event e;
            while (window.pollEvent(e))
            {  
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    window.close(); //close the game                        	    
            }
            
        if (Keyboard::isKeyPressed(Keyboard::Q)) //If left key is pressed
            { 
                window.close();   
            }
        
                
        

        window.clear(Color::Black); //clears the screen
        window.draw(GameOver);  // setting background
        window.draw(playtext);
        window.draw(playtext1);
        window.draw(playtext12);
        

        window.display();  //Displying all the sprites
        }
    }

    void Game::filehandle(std::string name)
    {

        ////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////
        //cout<<"\nEnter the Record to be Added.\n\n";

            fstream finsert("highscore.txt", ios::in|ios::app);
            fstream extra("extra.txt", ios_base::out|ios::app);

            if (finsert)
            {

                int found = 0;
                string in_name;
                int in_score=0;
                int count=0;

                while (getline(finsert, in_name) && finsert >> in_score)
                {
                    count +=1;
                    if (p->score >= in_score && found == 0)
                    {

                        extra << name << "\n";
                        extra << p->score << "\n";
                        extra << in_name << "\n";
                        extra << in_score << "\n";

                        cout << "\n";
                        //break;
                        found = 1;
                        count +=1;

                    }
                    else
                    {
                        extra << in_name << "\n";
                        extra << in_score << "\n";      
                    }

                    finsert.ignore();
                    // extra.ignore();
                }
                if(!found)
                {
                    extra << name<<"\n";
                    extra << p->score<<"\n";
                }
                finsert.close();
                extra.close();
                remove("highscore.txt");
                rename("extra.txt" , "highscore.txt");



               /* if (!found)
                {
                    cout << "No Record Found.\n";

                }
                else
                {
                    finsert.close();

                }*/
                }
            else
            {
                cout << "Error opening file.\n";

            }
    }

