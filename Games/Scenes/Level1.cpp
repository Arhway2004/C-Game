
#include "Level1.h"

Level1::Level1(sf::RenderWindow* window) : GameState(window){
    this->endNow = false;
    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Black);
    this->loadTextures(this->bgTex, "../assets/textures/map4.png");
    this->bg.setTexture(this->bgTex);
    this->bg.setScale(2.21f, 2.32f);
    this->bg.setPosition(0.f, 0.f);

    //target
    this->loadTextures(this->targetTex, "../assets/textures/target.png");
    this->target.setTexture(this->targetTex);
    this->target.setOrigin(this->targetTex.getSize().x/2, this->targetTex.getSize().y/2);
    this->target.setPosition(this->mousePosView.x, this->mousePosView.y);

    //inventory panel 
    this->inventoryPanel = std::make_shared<InventoryPanel>(30.f, 550.f, 1.5f, 1.5f); 
    this->currentItemSelected = this->inventoryPanel->getcurrentItemSelected();
    
    this->player = std::make_shared<Player>();
    enemySpawner = std::make_shared<EnemySpawner>();   
    this->hitCooldownDuration = sf::seconds(1.0f);

    //freeze screen
    this->freezeScreenTex.loadFromFile("../assets/textures/freeze_screen2.png");
    this->freezeScreen.setTexture(this->freezeScreenTex);
    this->freezeColor = this->freezeScreen.getColor();
    this->freezeColor.a = 0;
    this->freezeScreen.setColor(this->freezeColor);

    //collectible
    this->iceCollectibles.push_back(Collectible(200.f, 200.f, 0.07f, 0.07f, "../assets/textures/ice.png"));

    // sound
    this->music = new Setting();
}

Level1::~Level1(){
    
}

void Level1::endState(){
    std::cout << "Ending Level1" << "\n";
}

// void Level1::updateInput(const float& dt){
//     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
//         this->endNow = true;
//     }

//     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !this->freeze && this->iceCount > 0 && this->currentItemSelected == 1){
//         this->freeze = true;
//         this->freezeTimer.restart();
//         this->iceCount--;
//     }

//     if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
//             // this->playerState = SHOOTING;
//         music->shotSFX();
//         if(this->player->canShoot){
//             music->shotSFX();
//             this->shootBullet(*this->player, this->bullets, this->mousePosView);
//             this->player->shootCooldown.restart(); 
//             this->player->canShoot = false;
//         }
        
//         if(!this->player->canShoot && this->player->shootCooldown.getElapsedTime().asSeconds() >= this->player->shootCooldownTime){
//             music->shotSFX();
//             this->player->canShoot = true;
//         }
//     }
// }
void Level1::updateInput(const float& dt){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        this->endNow = true;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !this->freeze && this->iceCount > 0 && this->currentItemSelected == 1){
        this->freeze = true;
        this->freezeTimer.restart();
        this->iceCount--;
    }

    // Check for a single click of the left mouse button
    bool isLeftMousePressedThisFrame = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    if(isLeftMousePressedThisFrame && !wasLeftMousePressedLastFrame){
        music->shotSFX(); // Assume this plays the shooting sound effect
        if(this->player->canShoot){
            this->shootBullet(*this->player, this->bullets, this->mousePosView);
            this->player->shootCooldown.restart(); 
            this->player->canShoot = false;
        }
    }

    // After processing, update wasLeftMousePressedLastFrame for the next frame
    wasLeftMousePressedLastFrame = isLeftMousePressedThisFrame;

    // Handle cooldown for shooting independently from the click detection
    if(!this->player->canShoot && this->player->shootCooldown.getElapsedTime().asSeconds() >= this->player->shootCooldownTime){
        this->player->canShoot = true;
    }
}



