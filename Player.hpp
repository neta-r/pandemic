#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H

#include "City.hpp"
#include "Board.hpp"

namespace pandemic {
    class Player {
    protected:
        const size_t lower_blue = 0;
        const size_t higher_blue = 12;
        const size_t lower_yellow = 12;
        const size_t higher_yellow = 24;
        const size_t lower_black = 24;
        const size_t higher_black = 36;
        const size_t lower_red = 36;
        const size_t higher_red = 48;
        const int default_num_of_cards = 5;

        Board &board;
        City curr_city;
        std::array<bool,48> cards;
        bool removeCards(size_t indexStart, size_t indexEnd, int n);

        void fly(City dest_city, City card);

    public:
        Player(Board &board, City curr) : board(board) {
            for (size_t i = 0; i < 49; i++) cards.at(i) = false;
            curr_city = curr;
        }

        virtual void remove_cards();

        virtual Player &take_card(City city);

        virtual Player &drive(City other);

        virtual Player &fly_direct(City dest_city);

        virtual Player &fly_charter(City dest_city);

        virtual Player &fly_shuttle(City dest_city);

        virtual void build();

        virtual void discover_cure(Color color);

        virtual Player &treat(City city);

        virtual std::string role();
    };
}

#endif //UNTITLED_PLAYER_H
