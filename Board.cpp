#include "Board.hpp"
using namespace std;
namespace pandemic{
    unorderd_map <pandemic::City,pandemic::Color> Board::cities_and_colors = unorderd_map <pandemic::City,pandemic::Color>;
    unordered_map<pandemic::City,vector<pandemic::City>> Board::cities_neighbors = unordered_map<pandemic::City, vector<pandemic::City>>;


    void Board::load_map() {
        load_blue();
        load_yellow();
        load_black();
        load_red();
    }

    void Board::load_blue() {
        cities_and_colors[City::Atlanta]=Color::blue;
        cities_neighbors[atlanta]=pandemic::City{Chicago,Miami,Washington};
        cities_and_colors[City::Chicago]=Color::blue;
        cities_neighbors[Chicago]=pandemic::City{SanFrancisco,LosAngeles,MexicoCity,Atlanta,Montreal};
        cities_and_colors[City::Essen]=Color::blue;
        cities_neighbors[Essen]=pandemic::City{London,Paris,Milan,StPetersburg};
        cities_and_colors[City::London]=Color::blue;
        cities_neighbors[London]=pandemic::City{NewYork,Madrid,Essen,Paris};
        cities_and_colors[City::Madrid]=Color::blue;
        cities_neighbors[Madrid]=pandemic::City{London,NewYork,Paris,SaoPaulo,Algiers};
        cities_and_colors[City::Milan]=Color::blue;
        cities_neighbors[Milan]=pandemic::City{Essen,Paris,Istanbul};
        cities_and_colors[City::Montreal]=Color::blue;
        cities_neighbors[Montreal]=pandemic::City{Chicago,Washington,NewYork};
        cities_and_colors[City::NewYork]=Color::blue;
        cities_neighbors[NewYork]=pandemic::City{Montreal,Washington,London,Madrid};
        cities_and_colors[City::Paris]=Color::blue;
        cities_neighbors[Paris]=pandemic::City{Algiers,Essen,Madrid,Milan,London};
        cities_and_colors[City::SanFrancisco]=Color::blue;
        cities_neighbors[SanFrancisco]=pandemic::City{LosAngeles,Chicago,Tokyo,Manila};
        cities_and_colors[City::StPetersburg]=Color::blue;
        cities_neighbors[StPetersburg]=pandemic::City{Essen,Istanbul,Moscow};
        cities_and_colors[City::Washington]=Color::blue;
        cities_neighbors[Washington]=pandemic::City{Atlanta,NewYork,Montreal,Miami};
    }

    void Board::load_yellow() {
        cities_and_colors[City::Bogota]=Color::yellow;
        cities_neighbors[Bogota]=pandemic::City{MexicoCity,Lima,Miami,SaoPaulo,BuenosAires};
        cities_and_colors[City::BuenosAires]=Color::yellow;
        cities_neighbors[BuenosAires]=pandemic::City{Bogota,SaoPaulo};
        cities_and_colors[City::Johannesburg]=Color::yellow;
        cities_neighbors[Johannesburg]=pandemic::City{Kinshasa,Khartoum};
        cities_and_colors[City::Khartoum]=Color::yellow;
        cities_neighbors[Khartoum]=pandemic::City{Lagos,Kinshasa,Johannesburg};
        cities_and_colors[City::Kinshasa]=Color::yellow;
        cities_neighbors[Kinshasa]=pandemic::City{Lagos,Khartoum,Johannesburg};
        cities_and_colors[City::Lagos]=Color::yellow;
        cities_neighbors[Lagos]=pandemic::City{SaoPaulo,Khartoum,Kinshasa};
        cities_and_colors[City::Lima]=Color::yellow;
        cities_neighbors[Lima]=pandemic::City{MexicoCity,Bogota,Santiago};
        cities_and_colors[City::LosAngeles]=Color::yellow;
        cities_neighbors[LosAngeles]=pandemic::City{SanFrancisco,Chicago,MexicoCity,Sydney};
        cities_and_colors[City::MexicoCity]=Color::yellow;
        cities_neighbors[MexicoCity]=pandemic::City{LosAngeles,Chicago,Miami,Lima,Bogota};
        cities_and_colors[City::Miami]=Color::yellow;
        cities_neighbors[Miami]=pandemic::City{Atlanta,MexicoCity,Washington,Bogota};
        cities_and_colors[City::Santiago]=Color::yellow;
        cities_neighbors[Santiago]=pandemic::City{Lima};
        cities_and_colors[City::SaoPaulo]=Color::yellow;
        cities_neighbors[SaoPaulo]=pandemic::City{Bogota,BuenosAires,Lagos,Madrid};
    }

