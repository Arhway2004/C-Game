#ifndef BULLET_H
#define BULLET_H

#include "Enemy.h"

class Bullet{
    private:
        sf::Vector2f position;
        sf::Vector2f velocity; 
        // sf::Texture bulletTexture;  
        // std::shared_ptr<sf::Texture> bulletTexture;


        int bulletSpeed, bulletDamage, bulletDirection;
        bool destroy;

    public:
        sf::Sprite bulletSprite;
        std::shared_ptr<sf::Texture> bulletTexture;


        Bullet(const float pos_x, const float pos_y);
        Bullet();
        virtual ~Bullet();
        void loadFile(sf::Texture& tex, std::string path) ;
        void setPosition(const float x, const float y) ;
        void resetImage(std::string path, float scale_x, float scale_y);
        void setRotation(const float angle);
        sf::Vector2f getPosition() const;
        void move(const float& dt, const float x, const float y, const float movementSpeed, const float angle); 
        void update(const float& dt, const float angle);
        bool isOutBound() const;
        bool isCollided(Enemy& enemy) const;  //check if object is collided
        bool isCollided(Enemy& enemy, float radius) const;
        bool isEnemyWithinRadius(const Enemy& enemy, int radius);

        void updateInput(const float& dt, const float angle);
        void render(sf::RenderTarget* target) ;
};

#endif

//bullet set origin/position when shooting player::shoot()
//set rotation 


