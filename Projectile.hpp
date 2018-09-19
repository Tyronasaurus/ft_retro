#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

#include "Entity.hpp"

class Projectile : public Entity {
    public :
        Projectile(void);
        Projectile(int x, int y, int max_x, int max_y, std::string body);
        Projectile(Projectile const &rhs);
        virtual ~Projectile(void);

        Projectile &operator=(Projectile const &rhs);

        virtual int updatePosition(void);
}; 

#endif //PROJECTILE_HPP