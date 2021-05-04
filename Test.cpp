#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;

#include <string>
#include <iostream>

using namespace std;

Board board;

TEST_CASE ("test board") {
            CHECK(board.is_clean() == true);
    //able to put blue cubes
    board[Atlanta] = 1;
            CHECK(board[Atlanta] == 1);
    board[Chicago] = 1;
            CHECK(board[Chicago] == 1);
    //able to put yellow cubes
    board[Bogota] = 1;
            CHECK(board[Bogota] == 1);
    board[BuenosAires] = 1;
            CHECK(board[BuenosAires] == 1);
    //able to put black cubes
    board[Algiers] = 1;
            CHECK(board[Algiers] == 1);
    board[Baghdad] = 1;
            CHECK(board[Baghdad] == 1);
    //able to put red cubes
    board[Bangkok] = 1;
            CHECK(board[Bangkok] == 1);
    board[Beijing] = 1;
            CHECK(board[Beijing] == 1);
    //able to change
    board[Atlanta] = 5;
            CHECK(board[Atlanta] == 5);
    board[Chicago] = 4;
            CHECK(board[Chicago] == 4);
    board[Bogota] = 3;
            CHECK(board[Bogota] == 3);
    board[BuenosAires] = 2;
            CHECK(board[BuenosAires] == 2);
    board[Algiers] = 2;
            CHECK(board[Algiers] == 2);
    board[Baghdad] = 4;
            CHECK(board[Baghdad] == 4);
    board[Bangkok] = 5;
            CHECK(board[Bangkok] == 5);
    board[Beijing] = 2;
            CHECK(board[Beijing] == 2);
            CHECK(board.is_clean() == false);
}

OperationsExpert builder{board, Beijing};
OperationsExpert operationsExpert{board, Atlanta};
Dispatcher dispatcher{board, Atlanta};
Scientist scientist{board, Atlanta, 3};
Researcher researcher{board, Atlanta};
Medic medic{board, Atlanta};
Virologist virologist{board, Atlanta};
GeneSplicer geneSplicer{board, Atlanta};
FieldDoctor fieldDoctor{board, Atlanta};

void build_in(City city) {
    builder.take_card(city);
    builder.fly_direct(city);
    builder.build();
}


void all_take_card(City city) {
    operationsExpert.take_card(city);
    dispatcher.take_card(city);
    scientist.take_card(city);
    researcher.take_card(city);
    medic.take_card(city);
    virologist.take_card(city);
    geneSplicer.take_card(city);
    fieldDoctor.take_card(city);
}

void get_to(Player &p, City curr, City dest) {
    p.take_card(curr);
    p.fly_charter(dest);
}

void all_get_to(City curr, City dest) {
    get_to(operationsExpert, curr, dest);
    get_to(dispatcher, curr, dest);
    get_to(scientist, curr, dest);
    get_to(researcher, curr, dest);
    get_to(medic, curr, dest);
    get_to(virologist, curr, dest);
    get_to(geneSplicer, curr, dest);
    get_to(fieldDoctor, curr, dest);
}

void spread(City common_curr_city) {
    get_to(operationsExpert, common_curr_city, BuenosAires);
    get_to(dispatcher, common_curr_city, Istanbul);
    get_to(scientist, common_curr_city, Paris);
    get_to(researcher, common_curr_city, Mumbai);
    get_to(medic, common_curr_city, Sydney);
    get_to(virologist, common_curr_city, Essen);
    get_to(geneSplicer, common_curr_city, SanFrancisco);
    get_to(fieldDoctor, common_curr_city, Santiago);
}

void take_different_cards() {
    operationsExpert.take_card(BuenosAires);
    dispatcher.take_card(Istanbul);
    scientist.take_card(Paris);
    researcher.take_card(Mumbai);
    medic.take_card(Sydney);
    virologist.take_card(Essen);
    geneSplicer.take_card(SanFrancisco);
    fieldDoctor.take_card(Santiago);
}

