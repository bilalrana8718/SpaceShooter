#ifndef MENU_H_
#define MENU_H_

#include "game.h"
#include "game.cpp"
#include "pch.h"

using namespace std;
class Menu{
public:
    Sprite m_menu,mainMenu,resumeMenu,ins_menu,hs_sprite;
    Texture m_tex,mainTex,resumeTex,ins_tex,hs_tex;

     Game g; 
//add menu attributes here

void loading_menu();
void main_menu();
void leaderboard();

Menu();
// {
// m_tex.loadFromFile("img/pxfuel(2).jpg");
// m_menu.setTexture(m_tex);
// m_menu.setScale(1,1);

// mainTex.loadFromFile("img/pxfuel(2).jpg");
// mainMenu.setTexture(mainTex);
// mainMenu.setScale(1,1);

// ins_tex.loadFromFile("img/instruction.png");
// ins_menu.setTexture(ins_tex);
// ins_menu.setScale(0.42,0.75);

// hs_tex.loadFromFile("img/hscore.png");
// hs_sprite.setTexture(hs_tex);
// hs_sprite.setScale(1.05,1.6);


// }

void display_menu();

// {
   
// //display menu screen here
//     loading_menu();
// }

};


// void Menu::loading_menu()
// {
//     bool space = false,ins = false,lead = false;

//     Font font;
//     font.loadFromFile("Debrosee-ALPnL.ttf");

//     Text playtext;
//     playtext.setFont(font);
//     playtext.setFillColor(sf::Color::White);
//     playtext.setString("Play Game");
//     playtext.setCharacterSize(30);  
//     playtext.setPosition(110.f, 540.f);  
//     Text instext;
//     instext.setFont(font);
//     instext.setFillColor(sf::Color::White);
//     instext.setString("Instructions");
//     instext.setCharacterSize(30);  
//     instext.setPosition(110.f, 590.f);  
//     Text leadtext;
//     leadtext.setFont(font);
//     leadtext.setFillColor(sf::Color::White);
//     leadtext.setString("Leaderboard");
//     leadtext.setCharacterSize(30);  
//     leadtext.setPosition(110.f, 640.f);  
//     Text exittext;
//     exittext.setFont(font);
//     exittext.setFillColor(sf::Color::White);
//     exittext.setString("Exit");
//     exittext.setCharacterSize(30);  
//     exittext.setPosition(110.f, 690.f);    

//      srand(time(0));
//     RenderWindow window(VideoMode(780, 780), title);
//     Clock clock;
//     float timer=0;
//     Music music;
//     music.openFromFile("music1.ogg");
    
//     while (window.isOpen())
//     {
//         float time = clock.getElapsedTime().asSeconds(); 
//         clock.restart();
//         timer += time;  
//         //cout<<time<<endl; 
//  	Event e;
//         while (window.pollEvent(e))
//         {  
//             if (e.type == Event::Closed) // If cross/close is clicked/pressed
//                 window.close(); //close the game   
//             if (e.type == Event::KeyPressed) //If left key is pressed
//             { 
//                 if(e.key.code == Keyboard::I)
//                 {
//                     if(!ins)
//                     ins = true;
//                     else
//                     ins =false;
//                     music.play();
//                 }
//                 if(e.key.code == Keyboard::Q)
//                 {
//                     window.close();
//                     music.play();
//                 }
//                 if(e.key.code == Keyboard::L)
//                 {
//                      if(!lead)
//                     lead = true;
//                     else
//                     lead =false;
//                      music.play();
//                 }
//             }

                     
	               	    
//         }
          
// 	if (Keyboard::isKeyPressed(Keyboard::P)) //If left key is pressed
//           { 
//              music.play();
//             window.close();  /// MAKE A BOOL
//             this->main_menu();
//           }
         

//     // /////////////////////////////////////////////////////////////////////
//     if(lead)
//     {
//         window.close();
//         this->leaderboard();    
//          music.play();
//     }
//     // ////////////////////////////////////////////////////////////////////
   
// 	window.clear(Color::Black); //clears the screen
// 	window.draw(m_menu);  // setting background
//         window.draw(playtext);
//         window.draw(instext);
//         window.draw(leadtext);
//         window.draw(exittext);
    
//     if(ins)
//     window.draw(ins_menu);
	
// 	window.display();  //Displying all the sprites

        
//     }
//      music.stop(); 
// }

// void Menu::main_menu()
// {
//     // /////////////////////////////////////////////////////
//     string username;

//     Font font;
//     font.loadFromFile("Debrosee-ALPnL.ttf");

//      Text usertext;
//     usertext.setFont(font);
//     usertext.setFillColor(sf::Color::White);
//     usertext.setString("Username : ");
//     usertext.setCharacterSize(30);  
//     usertext.setPosition(110.f, 600.f);  
//      Text username1;
//     username1.setFont(font);
//     username1.setCharacterSize(30);
//     username1.setPosition(250.f, 600.f);
//     username1.setFillColor(sf::Color::White);

//      Text playtext;
//     playtext.setFont(font);
//     playtext.setFillColor(sf::Color::White);
//     playtext.setString("Press Enter");
//     playtext.setCharacterSize(30);  
//     playtext.setPosition(300.f, 700.f); 

//      srand(time(0));
//     RenderWindow window(VideoMode(780, 780), title);
//     Clock clock;
//     float timer=0;

