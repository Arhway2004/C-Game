#include "Player.h"
//problem: check player out of bound / or area that can't walk
//when idle player not move
//add isCollided function
//gun point init weird 

Player::Player(){
    this->loadFile(this->testTexture, "../assets/textures/right_idle2.png");
    this->testSprite.setTexture(this->testTexture);
    this->testSprite.setPosition(300.f, 300.f);
    this->testSprite.setTextureRect(sf::IntRect(0, 0, 80, 80));  //x, y, w, h
    this->testSprite.setScale(2.f, 2.f);
    this->testSprite.setOrigin(32.f, 40.f);

    //init gun
    this->loadFile(this->gunTexture, "../assets/textures/gun_r.png");
    this->gunSprite.setTexture(this->gunTexture);
    this->gunSprite.setPosition(testSprite.getPosition().x + this->gunSprite.getGlobalBounds().width, testSprite.getPosition().y);
    this->gunSprite.setScale(2.f, 2.f);//x, y, w, h
    this->gunSprite.setOrigin(0.f, 0.f);
}

Player::~Player(){
    
}

void Player::setPosition(const float x, const float y){
    this->testSprite.setPosition(x, y);
}

void Player::updateOrigin(){
    switch(this->playerState){
        case IDLE:
        case IDLE_LEFT:
            this->testSprite.setOrigin(64/2, 80/2);
            this->gunSprite.setOrigin(this->gunTexture.getSize().x, 0.f);
            this->gunSprite.setPosition(testSprite.getPosition().x + (this->gunTexture.getSize().x/5), testSprite.getPosition().y);
            break;
        case IDLE_RIGHT:
            this->testSprite.setOrigin(64/2, 80/2);
            this->gunSprite.setOrigin(0.f, 0.f);
            this->gunSprite.setPosition(testSprite.getPosition().x, testSprite.getPosition().y);
            break;
        case MOVING_LEFT:
        case MOVING_RIGHT:
            this->testSprite.setOrigin(80/2, 80/2);
            break;
        default:
            std::cout << "Player::updateOrigin:: Error: Player state not found" << std::endl;
            break;
    }
}

void Player::loadFile(sf::Texture& texture, std::string path){
    if(!texture.loadFromFile(path)){
        std::cout << "Player::loadFile:: Error: Player texture not loaded" << std::endl;
    }else{
        std::cout << "Texture load successfully" << std::endl;
    }
}

void Player::move(const float& dt, const float x, const float y, const float movementSpeed){
    this->testSprite.move(x * movementSpeed * dt ,y * movementSpeed * dt); 
}

void Player::update(const float& dt){
    
}

void Player::update(const float& dt, sf::Vector2f mousePos){
    // this->updateInput(dt);
    this->updateMovement(dt, mousePos);
    this->updateOrigin();
    this->updateGunMovement(mousePos);
    this->updateAnimation();

    //update bullet and check bullet out of bound
    for(int i = 0; i < bullets.size(); i++){
        bullets[i].update(dt, this->bulletAngles[i]);
        if (bullets[i].isOutBound()){
            bullets.erase(bullets.begin() + i); 
            bulletAngles.erase(bulletAngles.begin() + i);
        }
    }
}


