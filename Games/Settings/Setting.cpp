// #include "Setting.h"


// //what is the purpose of this function?

// Setting::Setting() : Base("Setting", 280, 100, 1.0, 1.2){
//     // this->bg_t.loadFromFile("/Users/arhway/Desktop/Arhway/C-Game/assets/textures/frame2.png");
//     this->Musicslide_texture.loadFromFile("/Users/arhway/Desktop/Arhway/C-Game/assets/textures/slide.png");
//     this->SFXslide_texture.loadFromFile("/Users/arhway/Desktop/Arhway/C-Game/assets/textures/slide.png");
//     this->Musicpoint_texture.loadFromFile("/Users/arhway/Desktop/Arhway/C-Game/assets/textures/point.png");
//     this->SFXpoint_texture.loadFromFile("/Users/arhway/Desktop/Arhway/C-Game/assets/textures/point.png");

//     this->background.setSize(sf::Vector2f(522,370));
//     this->background.setTexture(&this->bg_t);

//     this->Musicslide.setSize(sf::Vector2f(680,400));
//     this->Musicslide.setTexture(&this->Musicslide_texture);

//     this->SFXslide.setSize(sf::Vector2f(680,400));
//     this->SFXslide.setTexture(&this->Musicslide_texture);

//     this->Musicpoint.setSize(sf::Vector2f(300,300));
//     this->Musicpoint.setTexture(&this->Musicpoint_texture); 

//     this->SFXpoint.setSize(sf::Vector2f(300,300));  
//     this->SFXpoint.setTexture(&this->SFXpoint_texture);     

//     this->background.setPosition(280, 100);
//     this->Musicslide.setPosition(245,155);
//     this->SFXslide.setPosition(245, 75);
//     // this->Musicpoint.setPosition(275, 90); //upper
//     this->Musicpoint.setPosition(345, 90); //upper//70
//     this->SFXpoint.setPosition(275, 170);   


//     this->plus1 = new ClickableIcon(570, 20, 5.0, 5.0, "/Users/arhway/Desktop/Arhway/C-Game/assets/textures/plus.png");
//     this->delete1 = new ClickableIcon(150, 0, 5.0, 5.0, "/Users/arhway/Desktop/Arhway/C-Game/assets/textures/delete.png");
//     this->plus2 = new ClickableIcon(570, 100, 5.0, 5.0, "/Users/arhway/Desktop/Arhway/C-Game/assets/textures/plus.png");
//     this->delete2 = new ClickableIcon(150, 80, 5.0, 5.0, "/Users/arhway/Desktop/Arhway/C-Game/assets/textures/delete.png");     

//     this->SFX = new Message(2000.0, 3500.0, 0.6, 0.6, Textbox);
//     this->MUSIC = new Message(2000.0, 3500.0, 0.6, 0.6, Textbox);
//     this->RESOLUTION = new Message(2000.0, 3500.0, 0.6, 0.6, Textbox);

//     this->SFX->message("SFX", 530.0, 150.0, 24);   
//     this->MUSIC->message("MUSIC", 517.0, 230.0, 24);   
//     this->RESOLUTION->message("RESOLUTION: 1920X1080", 395.0, 320.0, 30);      
// }

// Setting::~Setting(){

// }

// void Setting::reset_quit(){
//     this->quit = false; 
// }

// bool Setting::return_quit(){
//     return this->quit;
// }

// void Setting::update(const sf::Vector2f mousePos){
//     // //add action
//     // this->resume_icon.isClicked(mousePos);
//     // this->restart_icon.isClicked(mousePos);
//     // this->setting_icon.isClicked(mousePos);
//     // this->guide_icon.isClicked(mousePos);
//     // this->quit_icon.isClicked(mousePos);
    
//     // Base::update(mousePos);
//     // this->show_base = true;
//     // std::cout << "show guide: " << this->show_guide << std::endl;
//     // if (this->resume_icon.getClicked()){
//     //     std::cout << "Click resume" << std::endl;
//     //     //add functionalities
//     // }
//     // else if (this->restart_icon.getClicked()){
//     //     std::cout << "Click restart" << std::endl;
//     //     this->quit = true;
//     //     this->show_guide = false;
//     //     this->show_resume = false;
//     //     this->show_setting = false;
//     //     this->show_restart = true;
//     //     this->show_quit = false;

//     // }else if (this->setting_icon.getClicked()){
//     //     std::cout << "Click setting" << std::endl;
//     //     this->quit = true;
//     //     this->show_guide = false;
//     //     this->show_resume = false;
//     //     this->show_setting = true;
//     //     this->show_restart = false;
//     //     this->show_quit = false;
//     // }
//     // else if (this->guide_icon.getClicked()){
//     //     this->quit = true;
//     //     this->show_guide = true;
//     //     this->show_resume = false;
//     //     this->show_setting = false;
//     //     this->show_restart = false;
//     //     this->show_quit = false;
//     // }
//     // else if (this->quit_icon.getClicked()){
//     //     std::cout << "Click quit" << std::endl;
//     //     // this->closeWindow(); 
//     // }
//     // else{
//     //     this->show_guide = false;
//     //     std::cout << "return base" << std::endl;
//     // }
    
