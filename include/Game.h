#pragma once 
#include "GameState.h"
#include <iostream>
#include "../Games/Scenes/MainMenu.h"
#include "../Games/Scenes/Basement.h"

class Game{
    private: 
        sf::RenderWindow* window;

        sf::Clock dtClock;
        float dt; //Synchonize graphics for every computer 

        //resources
        sf::Font font;
        std::stack<GameState*> states;
        
        //init
        void initWindow(); 
        void initVariables(); 
        void initStates(); 

    public:
        //scenes

        Game(); 
        virtual ~Game(); 

        void run(); 
        void update(); 
        void updateDt(); 
        void add_scene(GameState* scene); 
        void updateGUI(); //update fonts, score display etc
        void render(); 
        void endApplication(); 
};
