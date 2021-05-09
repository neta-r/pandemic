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
        cities[Atlanta] =Holder (Blue,"Atlanta",size_t(Atlanta), Chicago,Miami,Washington);
        cities[Chicago]=Holder(Blue,"Chicago",size_t(Chicago), SanFrancisco,LosAngeles,MexicoCity,Atlanta,Montreal);
        cities[Essen]=Holder(Blue,"Essen" ,size_t(Essen),London,Paris,Milan,StPetersburg);
        cities[London]=Holder(Blue,"London",size_t(London), NewYork,Madrid,Essen,Paris);
        cities[Madrid]=Holder(Blue,"Madrid",size_t(Madrid),London,NewYork,Paris,SaoPaulo,Algiers);
        cities[Milan]=Holder(Blue,"Milan",size_t(Milan), Essen,Paris,Istanbul);
        cities[Montreal]=Holder(Blue,"Montreal",size_t(Montreal),Chicago,Washington,NewYork);
        cities[NewYork]=Holder(Blue,"NewYork",size_t(NewYork), Montreal,Washington,London,Madrid);
        cities[Paris]=Holder(Blue,"Paris",size_t(Paris),Algiers,Essen,Madrid,Milan,London);
        cities[SanFrancisco]=Holder(Blue,"SanFrancisco",size_t(SanFrancisco),LosAngeles,Chicago,Tokyo,Manila);
        cities[StPetersburg]=Holder(Blue,"StPetersburg",size_t(StPetersburg),Essen,Istanbul,Moscow);
        cities[Washington]=Holder(Blue,"Washington",size_t(Washington),Atlanta,NewYork,Montreal,Miami);
    }
    void Board::load_yellow() {
        cities[Bogota]=Holder(Yellow,"Bogota",size_t(Bogota),MexicoCity,Lima,Miami,SaoPaulo,BuenosAires);
        cities[BuenosAires]=Holder(Yellow,"BuenosAires",size_t(BuenosAires),Bogota,SaoPaulo);
        cities[Johannesburg]=Holder(Yellow,"Johannesburg",size_t(Johannesburg),Kinshasa,Khartoum);
        cities[Khartoum]=Holder(Yellow,"Khartoum",size_t(Khartoum),Lagos,Kinshasa,Johannesburg);
        cities[Kinshasa]=Holder(Yellow,"Kinshasa",size_t(Kinshasa),Lagos,Khartoum,Johannesburg);
        cities[Lagos]=Holder(Yellow,"Lagos",size_t(Lagos),SaoPaulo,Khartoum,Kinshasa);
        cities[Lima]=Holder(Yellow,"Lima",size_t(Lima),MexicoCity,Bogota,Santiago);
        cities[LosAngeles]=Holder(Yellow,"LosAngeles",size_t(LosAngeles),SanFrancisco,Chicago,MexicoCity,Sydney);
        cities[MexicoCity]=Holder(Yellow,"MexicoCity",size_t(MexicoCity),LosAngeles,Chicago,Miami,Lima,Bogota);
        cities[Miami]=Holder(Yellow,"Miami",size_t(Miami),Atlanta,MexicoCity,Washington,Bogota);
        cities[Santiago]=Holder(Yellow,"Santiago",size_t(Santiago),Lima);
        cities[SaoPaulo]=Holder(Yellow,"SaoPaulo",size_t(SaoPaulo),Bogota,BuenosAires,Lagos,Madrid);
    }
    void Board::load_black() {
        cities[Algiers]=Holder(Black,"Algiers",size_t(Algiers),Madrid,Paris,Istanbul,Cairo);
        cities[Baghdad]=Holder(Black,"Baghdad",size_t(Baghdad),Tehran,Istanbul,Cairo,Riyadh,Karachi);
        cities[Cairo]=Holder(Black,"Cairo",size_t(Cairo),Algiers,Istanbul,Baghdad,Khartoum,Riyadh);
        cities[Chennai]=Holder(Black,"Chennai",size_t(Chennai),Mumbai,Delhi,Kolkata,Bangkok,Jakarta);
        cities[Delhi]=Holder(Black,"Delhi",size_t(Delhi),Tehran,Karachi,Mumbai,Chennai,Kolkata);
        cities[Istanbul]=Holder(Black,"Istanbul",size_t(Istanbul),Milan,Algiers,StPetersburg,Cairo,Baghdad,Moscow);
        cities[Karachi]=Holder(Black,"Karachi",size_t(Karachi),Tehran,Baghdad,Riyadh,Mumbai,Delhi);
        cities[Kolkata]=Holder(Black,"Kolkata",size_t(Kolkata),Delhi,Chennai,Bangkok,HongKong);
        cities[Moscow]=Holder(Black,"Moscow",size_t(Moscow),StPetersburg,Istanbul,Tehran);
        cities[Mumbai]=Holder(Black,"Mumbai",size_t(Mumbai),Karachi,Delhi,Chennai);
        cities[Riyadh]=Holder(Black,"Riyadh",size_t(Riyadh),Baghdad,Cairo,Karachi);
        cities[Tehran]=Holder(Black,"Tehran",size_t(Tehran),Baghdad,Moscow,Karachi,Delhi);
    }
    void Board::load_red() {
        cities[Bangkok]=Holder(Red,"Bangkok",size_t(Bangkok),Kolkata,Chennai,Jakarta,HoChiMinhCity,HongKong);
        cities[Beijing]=Holder(Red,"Beijing",size_t(Beijing),Shanghai,Seoul);
        cities[HoChiMinhCity]=Holder(Red,"HoChiMinhCity",size_t(HoChiMinhCity),Jakarta,Bangkok,HongKong,Manila);
        cities[HongKong]=Holder(Red,"HongKong",size_t(HongKong),Bangkok,Kolkata,HoChiMinhCity,Shanghai,Manila,Taipei);
        cities[Jakarta]=Holder(Red,"Jakarta",size_t(Jakarta),Chennai,Bangkok,HoChiMinhCity,Sydney);
        cities[Manila]=Holder(Red,"Manila",size_t(Manila),Taipei,SanFrancisco,HoChiMinhCity,Sydney,HongKong);
        cities[Osaka]=Holder(Red,"Osaka",size_t(Osaka),Taipei,Tokyo);
        cities[Seoul]=Holder(Red,"Seoul",size_t(Seoul),Beijing,Shanghai,Tokyo);
        cities[Shanghai]=Holder(Red,"Shanghai",size_t(Shanghai),Beijing,HongKong,Taipei,Seoul,Tokyo);
        cities[Sydney]=Holder(Red,"Sydney",size_t(Sydney),Jakarta,Manila,LosAngeles);
        cities[Taipei]=Holder(Red,"Taipei",size_t(Taipei),Shanghai,HongKong,Osaka,Manila);
        cities[Tokyo]=Holder(Red,"Tokyo",size_t(Tokyo),Seoul,Shanghai,Osaka,SanFrancisco);
    }

    string Board::get_city_name (City city){
        return cities.at(city).city_name;
    }

    size_t Board::get_city_num(City city) {
        return cities.at(city).city_num;
    }

    Color Board::get_city_color (City city){
        return cities.at(city).c;
    }

    int Board::get_city_level (City city){
        return cities.at(city).level;
    }

    void Board::reduce_city_level_by_one(City city) {
        cities.at(city).level--;
    }

    void Board::reduce_city_level_by_all(City city) {
        cities.at(city).level=0;
    }

    bool Board::is_there_research_station(City city){
        return cities[city].research_station;
    }

    void Board::build(City city){
        cities.at(city).research_station=true;
        stations++;
    }

    int& Board::operator[] (City city){ //write
        return cities.at(city).level;
    }
    int Board::operator[] (City city) const { //read
        return cities.at(city).level;
    }

    std::ostream &operator<<(std::ostream &os, const Board &board){
        string ans;
        for (int i=0; i<board.cities.size(); i++){
            Holder get = board.cities.at(static_cast<City>(i));
            ans+= "City:" + get.city_name+ ", Amount of diseases: " + to_string(get.level) + '\n';
        }
        if (board.blue_cure){
            ans+="blue cure has been discovered!\n";
        }
        if (board.yellow_cure){
            ans+="yellow cure has been discovered!\n";
        }
        if (board.black_cure){
            ans+="black cure has been discovered!\n";
        }
        if (board.red_cure){
            ans+="red cure has been discovered!\n";
        }
        ans+= "Research station built: "+to_string(board.stations)+"\n";

        return os << ans;
    }

    bool Board::is_clean(){
        for (int i=0; i<cities.size(); i++){
            if (cities[ static_cast<City>(i)].level!=0){
                return false;
            }
        }
        return true;
    }

    bool Board::are_neighbors(City first, City second){
        if (first==second) {
            return true;
        }
        for (auto nei:this->cities.at(first).nei){
            if (nei==second) {
                return true;
            }
        }
        return false;
    }

    void Board::remove_cures(){
        blue_cure=yellow_cure=black_cure=red_cure= false;
    }
}