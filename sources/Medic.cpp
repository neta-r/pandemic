//
// Created by neta on 26/04/2021.
//

#include "Medic.hpp"

using namespace std;
namespace pandemic {

    Player &Medic::drive(City other) {
        try {
            Player::drive(other);
            board.reduce_city_level_by_all(static_cast<City>(other));
        } catch (const exception &ex) {
            throw ex.what();
        }
        return *this;
    }

    Player &Medic::fly_direct(City dest_city) {
        try {
            Player::fly_direct(dest_city);
            board.reduce_city_level_by_all(static_cast<City>(dest_city));
        }
        catch (const exception &ex) {
            throw ex.what();
        }
        return *this;
    }

    Player &Medic::fly_charter(City dest_city) {
        try {
            Player::fly_charter(dest_city);
            board.reduce_city_level_by_all(static_cast<City>(dest_city));
        }
        catch (const exception &ex) {
            throw ex.what();
        }
        return *this;
    }

    Player &Medic::fly_shuttle(City dest_city) {
        try {
            Player::fly_shuttle(dest_city);
            board.reduce_city_level_by_all(static_cast<City>(dest_city));
    } catch (const exception &ex) {
        throw ex.what();
    }
    return *this;
}

Player &Medic::treat(City city) {
    if (city != curr_city) {
        string message =
                "You have to be in the city in order to treat it!";
        throw std::invalid_argument(message);
    }
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