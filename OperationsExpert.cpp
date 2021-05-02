//
// Created by neta on 26/04/2021.
//

#include "OperationsExpert.hpp"

using namespace std;
namespace pandemic {
    void OperationsExpert::build() {
        if ((!board.is_there_research_station(curr_city))) {
            board.build(curr_city);
        }
    }
    string OperationsExpert::role(){
        return "Operations Expert";
    }
}