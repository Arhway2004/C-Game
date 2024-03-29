//nothing vdo18
#ifndef MAINMENU_H
#define MAINMENU_H

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

        // void initKeybinds(); 
        Button quit_btn;
        Button start_btn;

        //should be enum
        // Base current_state; 

    public:
        MainMenu(sf::RenderWindow* window); 
        virtual ~MainMenu(); 

        // void updateInput(const float& dt, Button* btn) override;
        void endState() override; 
        void update(const float& dt, sf::RenderWindow* window) override; 
        void render(sf::RenderTarget* target = nullptr) override; 

}; 

#endif