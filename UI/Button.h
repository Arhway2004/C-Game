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
        Button(float x, float y, float width, float height, sf::Font* font, std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor); 
        ~Button(); 

        //accessor
        const bool isPressed() const; 

        void update(const sf::Vector2f mousePos); 
        void render(sf::RenderTarget* target); 
};