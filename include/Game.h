// #pragma once
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "GameState.h"
#include "../Games/Scenes/MainMenu.h"
#include "../Games/Scenes/Basement.h"
#include "../Games/Scenes/FirstScenes.h"
#include "../Games/Scenes/Level1.h"
#include "../Games/Entities/Player.h"
#include "../Games/Scenes/WinScene.h"

// global

class Game
{
private:
    sf::RenderWindow *window;

    sf::Clock dtClock;
    float dt; // Synchonize graphics for every computer

    // resources
    sf::Font font;
    std::stack<GameState *> states;

    // init
    void initWindow();
    void initVariables();
    void initStates();

    std::shared_ptr<Player> player;

public:
    // scenes

    Game();
    virtual ~Game();

    void run();
    void update();
    void updateDt();
    void add_scene(GameState *scene);
    void updateGUI(); // update fonts, score display etc
    void render();
    void endApplication();
};

#endif