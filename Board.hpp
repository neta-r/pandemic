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
        Board() {load_map();}
        std::string get_city_name (City city); //to be able to print it in player class
        bool is_there_research_station(City city); //for build and fly_shuttle
        bool are_neighbors(City first, City second); //public so we can reach it from class Player
        int& operator[] (City city); //write
        const int operator[] (City city) const; //read
        friend std::ostream &operator<<(std::ostream &os, const Board &board);
        bool is_clean();
    };
}

#endif //UNTITLED_BOARD_H