void clear_all() {
    operationsExpert.remove_cards();
    dispatcher.remove_cards();
    scientist.remove_cards();
    researcher.remove_cards();
    medic.remove_cards();
    virologist.remove_cards();
    geneSplicer.remove_cards();
    fieldDoctor.remove_cards();
}

TEST_CASE ("drive") {
    //able to drive to a nearby city in the same color
            CHECK_NOTHROW(operationsExpert.drive(Washington));
            CHECK_NOTHROW(dispatcher.drive(Washington));
            CHECK_NOTHROW(scientist.drive(Washington));
            CHECK_NOTHROW(researcher.drive(Washington));
            CHECK_NOTHROW(medic.drive(Washington));
            CHECK_NOTHROW(virologist.drive(Washington));
            CHECK_NOTHROW(geneSplicer.drive(Washington));
            CHECK_NOTHROW(fieldDoctor.drive(Washington));
    //able to drive to a nearby city in a different color
            CHECK_NOTHROW(operationsExpert.drive(Miami));
            CHECK_NOTHROW(dispatcher.drive(Miami));
            CHECK_NOTHROW(scientist.drive(Miami));
            CHECK_NOTHROW(researcher.drive(Miami));
            CHECK_NOTHROW(medic.drive(Miami));
            CHECK_NOTHROW(virologist.drive(Miami));
            CHECK_NOTHROW(geneSplicer.drive(Miami));
            CHECK_NOTHROW(fieldDoctor.drive(Miami));
    //unable to drive to a non nearby city in the same color
            CHECK_THROWS(operationsExpert.drive(SaoPaulo));
            CHECK_THROWS(dispatcher.drive(SaoPaulo));
            CHECK_THROWS(scientist.drive(SaoPaulo));
            CHECK_THROWS(researcher.drive(SaoPaulo));
            CHECK_THROWS(medic.drive(SaoPaulo));
            CHECK_THROWS(virologist.drive(SaoPaulo));
            CHECK_THROWS(geneSplicer.drive(SaoPaulo));
            CHECK_THROWS(fieldDoctor.drive(SaoPaulo));
    //unable to drive to a non nearby city in a different color
            CHECK_THROWS(operationsExpert.drive(Cairo));
            CHECK_THROWS(dispatcher.drive(Cairo));
            CHECK_THROWS(scientist.drive(Cairo));
            CHECK_THROWS(researcher.drive(Cairo));
            CHECK_THROWS(medic.drive(Cairo));
            CHECK_THROWS(virologist.drive(Cairo));
            CHECK_THROWS(geneSplicer.drive(Cairo));
            CHECK_THROWS(fieldDoctor.drive(Cairo));
}

