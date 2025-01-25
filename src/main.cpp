
#include "raylib.h"

#include <iostream>

#include "game_state.hpp"
#include "gameplay_system.hpp"
#include "rendering_system.hpp"
#include "scene.hpp"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

void step() {
    auto &state = GlobalState::inst();
    state.window_width = GetScreenWidth();
    state.window_height = GetScreenHeight();

    GameplaySystem::update();
    RenderingSystem::render();
}

int main(void) {
    auto &state = GlobalState::inst();
    state.window_width = 1080;
    state.window_height = 720;
    state.game_state = GameState::BASE;

    SetTraceLogLevel(TraceLogLevel::LOG_ERROR);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(state.window_width, state.window_height, "Bubbliss");

    RenderingSystem::init();


#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(step, 0, 1);
#else
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        step();
    }
#endif
    CloseWindow();

    return 0;
}