void Level1::update(const float& dt, sf::RenderWindow* window){
    if(!this->showOption && !this->showGuide && !this->showSetting || !endNow){
        this->target.setPosition(this->mousePosView.x, this->mousePosView.y);
        this->updateInput(dt);
        this->player->update(dt, this->mousePosView);
        this->updateSpawnTimer(); 

        if(this->freezeTimer.getElapsedTime().asSeconds() >= 3.0f){
            this->enemySpawner->update(dt, this->enemySpawnInterval, this->mousePosView , this->enemies);
            this->freeze = false;
        }
        
        for(size_t i = 0; i < this->bullets.size(); i++){
            this->bullets[i].update(dt, this->player->bulletAngles[i]);
            if(this->bullets[i].isOutBound()){
                this->bullets.erase(this->bullets.begin() + i);
                this->player->bulletAngles.erase(this->player->bulletAngles.begin() + i);
                break;
            }else{
                for(size_t j = 0; j < this->enemies.size(); j++){
                    if(this->bulletHitEnemy(this->bullets[i], this->enemies[j])){
                        //fume animation
                        this->killCount++;
                        this->enemies.erase(this->enemies.begin() + j);
                        this->bullets.erase(this->bullets.begin() + i);
                        this->player->bulletAngles.erase(this->player->bulletAngles.begin() + i);
                        std::cout << "Bullet hit Enemy" << std::endl;
                        break;
                    }
                }
            }
        }
        
        for(auto& enemy : enemies){
            if(this->isCollided(*this->player, enemy) && this->playerCanTakeHit()){
                this->player->setState(Player::DAMAGED);
                this->player->updateHealthbar(-3);
                this->resetHitCooldown();
                std::cout << "Player hit" << std::endl;
            }
        }

        this->inventoryPanel->update(this->killCount, this->iceCount);
        this->currentItemSelected = this->inventoryPanel->getcurrentItemSelected();
        
        //gen and collect item
        std::random_device rd; 
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> pos_x(60, WINDOW_WIDTH-60);
        std::uniform_int_distribution<> pos_y(100, 600);
        if(this->spawnItemTimer.getElapsedTime().asSeconds() >= 10.0f){ //spawn item every 8 seconds
            this->iceCollectibles.push_back(Collectible(pos_x(gen), pos_y(gen), 0.07f, 0.07f, "../assets/textures/ice.png"));
        }
        if(this->iceCollectibles.size() > 0){
            if(this->iceCollectibles[0].isCollectedByPlayer(*this->player)){
                this->iceCount++;
                this->iceCollectibles.erase(this->iceCollectibles.begin());
                spawnItemTimer.restart(); 
            }
        }

        //freezing effect
        if(this->freeze){
            if( this->freezeColor.a < 255){
                this->freezeColor.a += 5;
            }else{
                this->freezeColor.a = 255;
            }
        }else{
            this->freezeColor.a = 0;
        }
        this->freezeScreen.setColor(this->freezeColor);
    }

    if(this->player->defeated){
        this->playerLose = true;
        this->endNow = true;
    }else if(this->killCount >= 50){
        this->playerLose = false;
        this->endNow = true;
    }
    
    //last
    GameState::update(dt, window);
}

void Level1::loadTextures(sf::Texture& texture, std::string path){
    if(!texture.loadFromFile(path)){
        std::cout << "Player::loadFile:: Error: Player texture not loaded" << std::endl;
    }else{
        std::cout << "Texture load successfully" << std::endl;
    }
}


bool Level1::playerCanTakeHit() const{
    return this->hitCooldownTimer.getElapsedTime() >= this->hitCooldownDuration;
}

void Level1::resetHitCooldown(){
    this->hitCooldownTimer.restart();
}

//player
//myabe a better collision detection
bool Level1::isCollided(Player& player, const Enemy& enemy){
    float distance = sqrt(pow(player.getPosition().x - enemy.getPosition().x, 2) + pow(player.getPosition().y - enemy.getPosition().y, 2)); 
    if(distance <= player.getGlobalBounds().width - 40){
        player.setState(Player::DAMAGED);
        return true;
    }
    return false;
}

bool Level1::bulletHitEnemy(Bullet& b, Enemy& enemy) const{
    if(b.isCollided(enemy)){
    //temp
    // if(b.isCollided(enemy, this->bulletRadius)){
        return true;
    }
    return false;
}

void Level1::shootBullet(Player& p, std::vector<Bullet>& bullets, sf::Vector2f mousePos){
    bullets.push_back(Bullet(p.gunSprite.getPosition().x, p.gunSprite.getPosition().y));
    bullets.back().setRotation(p.gunAngle);
    float angle = std::atan2(mousePos.y - p.getPosition().y , mousePos.x - p.getPosition().x); 
    angle = angle * (180.0f / M_PI);
    this->player->bulletAngles.push_back(angle);
}

//enemy
void Level1::updateSpawnTimer(){
    if(this->killCount < 7){
        this->enemySpawnInterval = 3.0;
    }else if(this->killCount < 20){
        this->enemySpawnInterval = 2.0;
    }else if(this->killCount < 30){
        this->enemySpawnInterval = 1.0;
    }
}

void Level1::render(sf::RenderTarget* target) {
    if(!endNow){
        target->draw(this->background); 
        target->draw(this->bg);

        if(this->iceCollectibles.size() > 0){
            this->iceCollectibles[0].render(target);
        }
    
        for(auto& bullet : this->bullets){
            bullet.render(target);
        }

        this->player->render(target);

        
        for(auto& enemy : this->enemies){
            if(enemy.getState() != Enemy::EnemyStates::DEAD)
                enemy.render(target);
        }

        target->draw(this->target);
        this->inventoryPanel->render(target);


        target->draw(this->freezeScreen);
    }
    //last
    GameState::render(target); 
}