TEST_CASE ("fly_direct") {
    all_take_card(Beijing);
    //able to fly direct to Beijing
            CHECK_NOTHROW(operationsExpert.fly_direct(Beijing));
            CHECK_NOTHROW(dispatcher.fly_direct(Beijing));
            CHECK_NOTHROW(scientist.fly_direct(Beijing));
            CHECK_NOTHROW(researcher.fly_direct(Beijing));
            CHECK_NOTHROW(medic.fly_direct(Beijing));
            CHECK_NOTHROW(virologist.fly_direct(Beijing));
            CHECK_NOTHROW(geneSplicer.fly_direct(Beijing));
            CHECK_NOTHROW(fieldDoctor.fly_direct(Beijing));
    all_take_card(Beijing);
    //unable to fly direct to London (they can fly charter)
            CHECK_THROWS(operationsExpert.fly_direct(London));
            CHECK_THROWS(dispatcher.fly_direct(London));
            CHECK_THROWS(scientist.fly_direct(London));
            CHECK_THROWS(researcher.fly_direct(London));
            CHECK_THROWS(medic.fly_direct(London));
            CHECK_THROWS(virologist.fly_direct(London));
            CHECK_THROWS(geneSplicer.fly_direct(London));
            CHECK_THROWS(fieldDoctor.fly_direct(London));
    builder.build(); //built a research station in Beijing
    //all unable fly direct to Madrid except for **dispatcher**
            CHECK_THROWS(operationsExpert.fly_direct(Madrid));
            CHECK_NOTHROW(dispatcher.fly_direct(Madrid));
            CHECK_THROWS(scientist.fly_direct(Madrid));
            CHECK_THROWS(researcher.fly_direct(Madrid));
            CHECK_THROWS(medic.fly_direct(Madrid));
            CHECK_THROWS(virologist.fly_direct(Madrid));
            CHECK_THROWS(geneSplicer.fly_direct(Madrid));
            CHECK_THROWS(fieldDoctor.fly_direct(Madrid));
    //let's bring dispatcher back to Beijing
    dispatcher.take_card(Beijing);
    dispatcher.fly_direct(Beijing);
    all_take_card(Madrid);
    //all able fly direct to Madrid and dispatcher didn't waste his card (Beijing has a research station)
            CHECK_NOTHROW(operationsExpert.fly_direct(Madrid));
            CHECK_NOTHROW(dispatcher.fly_direct(Madrid));
            CHECK_NOTHROW(dispatcher.fly_charter(MexicoCity)); //just now throwing the Madrid card!
            CHECK_NOTHROW(scientist.fly_direct(Madrid));
            CHECK_NOTHROW(researcher.fly_direct(Madrid));
            CHECK_NOTHROW(medic.fly_direct(Madrid));
            CHECK_NOTHROW(virologist.fly_direct(Madrid));
            CHECK_NOTHROW(geneSplicer.fly_direct(Madrid));
            CHECK_NOTHROW(fieldDoctor.fly_direct(Madrid));
    //let's bring dispatcher back to Madrid
    dispatcher.take_card(Madrid);
    dispatcher.fly_direct(Madrid);
}

TEST_CASE ("fly_charter") {
    all_get_to(Madrid, Beijing);
    //all now in Beijing
    all_take_card(Beijing);
    //able to fly charter to Beijing
            CHECK_NOTHROW(operationsExpert.fly_charter(Manila));
            CHECK_NOTHROW(dispatcher.fly_charter(Manila));
            CHECK_NOTHROW(scientist.fly_charter(Manila));
            CHECK_NOTHROW(researcher.fly_charter(Manila));
            CHECK_NOTHROW(medic.fly_charter(Manila));
            CHECK_NOTHROW(virologist.fly_charter(Manila));
            CHECK_NOTHROW(geneSplicer.fly_charter(Manila));
            CHECK_NOTHROW(fieldDoctor.fly_charter(Manila));
    all_take_card(Moscow);
    //unable to fly direct to Moscow (they can fly direct)
            CHECK_THROWS(operationsExpert.fly_charter(Moscow));
            CHECK_THROWS(dispatcher.fly_charter(Moscow));
            CHECK_THROWS(scientist.fly_charter(Moscow));
            CHECK_THROWS(researcher.fly_charter(Moscow));
            CHECK_THROWS(medic.fly_charter(Moscow));
            CHECK_THROWS(virologist.fly_charter(Moscow));
            CHECK_THROWS(geneSplicer.fly_charter(Moscow));
            CHECK_THROWS(fieldDoctor.fly_charter(Moscow));
    build_in(Moscow); //built a research station in Moscow
    //all unable fly direct to Tokyo including dispatcher (even though Moscow has a research station)
            CHECK_THROWS(operationsExpert.fly_charter(Tokyo));
            CHECK_THROWS(dispatcher.fly_charter(Tokyo));
            CHECK_THROWS(scientist.fly_charter(Tokyo));
            CHECK_THROWS(researcher.fly_charter(Tokyo));
            CHECK_THROWS(medic.fly_charter(Tokyo));
            CHECK_THROWS(virologist.fly_charter(Tokyo));
            CHECK_THROWS(geneSplicer.fly_charter(Tokyo));
            CHECK_THROWS(fieldDoctor.fly_charter(Tokyo));
}

