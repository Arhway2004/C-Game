#ifndef OPTIONS_H
#define OPTIONS_H

#include "Base.h"
#include "../../UI/ClickableIcon.h"
#include "Guide.h"
// #include "Setting.h"
// #include "/Users/arhway/Desktop/Git/C-Game/Games/Settings/Setting.h"
#include "Setting.h"



class Options : public Base{
    private: 
        ClickableIcon resume_icon; 
        ClickableIcon restart_icon; 
        // ClickableIcon setting_icon; 
        ClickableIcon quit_icon; 
        Guide guide_page;
        Setting setting_page;

    public:
        ClickableIcon guide_icon; 
        ClickableIcon setting_icon;
        bool show_base;
        bool show_resume = false; 
        bool show_restart = false;
        bool show_setting = false;
        bool show_guide = false;
        bool show_quit;


        // Options(int pos_x = 0, int pos_y = 0, int scale_x = 1.0, int scale_y = 1.0, std::string title = "Options", std::string path = "../../assets/textures/base.png"); 
        Options();
        virtual ~Options();
        void reset_quit();

        // void update(const float& dt); 
        void update(const sf::Vector2f mousePos);
        void render_options(sf::RenderTarget* target = nullptr);
        bool return_quit(); 
        //is button clicked 

}; 

#endif