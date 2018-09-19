#include "Game.hpp"

Game::Game (void) {
    this->win = initscr(); //initialis the window
    noecho(); //dont echo any keypress
    keypad(this->win, TRUE);
    curs_set(FALSE); // dont display a cursor
    cbreak();
    nodelay(this->win, TRUE);
    getmaxyx(this->win, this->max_y, this->max_x);

    this->newPlayer = NULL;
    this->bullet = NULL;
    for (int i = 0; i < MAXENEMIES; i++)
        this->enemies[i] = NULL;
    this->life = 3;
    this->score = 0;
    this->seconds = clock();

} 

Game::Game(Game const &rhs) {
    *this = rhs;
}


int Game::GameLoop(void) {
    
    int ch;
    int wallCount = 0;
    int enemyLoop = 0;
    srand(time(NULL));

    this->newPlayer = new Player(max_x/2, max_y-3, max_x, max_y, "^");

    while(this->life > 0) {
        // Global var `stdscr` is created by the call to `initscr()`
        getmaxyx(this->win, this->max_y, this->max_x);
        ch = getch();
        if (this->getInput(ch) == -1) {
            break;
        }

        for (int i = 0; i < MAXENEMIES; i++) {
            if (enemies[i] == NULL) {
                enemies[i] = new Enemy(0, 0, max_x, max_y, "Y");
                enemies[i]->SetSpawn();
            }
        }
        if (enemyLoop == 20) {
            for (int j = 0; j < MAXENEMIES; j++) {
                if (enemies[j] != NULL) {
                    if (enemies[j]->updatePosition() == -1) {
                        delete enemies[j];
                        enemies[j] = NULL;
                    }
                }
            }
            wallCount++;
            enemyLoop = 0;
        }
        enemyLoop++;
        checkCollisions();
        updatePieces();
        printScreen(wallCount);
        if (wallCount == 3) {
            wallCount = 0;
        }
        refresh();
        usleep(16666);
    }

    delete newPlayer;
    return(1);
}

void Game::GameEnd(void) {
    clear();
    //usleep(1000000);
    while (1){
        mvprintw(max_y/2, max_x/2-4, "GAME OVER");
        mvprintw(max_y/2+1, max_x/2-5, "SCORE: %d", score);
        mvprintw(max_y/2+2, max_x/2-5, "ESC to exit");
        refresh();
        int ch = getch();
        if (ch == 27) {
            break;
        }
    }
    endwin();
}

Game &Game::operator=(Game const &rhs) {

    //int i = 0;

    this->isInit = rhs.isInit;
    this->max_x = rhs.max_x;
    this->max_y = rhs.max_y;
    this->newPlayer = rhs.newPlayer;
    // while (rhs.magazine[i] != NULL) {
    //     this->magazine[i] = rhs.magazine[i];
    //     i++;
    // }
    
    this->win = rhs.win;
    //*this = rhs;
    return *this;
}

Game::~Game(void) {

}

int Game::getInput(int ch) {
    if (ch == KEY_LEFT) {
        newPlayer->moveLeft();
        return(1);
    }
    else if (ch == KEY_RIGHT) {
        newPlayer->moveRight();
        return(1);
    }
    if (ch == 32 && this->bullet == NULL) {
        this->bullet = new Projectile(newPlayer->getX(), newPlayer->getY(), this->max_x, this->max_y, ".");
        return(1);
    }
    if (ch == 'q') {
        return (-1);
    }
    return (0);
}

void Game::printScreen(int wallCount) {
    clear();
    if (wallCount == 0) {
        box(this->win, '|', '-');
    }
    else if (wallCount == 1) {
        box(this->win, '(', '-');
    }
    else if (wallCount == 2) {
        box(this->win, ')', '-');
    }
    else if (wallCount == 3) {
        box(this->win, '|', '-');
    }

    mvprintw(2, max_x/2 - 9, "LIVES: %d SCORE: %d", life, score );

    mvprintw(3, max_x/2 - 6, "TIME: %.2f", (float)seconds/(60*60*2));
    seconds = clock(); 
    if (this->bullet != NULL)
        mvaddstr(this->bullet->getY(), this->bullet->getX(), this->bullet->getBody().c_str());

    int playerX = this->newPlayer->getX();
    int playerY = this->newPlayer->getY();
    std::string body = this->newPlayer->getBody();
    mvaddstr(playerY, playerX, "^");
    for (int i = 0; i < MAXENEMIES; i++) {
        if (enemies[i] != NULL) {
            mvaddstr(enemies[i]->getY(), enemies[i]->getX(), enemies[i]->getBody().c_str());
        }
    }
}

void Game::updatePieces(void) {
    if (this->bullet != NULL) {
        if (bullet->updatePosition() == -1) {
            delete this->bullet;
            this->bullet = NULL;
        }
    }
    this->newPlayer->updatePosition();
}

void Game::checkCollisions(void) {
    for (int i = 0; i < MAXENEMIES; i++) {
        if (enemies[i] != NULL && bullet != NULL) {
            if ((bullet->getX() == enemies[i]->getX()) && (bullet->getY() == enemies[i]->getY())) {
                //delete bullet;
                this->bullet = NULL;

                //delete enemies[i];
                enemies[i] = NULL;
                this->score += 10;
            }
        }
        if (enemies[i] != NULL ) {
            if (enemies[i]->getX() == newPlayer->getX() && enemies[i]->getY() == newPlayer->getY()) {
                enemies[i] = NULL;
                this->life -= 1;
            }
        }
    }
}