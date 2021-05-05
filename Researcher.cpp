//
// Created by neta on 26/04/2021.
//

#include "Researcher.hpp"

using namespace std;
namespace pandemic {
    void Researcher::discover_cure(Color color) {
        bool res= false;
        switch (color) {
            case Blue:
                if (board.blue_cure) {
                    return; //If blue cure exists we won't take the cards
                }
                board.blue_cure = res = removeCards(lower_blue, higher_blue, default_num_of_cards);
                break;
            case Yellow:
                if (board.yellow_cure) {
                    return; //If yellow cure exists we won't take the cards
                }
                board.yellow_cure = res = removeCards(lower_yellow, higher_yellow, default_num_of_cards);
                break;
            case Black:
                if (board.black_cure) {
                    return; //If black cure exists we won't take the cards
                }
                board.black_cure = res = removeCards(lower_black, higher_black, default_num_of_cards);
                break;
            case Red:
                if (board.red_cure) {
                    return; //If red cure exists we won't take the cards
                }
                board.red_cure = res = removeCards(lower_red, higher_red, default_num_of_cards);
                break;
        }
        if (!res) {
            string message = "You don't have 5 cards!";
            throw std::invalid_argument(message);
        }
    }

    string Researcher::role() {
        return "Researcher";
    }
}