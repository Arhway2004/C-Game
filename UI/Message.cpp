#include "Message.h"
Message::Message(float pos_x, float pos_y, float set_w, float set_h, sf::RectangleShape& Textbox)
{
    this->Texture_T = new sf::Texture(); // Allocate memory for Texture_T
    this->Textbox = new sf::RectangleShape(); // Allocate memory for Textbox
    
    this->Texture_T->loadFromFile("../assets/textures/TextBox.jpeg");

    this->Textbox->setTexture(this->Texture_T);
    this->Textbox->setSize(sf::Vector2f(900, 300));
    this->Textbox->setPosition(pos_x, pos_y);
    this->Textbox->setScale(set_w, set_h);

    text = new sf::Text;
}


Message::~Message()
{
    delete this->Texture_T; // Deallocate memory for Texture_T
    delete this->Textbox; // Deallocate memory for Textbox
    delete this->text;
}
void Message::Text(std::vector<std::string> t, int x) {

    // Load the font
    if (!font.loadFromFile("../assets/font/Blomberg-8MKKZ.ttf")) {
        // Failed to load font
        std::cerr << "Failed to load font!" << std::endl;
        return;
    }

    text->setFont(font); // Set the font for the text
    text->setString(t[x]);
    text->setCharacterSize(24);
    text->setFillColor(sf::Color::White);
    text->setPosition(230.0, 360.0);
    std::cout << "vsdjfi" << std::endl; 

}
void Message::render(sf::RenderTarget* target){
    target->draw(*Textbox); 
    target->draw(*text);

}
