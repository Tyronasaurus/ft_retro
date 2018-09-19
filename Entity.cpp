#include "Entity.hpp"

Entity::Entity(void) { 
    this->x = 0; 
    this->y = 0;
    this->max_x = 0;
    this->max_y = 0;
    this->body = "X";
}

Entity::Entity(int x, int y, int max_x, int max_y, std::string body) : 
                x(x), y(y), max_x(max_x), max_y(max_y), body(body)
{
    return;
}

Entity::Entity(Entity const &rhs) {
    *this = rhs;
}

Entity::~Entity(void) {
    return;
}

Entity &Entity::operator=(Entity const &rhs) {
    this->x = rhs.x;
    this->y = rhs.y;
    this->max_x = rhs.max_x;
    this->max_y = rhs.max_y;
    this->body = rhs.body;

    return *this;
}

int Entity::getX(void) {
    return this->x;
}

int Entity::getY(void) {
    return this->y;
}

std::string Entity::getBody(void) {
    return this->body;
}

int Entity::updatePosition(void) {
    return (0);
}