// }

// void Setting::render_setting(sf::RenderTarget* target){
//     // if(!quit && this->show_base == true){
//         target->draw(this->frame);
//         target->draw(this->close_icon);
//         target->draw(this->title);
//         // this->resume_icon.render(target);
//         // this->restart_icon.render(target);
//         // this->setting_icon.render(target);
//         // this->guide_icon.render(target);
//         // this->quit_icon.render(target);
//     // }else{
//         std::cout << "Options::render_options: Closing window" << std::endl;
//     // }

// }

// #include "Setting.h"

// Setting::Setting() : Base("Setting", 280, 100, 1.0, 1.2){
//     this->bg_t = new sf::Texture();
//     this->bg_t->loadFromFile("/Users/arhway/Desktop/Arhway/C-Game/assets/textures/frame2.png");
//     this->background = new sf::RectangleShape(sf::Vector2f(680, 400));
//     this->background->setTexture(this->bg_t);

//     this->Music_texture = new sf::Texture();
//     this->Music_texture->loadFromFile("/Users/arhway/Desktop/Arhway/C-Game/assets/textures/slide.png");
//     this->Music = new sf::RectangleShape(sf::Vector2f(150, 150));
//     this->Music->setTexture(this->Music_texture);
//     this->Music->setPosition(180, 220);
//     this->Music->setScale(1.0, 1.0);

//     this->SFX_texture = new sf::Texture();
//     this->SFX_texture->loadFromFile("/Users/arhway/Desktop/Arhway/C-Game/assets/textures/Slide.png");
//     this->SFX = new sf::RectangleShape(sf::Vector2f(150, 150));
//     this->SFX->setTexture(this->SFX_texture);
//     this->SFX->setPosition(350, 220);
//     this->SFX->setScale(1.0, 1.0);

//     this->plus_ = new ClickableIcon(180, 220, 1.0, 1.0, "Plus", "/Users/arhway/Desktop/Arhway/C-Game/assets/textures/plus.png");
//     this->delete_ = new ClickableIcon(350, 220, 1.0, 1.0, "Delete", "/Users/arhway/Desktop/Arhway/C-Game/assets/textures/delete.png");      
// }

// Setting::~Setting(){
//     // delete this->resume_icon;
//     // delete this->restart_icon;
//     // delete this->setting_icon;
//     // delete this->guide_icon; 
//     // delete this->quit_icon;
// }

// // void Setting::endState(){

// // }

// void Setting::reset_quit(){
//     this->quit = false; 
// }

// void Setting::update(const sf::Vector2f mousePos){
//     std::cout << "Setting::update: Closing window" << std::endl;
//     Base::update(mousePos);
//     // this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
//     //add action
//     if (this->resume_icon->isClicked(mousePos)){
//         // this->closeWindow(); 
//     }
//     if (this->restart_icon->isClicked(mousePos)){
//         // this->closeWindow(); 
//     }
//     if (this->setting_icon->isClicked(mousePos)){
//         // this->closeWindow(); 
//     }
//     if (this->guide_icon->isClicked(mousePos)){
//         // this->closeWindow(); 
//     }
//     if (this->quit_icon->isClicked(mousePos)){
//         // this->closeWindow(); 
//     }
// }

// void Setting::render_Setting(sf::RenderTarget* target){
//     //nothing vdo18
//     if(!quit){
//         std::cout << "Setting::render_Setting" << std::endl;
//         target->draw(*this->frame);
//         target->draw(*this->close_icon);
//         target->draw(this->title);
//         this->resume_icon->render(target);
//         this->restart_icon->render(target);
//         this->setting_icon->render(target);
//         this->guide_icon->render(target);
//         this->quit_icon->render(target);
//     }else{
//         std::cout << "Setting::render_Setting: Closing window" << std::endl;
//     }
    
// }

#include "Setting.h"

