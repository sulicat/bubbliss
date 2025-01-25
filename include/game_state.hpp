#pragma once

enum class GameState{
    BASE,
    MOVING
};

class GlobalState{
public:
    ~GlobalState(){};
    static GlobalState& inst();
    void init();

    int window_width;
    int window_height;
    GameState game_state;

private:
    GlobalState(){};
    static GlobalState* _state;
};