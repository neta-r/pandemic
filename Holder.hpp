
#include "City.hpp"
#include <unordered_map>
#include <vector>


namespace pandemic{
    class Holder {
    private:
        int level;
        pandemic::Color c;
        City nei[6];
        int size; //actual size of neighbors
        int curr; //current index to insert the nest neighbor
    public:
        Holder() { //default constructor
            level=0;
            c=blue;
            size=6;
        }

        Holder(Color c, int size): c(c), size(size), level(0) , curr(0){}

        Holder(Holder& other){ // copy constructor
            this->level=other.level;
            this->size=other.size;
            this->curr=other.curr;
            for (int i=0; i<size; i++){
                this->nei[i]= other.nei[i];
            }
        }

        Holder& addNei (City city);

        City get(int index){
            return this->nei[index];
        }

        void set_level(int lev);

        int get_level();

        Color get_color();
        //bool is_nei(City city){return this->nei.}
        // };

    };
}