#pragma once
#include "Base.h"
#include "../../UI/ClickableIcon.h"
#include "../../UI/Message.h"
// #include "/Users/arhway/Desktop/Final/C-Game/UI/Music.h"
#include "Guide.h"



class Setting: public Base{
    private:
        sf::RenderWindow* window;
        sf::RectangleShape background;
        sf::RectangleShape Musicslide;
        sf::RectangleShape SFXslide;
        sf::RectangleShape Musicpoint;
        sf::RectangleShape SFXpoint;
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

        sf::Music backgroundMusic,backgroundSFX;



    public:
        Setting();
        virtual ~Setting();
        bool return_quit();
        void reset_quit();
        void playSFX();
        void playMusic();
        void pauseMusic();
        void update(const sf::Vector2f mousePos);
        void render_setting(sf::RenderTarget* target = nullptr);
        static int Mpos;
        static int Spos;
        static int sound;
        static float volume,Svolume;




};
