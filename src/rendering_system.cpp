#include "rendering_system.hpp"
#include <iostream>

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

void RenderingSystem::render() {

    GlobalState &state = GlobalState::inst();
    Scene       &scene = Scene::inst();
    Bubble      &bubble = scene.get_bubble();

    ClearBackground(Color{255, 0, 255, 0});
    BeginDrawing();


    switch (state.game_state) {
    case GameState::BASE:
        render_base_scene();
        break;
    case GameState::MOVING:
        render_moving_scene();
        break;
    default:
        break;
    }

    if (GuiButton((Rectangle){24, 24, 120, 30}, "#Show Message")) {
        std::cout << "Message\n";
    }

    EndDrawing();
}

void RenderingSystem::render_base_scene(){

}

void RenderingSystem::render_moving_scene(){

}
