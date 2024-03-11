
#include "Level1.h"

Level1::Level1(sf::RenderWindow *window) : GameState(window) //, enemySpawnTimer(0.0f), spawnInterval(2.0f)
{
    this->endNow = false;
    // this->player = Player2(300.f, 300.f);
    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Black);
    this->loadTextures(this->bgTex, "../assets/textures/map.png");
    this->bg.setTexture(this->bgTex);
    this->bg.setScale(2.f, 2.1f);
    this->bg.setPosition(0.f, 0.f);
    // enemySpawner = EnemySpawner(); 
    this->enemy.setPosition(600.f, 600.f);
    // this->enemy1.setPosition(500.f, 400.f);
    // this->enemy2.setPosition(300.f, 200.f);
    // this->enemy3.setPosition(700.f, 300.f);
    // this->enemy4.setPosition(200.f, 400.f);
}

Level1::~Level1()
{
}

void Level1::endState()
{
    std::cout << "Ending Level1"
              << "\n";
}

void Level1::updateInput(const float &dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        this->endNow = true;
    }
}

// void Level1::spawnEnemy(const float &dt)
// {
//     Enemy newEnemy;
//     newEnemy.setPosition(400.f, 800.f);
//     enemies.push_back(newEnemy);
// }

void Level1::update(const float &dt, sf::RenderWindow *window)
{
    
    // enemySpawnTimer += dt;
    // if (enemySpawnTimer >= spawnInterval)
    // {
    //     spawnEnemy(dt);
    //     enemySpawnTimer = 0.0f;
    // }
    // for (auto &enemy : enemies)
    // {
    //     enemy.update(dt);
    // }
    this->updateInput(dt);
    this->updateOptions();
    this->player.update(dt);
    this->enemy.update(dt);
    enemySpawner.update(dt);
    // this->enemy1.update(dt);
    // this->enemy2.update(dt);
    // this->enemy3.update(dt);
    // this->enemy4.update(dt);
    
    sf::Vector2f playerPosition = player.getPosition();
    std::cout << "Player Position: " << playerPosition.x << ", " << playerPosition.y << std::endl;
    // last
    GameState::update(dt, window);
}

void Level1::loadTextures(sf::Texture &texture, std::string path)
{
    if (!texture.loadFromFile(path))
    {
        std::cout << "Player::loadFile:: Error: Player texture not loaded" << std::endl;
    }
    else
    {
        std::cout << "Texture load successfully" << std::endl;
    }
}

void Level1::render(sf::RenderTarget *target)
{
    if (!endNow)
    {
        target->draw(this->background);
        target->draw(this->bg);
        this->player.render(target);
        // this->enemy.render(target);
        // this->enemy1.render(target);
        // this->enemy2.render(target);
        // this->enemy3.render(target);
        // this->enemy4.render(target);

        // for (auto &enemy : enemies)
        // {
        //     enemy.render(target);
        // }

        enemySpawner.render(target);
    }
    // last
    GameState::render(target);
}
