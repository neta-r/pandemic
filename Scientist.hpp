//
// Created by neta on 26/04/2021.
//

#ifndef UNTITLED_SCIENTIST_H
#define UNTITLED_SCIENTIST_H

#include "Player.hpp"
namespace pandemic {
    class Scientist : public Player {
        int number_of_cards;
    public:
        Scientist(Board& board, City city, int n): Player(board, city), number_of_cards(n){}
        void discover_cure(Color color);
        std::string role();
    };
}


#endif //UNTITLED_SCIENTIST_H
