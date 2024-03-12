
#include "../../include/GameState.h"
#include "../../src/Config.h"
#include "../Entities/Player.h"
#include "../Entities/Enemy.h"
#include "../Entities/EnemySpawner.h"
#include "../Entities/Bullet.h"
#include "../../UI/InventoryPanel.h"
#include "../../UI/Collectible.h"

//add healer to inventory panel
//freeze screen later 
class Level1: public GameState{
    private:
        sf::RenderWindow* window;
        sf::RectangleShape background;
        sf::Texture bgTex;
        sf::Sprite bg;
        sf::Sprite target;
        sf::Texture targetTex;
        sf::Sprite freezeScreen;
        sf::Texture freezeScreenTex;
        sf::Color freezeColor;

        std::shared_ptr<Player> player;
        std::shared_ptr<EnemySpawner> enemySpawner;
        std::vector<Bullet> bullets;
        std::vector<Enemy> enemies;
        float enemySpawnInterval = 3.0;
        sf::Text text;
        sf::Font font;
        int killCount = 0;
        bool freeze = false;
        int iceCount = 1;
        std::vector<Collectible> iceCollectibles; 
        
        std::shared_ptr<InventoryPanel> inventoryPanel;
        short currentItemSelected;

        //time delay when collide with enemy
        sf::Clock hitCooldownTimer;
        sf::Time hitCooldownDuration;

        sf::Clock freezeTimer; 

        sf::Clock spawnItemTimer; 


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
        bool playerCanTakeHit() const; 
        void resetHitCooldown(); 

        //enemy
        void updateSpawnTimer(); 


        //shoot bullet 
        void shootBullet(Player& player, std::vector<Bullet>& bullets, sf::Vector2f mousePos);
};  