#pragma once
#include "../src/Config.h"

class ClickableIcon
{
private:
     bool clicked = false;
     // sf::Texture icon;
     sf::Sprite *icon;
     sf::Texture texture;

public:
     ClickableIcon(int pos_x, int pos_y, float scale_x, float scale_y, std::string path);
     virtual ~ClickableIcon();
     const bool getClicked() const;
     bool isClicked(const sf::Vector2f mousePos);
     void update(const float &dt);
     void render(sf::RenderTarget *target = nullptr);
};