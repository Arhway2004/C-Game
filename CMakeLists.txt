cmake_minimum_required(VERSION 3.16)
project(C-GAME LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(C-GAME src/main.cpp src/Game.cpp src/GameState.cpp Games/Scenes/Basement.cpp 
Games/Scenes/FirstScenes.cpp Games/Scenes/MainMenu.cpp UI/Button.cpp UI/ClickableIcon.cpp UI/Interactable_obj.cpp 
UI/Message.cpp Games/Settings/Base.cpp Games/Settings/Guide.cpp Games/Settings/Guide.cpp Games/Settings/Options.cpp)

target_include_directories(C-GAME PRIVATE "${SFML_SOURCE_DIR}/include")
target_link_libraries(C-GAME PRIVATE sfml-audio sfml-graphics sfml-window sfml-system)
target_compile_features(C-GAME PRIVATE cxx_std_17)
find_package(SFML 2.6.1 COMPONENTS system window graphics network audio REQUIRED)


if(WIN32)
    add_custom_command(
        TARGET C-GAME
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:CMakeSFMLProject>
        VERBATIM)
endif()



install(TARGETS C-GAME)