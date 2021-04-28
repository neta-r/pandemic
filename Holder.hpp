
#include "City.hpp"
#include <unordered_map>
#include <vector>


namespace pandemic{
    class Holder {
    private:
        int level;
        pandemic::Color c;
        City nei[6];
        int size;
    public:
        Holder() { //default constructor
            level=0;
            c=blue;
            size=0;
        }

        Holder(Color c, City nei1): c(c), level(0){
            nei[0]=nei1;
            size=1;
        }

        Holder(Color c, City nei1, City nei2): c(c), level(0){
            nei[0]=nei1;
            nei[1]=nei2;
            size=2;
        }

        Holder(Color c, City nei1, City nei2, City nei3): c(c), level(0){
            nei[0]=nei1;
            nei[1]=nei2;
            nei[2]=nei3;
            size=3;
        }

        Holder(Holder& other){ // copy constructor
            this->level=other.level;
            this->size=other.size;
            for (int i=0; i<size; i++){
                this->nei[i]= other.nei[i];
            }
        }

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