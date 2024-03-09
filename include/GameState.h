#pragma once 

#include "../src/Config.h"
#include "../UI/Button.h"
#include "../UI/ClickableIcon.h"
#include "../Games/Settings/Options.h"
#include <memory>
#include "../Games/Settings/Guide.h"
#include "../Games/Settings/Setting.h"


// #include "../Games/Entities/Entity.h"
//more general purpose than gamestate
class GameState{
    private:
        sf::RenderWindow* window; 
        std::vector<sf::Texture*> textures;

        ClickableIcon option_icon;
        std::shared_ptr<Options> option_page; 
        std::shared_ptr<Guide> guide_page;
        std::shared_ptr<Setting> setting_page;

        // Entity player; 


    protected: 
        bool showOption;
        bool showGuide;
        bool showSetting;
        bool endNow;
        bool clicked_icon; 

        // click for setting
        bool plus1click;
        bool plus2click;
        bool delete1click;
        bool delete2click;


        sf::Text game_title;
        sf::Vector2i mousePosScreen;
        sf::Vector2i mousePosWindow; //track only mouse in Window frame
        sf::Vector2f mousePosView; 
        void initFont(sf::Font& font, std::string path); 
        void updateOptions(); 

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
        virtual void update(const float& dt, sf::RenderWindow* window) = 0;  //pure virtual/ need to be defined a child class no implement(= 0) otherwise will crash
        virtual void render(sf::RenderTarget* target = nullptr) = 0; 
};