    void Board::load_black() {
        cities_and_colors[City::Algiers]=Color::black;
        cities_neighbors[Algiers]=pandemic::City{Madrid,Paris,Istanbul,Cairo};
        cities_and_colors[City::Baghdad]=Color::black;
        cities_neighbors[Baghdad]=pandemic::City{Tehran,Istanbul,Cairo,Riyadh,Karachi};
        cities_and_colors[City::Cairo]=Color::black;
        cities_neighbors[Cairo]=pandemic::City{Algiers,Istanbul,Baghdad,Khartoum,Riyadh};
        cities_and_colors[City::Chennai]=Color::black;
        cities_neighbors[Chennai]=pandemic::City{Mumbai,Delhi,Kolkata,Bangkok,Jakarta};
        cities_and_colors[City::Delhi]=Color::black;
        cities_neighbors[Delhi]=pandemic::City{Tehran,Karachi,Mumbai,Chennai,Kolkata};
        cities_and_colors[City::Istanbul]=Color::black;
        cities_neighbors[Istanbul]=pandemic::City{Milan,Algiers,StPetersburg,Cairo,Baghdad,Moscow};
        cities_and_colors[City::Karachi]=Color::black;
        cities_neighbors[Karachi]=pandemic::City{Tehran,Baghdad,Riyadh,Mumbai,Delhi};
        cities_and_colors[City::Kolkata]=Color::black;
        cities_neighbors[Kolkata]=pandemic::City{Delhi,Chennai,Bangkok,HongKong};
        cities_and_colors[City::Moscow]=Color::black;
        cities_neighbors[Moscow]=pandemic::City{StPetersburg,Istanbul,Tehran};
        cities_and_colors[City::Mumbai]=Color::black;
        cities_neighbors[Mumbai]=pandemic::City{Karachi,Delhi,Chennai};
        cities_and_colors[City::Riyadh]=Color::black;
        cities_neighbors[Riyadh]=pandemic::City{Baghdad,Cairo,Karachi};
        cities_and_colors[City::Tehran]=Color::black;
        cities_neighbors[Tehran]=pandemic::City{Baghdad,Moscow,Karachi,Delhi};
    }

    void Board::load_red() {
        cities_and_colors[City::Bangkok]=Color::red;
        cities_neighbors[Bangkok]=pandemic::City{Kolkata,Chennai,Jakarta,HoChiMinhCity,HongKong};
        cities_and_colors[City::Beijing]=Color::red;
        cities_neighbors[Beijing]=pandemic::City{Shanghai,Seoul};
        cities_and_colors[City::HoChiMinhCity]=Color::red;
        cities_neighbors[HoChiMinhCity]=pandemic::City{Jakarta,Bangkok,HongKong,Manila};
        cities_and_colors[City::HongKong]=Color::red;
        cities_neighbors[HongKong]=pandemic::City{Bangkok,Kolkata,HoChiMinhCity,Shanghai,Manila,Taipei};
        cities_and_colors[City::Jakarta]=Color::red;
        cities_neighbors[Jakarta]=pandemic::City{Chennai,Bangkok,HoChiMinhCity,Sydney};
        cities_and_colors[City::Manila]=Color::red;
        cities_neighbors[Manila]=pandemic::City{Taipei,SanFrancisco,HoChiMinhCity,Sydney};
        cities_and_colors[City::Osaka]=Color::red;
        cities_neighbors[Osaka]=pandemic::City{Taipei,Tokyo};
        cities_and_colors[City::Seoul]=Color::red;
        cities_neighbors[Seoul]=pandemic::City{Beijing,Shanghai,Tokyo};
        cities_and_colors[City::Shanghai]=Color::red;
        cities_neighbors[Shanghai]=pandemic::City{Beijing,HongKong,Taipei,Seoul,Tokyo};
        cities_and_colors[City::Sydney]=Color::red;
        cities_neighbors[Sydney]=pandemic::City{Jakarta,Manila,LosAngeles};
        cities_and_colors[City::Taipei]=Color::red;
        cities_neighbors[Taipei]=pandemic::City{Shanghai,HongKong,Osaka,Manila};
        cities_and_colors[City::Tokyo]=Color::red;
        cities_neighbors[Tokyo]=pandemic::City{Seoul,Shanghai,Osaka,SanFrancisco};
    }

    Board& Board::operator[] (City city){return *this;}

}