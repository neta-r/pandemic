//
// Created by neta on 26/04/2021.
//

#include "Researcher.hpp"

using namespace std;
namespace pandemic {
    void Researcher::discover_cure(Color color) {
        bool res;
        switch (color) {
            case Blue:
                if (board.blue_cure) return; //If blue cure exists we won't take the cards
                board.blue_cure = res = removeCards(0, 12, 5);
                break;
            case Yellow:
                if (board.yellow_cure) return; //If yellow cure exists we won't take the cards
                board.yellow_cure = res = removeCards(12, 24, 5);
                break;
            case Black:
                if (board.black_cure) return; //If black cure exists we won't take the cards
                board.black_cure = res = removeCards(24, 36, 5);
                break;
            case Red:
                if (board.red_cure) return; //If red cure exists we won't take the cards
                board.red_cure = res = removeCards(36, 48, 5);
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