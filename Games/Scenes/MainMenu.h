//nothing vdo18
#pragma once 
#include "../../include/Game.h"
#include "../../include/GameState.h"
#include "../../UI/Button.h"
#include "../../UI/ClickableIcon.h"
#include "../Settings/Options.h"
#include "../Settings/Base.h"

class MainMenu : public GameState{
    private:
        sf::RenderWindow* window;
        bool isPressed;

        sf::RectangleShape background;
        sf::Font font;

        // void initKeybinds(); for what
        Button* quit_btn;
        Button* start_btn;

        //should be enum
        // Base current_state; 

    public:
        MainMenu(sf::RenderWindow* window); 
        virtual ~MainMenu(); 

        // void updateInput(const float& dt, Button* btn) override;
        void endState() override; 
        void update(const float& dt) override; 
        void render(sf::RenderTarget* target = nullptr) override; 

}; 