#ifndef UNTITLED_CITY_H
#define UNTITLED_CITY_H

#include <string>
#include <unordered_map>
#include "Color.hpp"

namespace pandemic {
    class City {
        std::string name;
        pandemic::Color color;
        //City nei[];
    public:
        static pandemic::City Algiers;
        static pandemic::City Atlanta;
        static pandemic::City Baghdad;
        static pandemic::City Bangkok;
        static pandemic::City Beijing;
        static pandemic::City Bogota;
        static pandemic::City BuenosAires;
        static pandemic::City Cairo;
        static pandemic::City Chennai;
        static pandemic::City Chicago;
        static pandemic::City Delhi;
        static pandemic::City Essen;
        static pandemic::City HoChiMinhCity;
        static pandemic::City HongKong;
        static pandemic::City Istanbul;
        static pandemic::City Jakarta;
        static pandemic::City Johannesburg;
        static pandemic::City Karachi;
        static pandemic::City Khartoum;
        static pandemic::City Kinshasa;
        static pandemic::City Kolkata;
        static pandemic::City Lagos;
        static pandemic::City Lima;
        static pandemic::City London;
        static pandemic::City LosAngeles;
        static pandemic::City Madrid;
        static pandemic::City Manila;
        static pandemic::City MexicoCity;
        static pandemic::City Miami;
        static pandemic::City Milan;
        static pandemic::City Montreal;
        static pandemic::City Moscow;
        static pandemic::City Mumbai;
        static pandemic::City NewYork;
        static pandemic::City Osaka;
        static pandemic::City Paris;
        static pandemic::City Riyadh;
        static pandemic::City SanFrancisco;
        static pandemic::City Santiago;
        static pandemic::City SaoPaulo;
        static pandemic::City Seoul;
        static pandemic::City Shanghai;
        static pandemic::City StPetersburg;
        static pandemic::City Sydney;
        static pandemic::City Taipei;
        static pandemic::City Tehran;
        static pandemic::City Tokyo;
        static pandemic::City Washington;

        City(std::string name, pandemic::Color color) {
            this->name = name;
            this->color = color;
        }

        City &addNei(City &nei);
    };
}
#endif //UNTITLED_CITY_H
