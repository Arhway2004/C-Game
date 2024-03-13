//nothing vdo18
#ifndef MAINMENU_H
#define MAINMENU_H

#include "../../include/Game.h"
#include "../../include/GameState.h"
#include "../../UI/Button.h"
#include "../../UI/ClickableIcon.h"
#include "../Settings/Options.h"
#include "../Settings/Base.h"
#include "../../UI/Music.h"
#include "../Settings/Setting.h"

class MainMenu : public GameState{
    private:
        sf::RenderWindow* window;
        bool isPressed;

        sf::RectangleShape background;
        sf::Font font;

        Button quit_btn;
        Button start_btn;
        bool startPressed;  // To track if the start button was pressed once
        bool quitPressed;   // To track if the quit button was pressed once
        bool musicPlayed;   
        Setting* music;

    public:
        MainMenu(sf::RenderWindow* window); 
        virtual ~MainMenu(); 
        // bool startPressed = false;
        // quitPressed = false;
        // musicPlayed = false; 
        // void updateInput(const float& dt, Button* btn) override;
        void endState() override; 
        void update(const float& dt, sf::RenderWindow* window) override; 
        void render(sf::RenderTarget* target = nullptr) override; 

}; 

#endif