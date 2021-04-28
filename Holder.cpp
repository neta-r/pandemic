#include "Holder.hpp"
using namespace std;
namespace pandemic{
    void Holder::set_level(int lev) { this->level = lev; }

    int Holder::get_level() { return this->level; }

    Color Holder::get_color() { return this->c;}

}