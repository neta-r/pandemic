
#include "City.hpp"
#include <unordered_map>
#include <vector>


namespace pandemic{
    class Holder {
    private:
        pandemic::Color c;
        std::vector<City> nei;

    public:
        int level; //public so the operator [] could change it
        Holder() { //default constructor
            level=0;
            c=blue;
            nei= std::vector<City>();
        }
        Holder(Color c, City nei1=nullCity, City nei2=nullCity, City nei3=nullCity,
               City nei4=nullCity, City nei5=nullCity, City nei6=nullCity): c(c), level(0){
            this->nei.push_back(nei1);
            if (nei2!=nullCity) this->nei.push_back(nei2);
            if (nei3!=nullCity) this->nei.push_back(nei3);
            if (nei4!=nullCity) this->nei.push_back(nei4);
            if (nei5!=nullCity) this->nei.push_back(nei5);
            if (nei6!=nullCity) this->nei.push_back(nei6);
        }

        void set_level(int lev);

        Color get_color();
        //bool is_nei(City city){return this->nei.}
        // };

    };
}