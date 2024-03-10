
// Another version with random spawn and set the spawn positions

#include "EnemySpawner.h"

EnemySpawner::EnemySpawner()
    : spawnTimer(0.0f), spawnInterval(3.0f) // Spawn every 3 seconds
{
    // Initialize with some basic spawn positions
    spawnPositions.push_back(sf::Vector2f(-100.0f, 100.0f));
    //  
    // ... add more as needed
}

EnemySpawner::~EnemySpawner()
{
    // The vector 'enemies' will clean up its member objects automatically
}

void EnemySpawner::spawnEnemy(std::vector<Enemy>& enemies)
{
    Enemy newEnemy;
    // choose a random spawn position from the position vector:
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, spawnPositions.size() - 1);

    newEnemy.setPosition(spawnPositions[dist(gen)].x, spawnPositions[dist(gen)].y);
    enemies.push_back(newEnemy);
}

void EnemySpawner::update(const float &dt, sf::Vector2f mousePos, std::vector<Enemy>& enemies)
{
    spawnTimer += dt;
    if (spawnTimer >= spawnInterval)
    {
        spawnEnemy(enemies);
        spawnTimer = 0.0f; // Reset the timer
    }

    // Update each enemy
    for (auto &enemy : enemies)
    {
        enemy.update(dt, mousePos);
    }
    

}

// void EnemySpawner::render(sf::RenderTarget *target)
// {
//     for (auto &enemy : enemies)
//     {
//         enemy.render(target);
//     }
// }
