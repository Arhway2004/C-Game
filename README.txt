
run project for first time
g++ -c main.cpp
g++ main.o -o my_game -L/usr/local/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system
./my_game

run
g++ -Wall -Wextra -g -fsanitize=address -O0 -o my_game main.cpp Game.cpp GameState.cpp ../UI/Button.cpp ../UI/ClickableIcon.cpp ../Games/Settings/Base.cpp ../Games/Settings/Options.cpp ../Games/Scenes/Basement.cpp ../Games/Scenes/MainMenu.cpp ../Games/Settings/Guide.cpp ../UI/Message.cpp ../Games/Scenes/FirstScenes.cpp ../UI/interactable_obj.cpp  -lsfml-graphics -lsfml-window -lsfml-system
./my_game


not work bc it overlap to the start/end btn so when pressed it also pressed/start and end

git fork 
rebase branch to make it catch up to main and merge into it 
resolve conflict 

.
