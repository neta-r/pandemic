
#include "Player.hpp"

using namespace std;
namespace pandemic {

    bool Player::removeCards(int indexStart, int indexEnd, int n) {
        int counter = 0;
        for (int i = indexStart; i < indexEnd && counter != n; i++) {
            if (cards[i]) counter++;
        }
        if (counter < n) return false;
        for (int i = indexStart; i < indexEnd && counter > 0; i++) {
            if (cards[i]) {
                cards[i] = false;
                counter--;
            }
        }
        return true;
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
        if (cards[int(card)]) { //if card exist
            curr_city = dest_city;
            cards[int(card)] = false;
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
        if (board.is_there_research_station(curr_city) && board.is_there_research_station(dest_city)) {
            curr_city = dest_city;
        } else if (!board.is_there_research_station(curr_city)) {
            string message = "You're current city " + board.get_city_name(curr_city) + " has no research station!";
            throw std::invalid_argument(message);
        } else {
            string message = "You're dest city " + board.get_city_name(dest_city) + " has no research station!";
            throw std::invalid_argument(message);
        }
        return *this;
    }

    void Player::build() {
        if (cards[int(curr_city)] && (!board.is_there_research_station(curr_city))) {
            board.build(curr_city);
            cards[int(curr_city)] = false;
        } else {
            string message = "You don't have a  " + board.get_city_name(curr_city) + " card!";
            throw std::invalid_argument(message);
        }
    }


    Player &Player::take_card(City city) {
        cards[int(city)] = true;
        return *this;
    }

    void Player::discover_cure(Color color) {
        if (!board.is_there_research_station(curr_city)) {
            bool res;
            switch (color) {
                case Blue:
                    if (board.blue_cure) return; //If blue cure exists we won't take the cards
                    board.blue_cure = res = removeCards(0, 12, 5);
                    break;
                case Yellow:
                    if (board.yellow_cure) return; //If yellow cure exists we won't take the cards
                    board.yellow_cure = res = removeCards(12, 24, 5);
                    break;
                case Black:
                    if (board.black_cure) return; //If black cure exists we won't take the cards
                    board.blue_cure = res = removeCards(24, 36, 5);
                    break;
                case Red:
                    if (board.red_cure) return; //If red cure exists we won't take the cards
                    board.red_cure = res = removeCards(36, 48, 5);
                    break;
            }
            if (!res) {
                string message = "You don't have 5 cards!";
                throw std::invalid_argument(message);
            }
        } else {
            string message =
                    "You're current city " + board.get_city_name(curr_city) + " doesn't have a research station!";
            throw std::invalid_argument(message);
        }
    }

    Player &Player::treat(City city) {
        if (city != curr_city) {
            string message =
                    "You have to be in the city in order to treat it!";
            throw std::invalid_argument(message);
        }
        Color c = board.get_city_color(city);
        if (board.get_city_level(city) == 0) {
            string message =
                    "Current city's level of disease is 0!";
            throw std::invalid_argument(message);
        }
        switch (c) {
            case Blue:
                if (!board.blue_cure) {
                    board.reduce_city_level_by_one(city);
                } else {
                    board.reduce_city_level_by_all(city);
                }
                break;
            case Yellow:
                if (!board.yellow_cure) {
                    board.reduce_city_level_by_one(city);
                } else {
                    board.reduce_city_level_by_all(city);
                }
                break;
            case Black:
                if (!board.black_cure) {
                    board.reduce_city_level_by_one(city);
                } else {
                    board.reduce_city_level_by_all(city);
                }
                break;
            case Red:
                if (!board.red_cure) {
                    board.reduce_city_level_by_one(city);
                } else {
                    board.reduce_city_level_by_all(city);
                }
                break;
        }
        return *this;
    }
}