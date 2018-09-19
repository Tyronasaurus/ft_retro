#ifndef ENTITY_HPP
# define ENTITY_HPP


#include <ncurses.h>
#include <unistd.h>
#include <string>

class Entity {
    protected:
        int x;
        int y;
        int max_x;
        int max_y;
        std::string body;

    public: 
        Entity(void);
        Entity(int x, int y, int max_x, int max_y, std::string body);
        Entity(Entity const &rhs);
        ~Entity(void);
        Entity &operator=(Entity const &rhs);

        int getX(void);
        int getY(void);
        std::string getBody(void);

        virtual int updatePosition(void);

};

#endif