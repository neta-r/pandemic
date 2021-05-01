#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H

#include "City.hpp"
#include "Board.hpp"
#include <vector>

namespace pandemic {
    class Player {
    private:
        City curr_city;
        bool cards[48];
        Board board;

        void fly(City dest_city, City card);

    public:
        Player(Board board, City curr) {
            for (int i=0; i < 49 ; i++) cards[i]= false;
            this->board = board;
            this->curr_city = curr;
        }

        Player &take_card(City city);

        Player &drive(City other);

        Player &fly_direct(City dest_city);

        Player &fly_charter(City dest_city);

        Player &fly_shuttle(City dest_city);

        void build();

        void discover_cure(Color color);
    };
}

#endif //UNTITLED_PLAYER_H
