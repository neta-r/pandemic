
#include "City.hpp"
#include <unordered_map>
#include <vector>


namespace pandemic{
    class Holder {
    public:
        pandemic::Color c;
        std::vector<City> nei;
        std::string city_name;
        bool research_station;
        size_t city_num;
        int level; //public so the operator [] could change it
        Holder() { //default constructor
            city_name="";
            level=0;
            c=Blue;
            research_station= false;
            nei= std::vector<City>();
        }
        Holder(Color c,std::string name,size_t num, City nei1=nullCity, City nei2=nullCity, City nei3=nullCity,
               City nei4=nullCity, City nei5=nullCity, City nei6=nullCity): c(c), city_name(name), level(0), research_station(
                false), city_num(num){
            this->nei.push_back(nei1);
            if (nei2!=nullCity) this->nei.push_back(nei2);
            if (nei3!=nullCity) this->nei.push_back(nei3);
            if (nei4!=nullCity) this->nei.push_back(nei4);
            if (nei5!=nullCity) this->nei.push_back(nei5);
            if (nei6!=nullCity) this->nei.push_back(nei6);
        }

    };
}