TEST_CASE ("fly_shuttle") {
    //all now in Manila
    build_in(Manila); //built a research station in Manila
    //able to fly shuttle to Beijing (a city with research station)
            CHECK_NOTHROW(operationsExpert.fly_shuttle(Beijing));
            CHECK_NOTHROW(dispatcher.fly_shuttle(Beijing));
            CHECK_NOTHROW(scientist.fly_shuttle(Beijing));
            CHECK_NOTHROW(researcher.fly_shuttle(Beijing));
            CHECK_NOTHROW(medic.fly_shuttle(Beijing));
            CHECK_NOTHROW(virologist.fly_shuttle(Beijing));
            CHECK_NOTHROW(geneSplicer.fly_shuttle(Beijing));
            CHECK_NOTHROW(fieldDoctor.fly_shuttle(Beijing));
    //unable to fly shuttle to Lagos (a city without research station)
            CHECK_THROWS(operationsExpert.fly_shuttle(Lagos));
            CHECK_THROWS(dispatcher.fly_shuttle(Lagos));
            CHECK_THROWS(scientist.fly_shuttle(Lagos));
            CHECK_THROWS(researcher.fly_shuttle(Lagos));
            CHECK_THROWS(medic.fly_shuttle(Lagos));
            CHECK_THROWS(virologist.fly_shuttle(Lagos));
            CHECK_THROWS(geneSplicer.fly_shuttle(Lagos));
            CHECK_THROWS(fieldDoctor.fly_shuttle(Lagos));
    all_get_to(Beijing, BuenosAires);
    //unable to fly shuttle to Moscow (a city with research station- but you're in BuenosAires that has no research station)
            CHECK_THROWS(operationsExpert.fly_shuttle(Moscow));
            CHECK_THROWS(dispatcher.fly_shuttle(Moscow));
            CHECK_THROWS(scientist.fly_shuttle(Moscow));
            CHECK_THROWS(researcher.fly_shuttle(Moscow));
            CHECK_THROWS(medic.fly_shuttle(Moscow));
            CHECK_THROWS(virologist.fly_shuttle(Moscow));
            CHECK_THROWS(geneSplicer.fly_shuttle(Moscow));
            CHECK_THROWS(fieldDoctor.fly_shuttle(Moscow));
    //unable to fly shuttle to Milan (a city without research station- and you're in BuenosAires that has no research station)
            CHECK_THROWS(operationsExpert.fly_shuttle(Milan));
            CHECK_THROWS(dispatcher.fly_shuttle(Milan));
            CHECK_THROWS(scientist.fly_shuttle(Milan));
            CHECK_THROWS(researcher.fly_shuttle(Milan));
            CHECK_THROWS(medic.fly_shuttle(Milan));
            CHECK_THROWS(virologist.fly_shuttle(Milan));
            CHECK_THROWS(geneSplicer.fly_shuttle(Milan));
            CHECK_THROWS(fieldDoctor.fly_shuttle(Milan));
}

