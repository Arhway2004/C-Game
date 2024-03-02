#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"
#include "Player.h"

class Bullet : public Entity{
    private:
        sf::Vector2f position;
        sf::Sprite bulletSprite;
        sf::Texture bulletTexture;
        int bulletSpeed, bulletDamage, bulletDirection;
        bool destroy;
        Player::PlayerStates playerState;   

    public:
        Bullet();
        virtual ~Bullet();
        void loadFile(sf::Texture& tex, std::string path) override;
        void setPosition(const float x, const float y) override;
        void setPosition(Player& player); //real one
        void move(const float& dt, const float x, const float y, const float movementSpeed) override;
        void update(const float& dt) override;
        bool isOutBound() const override;
        bool isCollided(const Entity& entity) const override;  //check if object is collided
        void updateInput(const float& dt) override;
        void render(sf::RenderTarget* target) override;
};

#endif

