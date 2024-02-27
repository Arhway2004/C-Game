#include "Player.h"

Player::Player(const std::string& imgPath, int pos_x, int pos_y, float scale){
    if(this->player_tex->loadFromFile(imgPath)){
        std::cout << "ERROR at Player::Player::couldn't upload the image" << std::endl;
    }
    this->player_sprite->setTexture(*this->player_tex);
    this->player_sprite->setPosition(pos_x, pos_y);
    this->player_sprite->setScale(scale, scale);
}

Player::~Player(){

}

void Player::update(const float& dt){
    //click button to move

}

bool Player::isColliding_enemy(){//Enemy* enemy){
    return false;
}

bool Player::isColliding_tile(Tile tile_unit){
    
}

void Player::render_player(sf::RenderTarget* target){
}