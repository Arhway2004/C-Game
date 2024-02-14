#include "Base.h"

// Base::Base(int pos_x, int pos_y, int scale_x, int scale_y, std::string title, std::string path){
//     if(!this->texture.loadFromFile(path)){
//         std::cout << "ERROR::BASE::CONSTRUCTOR::FAILED_TO_LOAD_TEXTURE" << std::endl; 
//     }else{
//         std::cout << "BASE::Texture loaded" << std::endl;
//     }
//     this->frame = new sf::Sprite(this->texture); 
//     this->frame->setScale(scale_x, scale_y);
//     this->frame->setPosition(pos_x, pos_y);
//     this->set_up_sprite(pos_x, pos_y, scale_x, scale_y, this->frame, this->frame_texture, path); 
// }

Base::Base(std::string title, int pos_x, int pos_y, float scale_x, float scale_y){
    this->frame = new sf::Sprite();
    this->close_icon = new sf::Sprite();
    this->frame_texture = new sf::Texture();
    this->close_texture = new sf::Texture();
    this->title = sf::Text();
    this->frame_pos_x = this->frame->getPosition().x;
    this->frame_pos_y = this->frame->getPosition().y;

    this->set_up_sprite(pos_x, pos_y, scale_x, scale_y, this->frame, this->frame_texture, "../assets/textures/frame2.png"); 
    sf::FloatRect bound = this->frame->getGlobalBounds();

    float x = this->frame_pos_x;
    float y = this->frame_pos_y;
    this->set_up_sprite(x + bound.width * 1.5 - 10, y + 80, 0.08, 0.08, this->close_icon, this->close_texture, "../assets/textures/close2.png"); 

    this->initBaseFont(this->font, "../assets/font/BACKTO1982.TTF");
    this->setBaseText(this->title, this->font, title, sf::Color::White, 25, x + 280 , y + 70);
}

void Base::initBaseFont(sf::Font& font, std::string path){
    if(!font.loadFromFile(path)){
        std::cout << "ERROR at MainMenu/initFont::couldn't upload the font" << std::endl; 
    }
}

void Base::setBaseText(sf::Text& text, sf::Font& font, std::string msg, sf::Color msg_color, short size, float pos_x, float pos_y){
    text.setFont(font);
    text.setString(msg);
    text.setFillColor(msg_color);
    text.setCharacterSize(size); 
    text.setPosition(
        pos_x, pos_y
    );
}

void Base::set_up_sprite(int pos_x, int pos_y, float scale_x, float scale_y, sf::Sprite*& sprite, sf::Texture* tex, std::string path){
    if(!tex->loadFromFile(path)){
        std::cout << "ERROR::BASE::CONSTRUCTOR::FAILED_TO_LOAD_TEXTURE" << std::endl; 
        exit(1);
    }else{
        std::cout << "BASE::Texture loaded" << std::endl;
    }
    sprite->setTexture(*tex);
    sprite->setScale(scale_x, scale_y); 
    sprite->setPosition(pos_x, pos_y); 
}

Base::~Base(){
    delete this->close_icon; 
    delete this->frame; 
}

void Base::closeWindow(){
    //condition to close window )
    this->window->close(); 
}

// void Base::endState(){
//     if 
// }

//marked
void Base::update(const sf::Vector2f mousePos){
    if(this->close_icon->getGlobalBounds().contains(mousePos)){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            //close options window
            // this->~Base(); 
            this->quit = true; 
            // std::cout << "Base::update: Closing window" << std::endl;
        }
    }
}   

void Base::render(sf::RenderTarget* target){
    std::cout << "rendering base" << std::endl;
    // target->draw(*this->frame); 
    // target->draw(*this->close_icon); 
}