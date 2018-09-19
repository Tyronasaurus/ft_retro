#ifndef GAME_HPP
# define GAME_HPP

#include <ncurses.h>
#include <iostream>
#include <unistd.h>
#include "Entity.hpp"
#include "Player.hpp"
#include "Projectile.hpp"
#include "Enemy.hpp"

# define MAXOBJ 100
# define MAXENEMIES 5

class Game {
    private: 
        WINDOW *win;
        int isInit;
        Player *newPlayer;
        Projectile *bullet;
        Enemy *enemies[MAXENEMIES];
        int max_x;
        int max_y;
        int score;
        int life;
        clock_t seconds;
    public: 
        Game(void);
        Game(Game const &rhs);
        ~Game(void);

        void setBullet(void);

        Game &operator=(Game const &rhs);

        int GameLoop(void);

        void GameEnd(void);

        int getInput(int ch);

        void printScreen(int wallCount);

        void updatePieces(void) ;

        void checkCollisions(void);
};

#endif //GAME_HPP