#pragma once
#include "Base.h"
#include "../../UI/ClickableIcon.h"
#include "../../UI/Message.h"
#include "/Users/arhway/Desktop/Final/C-Game/UI/Music.h"
#include "Guide.h"



class Setting: public Base{
    private:

        sf::RenderWindow* window;
        sf::RectangleShape background;
        sf::RectangleShape Musicslide;
        sf::RectangleShape SFXslide;
        sf::RectangleShape Musicpoint;
        sf::RectangleShape SFXpoint;
        // sf:;Rectangle slide
        sf::Texture bg_t;
        sf::Texture Musicslide_texture; 
        sf::Texture SFXslide_texture;   
        sf::Texture Musicpoint_texture; 
        sf::Texture SFXpoint_texture;  

        ClickableIcon* plus1;
        ClickableIcon* delete1;

        ClickableIcon* plus2;
        ClickableIcon* delete2;

        ClickableIcon* plusSFX;

        sf::RectangleShape Textbox;
        Message* text;
        Message* MUSIC;
        Message* SFX;
        Message* RESOLUTION;
        Music& music;//need to use refre if want to use inheritance to cpp file


    public:
        Setting();
        virtual ~Setting();
        bool return_quit();
        void reset_quit();
        void update(const sf::Vector2f mousePos);
        void render_setting(sf::RenderTarget* target = nullptr);

        int Mpos = 535;// I not sure it need to use virtual or not
        int Spos = 535;
        int sound = 25;
        // int MUSIC = 0;
        // int SFX = 0;


};

// #pragma once 
// #include "Base.h"
// #include "../../UI/ClickableIcon.h"
// #include "/Users/arhway/Desktop/Arhway/C-Game/UI/Message.h"
// // #include "/Users/arhway/Desktop/Arhway/C-Game/Games/Settings/Base.h"

// class Setting : public Base{
// private: 
//     sf::RenderWindow* window;
//     sf::RectangleShape background;
//     sf::RectangleShape Musicslide;
//     sf::RectangleShape SFXslide;
//     sf::RectangleShape Musicpoint;
//     sf::RectangleShape SFXpoint;
//     // sf:;Rectangle slide
//     sf::Texture bg_t;
//     sf::Texture Musicslide_texture; 
//     sf::Texture SFXslide_texture;   
//     sf::Texture Musicpoint_texture; 
//     sf::Texture SFXpoint_texture;  
    
//     ClickableIcon* plus1;
//     ClickableIcon* delete1;
//     ClickableIcon* plus2;
//     ClickableIcon* delete2;

//     sf::RectangleShape Textbox;
//     // Message* text;
//     Message* MUSIC;
//     Message* SFX;
//     Message* RESOLUTION;






//     // Base* base;

// public: 
//     Setting();
//     virtual ~Setting(); 
//     void set_up_sprite( int pos_x, int pos_y, float scale_x, float scale_y, sf::Sprite*& sprite, sf::Texture* tex, std::string path);

//     // void reset_quit(); 
//     // void update(const sf::Vector2f mousePos);
//     void update(const float& dt);
//     // void update(const float& dt,const sf::Vector2f& mousePos);
//     void render_setting(sf::RenderTarget* target = nullptr);
// };
