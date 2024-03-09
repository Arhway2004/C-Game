#include "../src/Config.h"

class Healthbar{
    private:
        sf::Vector2f position;
        int damage; //(%)damage per hit
        int health; //(%)total damage can accept 
        sf::RectangleShape frame;
        sf::RectangleShape blood;
        sf::Color bloodColor; 

    public:
        Healthbar(); 
        ~Healthbar();
        void update(const float& dt);
        void decreaseHealth(int damage);
        void render(sf::RenderTarget* target);

}; 