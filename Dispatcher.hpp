//
// Created by neta on 26/04/2021.
//
#ifndef UNTITLED_DISPATCHER_H
#define UNTITLED_DISPATCHER_H

#include "Player.hpp"
namespace pandemic {
    class Dispatcher : public Player {
    public:
        Dispatcher(Board board, City city): Player(board, city){}
        void discover_cure(Color color);
        std::string role();
    };
}



#endif //UNTITLED_DISPATCHER_H
