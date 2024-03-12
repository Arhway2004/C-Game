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
        sf::Text scoreText;
        sf::Font scoreFont;
        sf::Text iceText;
        sf::Font iceFont;

        //inventories item
        sf::Sprite ice; 
        sf::Texture iceTex;
        sf::Sprite bullet1;
        sf::Texture bullet1Tex;
        sf::Sprite healer;
        sf::Texture healerTex;
        int clicked = 0; 

        //time delay
        sf::Clock pressCooldownTimer;
        sf::Time pressCooldownDuration;

    public: 
        enum currentItem{
            Bullet1 = 0, 
            Ice = 1, 
            Healer = 2
        };
        currentItem currentItemSelected;

        InventoryPanel(float pos_x, float pos_y, float scale_x, float scale_y);
        virtual ~InventoryPanel();
        void setPosition(float x, float y);
        short getcurrentItemSelected() const;
        void loadTextures(sf::Texture& texture, std::string path); 
        void initFont(int pos_x, int pos_y, sf::Text& text, sf::Font& font, std::string msg, short size, std::string path); 
        bool canPress() const;
        void resetPressCooldown(); 

        void update(int killCount, int iceCount);
        void updateInput();
        void updateCurrentItem(); 
        void updateFramePosition();
        void render(sf::RenderTarget* target);
};