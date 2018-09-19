#include "Enemy.hpp"

Enemy::Enemy(void) {}

Enemy::Enemy(int x, int y, int max_x, int max_y, std::string body) :Entity(x, y, max_x, max_y, body) 
{}

Enemy::Enemy(Enemy const &rhs) : Entity(rhs) {
    *this = rhs;
}

Enemy::~Enemy(void) {
    return;
}

Enemy &Enemy::operator=(Enemy const &rhs){
    Entity::operator=(rhs);
    return *this;
}

int Enemy::updatePosition(void) {
    if (this->y <= this->max_y - 3) {
        this->y++;
        return(0);
    }
    return (-1);
}

void Enemy::SetSpawn(void) {
    int i = rand() % max_x + 1;
    int j = rand() % 4 + 1;
    this->y = j;
    this->x = i;
}