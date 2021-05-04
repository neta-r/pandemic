//
// Created by neta on 26/04/2021.
//

#include "GeneSplicer.hpp"
using namespace std;
namespace pandemic {
    void GeneSplicer::discover_cure(Color color) {
        if (color==Blue && board.blue_cure) return;
        if (color==Yellow && board.yellow_cure) return;
        if (color==Black && board.black_cure) return;
        if (color==Red && board.red_cure) return;
        if (!board.is_there_research_station(curr_city)){
            string message =
                    "You're current city " + board.get_city_name(curr_city) + " doesn't have a research station!";
            throw std::invalid_argument(message);
        }
        int counter=0;
        for (int i=0; i<49&&counter!=5; i++){
            if (cards[i]) {
                counter++;
            }
        }
        if (counter<5) {
            string message = "You don't have 5 cards!";
            throw std::invalid_argument(message);
        }
        for (int i=0; i<49&&counter!=0; i++){
            if (cards[i]) {
                cards[i]= false;
                counter--;
            }
        }
        if (color==Blue) {
            board.blue_cure= true;
            return;
        }
        if (color==Yellow) {
            board.yellow_cure= true;
            return;
        }if (color==Black) {
            board.black_cure= true;
            return;
        }if (color==Red) {
            board.red_cure= true;
            return;
        }
    }
    string GeneSplicer::role() {
        return "Gene Splicer";
    }
}