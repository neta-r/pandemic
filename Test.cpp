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

void all_get_to(City city) {
    all_take_card(city);
    operationsExpert.fly_direct(city);
    dispatcher.fly_direct(city);
    scientist.fly_direct(city);
    researcher.fly_direct(city);
    medic.fly_direct(city);
    virologist.fly_direct(city);
    geneSplicer.fly_direct(city);
    fieldDoctor.fly_direct(city);
}

void all_print_location() { //TODO:remove it later
    cout << operationsExpert.role() << "is in " << operationsExpert.get_location() << endl;
    cout << dispatcher.role() << "is in " << dispatcher.get_location() << endl;
    cout << scientist.role() << "is in " << scientist.get_location() << endl;
    cout << researcher.role() << "is in " << researcher.get_location() << endl;
    cout << medic.role() << "is in " << medic.get_location() << endl;
    cout << virologist.role() << "is in " << virologist.get_location() << endl;
    cout << geneSplicer.role() << "is in " << geneSplicer.get_location() << endl;
    cout << fieldDoctor.role() << "is in " << fieldDoctor.get_location() << endl;
    cout << "builder is in " << builder.get_location() << endl;
}

void all_print_cards() { //TODO:remove it later
    cout << operationsExpert.role() << "has " << operationsExpert.get_cards() << endl;
    cout << dispatcher.role() << "has " << dispatcher.get_cards() << endl;
    cout << scientist.role() << "has " << scientist.get_cards() << endl;
    cout << researcher.role() << "has " << researcher.get_cards() << endl;
    cout << medic.role() << "has " << medic.get_cards() << endl;
    cout << virologist.role() << "has " << virologist.get_cards() << endl;
    cout << geneSplicer.role() << "has " << geneSplicer.get_cards() << endl;
    cout << fieldDoctor.role() << "has " << fieldDoctor.get_cards() << endl;
    cout << "builder has " << builder.get_cards() << endl;
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
    //all unable fly direct to Madrid except for dispatcher
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
}

TEST_CASE ("fly_charter") {
    all_get_to(Beijing);
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
    all_get_to(BuenosAires);
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
    all_take_card(BuenosAires);
    //able to build in BuenosAires and operationsExpert didnt waste his card
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
    all_take_card(BuenosAires);
    //unable to build in BuenosAires again but doesn't throw exception
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
    all_get_to(Algiers);
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