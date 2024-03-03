// #include "Entity.h"

// Entity::Entity() {

//     // this->shape.setSize(sf::Vector2f(50.f, 50.f));
//     // this->shape.setPosition(300.f, 300.f);
//     // this->shape.setFillColor(sf::Color::Green);
// }

// Entity::~Entity() {

// }
// void Entity::createSprite(std::shared_ptr<sf::Texture> texture){
//     this->texture = *texture;
// }

// void Entity::move(const float& dt, const float dir_x, const float dir_y) {
//     // this->shape.move(dir_x * this->movementSpeed * dt ,dir_y * this->movementSpeed * dt);
//     this->player.move(dir_x * this->movementSpeed * dt ,dir_y * this->movementSpeed * dt);

// }

// void Entity::update(const float& dt) {

//     //set default texture to idle

//     if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){

//         this->move(dt, -1.f, 0.f);
//     }
//     if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
//         if(!playerTexture.loadFromFile("../assets/textures/player_run.png")){
//             std::cout << "Entity::Entity:: Error: Player texture not loaded" << std::endl;
//         }
//         int xTexture = 0;
//         xTexture = (int)this->player.getPosition().x / 35 % 8; //slow down 35 frames
//         xTexture = xTexture * 112.5;
//         this->player.setTextureRect(sf::IntRect(xTexture, 0, 112.5, 113));  //x, y, w, h>
//         this->move(dt, 1.f, 0.f);
//     }
//     if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
//         this->move(dt, 0.f, -1.f);
//     }
//     if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
//         this->move(dt, 0.f, 1.f);
//     }
// }

// void Entity::render(sf::RenderTarget* target) {
//     target->draw(this->player);
//     // target->draw(this->shape);
// }
