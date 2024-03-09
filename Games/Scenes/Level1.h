
#include "../../include/GameState.h"
#include "../../src/Config.h"
#include "../Entities/Player.h"
#include "../Entities/Enemy.h"
#include "../Entities/EnemySpawner.h"
#include "../Entities/Bullet.h"


class Level1: public GameState{
    private:
        sf::RenderWindow* window; 

        //temp
        sf::RectangleShape background;
        sf::Texture bgTex;
        sf::Sprite bg;
        std::shared_ptr<Player> player;
        std::shared_ptr<EnemySpawner> enemySpawner;
        std::vector<Bullet> bullets; 
        std::vector<Enemy> enemies; 

    public:
        Level1(sf::RenderWindow* window);
        virtual ~Level1(); 
        void endState() override; 
        // void loadTextures(sf::Texture& tex);
        void loadTextures(sf::Texture& tex, std::string path);
        void updateInput(const float& dt) override;
        void update(const float& dt, sf::RenderWindow* window) override; 
        void updateBulletEnemiesCollision(const float& dt); 
        void render(sf::RenderTarget* target = nullptr) override;

        //player n enemy
        bool isCollided(Player& player, const Enemy& enemy);
        bool bulletHitEnemy(Bullet& b, Enemy& enemy) const; 

        //shoot bullet 
        void shootBullet(Player& player, std::vector<Bullet>& bullets, sf::Vector2f mousePos);
};  