#include "EnemySpawner.h"

// EnemySpawner::EnemySpawner(float spawnDelay)
//     : spawnDelay(spawnDelay), spawnTimer(0.0f)
// {
// }

// EnemySpawner::EnemySpawner()
//     : spawnDelay(1.0f), spawnTimer(0.0f) // Default constructor
// {
// }

// EnemySpawner::~EnemySpawner()
// {
// }

// void EnemySpawner::addEnemy()
// {
//     enemies.push_back(Enemy()); // Assuming your Enemy class has a default constructor
// }

// void EnemySpawner::update(const float &dt)
// {
//     spawnTimer += dt;

//     if (spawnTimer >= spawnDelay)
//     {
//         addEnemy();        // Create a new enemy
//         spawnTimer = 0.0f; // Reset the spawn timer
//     }

//     // Update positions of all existing enemies
//     for (auto &enemy : enemies)
//     {
//         enemy.update(dt);
//     }
// }

// void EnemySpawner::render(sf::RenderTarget *target)
// {
//     for (auto &enemy : enemies)
//     {
//         enemy.render(target);
//     }
// }

// Another version with random spawn and set the spawn positions

#include "EnemySpawner.h"

EnemySpawner::EnemySpawner()
    : spawnTimer(0.0f), spawnInterval(3.0f), MaxAliveEnemies(10), CurrentAliveEnemies(0)
{
    // Initialize with some basic spawn positions
    spawnPositions.push_back(sf::Vector2f(-100.0f, 100.0f));
    //
    // ... add more as needed

}

EnemySpawner::~EnemySpawner()
{

}

void EnemySpawner::spawnEnemy()
{
    if (CurrentAliveEnemies < MaxAliveEnemies)
    {
        Enemy newEnemy;

        // choose a random spawn position from the position vector:
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, spawnPositions.size() - 1);

        newEnemy.setPosition(spawnPositions[dist(gen)].x, spawnPositions[dist(gen)].y);
        enemies.push_back(newEnemy);
        CurrentAliveEnemies++;
    }
}

void EnemySpawner::enemyDied()
{
    CurrentAliveEnemies--;
}

void EnemySpawner::update(const float &dt)
{

    spawnTimer += dt;
    if (spawnTimer >= spawnInterval)
    {
        spawnEnemy();
        spawnTimer = 0.0f; // Reset the timer
    }

    //Update each enemy
    for (auto &enemy : enemies)
    {
        enemy.update(dt);
    }

}

void EnemySpawner::render(sf::RenderTarget *target)
{
    for (auto &enemy : enemies)
    {
        enemy.render(target);
    }
}

// #include <ctime> // For seeding the random number generator

// EnemySpawner::EnemySpawner(float spawnInterval) : spawnTimer(0.0f),
//                                                   spawnInterval(spawnInterval)
// {
//     std::srand(std::time(nullptr)); // Seed randomizer
// }

// EnemySpawner::EnemySpawner() : spawnTimer(0.0f),
//                                spawnInterval(3.0f) // Default spawn interval
// {
//     std::srand(std::time(nullptr)); // Seed randomizer
// }

// EnemySpawner::~EnemySpawner()
// {
//     // Note: Consider if you need explicit cleanup for enemies
// }

// void EnemySpawner::update(const float &deltaTime)
// {
//     spawnTimer += deltaTime;

//     if (spawnTimer >= spawnInterval)
//     {
//         Enemy newEnemy;
//         newEnemy.setPosition(randomSpawnPositionX(), randomSpawnPositionY());
//         enemies.push_back(newEnemy);
//         spawnTimer = 0.0f; // Restart the timer
//     }

//     // Update and manage existing enemies
//     for (auto &enemy : enemies)
//     {
//         enemy.update(deltaTime);

//         // Optional: Remove off-screen enemies
//         if (enemy.isOutBound())
//         {
//             // Remove enemy from vector (consider using iterators with erase-remove idiom)
//         }
//     }
// }

// void EnemySpawner::render(sf::RenderTarget *target)
// {
//     for (auto &enemy : enemies)
//     {
//         enemy.render(target);
//     }
// }

// float EnemySpawner::randomSpawnPositionX()
// {
//     return std::rand() % WINDOW_WIDTH; // Adjust based on your screen size
// }

// float EnemySpawner::randomSpawnPositionY()
// {
//     return std::rand() % WINDOW_HEIGHT; // Adjust based on your screen size
// }