TEST_CASE ("build") {
    //all now in BuenosAires
    spread(BuenosAires);
    take_different_cards();
    /*operations expert in BuenosAires
    dispatcher in Istanbul
    scientist in Paris
    researcher in Mumbai
    medic in Sydney
    virologist in Essen
    geneSplicer in SanFrancisco
    fieldDoctor in Santiago*/

    //able to build all over and **operationsExpert** didnt waste his card
            CHECK_NOTHROW(operationsExpert.build());
            CHECK_NOTHROW(operationsExpert.fly_charter(MexicoCity)); //just now throwing the BuenosAires card!
            CHECK_NOTHROW(dispatcher.build());
            CHECK_NOTHROW(scientist.build());
            CHECK_NOTHROW(researcher.build());
            CHECK_NOTHROW(medic.build());
            CHECK_NOTHROW(virologist.build());
            CHECK_NOTHROW(geneSplicer.build());
            CHECK_NOTHROW(fieldDoctor.build());
    //bringing operations expert back to BuenosAires
    operationsExpert.take_card(BuenosAires);
    operationsExpert.fly_direct(BuenosAires);
    take_different_cards();
    //unable to build all over again but doesn't throw exception
            CHECK_NOTHROW(operationsExpert.build());
            CHECK_NOTHROW(operationsExpert.fly_charter(MexicoCity)); //just now throwing the Madrid card!
            CHECK_NOTHROW(dispatcher.build());
            CHECK_NOTHROW(scientist.build());
            CHECK_NOTHROW(researcher.build());
            CHECK_NOTHROW(medic.build());
            CHECK_NOTHROW(virologist.build());
            CHECK_NOTHROW(geneSplicer.build());
            CHECK_NOTHROW(fieldDoctor.build());
    //bringing operations expert back to BuenosAires
    operationsExpert.take_card(BuenosAires);
    operationsExpert.fly_direct(BuenosAires);
    all_get_to(BuenosAires, Algiers);
    //unable to build in Algiers except for operations expert
            CHECK_NOTHROW(operationsExpert.build());
            CHECK_THROWS(dispatcher.build());
            CHECK_THROWS(scientist.build());
            CHECK_THROWS(researcher.build());
            CHECK_THROWS(medic.build());
            CHECK_THROWS(virologist.build());
            CHECK_THROWS(geneSplicer.build());
            CHECK_THROWS(fieldDoctor.build());
}


void discover_twice(Player &p, City research, City one, City two, City three, City four, City five, Color color) {
    p.take_card(one).take_card(two).take_card(three).take_card(four).take_card(five);
            CHECK_NOTHROW(p.discover_cure(color));
    p.take_card(one).take_card(two).take_card(three).take_card(four).take_card(five);
            CHECK_NOTHROW(p.discover_cure(color));
            CHECK_NOTHROW(p.fly_direct(one));
            CHECK_NOTHROW(p.fly_direct(two));
            CHECK_NOTHROW(p.fly_direct(three));
            CHECK_NOTHROW(p.fly_direct(four));
            CHECK_NOTHROW(p.fly_direct(five));
    get_to(p, five, research);
    board.remove_cures();
}

void all_discover_twice(City research, City one, City two, City three, City four, City five, Color color) {
    discover_twice(operationsExpert, research, one, two, three, four, five, color);
    discover_twice(dispatcher, research, one, two, three, four, five, color);
    discover_twice(scientist, research, one, two, three, four, five, color);
    discover_twice(researcher, research, one, two, three, four, five, color);
    discover_twice(medic, research, one, two, three, four, five, color);
    discover_twice(virologist, research, one, two, three, four, five, color);
    discover_twice(geneSplicer, research, one, two, three, four, five, color);
    discover_twice(fieldDoctor, research, one, two, three, four, five, color);
}

TEST_CASE ("discover cure - regular actions") {
    clear_all();
    //all in Algiers a city with a research station
    //able to discover blue cure and unble to discovre it twice
    all_discover_twice(Algiers, SanFrancisco, Chicago, Montreal, NewYork, Washington, Blue);
    clear_all();
    //able to discover yellow cure and unble to discovre it twice
    all_discover_twice(Algiers, SaoPaulo, Bogota, Miami, MexicoCity, Santiago, Yellow);
    clear_all();
    //able to discover black cure and unble to discovre it twice
    all_discover_twice(Algiers, Moscow, Baghdad, Tehran, Chennai, Mumbai, Black);
    clear_all();
    //able to discover red cure and unble to discovre it twice
    all_discover_twice(Algiers, Sydney, Manila, Osaka, Taipei, Bangkok, Red);
    clear_all();
}

