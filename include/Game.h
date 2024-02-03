#pragma once 
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <map>
#include <string>

class Game{
    private: 
        sf::RenderWindow* window; 

        //resources
        sf::Font font; 

        //init
        void initWindow(); 
        void initVariables(); 
        void initSystem(); 

    public: 
        Game(); 
        virtual ~Game(); 

        void run(); 
        void update(); 
        void updateGUI(); //update fonts, score display etc
        void render(); 
};
