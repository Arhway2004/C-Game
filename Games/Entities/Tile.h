#include "../src/Config.h"

class Tile{
    private: 
        sf::Texture tile_img; 
        sf::Sprite tile_sprite;

    public: 
        Tile(const std::string& imgPath, int pos_x, int pos_y, float scale);
        virtual ~Tile();
        bool isColliding(sf::Vector2f& player_pos); 
        void render_tile(sf::RenderTarget* target);
};