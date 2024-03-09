#pragma once
#include "../src/Config.h"

class Music
{
private:
    sf::Music backgroundMusic,backgroundSFX;
    float volume,Svolume;

public:
    Music();
    ~Music();
    void render(sf::RenderTarget *target); // Render function
    void setVolume(float volume); // Function to set the volume
    float getVolume();
    void setSVolume(float Svolume); // Function to set the volume
    float getSVolume();
};