//     while (window.isOpen())
//     {
      
//  	Event e;
//         while (window.pollEvent(e))
//         {  
//             if (e.type == Event::Closed) // If cross/close is clicked/pressed
//                 window.close(); //close the game 

//                    if (e.type == sf::Event::TextEntered)
//                     {
//                         if (e.text.unicode < 128)
//                         {
//                             if (e.text.unicode == '\b' && !username.empty())
//                             {
//                                 username.pop_back();
//                             }
//                             else if (e.text.unicode != '\b')
//                             {
//                                 username += static_cast<char>(e.text.unicode);
//                             }
//                         }

//                         username1.setString(username);
//                     }                	    
//         }
          
// 	if (Keyboard::isKeyPressed(Keyboard::Enter)) //If left key is pressed
//           { 
//             g.playername = username;
//             window.close();  /// MAKE A BOOL
//             g.start_game();
//           }
//           if (Keyboard::isKeyPressed(Keyboard::Q)) //If left key is pressed
//           { 
//             window.close();  /// MAKE A BOOL
//           }
// 	window.clear(Color::White); //clears the screen
// 	window.draw(m_menu);  // setting background
//        window.draw(username1);
//         window.draw(usertext);
//         window.draw(playtext);
 
	
// 	window.display();  //Displying all the sprites
//     }
// }

// void Menu::leaderboard()
// {
//     Sprite gold,silver,bronze;
//     Texture gtex,stex,btex;

//     gtex.loadFromFile("img/PNG/Power-ups/shield_gold.png");
//     stex.loadFromFile("img/PNG/Power-ups/shield_silver.png");
//     btex.loadFromFile("img/PNG/Power-ups/shield_bronze.png");
//     gold.setTexture(gtex);
//     silver.setTexture(stex);
//     bronze.setTexture(btex);
//     gold.setPosition(250.f,263.f);
//     silver.setPosition(250.f,363.f);
//     bronze.setPosition(250.f,463.f);


//     string* ptr = new string[3];
//     int* score_ptr = new int[3];

//     Font font;
//     font.loadFromFile("Amatic-Bold.ttf");
    
//     Text text1,text2,text3,integer1,integer2,integer3;
//     text1.setFont(font);
//     text2.setFont(font);
//     text3.setFont(font);
//     integer1.setFont(font);
//     integer2.setFont(font);
//     integer3.setFont(font);

//     text1.setFillColor(sf::Color::Red);
//     text2.setFillColor(sf::Color::Red);
//     text3.setFillColor(sf::Color::Red);
//     integer1.setFillColor(sf::Color::Red);
//     integer2.setFillColor(sf::Color::Red);
//     integer3.setFillColor(sf::Color::Red);

//     // /////////////////////////////////////////////////////
//      fstream finsert("highscore.txt", ios::in|ios::app);

//             if (finsert)
//             {

//                 int found = 0;
//                 string in_name;
//                 int in_score=0;
//                 int count=0;

//                 while (getline(finsert, in_name) && finsert >> in_score && count<3)
//                 {
                    
//                     ptr[count] = in_name;
//                     score_ptr[count] = in_score;
//                     count +=1;
//                     finsert.ignore();
//                     // extra.ignore();
//                 }
               
//                 finsert.close();
               
//             }
//     // /////////////////////////////////////////////////////
//     text1.setString(ptr[0]);
//     text2.setString(ptr[1]);
//     text3.setString(ptr[2]);
//     integer1.setString(to_string(score_ptr[0]));
//     integer2.setString(to_string(score_ptr[1]));
//     integer3.setString(to_string(score_ptr[2]));

//     text1.setCharacterSize(40);        			  
//     text1.setPosition(300.f, 250.f);
//     text2.setCharacterSize(40);        			  
//     text2.setPosition(300.f, 350.f);
//     text3.setCharacterSize(40);        			  
//     text3.setPosition(300.f, 450.f);
//     integer1.setCharacterSize(40);        			  
//     integer1.setPosition(420.f, 250.f);
//     integer2.setCharacterSize(40);        			  
//     integer2.setPosition(420.f, 350.f);
//     integer3.setCharacterSize(40);        			  
//     integer3.setPosition(420.f, 450.f);
    
//     // /////////////////////////////////////////////////////
//     string username;
//      srand(time(0));
//     RenderWindow window(VideoMode(780, 780), title);
//     Clock clock;
//     float timer=0;

//     while (window.isOpen())
//     {
      
//  	Event e;
//         while (window.pollEvent(e))
//         {  
//             if (e.type == Event::Closed) // If cross/close is clicked/pressed
//                 window.close(); //close the game             	    
//         }
          
// 	if (Keyboard::isKeyPressed(Keyboard::L)) //If left key is pressed
//           { 
//              window.close();
//              this->loading_menu(); 
//           }
// 	window.clear(Color::White); //clears the screen
// 	window.draw(hs_sprite);  // setting background
    
//     window.draw(text1);
//     window.draw(text2);
//     window.draw(text3);
//     window.draw(integer1);
//     window.draw(integer2);
//     window.draw(integer3);

//     window.draw(gold);
//     window.draw(silver);
//     window.draw(bronze);
	
// 	window.display();  //Displying all the sprites
//     }
// }

 #endif /* MENU_H_ */