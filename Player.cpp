
#include "Player.hpp"
#include <iostream>

using namespace std;
namespace pandemic {

    bool Player::removeCards(size_t indexStart, size_t indexEnd, int n) {
        int counter = 0;
        for (size_t i = indexStart; i < indexEnd; i++) {
            if (cards.at(i)) {
                counter++;
            }
            if (counter == n) {
                break;
            }
        }
        if (counter < n) {
            return false;
        }
        for (size_t i = indexStart; i < indexEnd; i++) {
            if (cards.at(i)) {
                cards.at(i) = false;
                counter--;
            }
            if (counter == 0) {
                break;
            }
        }
        return true;
    }

    Player &Player::drive(City other) {
        if (this->board.are_neighbors(curr_city, other)) {
            curr_city = other;
            return *this;
        }
        string message =
                board.get_city_name(curr_city) + " and " + board.get_city_name(other) + " aren't neighbors!";
        throw std::invalid_argument(message);
    }

    void Player::fly(City dest_city, City card) {
        if (cards.at(board.get_city_num(card))) { //if card exist
            curr_city = dest_city;
            cards.at(board.get_city_num(card)) = false;
        } else {
            string message = role() + " don't have a " + board.get_city_name(card) + " card!";
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
        if (cards.at(board.get_city_num(curr_city))) {
            if (!board.is_there_research_station(curr_city)) {
                board.build(curr_city);
                cards.at(board.get_city_num(curr_city)) = false;
            }
        } else {
            string message = "You don't have a  " + board.get_city_name(curr_city) + " card!";
            throw std::invalid_argument(message);
        }
    }


    Player &Player::take_card(City city) {
        cards.at(board.get_city_num(city)) = true;
        return *this;
    }

    void Player::discover_cure(Color color) {
        if (board.is_there_research_station(curr_city)) {
            bool res = false;
            switch (color) {
                case Blue:
                    if (board.blue_cure) {
                        return; //If blue cure exists we won't take the cards
                    }
                    board.blue_cure = res = removeCards(lower_blue, higher_blue, default_num_of_cards);
                    break;
                case Yellow:
                    if (board.yellow_cure) {
                        return; //If yellow cure exists we won't take the cards
                    }
                    board.yellow_cure = res = removeCards(lower_yellow, higher_yellow, default_num_of_cards);
                    break;
                case Black:
                    if (board.black_cure) {
                        return; //If black cure exists we won't take the cards
                    }
                    board.black_cure = res = removeCards(lower_black, higher_black, default_num_of_cards);
                    break;
                case Red:
                    if (board.red_cure) {
                        return; //If red cure exists we won't take the cards
                    }
                    board.red_cure = res = removeCards(lower_red, higher_red, default_num_of_cards);
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

    string Player::role() {
        return "Player";
    }

    void Player::remove_cards() {
        for (size_t i = lower_blue; i < higher_red + 1; i++) {
            cards.at(i) = false;
        }
    }
}