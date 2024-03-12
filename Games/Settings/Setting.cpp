#include "Setting.h"
    int Setting::Mpos = 535;
    int Setting::Spos = 535;
    // int Setting::sound = 25;
    float Setting::volume = 100.0f;
    float Setting::Svolume = 100.0f;

Setting::Setting(): Base("Setting", 280, 100, 1.0, 1.2){
    std::cout << "Setting::Setting: Setting constructor" << std::endl;
    this->bg_t.loadFromFile("../assets/textures/frame2.png");
    this->Musicslide_texture.loadFromFile("../assets/textures/slide.png");
    this->SFXslide_texture.loadFromFile("../assets/textures/slide.png");
    this->Musicpoint_texture.loadFromFile("../assets/textures/point.png");
    this->SFXpoint_texture.loadFromFile("../assets/textures/point.png");

    this->background.setSize(sf::Vector2f(522,370));
    this->background.setTexture(&this->bg_t);

    this->Musicslide.setSize(sf::Vector2f(660,400));
    this->Musicslide.setTexture(&this->Musicslide_texture);

    this->SFXslide.setSize(sf::Vector2f(660,400));
    this->SFXslide.setTexture(&this->Musicslide_texture);

    this->Musicpoint.setSize(sf::Vector2f(300,300));
    this->Musicpoint.setTexture(&this->Musicpoint_texture);

    this->SFXpoint.setSize(sf::Vector2f(300,300));  
    this->SFXpoint.setTexture(&this->SFXpoint_texture);

    this->background.setPosition(280, 100);
    this->Musicslide.setPosition(245,155);
    this->SFXslide.setPosition(245, 75);
    this->SFXpoint.setPosition(Mpos, 170);   
    this->Musicpoint.setPosition(Spos, 90); 

    this->plus1 = new ClickableIcon(680, 170, 0.5, 0.5, "../assets/textures/plus.png");
    this->delete1 = new ClickableIcon(350, 170, 0.5, 0.5, "../assets/textures/delete.png");

    this->plus2 = new ClickableIcon(680, 250, 0.5, 0.5, "../assets/textures/plus.png");
    this->delete2 = new ClickableIcon(350, 250, 0.5, 0.5, "../assets/textures/delete.png");     

    this->plusSFX = new ClickableIcon(570, 300, 5.0, 5.0, "../assets/textures/plusS.png");
    this->plusS = new ClickableIcon(200, 200, 5.0, 5.0, "../assets/textures/plusS.png");

    this->SFX = new Message(2000.0, 3500.0, 0.6, 0.6, Textbox);
    this->MUSIC = new Message(2000.0, 3500.0, 0.6, 0.6, Textbox);
    this->RESOLUTION = new Message(2000.0, 3500.0, 0.6, 0.6, Textbox);

    this->SFX->message("SFX", 520.0, 230.0, 24);   
    this->MUSIC->message("MUSIC", 510.0, 150.0, 24); 
    this->RESOLUTION->message("RESOLUTION: 1920X1080", 395.0, 320.0, 30);     

    // if (!backgroundMusic.openFromFile("../assets/sounds/background_audio.wav")) {
    //     std::cout << "Failed to load background music" << std::endl;
    // } else {
    //     backgroundMusic.setVolume(volume); // Set the volume
    //     // backgroundMusic.play(); // Play the music
    // }
    // if (!backgroundSFX.openFromFile("../assets/sounds/pop.wav")) {
    //     std::cout << "Failed to load background SFX" << std::endl;
    // } else {
    //     backgroundSFX.setVolume(Svolume); // Set the volume
    //     // backgroundSFX.play(); // Play the music
    // }
}



Setting::~Setting(){
    // delete this->plus1;
    // delete this->delete1;
    // delete this->plus2;
    // delete this->delete2;
  
    // delete this->text;
    // delete this->SFX;
}

void Setting::reset_quit(){
    this->quit = false; 
}

bool Setting::return_quit(){
    return this->quit;
}

