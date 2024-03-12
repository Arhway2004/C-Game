#include "Collectible.h"

//collision too wide
Collectible::Collectible(float pos_x, float pos_y , float scale_x, float scale_y, std::string path) : isCollected(false){
    collectibleTex = std::make_shared<sf::Texture>(); 
    if(!collectibleTex->loadFromFile(path)){
        std::cout << "Collectible::Error::Texture not loaded" << std::endl;
    }else{
        std::cout << "Collectible::Texture loaded successfully" << std::endl;
    }
    collectible.setTexture(*collectibleTex);
    collectible.setScale(scale_x, scale_y);
    collectible.setPosition(pos_x, pos_y);
    collectible.setOrigin(collectible.getGlobalBounds().width/2, collectible.getGlobalBounds().height/2);
}

Collectible::~Collectible(){
}


bool Collectible::isCollectedByPlayer(Player& player){
    float distance = sqrt(pow(player.getPosition().x - this->collectible.getPosition().x, 2) + pow(player.getPosition().y - this->collectible.getPosition().y, 2)); 
    if(distance <= player.getGlobalBounds().width - 40){
        return true;
    }
    return false;
}

void Collectible::render(sf::RenderTarget* target){
    if(!this->isCollected)
        target->draw(this->collectible);
}