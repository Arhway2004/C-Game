//nothing vdo18

#include "GameState.h"
#include "../UI/Button.h"

class MainMenu : public GameState{
    private:
        sf::RenderWindow* window; 
        bool isPressed; 

        sf::RectangleShape background; 
        sf::Font font; 

        //fn
        void initFont(); 
        // void initKeybinds(); for what 

        Button* main_menu_btn; 

    public:
        MainMenu(sf::RenderWindow* window); 
        virtual ~MainMenu(); 

        //temp
        void updateMouseTemp() override; 
        void updateInput(const float& dt) override;
        void endState() override; 
        // bool getQuit() const override; 
        // void checkForEnd() override;  
        void update(const float& dt) override; 
        void render(sf::RenderTarget* target = nullptr) override; 

}; 