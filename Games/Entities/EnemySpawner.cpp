
// Another version with random spawn and set the spawn positions


#include "EnemySpawner.h"

EnemySpawner::EnemySpawner()
    : spawnTimer(0.0f), spawnInterval(3.0f) // Spawn every 3 seconds
{
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    for(size_t i = 0; i < 20; i++){
        if(i % 3 == 1){
            std::uniform_int_distribution<> dist(50, 740);
            spawnPositions.push_back(sf::Vector2f(dist(gen), 1100.f));
        }else if(i % 3 == 2){
            std::uniform_int_distribution<> dist(0, 1060);
            spawnPositions.push_back(sf::Vector2f(dist(gen), 790.f));
        }else{
            std::uniform_int_distribution<> dist(50, 740);
            spawnPositions.push_back(sf::Vector2f(-50.f, dist(gen)));
        }   
    }
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

void EnemySpawner::update(const float &dt, float spawn_interval, sf::Vector2f mousePos, std::vector<Enemy>& enemies)
{   
    spawnInterval = spawn_interval;
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
