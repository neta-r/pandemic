
#include "Player.hpp"
using namespace std;
namespace pandemic{
    bool Player::is_card_exist(City city){
        for (auto card:cards){
            if (card==city) return true;
        }
        return false;
    }
    void Player::drive(City other){
        if (this->board.are_neighbors(curr_city,other)){
            curr_city = other;
        }
        else{
            string message = to_string(curr_city) + " and " + to_string(other) + "aren't neighbors!";
            throw std::invalid_argument(message);
        }
    }

    Player &Player::take_card(City city){
        if (!is_card_exist(city)) { //adding card we don't already have it
            this->cards.push_back(city);
        }
        return *this;
    }
    void Player::discover_cure(Color color) {  };
}