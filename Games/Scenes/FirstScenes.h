#include "../../include/Gamestate.h"
// #include "../../UI/Message.h"
#include "../../UI/Music.h"

class FirstScenes : public GameState
{
private:
    sf::RenderWindow* window;
    sf::RectangleShape background;
    sf::Texture bg_t, p1t, p2t;
    sf::Sprite p1, p2;
    // Message* message;
    std::vector<std::string> textLine;
    bool enterPress;
    int x;
    sf::RectangleShape Textbox;
    Music* music;


public:
    FirstScenes(sf::RenderWindow* window);
    ~FirstScenes();
    void endState() override;
    void update(const float& dt, sf::RenderWindow* window) override;
    void render(sf::RenderTarget* target) override;
};


