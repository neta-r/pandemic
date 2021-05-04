#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H

#include "City.hpp"
#include "Board.hpp"

namespace pandemic {
    class Player {
    protected:
        Board &board;
        City curr_city;
        bool cards[48];

        bool removeCards(int indexStart, int indexEnd, int n);

        void fly(City dest_city, City card);

    public:
        Player(Board &board, City curr) : board(board) {
            for (int i = 0; i < 49; i++) cards[i] = false;
            curr_city = curr;
        }

        std::string get_location() { return board.get_city_name(curr_city); } //TODO:remove it later
        std::string get_cards() {//TODO:remove it later
            std::string ans="";
            for (int i = 0; i < 49; i++){
                if (cards[i]) ans+=board.get_city_name(static_cast<City>(i))+", ";
            }
            return ans;
        }

        void remove_cards();

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
