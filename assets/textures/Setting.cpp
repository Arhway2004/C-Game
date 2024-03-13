
#include "Setting.h"

Setting::Setting(): Base("Setting", 280, 100, 1.0, 1.2),music(music){
    std::cout << "Setting::Setting: Setting constructor" << std::endl;
    this->bg_t.loadFromFile("/Users/arhway/Desktop/Arhway/C-Game/assets/textures/frame2.png");
    this->Musicslide_texture.loadFromFile("/Users/arhway/Desktop/Arhway/C-Game/assets/textures/slide.png");
    this->SFXslide_texture.loadFromFile("/Users/arhway/Desktop/Arhway/C-Game/assets/textures/slide.png");
    this->Musicpoint_texture.loadFromFile("/Users/arhway/Desktop/Arhway/C-Game/assets/textures/point.png");
    this->SFXpoint_texture.loadFromFile("/Users/arhway/Desktop/Arhway/C-Game/assets/textures/point.png");

    this->background.setSize(sf::Vector2f(522,370));
    this->background.setTexture(&this->bg_t);

    this->Musicslide.setSize(sf::Vector2f(680,400));
    this->Musicslide.setTexture(&this->Musicslide_texture);

    this->SFXslide.setSize(sf::Vector2f(680,400));
    this->SFXslide.setTexture(&this->Musicslide_texture);

    this->Musicpoint.setSize(sf::Vector2f(300,300));
    this->Musicpoint.setTexture(&this->Musicpoint_texture); 

    this->SFXpoint.setSize(sf::Vector2f(300,300));  
    this->SFXpoint.setTexture(&this->SFXpoint_texture);     

    this->background.setPosition(280, 100);
    this->Musicslide.setPosition(245,155);
    this->SFXslide.setPosition(245, 75);
    // this->Musicpoint.setPosition(275, 90); //upper
    this->SFXpoint.setPosition(Spos, 170);   
    this->Musicpoint.setPosition(Mpos, 90); //upper//70



    this->plus1 = new ClickableIcon(570, 20, 5.0, 5.0, "./plus.png");
    this->delete1 = new ClickableIcon(150, 0, 5.0, 5.0, "../textures/delete.png");

    this->plus2 = new ClickableIcon(570, 100, 5.0, 5.0, "../textures/plus.png");
    this->delete2 = new ClickableIcon(150, 80, 5.0, 5.0, "../textures/delete.png");     

    this->SFX = new Message(2000.0, 3500.0, 0.6, 0.6, Textbox);
    this->MUSIC = new Message(2000.0, 3500.0, 0.6, 0.6, Textbox);
    this->RESOLUTION = new Message(2000.0, 3500.0, 0.6, 0.6, Textbox);

    this->SFX->message("SFX", 530.0, 150.0, 24);   
    this->MUSIC->message("MUSIC", 517.0, 230.0, 24);   
    this->RESOLUTION->message("RESOLUTION: 1920X1080", 395.0, 320.0, 30);     
}



Setting::~Setting(){
    delete this->plus1;
    delete this->delete1;
    delete this->plus2;
    delete this->delete2;
}

void Setting::reset_quit(){
    this->quit = false; 
}

bool Setting::return_quit(){
    return this->quit;
}

// void Setting::update(const sf::Vector2f mousePos){
//     this->plus1->isClicked(mousePos);
//     this->plus2->isClicked(mousePos);
//     this->delete1->isClicked(mousePos);
//     this->delete2->isClicked(mousePos);    

//     Base::update(mousePos); //track if user click red cross to quit 
//     std::cout << "plus1: " << this->plus1->getClicked() << std::endl; 
//     if(this->plus1->getClicked()){
//         std::cout << "plus1" << std::endl;
//     }
//     else if(this->plus2->getClicked()){
//         std::cout << "plus2" << std::endl;
//     }
//     else if(this->delete1->getClicked()){
//         std::cout << "delete1" << std::endl;
//     }
//     else if(this->delete2->getClicked()){
//         std::cout << "delete2" << std::endl;
//     }
    
