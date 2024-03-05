#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"
#include "Enemy.h"

class Bullet : public Entity{
    private:
        sf::Vector2f position;
        sf::Vector2f velocity; 
        sf::Sprite bulletSprite;
        // sf::Texture bulletTexture;
        std::shared_ptr<sf::Texture> bulletTexture;

        int bulletSpeed, bulletDamage, bulletDirection;
        bool destroy;

    public:
        Bullet(const float pos_x, const float pos_y);
        Bullet();
        virtual ~Bullet();
        void loadFile(sf::Texture& tex, std::string path) override;
        void setPosition(const float x, const float y) override;
        void setRotation(const float angle);
        void move(const float& dt, const float x, const float y, const float movementSpeed) override;
        void move(const float& dt, const float x, const float y, const float movementSpeed, const float angle); 

        void update(const float& dt) override;
        void update(const float& dt, const float angle);

        bool isOutBound() const override;
        bool isCollided(const Enemy& enemy) const;  //check if object is collided
        void updateInput(const float& dt) override;
        void updateInput(const float& dt, const float angle);

        void render(sf::RenderTarget* target) override;
};

#endif

//bullet set origin/position when shooting player::shoot()
//set rotation 


