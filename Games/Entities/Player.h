// #include "./../src/Config.h"
#include "../src/Config.h"
#include "Tile.h"

class Player{
    private: 
        std::shared_ptr<sf::Texture> player_tex; 
        std::shared_ptr<sf::Sprite> player_sprite;
        bool canWalk = true;
        float speed = 2.0f; 

    public: 
        Player(const std::string& imgPath, int pos_x, int pos_y, float scale);
        virtual ~Player();
        void update(const float& dt);
        bool isColliding_enemy();//Enemy* enemy);
        bool isColliding_tile(Tile tile_unit);
        void render_player(sf::RenderTarget* target);
};