//
// Created by neta on 26/04/2021.
//

#include "Scientist.hpp"


using namespace std;
namespace pandemic {
    void Scientist::discover_cure(Color color) {
        if (board.is_there_research_station(curr_city)) {
            bool res;
            switch (color) {
                case Blue:
                    if (board.blue_cure) return; //If blue cure exists we won't take the cards
                    board.blue_cure = res = removeCards(0, 12, this->number_of_cards);
                    break;
                case Yellow:
                    if (board.yellow_cure) return; //If yellow cure exists we won't take the cards
                    board.yellow_cure = res = removeCards(12, 24, this->number_of_cards);
                    break;
                case Black:
                    if (board.black_cure) return; //If black cure exists we won't take the cards
                    board.black_cure = res = removeCards(24, 36, this->number_of_cards);
                    break;
                case Red:
                    if (board.red_cure) return; //If red cure exists we won't take the cards
                    board.red_cure = res = removeCards(36, 48, this->number_of_cards);
                    break;
            }
            if (!res) {
                string message = "You don't have 5 cards!";
                throw std::invalid_argument(message);
            }
        } else {
            string message =
                    "You're current city " + board.get_city_name(curr_city) + " doesn't have a research station!";
            throw std::invalid_argument(message);
        }
    }

    string Scientist::role() {
        return "Scientist";
    }
}

