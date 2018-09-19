#include "Projectile.hpp"

Projectile::Projectile(void) {
}


Projectile::Projectile(int x, int y, int max_x, int max_y, std::string body) : Entity(x, y, max_x, max_y, body)  
{}

Projectile::Projectile(Projectile const &rhs) : Entity(rhs){
    *this = rhs;
}

Projectile::~Projectile(void) 
{
    return;
}

Projectile &Projectile::operator=(Projectile const &rhs) {
    Entity::operator=(rhs);
    return *this;
}

int Projectile::updatePosition(void) {
    //mvaddch(this->y, this->x, ' ');
    if (this->y > 1) {
        this->y--;
        return (0);
    }
    return (-1);
}
