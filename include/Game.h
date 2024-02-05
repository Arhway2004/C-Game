#pragma once 
#include "GameState.h"
#include <iostream>
#include "MainMenu.h"

class Game{
    private: 
        sf::RenderWindow* window;

        sf::Clock dtClock;
        float dt; //Synchonize graphics for every computer 
        std::stack<GameState*> states; //scenes
        //resources
        sf::Font font;

        //init
        void initWindow(); 
        void initVariables(); 
        void initStates(); 

    public:
        Game(); 
        virtual ~Game(); 

        void run(); 
        void update(); 
        void updateDt(); 
        void updateGUI(); //update fonts, score display etc
        void render(); 
        void endApplication(); 
};
