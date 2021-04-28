#include "Board.hpp"
using namespace std;
namespace pandemic{

    void Board::load_map() {
        load_blue();
//        load_yellow();
//        load_black();
//        load_red();
    }

    void Board::load_blue() {
        cities[Atlanta] = {blue,Chicago,Miami,Washington};
//        cities[Chicago]=Holder(blue,pandemic::City{SanFrancisco,LosAngeles,MexicoCity,Atlanta,Montreal});
//        cities[Essen]=Holder(blue,pandemic::City{London,Paris,Milan,StPetersburg});
//        cities[London]=Holder(blue,pandemic::City{NewYork,Madrid,Essen,Paris});
//        cities[Madrid]=Holder(blue,pandemic::City{London,NewYork,Paris,SaoPaulo,Algiers});
//        cities[Milan]=Holder(blue,pandemic::City{Essen,Paris,Istanbul});
//        cities[Montreal]=Holder(blue,pandemic::City{Chicago,Washington,NewYork});
//        cities[NewYork]=Holder(blue,pandemic::City{Montreal,Washington,London,Madrid});
//        cities[Paris]=Holder(blue,pandemic::City{Algiers,Essen,Madrid,Milan,London});
//        cities[SanFrancisco]=Holder(blue,pandemic::City{LosAngeles,Chicago,Tokyo,Manila});
//        cities[StPetersburg]=Holder(blue,pandemic::City{Essen,Istanbul,Moscow});
//        cities[Washington]=Holder(blue,pandemic::City{Atlanta,NewYork,Montreal,Miami});
    }
//    void Board::load_yellow() {
//        cities[Bogota]=Holder(yellow,pandemic::City{MexicoCity,Lima,Miami,SaoPaulo,BuenosAires});
//        cities[BuenosAires]=Holder(yellow,pandemic::City{Bogota,SaoPaulo});
//        cities[Johannesburg]=Holder(yellow,pandemic::City{Kinshasa,Khartoum});
//        cities[Khartoum]=Holder(yellow,pandemic::City{Lagos,Kinshasa,Johannesburg});
//        cities[Kinshasa]=Holder(yellow,pandemic::City{Lagos,Khartoum,Johannesburg});
//        cities[Lagos]=Holder(yellow,pandemic::City{SaoPaulo,Khartoum,Kinshasa});
//        cities[Lima]=Holder(yellow,pandemic::City{MexicoCity,Bogota,Santiago});
//        cities[LosAngeles]=Holder(yellow,pandemic::City{SanFrancisco,Chicago,MexicoCity,Sydney});
//        cities[MexicoCity]=Holder(yellow,pandemic::City{LosAngeles,Chicago,Miami,Lima,Bogota});
//        cities[Miami]=Holder(yellow,pandemic::City{Atlanta,MexicoCity,Washington,Bogota});
//        cities[Santiago]=Holder(yellow,pandemic::City{Lima});
//        cities[SaoPaulo]=Holder(yellow,pandemic::City{Bogota,BuenosAires,Lagos,Madrid});
//    }
//    void Board::load_black() {
//        cities[Algiers]=Holder(black,pandemic::City{Madrid,Paris,Istanbul,Cairo});
//        cities[Baghdad]=Holder(black,pandemic::City{Tehran,Istanbul,Cairo,Riyadh,Karachi});
//        cities[Cairo]=Holder(black,pandemic::City{Algiers,Istanbul,Baghdad,Khartoum,Riyadh});
//        cities[Chennai]=Holder(black,pandemic::City{Mumbai,Delhi,Kolkata,Bangkok,Jakarta});
//        cities[Delhi]=Holder(black,pandemic::City{Tehran,Karachi,Mumbai,Chennai,Kolkata});
//        cities[Istanbul]=Holder(black,pandemic::City{Milan,Algiers,StPetersburg,Cairo,Baghdad,Moscow});
//        cities[Karachi]=Holder(black,pandemic::City{Tehran,Baghdad,Riyadh,Mumbai,Delhi});
//        cities[Kolkata]=Holder(black,pandemic::City{Delhi,Chennai,Bangkok,HongKong});
//        cities[Moscow]=Holder(black,pandemic::City{StPetersburg,Istanbul,Tehran});
//        cities[Mumbai]=Holder(black,pandemic::City{Karachi,Delhi,Chennai});
//        cities[Riyadh]=Holder(black,pandemic::City{Baghdad,Cairo,Karachi});
//        cities[Tehran]=Holder(black,pandemic::City{Baghdad,Moscow,Karachi,Delhi});
//
//    }
//    void Board::load_red() {
//        cities[Bangkok]=Holder(red,pandemic::City{Kolkata,Chennai,Jakarta,HoChiMinhCity,HongKong});
//        cities[Beijing]=Holder(red,pandemic::City{Shanghai,Seoul});
//        cities[HoChiMinhCity]=Holder(red,pandemic::City{Jakarta,Bangkok,HongKong,Manila});
//        cities[HongKong]=Holder(red,pandemic::City{Bangkok,Kolkata,HoChiMinhCity,Shanghai,Manila,Taipei});
//        cities[Jakarta]=Holder(red,pandemic::City{Chennai,Bangkok,HoChiMinhCity,Sydney});
//        cities[Manila]=Holder(red,pandemic::City{Taipei,SanFrancisco,HoChiMinhCity,Sydney});
//        cities[Osaka]=Holder(red,pandemic::City{Taipei,Tokyo});
//        cities[Seoul]=Holder(red,pandemic::City{Beijing,Shanghai,Tokyo});
//        cities[Shanghai]=Holder(red,pandemic::City{Beijing,HongKong,Taipei,Seoul,Tokyo});
//        cities[Sydney]=Holder(red,pandemic::City{Jakarta,Manila,LosAngeles});
//        cities[Taipei]=Holder(red,pandemic::City{Shanghai,HongKong,Osaka,Manila});
//        cities[Tokyo]=Holder(red,pandemic::City{Seoul,Shanghai,Osaka,SanFrancisco});
//    }
//
//    int& Board::operator[] (City city){ //write
//        return this->cities[city].get_level();
//    }
//    int Board::operator[] (City city) const{ //read
//        return this->cities[city].get_level();
//    }
//    bool Board::is_clean(){return this->num_of_diseases==0;}
}