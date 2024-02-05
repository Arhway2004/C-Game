#pragma once 
#include <vector>
#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

//more general purpose than gamestate
class GameState{
    private:
        sf::RenderWindow* window; 
        std::vector<sf::Texture*> textures;
        bool endNow; 

    public:
        GameState(sf::RenderWindow* window);
        virtual ~GameState();
    
        // virtual void enter() = 0; 
        // virtual void endState() = 0; 
        virtual void updateInput(const float& dt) = 0; 
        // void transitiionTo(GameState* nextState); 

        virtual void endState() = 0; 
        virtual bool getQuit() const; 
        virtual void checkForEnd(); 
        virtual void update(const float& dt) = 0;  //pure virtual/ need to be defined a child class no implement(= 0) otherwise will crash
        virtual void render(sf::RenderTarget* target = nullptr) = 0; 
};
