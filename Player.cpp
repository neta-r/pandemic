
#include "Player.hpp"

using namespace std;
namespace pandemic {

    Player &Player::drive(City other) {
        if (this->board.are_neighbors(curr_city, other)) {
            curr_city = other;
            return *this;
        } else {
            string message =
                    board.get_city_name(curr_city) + " and " + board.get_city_name(other) + " aren't neighbors!";
            throw std::invalid_argument(message);
        }
    }

    void Player::fly(City dest_city, City card) {
        if (cards[int(card)]) { //if card exist
            curr_city = dest_city;
            cards[int(card)]= false;
            return;
        } else {
            string message = "You don't have a " + board.get_city_name(card) + " card!";
            throw std::invalid_argument(message);
        }
    }

    Player &Player::fly_direct(City dest_city) {
        fly(dest_city, dest_city);
        return *this;
    }

    Player &Player::fly_charter(City dest_city) {
        fly(dest_city, curr_city);
        return *this;
    }

    Player &Player::fly_shuttle(City dest_city) {
        if (board.is_there_research_station(curr_city)&&board.is_there_research_station(dest_city)){
            curr_city=dest_city;
        } else if (!board.is_there_research_station(curr_city)){
            string message = "You're current city " + board.get_city_name(curr_city) + " has no research station!";
            throw std::invalid_argument(message);
        }
        else {
            string message = "You're dest city " + board.get_city_name(dest_city) + " has no research station!";
            throw std::invalid_argument(message);
        }
        return *this;
    }

    void Player::build(){
        if (cards[int(curr_city)]&&(!board.is_there_research_station(curr_city))){
            board.build(curr_city);
            cards[int(curr_city)]= false;
        }
        else{
            string message = "You don't have a  " + board.get_city_name(curr_city) + " card!";
            throw std::invalid_argument(message);
        }
    }


    Player &Player::take_card(City city) {
        cards[int(city)]= true;
        return *this;
    }

    void Player::discover_cure(Color color) {
        if (board.get_city_color(curr_city)!=color){
            string message = "You're not in a " + to_string(color) + " city!"; //TODO:convert it to string and not to int
            throw std::invalid_argument(message);
        }
        if (board.is_there_research_station(curr_city)){

        }
        else{
            string message = "You're current city " + board.get_city_name(curr_city) + " doesn't have a research station!";
            throw std::invalid_argument(message);
        }
    };
}