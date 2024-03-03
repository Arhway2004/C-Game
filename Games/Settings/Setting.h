// #ifndef OPTIONS_H
// #define OPTIONS_H

// #include "Base.h"
// #include "../../UI/ClickableIcon.h"
// #include "/Users/arhway/Desktop/Arhway/C-Game/UI/Message.h"
// // #include "Guide.h"
// // #include "Setting.h"

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

// public:
//         // ClickableIcon guide_icon; 
//         // bool show_base;
//         // bool show_resume; = false; 
//         // bool show_restart = false;
//         // bool show_setting = false;
//         // bool show_guide = false;
//         // bool show_quit;

//         // Options(int pos_x = 0, int pos_y = 0, int scale_x = 1.0, int scale_y = 1.0, std::string title = "Options", std::string path = "../../assets/textures/base.png"); 
//     Setting();
//     virtual ~Setting(); 
//     void reset_quit();

//         // void update(const float& dt); 
//     void update(const sf::Vector2f mousePos);
//     void render_setting(sf::RenderTarget* target = nullptr);
//     bool return_quit(); 
//         //is button clicked 

// }; 

// #endif

// #pragma once 
// #include "Base.h"
// #include "../../UI/ClickableIcon.h"

// class Setting : public Base{
//     private: 
//         // ClickableIcon* resume_icon; 
//         // ClickableIcon* restart_icon; 
//         // ClickableIcon* setting_icon; 
//         // ClickableIcon* guide_icon; 
//         // ClickableIcon* quit_icon; 
//         sf::RectangleShape* background;
//         sf::Texture* bg_t;
//         sf::RectangleShape* Music, SFX;
//         sf::Texture* Music_texture, SFX_texture;    
//         ClickableIcon* plus_;
//         ClickableIcon* delete_;


//     public: 
//         // Options(int pos_x = 0, int pos_y = 0, int scale_x = 1.0, int scale_y = 1.0, std::string title = "Options", std::string path = "../../assets/textures/base.png"); 
//         Setting();
//         virtual ~Setting(); 
//         void reset_quit(); 

//         // void endState() override; 
//         // void update(const float& dt); 
//         void update(const sf::Vector2f mousePos);
//         void render_Setting(sf::RenderTarget* target = nullptr);

//         //is button clicked 

// }; 

#pragma once 
#include "Base.h"
#include "../../UI/ClickableIcon.h"
#include "/Users/arhway/Desktop/Git/C-Game/UI/Message.h"
#include "./Music.h"
// #include "/Users/arhway/Desktop/Arhway/C-Game/Games/Settings/Base.h"

class Setting : public Base{
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

    sf::RectangleShape Textbox;
    // Message* text;
    Message* MUSIC;
    Message* SFX;
    Message* RESOLUTION;

    Music& music;//need to use refre if want to use inheritance to cpp file
    Music& sfx;

//    int MUSIC;
//    int SFX;
//    int delete1ClickCount;
//    int delete2ClickCount;







    // Base* base;

public: 
    Setting();
    virtual ~Setting(); 
    bool return_quit();
    void reset_quit();
    int Mpos = 555;// I not sure it need to use virtual or not
    int Spos = 555;

    // void reset_quit(); 
    // void update(const sf::Vector2f mousePos);
    // void update(const float& dt);
    void update(const sf::Vector2f mousePos);
    // void update(const float& dt,const sf::Vector2f& mousePos);
    void render_setting(sf::RenderTarget* target = nullptr);
};

