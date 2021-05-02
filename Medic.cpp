//
// Created by neta on 26/04/2021.
//

#include "Medic.hpp"

using namespace std;
namespace pandemic {
    void Medic::remove_all_diseases(int indexStart, int indexEnd){
        for (int i = indexStart; i < indexEnd; i++) {
            board.reduce_city_level_by_all(cards[i]);
        }
    }

    void Medic::discover_cure(Color color) {
        Player::discover_cure(color);
        switch (color) {
            case Blue:
                remove_all_diseases(0, 12);
                break;
            case Yellow:
                remove_all_diseases(12, 24);
                break;
            case Black:
                remove_all_diseases(24, 36);
                break;
            case Red:
                remove_all_diseases(36, 48);
                break;
        }
    }

    Player &Medic::treat(City city) {
        if (board.get_city_level(city) == 0) {
            string message =
                    "Current city's level of disease is 0!";
            throw std::invalid_argument(message);
        }
        board.reduce_city_level_by_all(city);
        return *this;
    }

    string Medic::role() {
        return "Medic";
    }
}