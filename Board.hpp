#ifndef UNTITLED_BOARD_H
#define UNTITLED_BOARD_H

#include "City.hpp"
#include <unordered_map>
#include <vector>
#include "Holder.hpp"


namespace pandemic{
    class Board {
    private:
        static std::unordered_map<City,Holder> cities;

        static void load_map();
        static void load_blue();
        static void load_yellow();
        static void load_black();
        static void load_red();
    public:
        Board() {load_map();}
        Board& operator[] (City city);
    };
}

#endif //UNTITLED_BOARD_H
