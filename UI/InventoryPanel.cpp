#include "InventoryPanel.h"

//killCount is the score not showing

InventoryPanel::InventoryPanel(float pos_x, float pos_y, float scale_x, float scale_y){
    this->loadTextures(this->inventoryPanelTex, "../assets/textures/inventories.png");
    this->inventoryPanel.setTexture(this->inventoryPanelTex);
    this->inventoryPanel.setScale(1.5f, 1.5f);
    this->inventoryPanel.setPosition(30.f, 550.f);

    this->selectedSquare.setSize(sf::Vector2f(79, 65));
    this->selectedSquare.setFillColor(sf::Color(255, 255, 255, 120)); // Set alpha value for transparency
    this->selectedSquare.setPosition(275, 632); // Adjusted position

    //set text
    this->initFont(180, 660, this->scoreText, this->scoreFont, "0", 30, "../assets/font/Blomberg-8MKKZ.ttf");
    this->initFont(440, 650, this->iceText, this->iceFont, "0", 20, "../assets/font/Blomberg-8MKKZ.ttf");

    //sniper
    this->loadTextures(this->iceTex, "../assets/textures/ice.png");
    this->ice.setTexture(this->iceTex);
    this->ice.setScale(0.05, 0.05f);
    this->ice.setPosition(390.f, 633.f);

    //bomb
    this->loadTextures(this->bullet1Tex, "../assets/textures/bulletset1.png");
    this->bullet1.setTexture(this->bullet1Tex);
    this->bullet1.setScale(0.15f, 0.15f);
    this->bullet1.setPosition(290.f, 636.f);
    this->pressCooldownDuration = sf::seconds(0.2f);
}

InventoryPanel::~InventoryPanel(){
    
}

void InventoryPanel::loadTextures(sf::Texture& texture, std::string path){
    if(!texture.loadFromFile(path)){
        std::cout << "Player::loadFile:: Error: Player texture not loaded" << std::endl;
    }else{
        std::cout << "Texture load successfully" << std::endl;
    }
}

void InventoryPanel::initFont(int pos_x, int pos_y, sf::Text& text, sf::Font& font, std::string msg, short size, std::string path){
    if(!font.loadFromFile(path)){
        std::cout << "Failed to load font." << std::endl;
    }
    text.setFont(font);
    text.setString(msg);
    text.setCharacterSize(size);
    text.setFillColor(sf::Color::Black);
    text.setPosition(pos_x, pos_y);
}

void InventoryPanel::setPosition(float x, float y){
    this->inventoryPanel.setPosition(x, y);
}

short InventoryPanel::getcurrentItemSelected() const{
    return this->currentItemSelected;
}

void InventoryPanel::update(int killCount, int iceCount){
    std::cout << "InventoryPanel::update:: clicked: " << this->clicked << std::endl;
    this->updateInput();
    this->updateCurrentItem();
    this->scoreText.setString(std::to_string(killCount));
    this->iceText.setString(std::to_string(iceCount));
}

void InventoryPanel::updateInput(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if(canPress()){
            this->clicked = (this->clicked + 1)%3; 
            this->updateFramePosition();
            this->resetPressCooldown();
        }
    }
}

bool InventoryPanel::canPress() const{
    return this->pressCooldownTimer.getElapsedTime() >= this->pressCooldownDuration;
}

void InventoryPanel::resetPressCooldown(){
    this->pressCooldownTimer.restart();
}

void InventoryPanel::updateFramePosition(){
    float newPosx = 275 + clicked * 112; 
    // if(canPress()){
    this->selectedSquare.setPosition(newPosx, 632);
    // }
}

void InventoryPanel::updateCurrentItem(){ //frame pos
    if(this->clicked == 0){
        this->currentItemSelected = currentItem::Bullet1;
    }else if(this->clicked == 1){
        this->currentItemSelected = currentItem::Ice;
    }else if(this->clicked == 2){
        this->currentItemSelected = currentItem::Healer;
    }
}

void InventoryPanel::render(sf::RenderTarget* target){
    target->draw(this->inventoryPanel);
    target->draw(this->selectedSquare);
    target->draw(this->ice);
    target->draw(this->bullet1);
    target->draw(this->scoreText);
    target->draw(this->iceText);
}
