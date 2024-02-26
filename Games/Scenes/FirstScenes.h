#include "../../include/Gamestate.h"
#include "/Users/yangyaohui/Desktop/Arhway/C-Game/UI/Message.h"
#include "/Users/yangyaohui/Desktop/Arhway/C-Game/Games/Settings/Guide.h"

class FirstScenes : public GameState
{
private:
    sf::RenderWindow* window;
    sf::RectangleShape background;
    sf::Texture bg_t, p1t, p2t;
    sf::Sprite p1, p2;
    Message* message;
    Guide* guide;
    std::vector<std::string> textLine;
    bool enterPress;
    int x;
    sf::RectangleShape Textbox;


public:
    FirstScenes(sf::RenderWindow* window);
    ~FirstScenes();
    void endState() override;
    void update(const float& dt) override;
    void render(sf::RenderTarget* target) override;
};


