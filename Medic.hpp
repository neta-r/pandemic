//
// Created by neta on 26/04/2021.
//

#ifndef UNTITLED_MEDIC_H
#define UNTITLED_MEDIC_H
#include "Player.hpp"
namespace pandemic {
    class Medic : public Player {
    private:
        void remove_all_diseases(int indexStart, int indexEnd);
    public:
        Medic(Board& board, City city): Player(board, city){}
        Player & treat(City city);
        void discover_cure(Color color);
        std::string role();
    };
}


#endif //UNTITLED_MEDIC_H
