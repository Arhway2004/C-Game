#pragma once
#include "../src/Config.h"

class InventoryPanel{
    private: 
        sf::Vector2f position;
        sf::Sprite inventoryPanel;
        sf::Texture inventoryPanelTex; 
        sf::Vector2f selectedSquarePos;
        sf::RectangleShape selectedSquare;
        
        //add text to show score
        sf::Text text;
        sf::Font font;

        //inventories item
        sf::Sprite bomb; 
        sf::Texture bombTex;
        sf::Sprite sniper;
        sf::Texture sniperTex;
        sf::Sprite healer;
        sf::Texture healerTex;
        int clicked = 0; 

        //time delay
        sf::Clock pressCooldownTimer;
        sf::Time pressCooldownDuration;

    public: 
        enum currentItem{
            Bomb = 0, 
            Sniper = 1, 
            Healer = 2
        };
        currentItem currentItemSelected;

        InventoryPanel(float pos_x, float pos_y, float scale_x, float scale_y);
        virtual ~InventoryPanel();
        void setPosition(float x, float y);
        short getcurrentItemSelected() const;
        void loadTextures(sf::Texture& texture, std::string path); 
        bool canPress() const;
        void resetPressCooldown(); 

        void update(int killCount);
        void updateInput();
        void updateCurrentItem(); 
        void updateFramePosition();
        void render(sf::RenderTarget* target);
};