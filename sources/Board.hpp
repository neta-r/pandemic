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
        int stations; //number of research stations built
        void load_map();
        void load_blue();
        void load_yellow();
        void load_black();
        void load_red();
    public:
        bool blue_cure;
        bool yellow_cure;
        bool black_cure;
        bool red_cure;
        Board(): stations(0), blue_cure(false), yellow_cure(false), black_cure(false), red_cure(false) {load_map();}
        std::string get_city_name (City city); //to be able to print it in player class
        Color get_city_color (City city);
        int get_city_level (City city);
        size_t get_city_num (City city);
        void reduce_city_level_by_one(City city);
        void reduce_city_level_by_all(City city);
        bool is_there_research_station(City city); //for build and fly_shuttle
        void build(City city);
        bool are_neighbors(City first, City second); //public so we can reach it from class Player
        int& operator[] (City city); //write
        int operator[] (City city) const; //read
        friend std::ostream &operator<<(std::ostream &os, const Board &board);
        bool is_clean();
        void remove_cures();
    };
}

#endif //UNTITLED_BOARD_H
