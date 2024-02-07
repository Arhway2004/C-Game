#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <string>

enum button_states{
    IDLE = 0, 
    HOVER = 1, 
    PRESSED = 2
}; 

class Button{
    private: 
        // sf::RenderWindow* window; 
        short unsigned buttonStates; 

        sf::RectangleShape shape; 
        sf::Font* font; 
        sf::Text text; 
        bool pressed; 
        bool hover; 

        sf::Color idleColor; 
        sf::Color hoverColor; 
        sf::Color activeColor; 

    public: 
        Button(float x=0.0, float y=0.0, float width=0.0 , float height=0.0, sf::Font* font = nullptr, std::string text = "text"); 
        ~Button(); 

        //accessor
        const bool isPressed() const; 

        void update(const sf::Vector2f mousePos); 
        void render(sf::RenderTarget* target); 
};