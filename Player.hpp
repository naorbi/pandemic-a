#pragma once
#include "Board.hpp"
#include "City.hpp"
#include <set>

namespace pandemic{
    class Player{
       
        protected:
            Board& board;
            City city;
            std :: set<City> cards;
            std:: string playerRole;

        public:
            Player(Board& b, City c): board(b), city(c){}
            Player& drive(City c);
            virtual Player& fly_direct(City c);
            Player& fly_charter(City c);
            Player& fly_shuttle(City c);
            virtual Player& build();
            virtual Player& discover_cure(Color c);
            virtual Player& treat(City c);
            std::string role(){return playerRole;}
            Player& take_card(City c);
    };
}
