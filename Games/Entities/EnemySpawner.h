#pragma once

#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H
#include "../../src/Config.h"
#include "../../src/Constant.h"
#include "Enemy.h"

// class EnemySpawner
// {
// public:
//     EnemySpawner(float spawnDelay);
//     EnemySpawner(); // Default constructor
//     ~EnemySpawner();

//     void update(const float &dt);
//     void render(sf::RenderTarget *target);

//     // Add enemies to the spawner for automatic spawning
//     void addEnemy();

//     sf::Texture enemyTexture;

// private:
//     std::vector<Enemy> enemies;
//     float spawnDelay;
//     float spawnTimer;
// };

// #endif

// #ifndef ENEMYSPAWNER_H
// #define ENEMYSPAWNER_H

// #include <vector>
// #include "Enemy.h"

class EnemySpawner
{
public:
    EnemySpawner();
    ~EnemySpawner();

    void spawnEnemy(); // Create a new enemy
    void enemyDied();  // Called when an enemy dies (or is otherwise removed from the game world

    void update(const float &dt);
    void render(sf::RenderTarget *target);

private:
    std::vector<Enemy> enemies;

    // Spawning parameters:
    float spawnTimer;
    float spawnInterval;                      // Time between spawns
    std::vector<sf::Vector2f> spawnPositions; // Potential places to spawn enemies
    Player player;
    int MaxAliveEnemies;
    int CurrentAliveEnemies;
};

#endif

// #include <vector>
// #include <random>

// class EnemySpawner
// {
// public:
//     EnemySpawner(float spawnInterval); // Constructor
//     EnemySpawner();                    // Default constructor   
//     ~EnemySpawner();

//     void update(const float &deltaTime);
//     void render(sf::RenderTarget *target);

// private:
//     float spawnTimer;
//     float spawnInterval;
//     std::vector<Enemy> enemies;
//     Player player;

//     // Helper for random position generation
//     float randomSpawnPositionX();
//     float randomSpawnPositionY();
// };
// #endif