void able_to_discover_mixed_color(City one, City two, City three, City four, City five, Color color) {
    all_take_card(one);
    all_take_card(two);
    all_take_card(three);
    all_take_card(four);
    all_take_card(five);
    //Only **GeneSplicer** able to
            CHECK_THROWS(operationsExpert.discover_cure(color));
            CHECK_THROWS(dispatcher.discover_cure(color));
            CHECK_THROWS(scientist.discover_cure(color));
            CHECK_THROWS(researcher.discover_cure(color));
            CHECK_THROWS(medic.discover_cure(color));
            CHECK_THROWS(virologist.discover_cure(color));
            CHECK_NOTHROW(geneSplicer.discover_cure(color));
    board.remove_cures();
            CHECK_THROWS(fieldDoctor.discover_cure(color));
}

TEST_CASE ("discover cure - mixed colors") {
    clear_all();
    able_to_discover_mixed_color(SanFrancisco, Bogota, Chennai, Sydney, Miami, Blue);
    able_to_discover_mixed_color(SanFrancisco, Bogota, Chennai, Sydney, Miami, Yellow);
    able_to_discover_mixed_color(SanFrancisco, Bogota, Chennai, Sydney, Miami, Black);
    able_to_discover_mixed_color(SanFrancisco, Bogota, Chennai, Sydney, Miami, Red);
}

void able_to_discover_with_three_cards(City one, City two, City three, Color color) {
    all_take_card(one);
    all_take_card(two);
    all_take_card(three);
    //Only **scientist** able to
            CHECK_THROWS(operationsExpert.discover_cure(color));
            CHECK_THROWS(dispatcher.discover_cure(color));
            CHECK_NOTHROW(scientist.discover_cure(color));
    board.remove_cures();
            CHECK_THROWS(researcher.discover_cure(color));
            CHECK_THROWS(medic.discover_cure(color));
            CHECK_THROWS(virologist.discover_cure(color));
            CHECK_THROWS(geneSplicer.discover_cure(color));
            CHECK_THROWS(fieldDoctor.discover_cure(color));
}

TEST_CASE ("discover cure - less then 5 cards") {
    clear_all();
    able_to_discover_with_three_cards(SanFrancisco, Chicago, Montreal, Blue);
    clear_all();
    able_to_discover_with_three_cards(SaoPaulo, Bogota, Miami, Yellow);
    clear_all();
    able_to_discover_with_three_cards(Moscow, Baghdad, Tehran, Black);
    clear_all();
    able_to_discover_with_three_cards(Sydney, Manila, Osaka, Red);
}


void unable_to_discover_not_in_a_research_station(City one, City two, City three, City four, City five, Color color) {
    all_take_card(one);
    all_take_card(two);
    all_take_card(three);
    all_take_card(four);
    all_take_card(five);
    //Only **researcher** able to
            CHECK_THROWS(operationsExpert.discover_cure(color));
            CHECK_THROWS(dispatcher.discover_cure(color));
            CHECK_THROWS(scientist.discover_cure(color));
            CHECK_THROWS(medic.discover_cure(color));
            CHECK_NOTHROW(researcher.discover_cure(color));
    board.remove_cures();
            CHECK_THROWS(virologist.discover_cure(color));
            CHECK_THROWS(geneSplicer.discover_cure(color));
            CHECK_THROWS(fieldDoctor.discover_cure(color));
}

TEST_CASE ("discover cure - not in a research station") {
    all_get_to(Algiers, NewYork); //NewYork has no research station
    unable_to_discover_not_in_a_research_station(SanFrancisco, Chicago, Montreal, NewYork, Washington, Blue);
    unable_to_discover_not_in_a_research_station(SaoPaulo, Bogota, Miami, MexicoCity, Santiago, Yellow);
    unable_to_discover_not_in_a_research_station(Moscow, Baghdad, Tehran, Chennai, Mumbai, Black);
    unable_to_discover_not_in_a_research_station(Sydney, Manila, Osaka, Taipei, Bangkok, Red);
}

