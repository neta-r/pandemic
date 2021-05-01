
#include "Player.hpp"

using namespace std;
namespace pandemic {
    bool Player::is_card_exist(City city) {
        for (auto card:cards) {
            if (card == city) return true;
        }
        return false;
    }

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
        if (is_card_exist(card)) {
            curr_city = dest_city;
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
            string message = "You're current city ' " + board.get_city_name(curr_city) + " has no research station!";
            throw std::invalid_argument(message);
        }
        else {
            string message = "You're dest city' " + board.get_city_name(dest_city) + " has no research station!";
            throw std::invalid_argument(message);
        }
        return *this;
    }

    Player &Player::take_card(City city) {
        if (!is_card_exist(city)) { //adding card we don't already have it
            this->cards.push_back(city);
        }
        return *this;
    }

    void Player::discover_cure(Color color) {};
}