void Player::updateInput(const float& dt){
    int xTexture = 0; 

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        this->move(dt, -1.f, 0.f, 200.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){ 
        this->loadFile(this->testTexture, "../assets/textures/player_run.png");
        xTexture = (int)this->testSprite.getPosition().x / 35 % 8; //slow down 35 frames
        xTexture = xTexture * 80;
        this->testSprite.setTextureRect(sf::IntRect(xTexture, 0, 80, 80));  //x, y, w, h>
        this->move(dt, 1.f, 0.f, 200.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        this->move(dt, 0.f, -1.f, 200.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        this->move(dt, 0.f, 1.f, 200.f);
    }
}

void Player::updateMovement(const float& dt, sf::Vector2f mousePos){
    this->playerState = IDLE;
    // std::cout << "Player::outbound:: " << this->isOutBound() << std::endl;
    // if(!this->isOutBound()){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            this->playerState = MOVING_LEFT;
            this->move(dt, -1.f, 0.f, 200.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){     
            this->playerState = MOVING_RIGHT;   
            this->move(dt, 1.f, 0.f, 200.f);
            // std::cout << "player x: " << this->testSprite.getPosition().x << " player y: " << this->testSprite.getPosition().y << std::endl;
            // std::cout << "player out of bound: " << this->isOutBound() << std::endl;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            this->move(dt, 0.f, -1.f, 200.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            this->move(dt, 0.f, 1.f, 200.f);
        }
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            // this->playerState = SHOOTING;
            if(this->canShoot){
                this->shootBullet(bullets, mousePos);
                this->shootCooldown.restart(); 
                this->canShoot = false;
            }
            
            if(!canShoot && this->shootCooldown.getElapsedTime().asSeconds() >= this->shootCooldownTime){
                this->canShoot = true;
            }
        }

        if(prevState == MOVING_LEFT && playerState == IDLE){
            this->playerState = IDLE_LEFT;
        }else if(prevState == MOVING_RIGHT && playerState == IDLE){
            this->playerState = IDLE_RIGHT;
        }else{
            prevState = playerState;
        }
    // }
}

void Player::shootBullet(std::vector<Bullet>& bullets, sf::Vector2f mousePos){
    bullets.push_back(Bullet(this->gunSprite.getPosition().x, this->gunSprite.getPosition().y));
    bullets.back().setRotation(this->gunAngle);
    float angle = std::atan2(mousePos.y - this->testSprite.getPosition().y , mousePos.x - this->testSprite.getPosition().x); 
    angle = angle * (180.0f / M_PI);
    bulletAngles.push_back(angle);
}

bool Player::bulletHitEnemy(Enemy& enemy) const{
    for(auto& bullet : this->bullets){
        if(bullet.isCollided(enemy)){
            return true;
        }
    }
    return false;
}

void Player::updateGunMovement(sf::Vector2f mousePos){
// this->gunSprite.setPosition(testSprite.getPosition().x - 2*this->gunSprite.getLocalBounds().width, testSprite.getPosition().y);
    float angle = 0.0;
    if(this->playerState == IDLE_RIGHT || this->playerState == IDLE){
        angle = std::atan2(mousePos.y - this->gunSprite.getPosition().y , mousePos.x - this->gunSprite.getPosition().x); 
    }else if(this->playerState == IDLE_LEFT){
        angle = -1 * std::atan2(mousePos.y - this->gunSprite.getPosition().y , (this->gunSprite.getPosition().x + this->gunTexture.getSize().x) - mousePos.x);
    }
   
    angle = angle * 180.f / static_cast<float>(M_PI);
    this->gunAngle = angle;
    this->gunSprite.setRotation(angle);
    //rotate bullet
}

bool Player::isOutBound() const{
    if((this->testSprite.getPosition().x > 0 || this->testSprite.getPosition().x < WINDOW_WIDTH) && (this->testSprite.getPosition().y > 0 || this->testSprite.getPosition().y < WINDOW_HEIGHT)){
        return false;
    }
    return true;
}

//here
bool Player::isCollided(const Enemy& enemy){
    float distance = sqrt(pow(this->testSprite.getPosition().x - enemy.getPosition().x, 2) + pow(this->testSprite.getPosition().y - enemy.getPosition().y, 2)); 
    if(distance <= (this->testSprite.getGlobalBounds().width + enemy.getGlobalBounds().height)/2){
        this->playerState = DAMAGED;
        return true;
    }
    return false;
}

void Player::updateAnimation(){
    int xTexture = 0;
    switch(this->playerState){
        case IDLE:
            animation.updateAnimation(this->testSprite, this->testTexture, 0, 64, 80, 1, 35, "../assets/textures/right_idle2.png");
            this->loadFile(this->gunTexture, "../assets/textures/gun_r.png");
            // if(this->prevState == MOVING_LEFT){
            //     animation.updateAnimation(this->testSprite, this->testTexture, 240, 64, 80, 4, 35, "../assets/textures/player_idle.png");
            // }else{
            // }
            break;
        case MOVING_LEFT:
            animation.updateAnimation(this->testSprite, this->testTexture, 240, 80, 80, 8, 35, "../assets/textures/player_run.png");
            break;
        case MOVING_RIGHT:
            animation.updateAnimation(this->testSprite, this->testTexture, 160, 80, 80, 8, 35, "../assets/textures/player_run.png");
            break;
        case IDLE_LEFT:
            animation.updateAnimation(this->testSprite, this->testTexture, 0, 64, 80, 1, 35, "../assets/textures/left_idle2.png");
            this->loadFile(this->gunTexture, "../assets/textures/gun_l.png");
            break;
        case IDLE_RIGHT:
            animation.updateAnimation(this->testSprite, this->testTexture, 0, 64, 80, 1, 35, "../assets/textures/right_idle2.png");
            this->loadFile(this->gunTexture, "../assets/textures/gun_r.png");
            break;
        case SHOOTING:
            break;
        default:
            animation.updateAnimation(this->testSprite, this->testTexture, 0, 64, 80, 4, 35, "../assets/textures/player_idle.png");
            break;
    }
}

void Player::render(sf::RenderTarget* target){
    target->draw(this->testSprite);

    for(auto& bullet : bullets){
        bullet.render(target);
    }
    if(this->playerState == IDLE_LEFT || this->playerState == IDLE_RIGHT || this->playerState == IDLE){
        target->draw(this->gunSprite);
    }
}


//set enemy origin to center 
//recalculate collision point(distant from player's origin to enemy's origin)

