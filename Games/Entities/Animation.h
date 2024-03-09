#pragma once 
#include "../../src/Config.h"

struct Animation{
    void loadFile(sf::Texture& tex, std::string path){
        if(!tex.loadFromFile(path)){
            std::cout << "Animation::loadFile:: Error: Player texture not loaded" << std::endl;
        }else{
            std::cout << "Texture load successfully" << std::endl;
        }
    }

    void updateAnimation(sf::Sprite& sprite, sf::Texture& tex,  int startPosY, int width, int height, int number_of_frames, int framespeed, std::string path){
        loadFile(tex, path);
        int xTexture = 0;
        xTexture = (int)sprite.getPosition().x / framespeed % number_of_frames; //slow down 35 frames
        xTexture = xTexture * width;
        sprite.setTextureRect(sf::IntRect(xTexture, startPosY, width, height));  //x, y, w, h>
    }
};