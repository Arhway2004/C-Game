
#include "../../include/GameState.h"
#include "../../src/Config.h"
#include "../Entities/Player.h"

class Level1: public GameState{
    private:
        sf::RenderWindow* window; 

        //temp
        sf::RectangleShape background;
        sf::Texture bgTex;
        sf::Sprite bg;  
        Player player; 


    public: 
        Level1(sf::RenderWindow* window); 
        virtual ~Level1(); 
        void endState() override; 
        // void loadTextures(sf::Texture& tex);
        void loadTextures(sf::Texture& tex, std::string path);
        void updateInput(const float& dt) override;
        void update(const float& dt, sf::RenderWindow* window) override; 
        void render(sf::RenderTarget* target = nullptr) override;
}; 