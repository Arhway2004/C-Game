#pragma once
#include "../src/Config.h"

class Music
{
private:
    sf::Music backgroundMusic;
    float volume;

public:
    Music();
    ~Music();
    void render(sf::RenderTarget *target); // Render function
    void setVolume(float volume); // Function to set the volume
};
