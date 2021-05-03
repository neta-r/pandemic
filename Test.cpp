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

void all_take_card(City city){
    operationsExpert.take_card(city);
    dispatcher.take_card(city);
    scientist.take_card(city);
    researcher.take_card(city);
    medic.take_card(city);
    virologist.take_card(city);
    geneSplicer.take_card(city);
    fieldDoctor.take_card(city);
}

void all_print_location(){ //TODO:remove it later
    cout << operationsExpert.role() << "is in " << operationsExpert.get_location() << endl;
    cout << dispatcher.role() << "is in " << dispatcher.get_location() << endl;
    cout << scientist.role() << "is in " << scientist.get_location() << endl;
    cout << researcher.role() << "is in " << researcher.get_location() << endl;
    cout << medic.role() << "is in " << medic.get_location() << endl;
    cout << virologist.role() << "is in " << virologist.get_location() << endl;
    cout << geneSplicer.role() << "is in " << geneSplicer.get_location() << endl;
    cout << fieldDoctor.role() << "is in " << fieldDoctor.get_location() << endl;



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
    //let's bring dispatcher back to London
    dispatcher.take_card(London);
    dispatcher.fly_direct(London);
}