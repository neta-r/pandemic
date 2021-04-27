#ifndef UNTITLED_BOARD_H
#define UNTITLED_BOARD_H

#include "City.hpp"
#include <unordered_map>
#include <vector>


namespace pandemic{
    class Board {
    private:
        static std::unordered_map<pandemic::City, pandemic::Color> cities_and_colors;
        static std::unordered_map<pandemic::City, std::vector<pandemic::City>> cities_neighbors;

        static void load_map();
        static void load_blue();
        static void load_yellow();
        static void load_black();
        static void load_red();
    public:
        Board& operator[] (City city);
    };
}

#endif //UNTITLED_BOARD_H
