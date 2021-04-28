#include "Board.hpp"
using namespace std;
namespace pandemic{

    void Board::load_map() {
        load_blue();
        load_yellow();
        load_black();
        load_red();
    }


    void Board::load_blue() {
        cities[Atlanta] =Holder (blue,Chicago,Miami,Washington);
        cities[Chicago]=Holder(blue,SanFrancisco,LosAngeles,MexicoCity,Atlanta,Montreal);
        cities[Essen]=Holder(blue,London,Paris,Milan,StPetersburg);
        cities[London]=Holder(blue,NewYork,Madrid,Essen,Paris);
        cities[Madrid]=Holder(blue,London,NewYork,Paris,SaoPaulo,Algiers);
        cities[Milan]=Holder(blue,Essen,Paris,Istanbul);
        cities[Montreal]=Holder(blue,Chicago,Washington,NewYork);
        cities[NewYork]=Holder(blue,Montreal,Washington,London,Madrid);
        cities[Paris]=Holder(blue,Algiers,Essen,Madrid,Milan,London);
        cities[SanFrancisco]=Holder(blue,LosAngeles,Chicago,Tokyo,Manila);
        cities[StPetersburg]=Holder(blue,Essen,Istanbul,Moscow);
        cities[Washington]=Holder(blue,Atlanta,NewYork,Montreal,Miami);
    }
    void Board::load_yellow() {
        cities[Bogota]=Holder(yellow,MexicoCity,Lima,Miami,SaoPaulo,BuenosAires);
        cities[BuenosAires]=Holder(yellow,Bogota,SaoPaulo);
        cities[Johannesburg]=Holder(yellow,Kinshasa,Khartoum);
        cities[Khartoum]=Holder(yellow,Lagos,Kinshasa,Johannesburg);
        cities[Kinshasa]=Holder(yellow,Lagos,Khartoum,Johannesburg);
        cities[Lagos]=Holder(yellow,SaoPaulo,Khartoum,Kinshasa);
        cities[Lima]=Holder(yellow,MexicoCity,Bogota,Santiago);
        cities[LosAngeles]=Holder(yellow,SanFrancisco,Chicago,MexicoCity,Sydney);
        cities[MexicoCity]=Holder(yellow,LosAngeles,Chicago,Miami,Lima,Bogota);
        cities[Miami]=Holder(yellow,Atlanta,MexicoCity,Washington,Bogota);
        cities[Santiago]=Holder(yellow,Lima);
        cities[SaoPaulo]=Holder(yellow,Bogota,BuenosAires,Lagos,Madrid);
    }
    void Board::load_black() {
        cities[Algiers]=Holder(black,Madrid,Paris,Istanbul,Cairo);
        cities[Baghdad]=Holder(black,Tehran,Istanbul,Cairo,Riyadh,Karachi);
        cities[Cairo]=Holder(black,Algiers,Istanbul,Baghdad,Khartoum,Riyadh);
        cities[Chennai]=Holder(black,Mumbai,Delhi,Kolkata,Bangkok,Jakarta);
        cities[Delhi]=Holder(black,Tehran,Karachi,Mumbai,Chennai,Kolkata);
        cities[Istanbul]=Holder(black,Milan,Algiers,StPetersburg,Cairo,Baghdad,Moscow);
        cities[Karachi]=Holder(black,Tehran,Baghdad,Riyadh,Mumbai,Delhi);
        cities[Kolkata]=Holder(black,Delhi,Chennai,Bangkok,HongKong);
        cities[Moscow]=Holder(black,StPetersburg,Istanbul,Tehran);
        cities[Mumbai]=Holder(black,Karachi,Delhi,Chennai);
        cities[Riyadh]=Holder(black,Baghdad,Cairo,Karachi);
        cities[Tehran]=Holder(black,Baghdad,Moscow,Karachi,Delhi);
    }
    void Board::load_red() {
        cities[Bangkok]=Holder(red,Kolkata,Chennai,Jakarta,HoChiMinhCity,HongKong);
        cities[Beijing]=Holder(red,Shanghai,Seoul);
        cities[HoChiMinhCity]=Holder(red,Jakarta,Bangkok,HongKong,Manila);
        cities[HongKong]=Holder(red,Bangkok,Kolkata,HoChiMinhCity,Shanghai,Manila,Taipei);
        cities[Jakarta]=Holder(red,Chennai,Bangkok,HoChiMinhCity,Sydney);
        cities[Manila]=Holder(red,Taipei,SanFrancisco,HoChiMinhCity,Sydney);
        cities[Osaka]=Holder(red,Taipei,Tokyo);
        cities[Seoul]=Holder(red,Beijing,Shanghai,Tokyo);
        cities[Shanghai]=Holder(red,Beijing,HongKong,Taipei,Seoul,Tokyo);
        cities[Sydney]=Holder(red,Jakarta,Manila,LosAngeles);
        cities[Taipei]=Holder(red,Shanghai,HongKong,Osaka,Manila);
        cities[Tokyo]=Holder(red,Seoul,Shanghai,Osaka,SanFrancisco);
    }
//
//    int& Board::operator[] (City city){ //write
//        return this->cities[city].get_level();
//    }
//    int Board::operator[] (City city) const{ //read
//        return this->cities[city].get_level();
//    }
//    bool Board::is_clean(){return this->num_of_diseases==0;}
}