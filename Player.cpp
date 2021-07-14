#include "Player.hpp"

using namespace std;
using namespace pandemic;

Player& Player:: drive(City c){
    if(board.isConnected(city, c)){city=c;}
    else{throw std::invalid_argument{"the city "+ cityToString(city)+" is not connected to the city "+cityToString(c)};}
    return *this;
}

Player& Player:: fly_direct(City c){
    if(cards.count(c)){
        city=c;
        cards.erase(c);
    }
    else{throw std::invalid_argument{"you don't have the card of the city "+cityToString(c)};}
    return *this;
}
Player& Player::fly_charter(City c){
    if(cards.count(city)){
        cards.erase(city);
        city=c;
    }
    else{throw std::invalid_argument{"you don't have the card of the city "+cityToString(city)};}
    return *this;
}
Player& Player::fly_shuttle(City c){
    if(board.isResearchStation(city) && board.isResearchStation(c)){city=c;}
    else{throw std::invalid_argument{"the city " + cityToString(city) + " and " + cityToString(c) + " must have research station."};}
    return *this;
}
Player& Player::build(){
    if(!cards.count(city)){throw std::invalid_argument{"you don't have the card of the city "+cityToString(city)};}
    if(!board.isResearchStation(city)){
        board.buildStation(city);
        cards.erase(city);
    }
    return *this;
}
Player& Player:: discover_cure(Color c){
    return *this;
}
Player& Player:: treat(City c){
    if(city != c){ throw std::invalid_argument{"you are not in the city " + cityToString(c)};}
    else if(board[c] == 0){  throw std::invalid_argument{"no cubes left in the city " + cityToString(c)};}
    else if(board.cureDiscoverd(c)){board[c]=0;}
    else{
        board[c]--;
    }
    return *this;
}

Player& Player::take_card(City c){
    cards.insert(c);
    return *this;
}
