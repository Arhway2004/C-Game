#pragma once
#include "../../src/Config.h"

class Base{
    private: 
        sf::Font font; 

    protected: 
        int frame_pos_x, frame_pos_y;

        sf::Text title; 
        sf::RenderWindow* window; 
        sf::Sprite* frame; 
        sf::Texture* frame_texture;
        sf::Sprite* close_icon; 
        sf::Texture* close_texture;

        bool quit = false;
        sf::Vector2f mousePosView; 
    
    public:
        // Base(int pos_x, int pos_y, int scale_x, int scale_y, std::string title, std::string path); 
        Base(std::string title, int pos_x, int pos_y, float scale_x, float scale_y); 

        virtual ~Base();
        void set_up_sprite( int pos_x, int pos_y, float scale_x, float scale_y, sf::Sprite*& sprite, sf::Texture* tex, std::string path);
        void closeWindow();

        //add
        void initBaseFont(sf::Font& font, std::string path);
        void setBaseText(sf::Text& text, sf::Font& font, std::string msg, sf::Color msg_color, short size, float pos_x, float pos_y);
        void initFont(sf::Font& font, std::string path);
        void setText(sf::Text& text, sf::Font& font, std::string msg, sf::Color msg_color, short size, short int pos_x, short int pos_y);
        // void endState();
        // void update(const float& dt);
        void update(const sf::Vector2f mousePos);  

        void render(sf::RenderTarget* target = nullptr);
}; 