Setting::Setting() : Base("Setting", 280, 100, 1.0, 1.2),music(music),sfx(sfx){

    // this->bg_t = new sf::Texture();
    this->Musicslide_texture.loadFromFile("/Users/arhway/Desktop/Arhway/C-Game/assets/textures/slide.png");
    this->SFXslide_texture.loadFromFile("/Users/arhway/Desktop/Arhway/C-Game/assets/textures/slide.png");
    this->Musicpoint_texture.loadFromFile("/Users/arhway/Desktop/Arhway/C-Game/assets/textures/point.png");
    this->SFXpoint_texture.loadFromFile("/Users/arhway/Desktop/Arhway/C-Game/assets/textures/point.png");

    this->Musicslide.setSize(sf::Vector2f(680,400));
    this->Musicslide.setTexture(&this->Musicslide_texture);

    this->SFXslide.setSize(sf::Vector2f(680,400));
    this->SFXslide.setTexture(&this->Musicslide_texture);

    this->Musicpoint.setSize(sf::Vector2f(300,300));
    this->Musicpoint.setTexture(&this->Musicpoint_texture); 

    this->SFXpoint.setSize(sf::Vector2f(300,300));  
    this->SFXpoint.setTexture(&this->SFXpoint_texture);     

    this->Musicslide.setPosition(245,155);
    this->SFXslide.setPosition(245, 75);
    this->Musicpoint.setPosition(Mpos, 90); //upper
    // this->Musicpoint.setPosition(345, 90); //upper//70
    this->SFXpoint.setPosition(Spos, 170);   


    this->plus1 = new ClickableIcon(570, 20, 5.0, 5.0, "/Users/arhway/Desktop/Arhway/C-Game/assets/textures/plus.png");
    this->delete1 = new ClickableIcon(150, 0, 5.0, 5.0, "/Users/arhway/Desktop/Arhway/C-Game/assets/textures/delete.png");
    this->plus2 = new ClickableIcon(570, 100, 5.0, 5.0, "/Users/arhway/Desktop/Arhway/C-Game/assets/textures/plus.png");
    this->delete2 = new ClickableIcon(150, 80, 5.0, 5.0, "/Users/arhway/Desktop/Arhway/C-Game/assets/textures/delete.png");     

    this->SFX = new Message(2000.0, 3500.0, 0.6, 0.6, Textbox);
    this->MUSIC = new Message(2000.0, 3500.0, 0.6, 0.6, Textbox);
    this->RESOLUTION = new Message(2000.0, 3500.0, 0.6, 0.6, Textbox);

    this->SFX->message("SFX", 530.0, 150.0, 24);   
    this->MUSIC->message("MUSIC", 517.0, 230.0, 24);   
    this->RESOLUTION->message("RESOLUTION: 1920X1080", 395.0, 320.0, 30);      


}

Setting::~Setting(){
    // delete this->bg_t;
    // delete this->background;
    // delete this->Music_texture;
    // delete this->Music;
    // delete this->SFX_texture;
    // delete this->SFX;
    // delete this->plus1;
    // delete this->delete1;
    // delete this->plus2;
    // delete this->delete2;
}
void Setting::reset_quit(){
    this->quit = false; 
}

bool Setting::return_quit(){
    return this->quit;
}

void Setting::update(const sf::Vector2f mousePos){
    // Base::update(mousePos); //track if user click red cross to quit 
    // std::cout << "Setting::update: Click" << std::endl;    
    int MUSIC = 4;
    int SFX = 4;
    int x =70;
    int sound = 25;
    // int Mpos =555;
    // int Spos = 555;
    // int delete1ClickCount = 0;
    // int delete2ClickCount = 0;

    this->plus1->isClicked(mousePos);
    this->plus2->isClicked(mousePos);
    this->delete1->isClicked(mousePos);
    this->delete2->isClicked(mousePos); 

    Base::update(mousePos); 
    std::cout << "Setting::update: Closing window" << std::endl;
    if(MUSIC<=4){
        if(this->plus1->getClicked()){
            std::cout << "Click plus1" << std::endl;
            this->Musicpoint.setPosition(Mpos+(x*MUSIC), 90); 
            // music.setVolume(music.setVolume() + sound); // Increment volume
            music.setVolume(music.getVolume() + sound); 
            // volume += 10; // You can change this increment as needed
            // if (volume > 100) volume = 100; 
            //     backgroundMusic.setVolume(volume);
            
        MUSIC++;
        }
    }   
    // }
    if(MUSIC>=4){
        if(this->delete1->getClicked()){
            std::cout << "Click delete1" << std::endl;
            this->Musicpoint.setPosition(Mpos-(x*MUSIC), 155);
            music.setVolume(music.getVolume() - sound); 
        
        MUSIC++;
        }
    }
    if(SFX<=4){
        if(this->plus2->getClicked()){
            std::cout << "Click plus2" << std::endl;
            this->SFXpoint.setPosition(Spos+(x*MUSIC), 170);   
            sfx.setSVolume(sfx.getSVolume() + sound); 
        SFX++;
        }   
    }
    if(SFX>=4){
        if(this->delete2->getClicked()){
            std::cout << "Click delete2" << std::endl;
            this->SFXpoint.setPosition(Spos-(x*MUSIC), 170);   
            sfx.setSVolume(sfx.getSVolume() - sound); 
        SFX++;
        }
    }   

}



void Setting::render_setting(sf::RenderTarget* target){
    if(!quit){
        target->draw(this->frame);
        target->draw(this->close_icon);
        target->draw(this->title);
        // target->draw(this->background);
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
        // if (this->text != nullptr) {
        //     this->text->render(target); // Assuming render method exists in Message class
        // } else {
        //     std::cerr << "Error: 'text' pointer is null." << std::endl;
        // }

    }
}
