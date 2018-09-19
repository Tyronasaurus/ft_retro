#include "Player.hpp"

Player::Player(void){
}

Player::Player(int x, int y, int max_x, int max_y, std::string body) : Entity(x, y, max_x, max_y, body) 
{
    this->direction = 0;
    return;
}

Player::Player(Player const &rhs) : Entity(rhs) {
    *this = rhs;
}


Player::~Player(void) 
{}

Player &Player::operator=(Player const &rhs) {
    Entity::operator=(rhs);
    return *this;
}

void Player::moveLeft(void) {
    //mvaddch(this->y, this->x, ' ');
    this->direction = -1;
}

void Player::moveRight(void) {
   // mvaddch(this->y, this->x, ' ');
   this->direction = 1;
}


int Player::updatePosition(void) {
    if (this->direction == -1) {
        if (this->x > 0 + 1)
            this->x--;
    }
    else if (this->direction == 1) {
        if (this->x +1 < this->max_x - 1)
            this->x++; 
    }
    this->direction = 0;
    return (0);
}