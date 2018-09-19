#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "Entity.hpp"

class Enemy : public Entity {
    public :
        Enemy(void);
        Enemy(int x, int y, int max_x, int max_y, std::string body);
        Enemy(Enemy const &rhs);
        virtual ~Enemy(void);

        Enemy &operator=(Enemy const &rhs);

        virtual int updatePosition(void);
        void SetSpawn(void);
}; 

#endif //ENEMY_HPP