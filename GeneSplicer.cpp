//
// Created by neta on 26/04/2021.
//

#include "GeneSplicer.hpp"
using namespace std;
namespace pandemic {
    void GeneSplicer::discover_cure(Color color) {
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
    }
    string GeneSplicer::role() {
        return "Gene Splicer";
    }
}