void able_to_treat_no_cure() {
    //Only **medic** reduce disease level to 0 !!
    board[NewYork] = 8;
            CHECK_NOTHROW(operationsExpert.treat(NewYork));
            CHECK(board[NewYork] == 7);
            CHECK_NOTHROW(dispatcher.treat(NewYork));
            CHECK(board[NewYork] == 6);
            CHECK_NOTHROW(scientist.treat(NewYork));
            CHECK(board[NewYork] == 5);
            CHECK_NOTHROW(researcher.treat(NewYork));
            CHECK(board[NewYork] == 4);
            CHECK_NOTHROW(medic.treat(NewYork));
            CHECK(board[NewYork] == 0);
    board[NewYork] = 3;
            CHECK_NOTHROW(virologist.treat(NewYork));
            CHECK(board[NewYork] == 2);
            CHECK_NOTHROW(geneSplicer.treat(NewYork));
            CHECK(board[NewYork] == 1);
            CHECK_NOTHROW(fieldDoctor.treat(NewYork));
            CHECK(board[NewYork] == 0);
}

void able_to_treat_with_cure(Player &p) {
    board[NewYork] = 8;
    builder.take_card(London).take_card(Paris).take_card(Washington).take_card(Essen).take_card(Milan);
    builder.discover_cure(Blue);
            CHECK_NOTHROW(operationsExpert.treat(NewYork));
            CHECK(board[NewYork] == 0);
    board.remove_cures();
}

void all_able_to_treat_with_cure() {
    able_to_treat_with_cure(operationsExpert);
    able_to_treat_with_cure(dispatcher);
    able_to_treat_with_cure(scientist);
    able_to_treat_with_cure(researcher);
    able_to_treat_with_cure(medic);
    able_to_treat_with_cure(virologist);
    able_to_treat_with_cure(geneSplicer);
    able_to_treat_with_cure(fieldDoctor);
}

void all_throw() {
            CHECK_THROWS(operationsExpert.treat(NewYork));
            CHECK_THROWS(dispatcher.treat(NewYork));
            CHECK_THROWS(scientist.treat(NewYork));
            CHECK_THROWS(researcher.treat(NewYork));
            CHECK_THROWS(medic.treat(NewYork));
            CHECK_THROWS(virologist.treat(NewYork));
            CHECK_THROWS(geneSplicer.treat(NewYork));
            CHECK_THROWS(fieldDoctor.treat(NewYork));
}

void able_to_treat_not_in_the_same_city() {
    //Only **virologist** able to
    board[Manila] = 8;
            CHECK_THROWS(operationsExpert.treat(Manila));
            CHECK_THROWS(dispatcher.treat(Manila));
            CHECK_THROWS(scientist.treat(Manila));
            CHECK_THROWS(researcher.treat(Manila));
            CHECK_THROWS(medic.treat(Manila));
            CHECK_NOTHROW(virologist.treat(Manila));
            CHECK_THROWS(geneSplicer.treat(Manila));
            CHECK_THROWS(fieldDoctor.treat(Manila));
}

void able_to_treat_not_in_a_nearby_city() {
    //Only **fieldDoctor** able to (and virologist- can everywhere)
    board[Washington] = 8;
            CHECK_THROWS(operationsExpert.treat(Washington));
            CHECK_THROWS(dispatcher.treat(Washington));
            CHECK_THROWS(scientist.treat(Washington));
            CHECK_THROWS(researcher.treat(Washington));
            CHECK_THROWS(medic.treat(Washington));
            CHECK_NOTHROW(virologist.treat(Washington));
            CHECK_THROWS(geneSplicer.treat(Washington));
            CHECK_NOTHROW(fieldDoctor.treat(Washington));
}

