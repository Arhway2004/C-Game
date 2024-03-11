//problem
//td
//uneralistic bullet collision enemy too easy 1
//multiple collision
//enemy stop when player stop : Teemy
//design when move up or down , animation when idle

//creating 
//player flashes when colliding 3
//laser gun
//inventories 2

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

    this->player = std::make_shared<Player>();
    enemySpawner = std::make_shared<EnemySpawner>();   

    this->hitCooldownDuration = sf::seconds(1.0f);
}

Level1::~Level1(){
    
}

void Level1::endState(){
    std::cout << "Ending Level1" << "\n";
}

void Level1::updateInput(const float& dt){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        this->endNow = true;
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            // this->playerState = SHOOTING;
        if(this->player->canShoot){
            this->shootBullet(*this->player, this->bullets, this->mousePosView);
            this->player->shootCooldown.restart(); 
            this->player->canShoot = false;
        }
        
        if(!this->player->canShoot && this->player->shootCooldown.getElapsedTime().asSeconds() >= this->player->shootCooldownTime){
            this->player->canShoot = true;
        }
    }
}

void Level1::update(const float& dt, sf::RenderWindow* window){
    this->target.setPosition(this->mousePosView.x, this->mousePosView.y);
    this->updateInput(dt);
    // this->player->update(dt, this->mousePosView);
    // this->enemySpawner->update(dt, this->mousePosView , this->enemies);

    for(size_t i = 0; i < this->bullets.size(); i++){
        this->bullets[i].update(dt, this->player->bulletAngles[i]);
        if(this->bullets[i].isOutBound()){
            this->bullets.erase(this->bullets.begin() + i);
            this->player->bulletAngles.erase(this->player->bulletAngles.begin() + i);
        }

        for(size_t j = 0; j < this->enemies.size(); j++){
            if(this->bulletHitEnemy(this->bullets[i], this->enemies[j])){
                this->killCount++;
                this->bullets.erase(this->bullets.begin() + i);
                this->player->bulletAngles.erase(this->player->bulletAngles.begin() + i);
                this->enemies.erase(this->enemies.begin() + j);
                // this->enemies[j].setState(Enemy::EnemyStates::DAMAGED);
                // this->enemies[j].updateState();
                // if(enemies[j].getState() == Enemy::EnemyStates::DEAD){
                //     this->enemies.erase(this->enemies.begin() + j);
                // }
                std::cout << "Bullet hit Enemy" << std::endl;
            }
        }
    }
    

    for(auto& enemy : enemies){
        if(this->isCollided(*this->player, enemy) && this->playerCanTakeHit()){
            //since this runs every update, the player runs ouut of health quicktly 
            this->player->setState(Player::DAMAGED);
            this->player->updateHealthbar(-3);
            this->resetHitCooldown();
            std::cout << "Player hit" << std::endl;
        }
    }
    this->inventoryPanel->update(this->killCount);

    //last
    GameState::update(dt, window);
}

// void Level1::updateBulletEnemiesCollision(const float& dt){
//     for (auto bullet = this->bullets.begin(); bullet != this->bullets.end();) {
//         bullet->update(dt, this->player->bulletAngles[std::distance(this->bullets.begin(), bullet)]);

//         if (bullet->isOutBound()) {
//             bullet = this->bullets.erase(bullet);
//             this->player->bulletAngles.erase(this->player->bulletAngles.begin() + std::distance(this->bullets.begin(), bullet));
//         } else {
//             bool bulletHitEnemy = false;
//             for (auto enemy = this->enemies.begin(); enemy != this->enemies.end();) {
//                 if (this->bulletHitEnemy(*bullet, *enemy)) {
//                     bullet = this->bullets.erase(bullet);
//                     this->player->bulletAngles.erase(this->player->bulletAngles.begin() + std::distance(this->bullets.begin(), bullet));
//                     enemy = this->enemies.erase(enemy);
//                     // enemy->setState(Enemy::EnemyStates::DAMAGED);
//                     // enemy->update(dt, this->mousePosView);
//                     // if(enemy->getState() == Enemy::EnemyStates::DEAD){
//                     //     enemy = this->enemies.erase(enemy);
//                     // }
//                     bulletHitEnemy = true;
//                     std::cout << "Bullet hit Enemy" << std::endl;
//                 } else {
//                     ++enemy;
//                 }
//             }
//             if (!bulletHitEnemy) {
//                 ++bullet;
//             }
//         }
//     }
// }


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

void Level1::render(sf::RenderTarget* target) {
    if(!endNow){
        target->draw(this->background); 
        target->draw(this->bg);

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
    }
    //last
    GameState::render(target); 
}


