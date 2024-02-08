
run project for first time
g++ -c main.cpp
g++ main.o -o my_game -L/usr/local/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system
./my_game

run 
g++ -o my_game main.cpp Game.cpp GameState.cpp MainMenu.cpp ../UI/Button.cpp  -lsfml-graphics -lsfml-window -lsfml-system./my_game
