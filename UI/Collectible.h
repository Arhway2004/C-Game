#pragma once 
#include "../src/Config.h"
#include "../src/Constant.h"
#include "../Games/Entities/Player.h"

class Collectible{

    private: 
        sf::Sprite collectible;
        std::shared_ptr<sf::Texture> collectibleTex;

    public:
        sf::Vector2f position;
        bool isCollected;

        Collectible(float pos_x = 200.f, float pos_y = 200.f, float scale_x = 0.07f, float scale_y = 0.07f, std::string path = "../assets/textures/ice.png");
        virtual ~Collectible();
        bool isCollectedByPlayer(Player& player);
        void render(sf::RenderTarget* target);
        
};