void reduce_level_to_0_after_cure_drive() {
    //Only **medic** can
    board[Washington] = 8;
    operationsExpert.drive(Washington);
            CHECK(board[Washington] == 8);
    dispatcher.drive(Washington);
            CHECK(board[Washington] == 8);
    scientist.drive(Washington);
            CHECK(board[Washington] == 8);
    researcher.drive(Washington);
            CHECK(board[Washington] == 8);
    virologist.drive(Washington);
            CHECK(board[Washington] == 8);
    geneSplicer.drive(Washington);
            CHECK(board[Washington] == 8);
    fieldDoctor.drive(Washington);
            CHECK(board[Washington] == 8);
    medic.drive(Washington);
            CHECK(board[Washington] == 0);
}

void reduce_level_to_0_after_cure_fly_direct() {
    //Only **medic** can
    all_take_card(Madrid);
    board[Madrid] = 8;
    operationsExpert.fly_direct(Madrid);
            CHECK(board[Madrid] == 8);
    dispatcher.fly_direct(Madrid);
            CHECK(board[Madrid] == 8);
    scientist.fly_direct(Madrid);
            CHECK(board[Madrid] == 8);
    researcher.fly_direct(Madrid);
            CHECK(board[Madrid] == 8);
    virologist.fly_direct(Madrid);
            CHECK(board[Madrid] == 8);
    geneSplicer.fly_direct(Madrid);
            CHECK(board[Madrid] == 8);
    fieldDoctor.fly_direct(Madrid);
            CHECK(board[Madrid] == 8);
    medic.fly_direct(Madrid);
            CHECK(board[Madrid] == 0);
}

void reduce_level_to_0_after_cure_fly_charter() {
    //Only **medic** can
    all_take_card(Madrid);
    board[Chicago] = 8;
    operationsExpert.fly_charter(Chicago);
            CHECK(board[Chicago] == 8);
    dispatcher.fly_charter(Chicago);
            CHECK(board[Chicago] == 8);
    scientist.fly_charter(Chicago);
            CHECK(board[Chicago] == 8);
    researcher.fly_charter(Chicago);
            CHECK(board[Chicago] == 8);
    virologist.fly_charter(Chicago);
            CHECK(board[Chicago] == 8);
    geneSplicer.fly_charter(Chicago);
            CHECK(board[Chicago] == 8);
    fieldDoctor.fly_charter(Chicago);
            CHECK(board[Chicago] == 8);
    medic.fly_charter(Chicago);
            CHECK(board[Chicago] == 0);
}

void reduce_level_to_0_after_cure_fly_shuttle() {
    //Only **medic** can
    board[Essen] = 8;
    operationsExpert.fly_shuttle(Essen);
            CHECK(board[Essen] == 8);
    dispatcher.fly_shuttle(Essen);
            CHECK(board[Essen] == 8);
    scientist.fly_shuttle(Essen);
            CHECK(board[Essen] == 8);
    researcher.fly_shuttle(Essen);
            CHECK(board[Essen] == 8);
    virologist.fly_shuttle(Essen);
            CHECK(board[Essen] == 8);
    geneSplicer.fly_shuttle(Essen);
            CHECK(board[Essen] == 8);
    fieldDoctor.fly_shuttle(Essen);
            CHECK(board[Essen] == 8);
    medic.fly_shuttle(Essen);
            CHECK(board[Essen] == 0);
}


TEST_CASE ("treat - regular actions") {
    //all in NewYork
    board.remove_cures();
    able_to_treat_no_cure();
    all_able_to_treat_with_cure();
    all_throw();
    able_to_treat_not_in_the_same_city();
    able_to_treat_not_in_a_nearby_city();
    //discover blue cure
    builder.take_card(London).take_card(Paris).take_card(Washington).take_card(Essen).take_card(Milan);
    builder.discover_cure(Blue);
    reduce_level_to_0_after_cure_drive();
    reduce_level_to_0_after_cure_fly_direct();
    reduce_level_to_0_after_cure_fly_charter();
    build_in(Chicago);
    build_in(Essen);
    reduce_level_to_0_after_cure_fly_shuttle();
}