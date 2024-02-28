#pragma once
#include "../src/Config.h"


enum clickable_state{
     RELEASED_C = 0,
     PRESSED_C = 1 
     
};

class ClickableIcon
{
private:
     short unsigned clickableState;
     bool clicked = false;
     bool hasBeenClicked;
     bool prevMousePressed; 
     // sf::Texture icon;
     sf::Sprite *icon;
     sf::Texture texture;

public:
     ClickableIcon(int pos_x, int pos_y, float scale_x, float scale_y, std::string path);
     virtual ~ClickableIcon();
     const bool getClicked() const;
     const bool isClicked2() const;
     bool isClicked(const sf::Vector2f mousePos);
     bool onceClicked(const sf::Vector2f mousePos, sf::RenderWindow* window);
     bool resetClick();
     void update(const sf::Vector2f mousePos);
     void render(sf::RenderTarget *target = nullptr);
};