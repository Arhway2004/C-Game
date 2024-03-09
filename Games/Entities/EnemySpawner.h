#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H

#include <vector>
#include "Enemy.h"

class EnemySpawner
{
public:
    EnemySpawner();
    ~EnemySpawner();

    void spawnEnemy(std::vector<Enemy>& enemies); // Create a new enemy

    void update(const float &dt,  sf::Vector2f mousePos, std::vector<Enemy>& enemies);
    // void render(sf::RenderTarget *target);

private:
    // std::vector<Enemy> enemies;

    // Spawning parameters:
    float spawnTimer;
    float spawnInterval;                      // Time between spawns
    std::vector<sf::Vector2f> spawnPositions; // Potential places to spawn enemies
};

#endif