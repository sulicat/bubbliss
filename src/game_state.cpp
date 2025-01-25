#include "game_state.hpp"

#include <iostream>

GlobalState* GlobalState::_state = nullptr;

GlobalState& GlobalState::inst(){
    if (_state == nullptr) {
        _state = new GlobalState();
        _state->init();
    }
    return *_state;
}

void GlobalState::init(){
}