void Setting::update(const sf::Vector2f mousePos){
    this->Musicpoint.setPosition(Mpos, 90); 
    this->SFXpoint.setPosition(Spos, 170); 
    this->backgroundMusic.setVolume(volume);
    this->backgroundSFX.setVolume(Svolume);

    static bool wasPlus1ClickedLastFrame = false;
    static bool wasDelete1ClickedLastFrame = false;
    static bool wasPlus2ClickedLastFrame = false;
    static bool wasDelete2ClickedLastFrame = false;
    // static bool wasplus1 = false;
    static int SFX =4;
    static int MUSIC =4;

    const int x = 65; // Position adjustment step
    const float sound = 25.0f;


    bool isPlus1ClickedThisFrame = this->plus1->isClicked(mousePos);
    if (isPlus1ClickedThisFrame && !wasPlus1ClickedLastFrame) {
        backgroundSFX.play(); 
        if(MUSIC < 4){ 
            std::cout << "Click plus1" << std::endl;
            Mpos += x; 
            this->Musicpoint.setPosition(Mpos, 90); 
            volume += sound;
            this->backgroundMusic.setVolume(volume); 
            std::cout << volume << std::endl;

            MUSIC++;
        }
    }
    wasPlus1ClickedLastFrame = isPlus1ClickedThisFrame;


    bool isDelete1ClickedThisFrame = this->delete1->isClicked(mousePos);
    if (isDelete1ClickedThisFrame && !wasDelete1ClickedLastFrame) {
        backgroundSFX.play(); 
        if(MUSIC > 0){
            std::cout << "Click delete1" << std::endl;
            Mpos -= x; 
            this->Musicpoint.setPosition(Mpos, 90); 
            volume -= sound;
            this->backgroundMusic.setVolume(volume); 
            std::cout << volume << std::endl;

            MUSIC--;
        }
    }
    wasDelete1ClickedLastFrame = isDelete1ClickedThisFrame;


    bool isPlus2ClickedThisFrame = this->plus2->isClicked(mousePos);
    if (isPlus2ClickedThisFrame && !wasPlus2ClickedLastFrame) {
        backgroundSFX.play(); 
        if(SFX < 4){ 
            std::cout << "Click plus2" << std::endl;
            Spos += x; 
            this->SFXpoint.setPosition(Spos, 170); 
            Svolume += sound;
            this->backgroundMusic.setVolume(Svolume); 
            std::cout << Svolume << std::endl;
            SFX++;
        }
    }
    wasPlus2ClickedLastFrame = isPlus2ClickedThisFrame;


    bool isDelete2ClickedThisFrame = this->delete2->isClicked(mousePos);
    if (isDelete2ClickedThisFrame && !wasDelete2ClickedLastFrame) {
        backgroundSFX.play(); 
        if(SFX > 0){
            std::cout << "Click delete2" << std::endl;
            Spos -= x; 
            this->SFXpoint.setPosition(Spos, 170); 
            Svolume -= sound;
            this->backgroundMusic.setVolume(Svolume); 
            std::cout << Svolume << std::endl;
            SFX--;
        }
    }
    wasDelete2ClickedLastFrame = isDelete2ClickedThisFrame;
    backgroundMusic.setVolume(volume); // Apply music volume change
    backgroundSFX.setVolume(Svolume); 
    Base::update(mousePos); 
}

void Setting::playSFX(){
    backgroundSFX.setVolume(Svolume); 
    backgroundSFX.play();
}
void Setting::playMusic(){
    backgroundMusic.setVolume(volume); 
    backgroundMusic.play();
    backgroundMusic.setLoop(true);
    std::cout <<"music" << std::endl;
}
void Setting::pauseMusic(){
    backgroundMusic.setVolume(volume); 
    backgroundMusic.pause();
    backgroundMusic.setLoop(true);
    std::cout <<"music" << std::endl;
}

void Setting::volume1(){
    backgroundMusic.setVolume(volume);
}
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
        this->plusS->render(target);
    }else{
        std::cout << "Options::render_options: Closing window" << std::endl;
    }
}