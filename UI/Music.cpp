#include "Music.h"

Music::Music() : volume(100.0f) {
    // Load and play music
    if (!backgroundMusic.openFromFile("/Users/arhway/Desktop/Arhway/C-Game/assets/sounds/background audio.wav")) {
        std::cout << "Failed to load background music" << std::endl;
    } else {
        backgroundMusic.setVolume(volume); // Set the volume
        backgroundMusic.play(); // Play the music
    }
}

Music::~Music() {
    // Stop and release resources when the object is destroyed
    backgroundMusic.stop();
}

void Music::render(sf::RenderTarget *target) {

}

void Music::setVolume(float volume) {
    this->volume = volume;
    backgroundMusic.setVolume(volume);
}
