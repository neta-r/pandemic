
#include "City.hpp"
#include <unordered_map>
#include <vector>


namespace pandemic{
    class Holder {
    private:
        int level;
        pandemic::Color c;
        std::vector<City> nei;
    public:
        Holder(Color color, std::vector<City> &nei) : c(color), nei(nei), level(0) {}

        void set_level(int lev) { this->level = lev; }

        int get_level() { return this->level; }

        Color get_color() { return this->c; }
        //bool is_nei(City city){return this->nei.}
        // };
    };
}