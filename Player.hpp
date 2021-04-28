#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H

#include "City.hpp"


namespace pandemic {
    class Player {
    public:
        Player &take_card(City city);
        void discover_cure(Color color);
    };
}

#endif //UNTITLED_PLAYER_H
