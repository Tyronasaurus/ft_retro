#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "Entity.hpp"

class Player : public Entity {
    private:
        int direction;
    public :
        Player(void);
        Player(int x, int y, int max_x, int max_y, std::string body);
        Player(Player const &rhs);
        virtual ~Player(void);

        Player &operator=(Player const &rhs);

        void moveLeft(void);
        void moveRight(void);

        virtual int updatePosition(void);
};

#endif //PLAYER_HPP