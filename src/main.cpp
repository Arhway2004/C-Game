#include <time.h>
#include <stdlib.h>
#include "../include/Game.h"
// #include "../src/Config.h"

int main()
{
    srand(time(static_cast<unsigned>(0)));
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
// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(960, 540),"Bouncing mushroom.");

//     sf::Texture mushroomTexture;
//     mushroomTexture.loadFromFile("../assets/textures/gun_r.png");
//     sf::Sprite mushroom(mushroomTexture);
//     mushroom.setPosition(300, 300);
//     mushroom.setScale(2.f, 2.f);
//     sf::Vector2u size = mushroomTexture.getSize();
//     // mushroom.setOrigin(0.f, 0.f);

//     sf::Texture playerTex;
//     playerTex.loadFromFile("../assets/textures/right_idle2.png");
//     sf::Sprite player(playerTex);
//     player.setScale(2.f, 2.f);
//     sf::Vector2u size2 = playerTex.getSize();
//     player.setOrigin(playerTex.getSize().x/2, playerTex.getSize().y/2);
//     player.setPosition(300, 300);

//     sf::CircleShape circle(10.f); // Radius of the circle
//     circle.setFillColor(sf::Color::Red);
//     circle.setPosition(300.f, 300.f);

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
//         sf::Vector2f mousePosView = window.mapPixelToCoords(sf::Mouse::getPosition(window));
//         float angle = -1 * std::atan2(mousePosView.y - mushroom.getPosition().y , (mushroom.getPosition().x + size.x) - mousePosView.x); 
//         angle = angle * 180.f / static_cast<float>(M_PI); 
//         mushroom.setRotation(angle + 180);

//         window.clear(sf::Color(16, 16, 16, 255)); // Dark gray.
//         window.draw(player);                 // Drawing our sprite.
//         window.draw(mushroom);                  // Drawing our sprite.
//         window.draw(circle);
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