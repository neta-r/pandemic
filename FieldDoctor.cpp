//
// Created by neta on 26/04/2021.
//

#include "FieldDoctor.hpp"
using namespace std;
namespace pandemic {
    Player &FieldDoctor::treat(City city) {
        if (city != curr_city&&!board.are_neighbors(curr_city,city)) {
            string message =
                    "You have to be in the city in order to treat it or in a neighbor city!";
            throw std::invalid_argument(message);
        }
        Color c = board.get_city_color(city);
        if (board.get_city_level(city) == 0) {
            string message =
                    "Current city's level of disease is 0!";
            throw std::invalid_argument(message);
        }
        switch (c) {
            case Blue:
                if (!board.blue_cure) {
                    board.reduce_city_level_by_one(city);
                } else {
                    board.reduce_city_level_by_all(city);
                }
                break;
            case Yellow:
                if (!board.yellow_cure) {
                    board.reduce_city_level_by_one(city);
                } else {
                    board.reduce_city_level_by_all(city);
                }
                break;
            case Black:
                if (!board.black_cure) {
                    board.reduce_city_level_by_one(city);
                } else {
                    board.reduce_city_level_by_all(city);
                }
                break;
            case Red:
                if (!board.red_cure) {
                    board.reduce_city_level_by_one(city);
                } else {
                    board.reduce_city_level_by_all(city);
                }
                break;
        }
        return *this;
    }
    string FieldDoctor::role() {
        return "Field Doctor";
    }
}