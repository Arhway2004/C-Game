#include <time.h>
#include <stdlib.h>
#include "../include/Game.h"
#include "../src/Config.h"

int main()
{
    // srand(time(static_cast<unsigned>(0)));
    srand(static_cast<unsigned>(time(nullptr)));
    Game game;
    game.run();
    return 0;
}

// int main(){
//     // Declare and load a font
//     sf::RenderWindow window(sf::VideoMode(960, 540),"Bouncing mushroom.");
//     sf::Font font;
//     if (!font.loadFromFile("../assets/font/BACKTO1982.TTF")) {
//         std::cout << "Failed to load font." << std::endl;
//         return 1;
//     }   
    
//     // Create a text
//     sf::Text text("hello", font);
//     text.setCharacterSize(30);
//     text.setStyle(sf::Text::Bold);
//     text.setFillColor(sf::Color::Red);
//     text.setPosition(100, 100);
    
//     // Draw it
//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//             {
//                 window.close();
//             }
//         }

//         window.clear(sf::Color(16, 16, 16, 255)); // Dark gray.
//         window.draw(text);                 // Drawing our sprite.
//         window.display();
//     }
//     return 0; 
// }


// this->loadFile(this->gunTexture, "../assets/textures/gun_r.png");
//     this->gunSprite.setTexture(this->gunTexture);
//     this->gunSprite.setPosition(this->testSprite.getPosition().x, this->testSprite.getPosition().y);
//     this->gunSprite.setScale(2.f, 2.f);
//     this->gunSprite.setOrigin(this->gunTexture.getSize().x / 2.f, this->gunTexture.getSize().y / 2.f);


//test sprite
// void initFont(int pos_x, int pos_y, sf::Text& text, sf::Font& font, std::string msg, short size, std::string path){
//     if(!font.loadFromFile(path)){
//         std::cout << "Failed to load font." << std::endl;
//     }
//     text.setFont(font);
//     text.setString(msg);
//     text.setCharacterSize(size);
//     text.setFillColor(sf::Color::Black);
//     text.setPosition(pos_x, pos_y);
// }

// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(1060, 740), "Bouncing mushroom.");

//     sf::Texture mushroomTexture;
//     mushroomTexture.loadFromFile("../assets/textures/inventories.png");
//     sf::Sprite mushroom(mushroomTexture);
//     mushroom.setPosition(30, 550); // Adjusted position
//     mushroom.setScale(1.5f, 1.5f);

//     sf::Font font; 
//     sf::Text text; 
//     // if(!font.loadFromFile("../assets/font/Blomberg-8MKKZ.ttf")){
//     //     std::cout << "Failed to load font." << std::endl;
//     //     return 1;
//     // }
//     // text.setFont(font);
//     // text.setString(std::to_string(5));
//     // text.setCharacterSize(30);
//     // text.setFillColor(sf::Color::Black);
//     // text.setPosition(180, 660);
//     initFont(180, 660, text, font, std::to_string(8), 30, "../assets/font/Blomberg-8MKKZ.ttf");

//     sf::RectangleShape frame;
//     frame.setSize(sf::Vector2f(79, 65));
//     frame.setFillColor(sf::Color(255, 255, 255, 120)); // Set alpha value for transparency
//     frame.setPosition(275, 632); // Adjusted position


//     sf::RectangleShape frame2;
//     frame2.setSize(sf::Vector2f(79, 65));
//     frame2.setFillColor(sf::Color(255, 255, 255, 120)); // Set alpha value for transparency
//     frame2.setPosition(275 + 112, 632);

//     sf::RectangleShape frame3;
//     frame3.setSize(sf::Vector2f(79, 65));
//     frame3.setFillColor(sf::Color(255, 255, 255, 120)); // Set alpha value for transparency
//     frame3.setPosition(275 + 112 + 112, 632);

//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//             {
//                 window.close();
//             }
//         }

//         window.clear(sf::Color(16, 16, 16, 255)); // Dark gray.
//         window.draw(mushroom);
//         window.draw(frame);
//         window.draw(frame2);
//         window.draw(frame3);
//         window.draw(text);
//         window.display();
//     }

//     return 0;
// }


//test ui
// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(960, 540),"Bouncing mushroom.");

//     sf::RectangleShape frame;
//     sf::RectangleShape blood;
//     frame.setSize(sf::Vector2f(77, 8));
//     frame.setFillColor(sf::Color::Transparent);
//     frame.setOutlineColor(sf::Color::White);
//     frame.setOutlineThickness(1.0f);
//     frame.setPosition(300, 300);

//     blood.setSize(sf::Vector2f(74, 5));
//     blood.setFillColor(sf::Color::Red);
//     blood.setOutlineColor(sf::Color::Red);
//     // frame.setOutlineThickness(1.0f);
//     blood.setPosition(302, 302);
//     blood.setSize(sf::Vector2f(50, 5));

//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//             {
//                 window.close();
//             }
//         }
//         // sf::Vector2f mousePosView = window.mapPixelToCoords(sf::Mouse::getPosition(window));
//         window.clear(sf::Color(16, 16, 16, 255)); // Dark gray.
//         window.draw(frame);
//         window.draw(blood);
//         window.display();
//     }
//     return 0; 
// }