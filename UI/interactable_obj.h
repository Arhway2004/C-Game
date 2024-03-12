#pragma once
#include "../src/Config.h"
#include <SFML/Graphics/Text.hpp>

class InteractableObj
{
private:
    bool inputted = false;
    bool showText;
    sf::Sprite *icon;
    sf::Texture texture;
    sf::Event event;
    sf::RenderWindow window;
    sf::FloatRect bounds;
    sf::Text interactText;
    sf::Font font;

public:
    InteractableObj(int pos_x, int pos_y, float scale_x, float scale_y, std::string path);
    virtual ~InteractableObj();
    const bool getInput() const;
    bool IsPressed(const sf::Vector2f playerPosition);
    void update(const float &dt);
    void render(sf::RenderTarget *target = nullptr);
};
