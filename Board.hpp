#ifndef UNTITLED_BOARD_H
#define UNTITLED_BOARD_H

#include "City.hpp"
#include <unordered_map>
#include <vector>
#include "Holder.hpp"


namespace pandemic{
    class Board {
    private:
        std::unordered_map<City,Holder> cities;

        void load_map();
        void load_blue();
        void load_yellow();
        void load_black();
        void load_red();
    public:
        Board() {
            load_map();
        }
        int& operator[] (City city); //write
        const int operator[] (City city) const; //read
        bool is_clean();
    };
}

#endif //UNTITLED_BOARD_H
