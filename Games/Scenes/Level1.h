
#include "../../include/GameState.h"
#include "../../src/Config.h"
#include "../Entities/Player.h"
#include "../Entities/Enemy.h"
#include "../Entities/EnemySpawner.h"
class Level1 : public GameState
{
private:
    std::shared_ptr<sf::RenderWindow> window;

    // temp
    sf::RectangleShape background;
    sf::Texture bgTex;
    sf::Sprite bg;
    Player player;
    Enemy enemy;
    // Enemy enemy1;
    // Enemy enemy2;
    // Enemy enemy3;
    // Enemy enemy4;
    EnemySpawner enemySpawner;
    sf::Texture enemyTexture;
    std::vector<Enemy> enemies;
    // float enemySpawnTimer = 0.0f;
    // float spawnInterval = 2.0f;

public:
    Level1(sf::RenderWindow *window); 
    virtual ~Level1();
    void endState() override;
    // void loadTextures(sf::Texture& tex);
    void loadTextures(sf::Texture &tex, std::string path);
    void updateInput(const float &dt);
    void update(const float &dt, sf::RenderWindow *window) override;
    void render(sf::RenderTarget *target = nullptr) override;
    // void spawnEnemy(const float &dt);
};