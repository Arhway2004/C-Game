#include "Tile.h"

Tile::Tile(const std::string& imgPath, int pos_x, int pos_y, float scale){
    if(this->tile_img.loadFromFile(imgPath)){
        std::cout << "ERROR at Tile::Tile::couldn't upload the image" << std::endl;
    }
    this->tile_sprite.setTexture(this->tile_img);
    this->tile_sprite.setPosition(pos_x, pos_y);
    this->tile_sprite.setScale(scale, scale);
}

Tile::~Tile(){

}

bool Tile::isColliding(sf::Vector2f& player_pos){
    if(this->tile_sprite.getGlobalBounds().contains(player_pos)){
        return true;
    }
    return false;
}

void Tile::render_tile(sf::RenderTarget* target){
    target->draw(this->tile_sprite);
}


