#include "Game.hpp"


int main(void) {
    Game _Game;

    //_Game.Game();

    if (_Game.GameLoop() == 1) {
        _Game.GameEnd();
    }
}