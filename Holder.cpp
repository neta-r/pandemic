#include "Holder.hpp"
using namespace std;
namespace pandemic{
    void Holder::set_level(int lev) { this->level = lev; }

    Color Holder::get_color() { return this->c;}

    bool Holder::is_nei(City city){
        for (int i=0; i<nei.size(); i++){
            if (nei.at(i)==city) return true;
        }
        return false;
    }
}