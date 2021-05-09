//
// Created by neta on 26/04/2021.
//

#ifndef UNTITLED_MEDIC_H
#define UNTITLED_MEDIC_H
#include "Player.hpp"
namespace pandemic {
    class Medic : public Player {
        void check_color_and_treat(City city);
    public:
        Medic(Board& board, City city): Player(board, city){}

        Player & treat(City city);

        Player &drive(City other);

        Player &fly_direct(City dest_city);

        Player &fly_charter(City dest_city);

        Player &fly_shuttle(City dest_city);

        std::string role();
    };
}


#endif //UNTITLED_MEDIC_H
