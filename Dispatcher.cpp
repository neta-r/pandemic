//
// Created by neta on 26/04/2021.
//

#include "Dispatcher.hpp"

using namespace std;
namespace pandemic {
    Player &Dispatcher::fly_direct(City dest_city) {
        if (board.is_there_research_station(curr_city)){
            curr_city = dest_city;
        }
        else{
            fly(dest_city, dest_city);
        }
        return *this;
    }
    string Dispatcher::role(){
        return "Dispatcher";
    }
}