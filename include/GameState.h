#pragma once 

#include "../src/Config.h"
#include "../UI/Button.h"
#include "../UI/ClickableIcon.h"
#include "../Games/Settings/Options.h"
#include <memory>
#include "../Games/Settings/Guide.h"

//more general purpose than gamestate
class GameState{
    private:
        sf::RenderWindow* window; 
        std::vector<sf::Texture*> textures;

        ClickableIcon* option_icon;
        // Options* option_page; 
        bool showOption = false;
        // Guide* guide_page;

        std::unique_ptr<Options> option_page; 
        std::unique_ptr<Guide> guide_page;

        // bool isPressed; 
        // bool resume_isPressed;
        // bool restart_isPressed;
        // bool setting_isPressed;
        // bool guide_icon_isPressed;
        // bool quit_icon_isPressed;

    protected: 
        bool endNow; 
        
        sf::Text game_title; 
        sf::Vector2i mousePosScreen; 
        sf::Vector2i mousePosWindow; //track only mouse in Window frame
        sf::Vector2f mousePosView; 
        void initFont(sf::Font& font, std::string path); 

    public:
        GameState(sf::RenderWindow* window);
        virtual ~GameState();
    
        // virtual void enter() = 0;
        // virtual void endState() = 0;
        // virtual void updateInput(const float& dt, Button* btn) = 0; 
        virtual void updateMousePosition(); 
        virtual void setText(sf::Text& text, sf::Font& font, sf::Color msg_color, short size, short int pos_x, short int pos_y, std::string msg);

        // void transitiionTo(GameState* nextState); 

        virtual void endState() = 0;
        virtual bool getQuit() const;
        virtual void checkForEnd();
        virtual void update(const float& dt) = 0;  //pure virtual/ need to be defined a child class no implement(= 0) otherwise will crash
        virtual void render(sf::RenderTarget* target = nullptr) = 0; 
};
