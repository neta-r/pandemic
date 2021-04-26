#ifndef UNTITLED_BOARD_H
#define UNTITLED_BOARD_H

#include "City.hpp"

namespace pandemic{
    class Board {
        Board& operator[] (City city);
    };
}

#endif //UNTITLED_BOARD_H
