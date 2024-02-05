//nothing vdo18

#include "GameState.h"

class MainMenu : public GameState{
    private:
        sf::RenderWindow* window; 
        bool isPressed; 
    public:
        MainMenu(sf::RenderWindow* window); 
        virtual ~MainMenu(); 


        void updateInput(const float& dt) override;
        void endState() override; 
        // bool getQuit() const override; 
        // void checkForEnd() override;  
        void update(const float& dt) override; 
        void render(sf::RenderTarget* target = nullptr) override; 

};