// }
// void Setting::update(const sf::Vector2f mousePos){
//     int MUSIC = 4;
//     int SFX = 4;
//     int x =70;
//     int sound = 25;

//     this->plus1->isClicked(mousePos);
//     this->plus2->isClicked(mousePos);
//     this->delete1->isClicked(mousePos);
//     this->delete2->isClicked(mousePos); 

//     Base::update(mousePos); 
//     std::cout << "Setting::update: Closing window" << std::endl;
//     if(MUSIC<=4){
//         if(this->plus1->getClicked()){
//             std::cout << "Click plus1" << std::endl;
//             this->Musicpoint.setPosition(Mpos+(x*MUSIC), 90); 
//             // music.setVolume(music.getVolume() + sound); 

            
//         MUSIC++;
//         }
//     }   
//     // }
//     else if(MUSIC>=4){
//         if(this->delete1->getClicked()){
//             std::cout << "Click delete1" << std::endl;
//             this->Musicpoint.setPosition(Mpos-(x*MUSIC), 155);
//             // music.setVolume(music.getVolume() - sound); 
        
//         MUSIC--;
//         }
//     }
//     if(SFX<=4){
//         if(this->plus2->getClicked()){
//             std::cout << "Click plus2" << std::endl;
//             this->SFXpoint.setPosition(Spos+(x*MUSIC), 170);   
//         SFX++;
//         }   
//     }
//     else if(SFX>=4){
//         if(this->delete2->getClicked()){
//             std::cout << "Click delete2" << std::endl;
//             this->SFXpoint.setPosition(Spos-(x*MUSIC), 170);   
//         SFX--;
//         }
//     }   

// }
void Setting::update(const sf::Vector2f mousePos){
    int MUSIC = 1;
    int SFX = 4;
    int x =70;
    int sound = 25;

    this->plus1->isClicked(mousePos);
    this->plus2->isClicked(mousePos);
    this->delete1->isClicked(mousePos);
    this->delete2->isClicked(mousePos); 

    Base::update(mousePos); 
    std::cout << "Setting::update: Closing window" << std::endl;

    if(this->plus1->getClicked()){
        // if(MUSIC<=4){
            std::cout << "Click plus1" << std::endl;
            this->Musicpoint.setPosition(Mpos+(x*MUSIC), 90); 
            // music.setVolume(music.getVolume() + sound); 
            MUSIC++;
        // }
    }   
    // // }
    if(this->delete1->getClicked()){
    //     if(MUSIC>=0){

            std::cout << "Click delete1" << std::endl;
            this->Musicpoint.setPosition(Mpos-(x*MUSIC), 90);
    //         // music.setVolume(music.getVolume() - sound); 
        
    //         MUSIC--;
        }
    }
    // if(SFX<=4){
    //     if(this->plus2->getClicked()){
    //         std::cout << "Click plus2" << std::endl;
    //         this->SFXpoint.setPosition(Spos+(x*MUSIC), 170);   
    //     SFX++;
    //     }   
    // }
    // else if(SFX>=4){
    //     if(this->delete2->getClicked()){
    //         std::cout << "Click delete2" << std::endl;
    //         this->SFXpoint.setPosition(Spos-(x*MUSIC), 170);   
    //     SFX--;
    //     }
    // }   

// }
void Setting::render_setting(sf::RenderTarget* target){
    if(!quit){
        std::cout << "Setting::render_Setting" << std::endl;
        target->draw(this->frame);
        target->draw(this->close_icon);
        target->draw(this->title);
        target->draw(this->Musicslide);
        target->draw(this->SFXslide);
        target->draw(this->Musicpoint); 
        target->draw(this->SFXpoint);       
        this->plus1->render(target);
        this->delete1->render(target);
        this->plus2->render(target);
        this->delete2->render(target);
        // this->text->render(target);
        this->SFX->render(target);  
        this->MUSIC->render(target);   
        this->RESOLUTION->render(target); 
    }else{
        std::cout << "Options::render_options: Closing window" << std::endl;
    }
}
