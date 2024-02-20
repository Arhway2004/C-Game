#include "../../include/Gamestate.h"


class Basement : public GameState{
    private: 
    
        sf::RenderWindow* window; 
        sf::RectangleShape background; 
        sf::Font font; 

        //fn
        // void initKeybinds(); for what
        
    public: 
        Basement(sf::RenderWindow* window); 
        virtual ~Basement(); 
        
        // void updateInput(const float& dt, Button* btn) override;
        void endState() override; 
        void update(const float& dt) override; 
        void render(sf::RenderTarget* target = nullptr) override;
};