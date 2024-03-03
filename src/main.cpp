#include <time.h>
#include <stdlib.h>
#include "../include/Game.h"

int main()
{
    srand(time_t(static_cast<unsigned>(0)));
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


// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(960, 540),"Bouncing mushroom.");

//     sf::Texture mushroomTexture;
//     mushroomTexture.loadFromFile("../assets/icons/restart2.png");
//     sf::Sprite mushroom(mushroomTexture);
//     sf::Vector2u size = mushroomTexture.getSize();
//     mushroom.setPosition(100, 20);
//     mushroom.setScale(0.3, 0.3);

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
//         window.draw(mushroom);                    // Drawing our sprite.
//         window.display();
//     }
//     return 0; 
// }