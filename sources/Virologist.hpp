//
// Created by neta on 26/04/2021.
//

#ifndef UNTITLED_VIROLOGIST_H
#define UNTITLED_VIROLOGIST_H
#include "Player.hpp"
namespace pandemic {
    class Virologist : public Player {
    public:
        Virologist(Board& board, City city): Player(board, city){}
        Player & treat(City city);
        std::string role();
    };
}

#endif //UNTITLED_VIROLOGIST_H
