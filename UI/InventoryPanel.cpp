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
    if(!this->font.loadFromFile("../assets/fonts/Blomberg-8MKKZ.ttf")){
        std::cout << "Failed to load font." << std::endl;
    }
    // this->font.loadFromFile("../assets/fonts/Blomberg-8MKKZ.ttf");
    this->text.setFont(this->font);
    this->text.setString("Hello");
    this->text.setCharacterSize(30);
    this->text.setFillColor(sf::Color::Black);
    this->text.setPosition(180, 660);

    //sniper
    this->loadTextures(this->bombTex, "../assets/textures/bomb.png");
    this->bomb.setTexture(this->bombTex);
    this->bomb.setScale(0.1, 0.1f);
    this->bomb.setPosition(390.f, 630.f);

    //bomb
    this->loadTextures(this->sniperTex, "../assets/textures/gun_r.png");
    this->sniper.setTexture(this->sniperTex);
    this->sniper.setScale(2.5f, 2.5f);
    this->sniper.setPosition(277.f, 650.f);

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

void InventoryPanel::setPosition(float x, float y){
    this->inventoryPanel.setPosition(x, y);
}

short InventoryPanel::getcurrentItemSelected() const{
    return this->currentItemSelected;
}

void InventoryPanel::update(int killCount){
    std::cout << "InventoryPanel::update:: clicked: " << this->clicked << std::endl;
    this->updateInput();
    this->updateCurrentItem();
    this->text.setString(std::to_string(killCount));
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
        this->currentItemSelected = currentItem::Bomb;
    }else if(this->clicked == 1){
        this->currentItemSelected = currentItem::Sniper;
    }else if(this->clicked == 2){
        this->currentItemSelected = currentItem::Healer;
    }
}

void InventoryPanel::render(sf::RenderTarget* target){
    target->draw(this->inventoryPanel);
    target->draw(this->selectedSquare);
    target->draw(this->bomb);
    target->draw(this->sniper);
    target->draw(this->text);
}
