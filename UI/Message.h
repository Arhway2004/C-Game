// #pragma once
// #include "../src/Config.h"

// class Message
// {
// private:
//     sf::RenderWindow* window;
//     sf::RectangleShape* Textbox;
//     sf::Texture* Texture_T;
//     sf::Text* text;
//     sf::Text* text1;
//     sf::Font font;


// public:
//     Message(float pos_x, float pos_y, float set_w, float set_h, sf::RectangleShape& Textbox);
//     ~Message();
//     // void box();
//     void Text(std::vector<std::string> t, int x=0);
//     void message(std::string t,float pos_x, float pos_y, int size);
//     void render(sf::RenderTarget *target);
//     //  ClickableIcon(int pos_x, int pos_y, float scale_x, float scale_y, std::string path);
//     //  virtual ~ClickableIcon();
//     //  const bool getClicked() const;
//     //  bool isClicked(const sf::Vector2f mousePos);
//     //  void update(const float &dt);
//     //  void render(sf::RenderTarget *target = nullptr);
// };

#pragma once
#include "../src/Config.h"

class Message
{
private:
    sf::RenderWindow* window;
    sf::RectangleShape* Textbox;
    sf::Texture* Texture_T;
    sf::Text* text;
    sf::Text* text1;
    sf::Font font;


public:
    Message(float pos_x, float pos_y, float set_w, float set_h, sf::RectangleShape& Textbox);
    ~Message();
    // void box();
    void Text(std::vector<std::string> t, int x=0);
    void message(std::string t,float pos_x, float pos_y, int size);
    void render(sf::RenderTarget *target);
    //  ClickableIcon(int pos_x, int pos_y, float scale_x, float scale_y, std::string path);
    //  virtual ~ClickableIcon();
    //  const bool getClicked() const;
    //  bool isClicked(const sf::Vector2f mousePos);
    //  void update(const float &dt);
    //  void render(sf::RenderTarget *target = nullptr);
};