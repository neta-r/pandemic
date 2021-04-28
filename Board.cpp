#include "Board.hpp"
#include <iostream>
using namespace std;
namespace pandemic{

    void Board::load_map() {
        load_blue();
        load_yellow();
        load_black();
        load_red();
    }


    void Board::load_blue() {
        cities[Atlanta] =Holder (blue,"Atlanta", Chicago,Miami,Washington);
        cities[Chicago]=Holder(blue,"Chicago", SanFrancisco,LosAngeles,MexicoCity,Atlanta,Montreal);
        cities[Essen]=Holder(blue,"Essen" ,London,Paris,Milan,StPetersburg);
        cities[London]=Holder(blue,"London", NewYork,Madrid,Essen,Paris);
        cities[Madrid]=Holder(blue,"Madrid",London,NewYork,Paris,SaoPaulo,Algiers);
        cities[Milan]=Holder(blue,"Milan", Essen,Paris,Istanbul);
        cities[Montreal]=Holder(blue,"Montreal",Chicago,Washington,NewYork);
        cities[NewYork]=Holder(blue,"NewYork", Montreal,Washington,London,Madrid);
        cities[Paris]=Holder(blue,"Paris",Algiers,Essen,Madrid,Milan,London);
        cities[SanFrancisco]=Holder(blue,"SanFrancisco",LosAngeles,Chicago,Tokyo,Manila);
        cities[StPetersburg]=Holder(blue,"StPetersburg",Essen,Istanbul,Moscow);
        cities[Washington]=Holder(blue,"Washington",Atlanta,NewYork,Montreal,Miami);
    }
    void Board::load_yellow() {
        cities[Bogota]=Holder(yellow,"Bogota",MexicoCity,Lima,Miami,SaoPaulo,BuenosAires);
        cities[BuenosAires]=Holder(yellow,"BuenosAires",Bogota,SaoPaulo);
        cities[Johannesburg]=Holder(yellow,"Johannesburg",Kinshasa,Khartoum);
        cities[Khartoum]=Holder(yellow,"Khartoum",Lagos,Kinshasa,Johannesburg);
        cities[Kinshasa]=Holder(yellow,"Kinshasa",Lagos,Khartoum,Johannesburg);
        cities[Lagos]=Holder(yellow,"Lagos",SaoPaulo,Khartoum,Kinshasa);
        cities[Lima]=Holder(yellow,"Lima",MexicoCity,Bogota,Santiago);
        cities[LosAngeles]=Holder(yellow,"LosAngeles",SanFrancisco,Chicago,MexicoCity,Sydney);
        cities[MexicoCity]=Holder(yellow,"MexicoCity",LosAngeles,Chicago,Miami,Lima,Bogota);
        cities[Miami]=Holder(yellow,"Miami",Atlanta,MexicoCity,Washington,Bogota);
        cities[Santiago]=Holder(yellow,"Santiago",Lima);
        cities[SaoPaulo]=Holder(yellow,"SaoPaulo",Bogota,BuenosAires,Lagos,Madrid);
    }
    void Board::load_black() {
        cities[Algiers]=Holder(black,"Algiers",Madrid,Paris,Istanbul,Cairo);
        cities[Baghdad]=Holder(black,"Baghdad",Tehran,Istanbul,Cairo,Riyadh,Karachi);
        cities[Cairo]=Holder(black,"Cairo",Algiers,Istanbul,Baghdad,Khartoum,Riyadh);
        cities[Chennai]=Holder(black,"Chennai",Mumbai,Delhi,Kolkata,Bangkok,Jakarta);
        cities[Delhi]=Holder(black,"Delhi",Tehran,Karachi,Mumbai,Chennai,Kolkata);
        cities[Istanbul]=Holder(black,"Istanbul",Milan,Algiers,StPetersburg,Cairo,Baghdad,Moscow);
        cities[Karachi]=Holder(black,"Karachi",Tehran,Baghdad,Riyadh,Mumbai,Delhi);
        cities[Kolkata]=Holder(black,"Kolkata",Delhi,Chennai,Bangkok,HongKong);
        cities[Moscow]=Holder(black,"Moscow",StPetersburg,Istanbul,Tehran);
        cities[Mumbai]=Holder(black,"Mumbai",Karachi,Delhi,Chennai);
        cities[Riyadh]=Holder(black,"Riyadh",Baghdad,Cairo,Karachi);
        cities[Tehran]=Holder(black,"Tehran",Baghdad,Moscow,Karachi,Delhi);
    }
    void Board::load_red() {
        cities[Bangkok]=Holder(red,"Bangkok",Kolkata,Chennai,Jakarta,HoChiMinhCity,HongKong);
        cities[Beijing]=Holder(red,"Beijing",Shanghai,Seoul);
        cities[HoChiMinhCity]=Holder(red,"HoChiMinhCity",Jakarta,Bangkok,HongKong,Manila);
        cities[HongKong]=Holder(red,"HongKong",Bangkok,Kolkata,HoChiMinhCity,Shanghai,Manila,Taipei);
        cities[Jakarta]=Holder(red,"Jakarta",Chennai,Bangkok,HoChiMinhCity,Sydney);
        cities[Manila]=Holder(red,"Manila",Taipei,SanFrancisco,HoChiMinhCity,Sydney);
        cities[Osaka]=Holder(red,"Osaka",Taipei,Tokyo);
        cities[Seoul]=Holder(red,"Seoul",Beijing,Shanghai,Tokyo);
        cities[Shanghai]=Holder(red,"Shanghai",Beijing,HongKong,Taipei,Seoul,Tokyo);
        cities[Sydney]=Holder(red,"Sydney",Jakarta,Manila,LosAngeles);
        cities[Taipei]=Holder(red,"Taipei",Shanghai,HongKong,Osaka,Manila);
        cities[Tokyo]=Holder(red,"Tokyo",Seoul,Shanghai,Osaka,SanFrancisco);
    }

    int& Board::operator[] (City city){ //write
        return cities.at(city).level;
    }
    const int Board::operator[] (City city) const { //read
        return cities.at(city).level;
    }

    std::ostream &operator<<(std::ostream &os, const Board &board){
        string ans;
        for (int i=0; i<board.cities.size(); i++){
            Holder get = board.cities.at(static_cast<City>(i));
            ans+= "City:" + get.city_name+ ", Amount of diseases: " + to_string(get.level) + '\n';
        }
        ans+= "The cures that were discovered: \n";
        ans+= "Research station built: \n";

        return os << ans;
    }

    bool Board::is_clean(){
        for (int i=0; i<cities.size(); i++){
            if (cities[ static_cast<City>(i)].level!=0) return false;
        }
        return true;
    }

    bool Board::are_neighbors(City first, City second){
        for (auto nei:this->cities.at(first).nei){
            if (nei==second) return true;
        }
        return false;
    }
}