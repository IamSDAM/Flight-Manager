#include "Flight.h"
#include "Passenger.h"
//Author Sergio Avila
Flight::Flight() : airport("noAirport"), id(0), time("00:00"), day("noDay"), maxSeats(0){}
Flight::Flight(const std::string& airport, int id, const std::string& time, const std::string& day, int maxSeats): airport(airport), id(id), time(time), day(day), maxSeats(maxSeats) {}


std::string Flight::getAirport()const{
    return airport;
}
void Flight::setAirport(const std::string& airport){
    this->airport = airport;
}

int Flight::getId()const{
    return id;
}
void Flight::setId(int id){
    this->id = id;
}

std::string Flight::getTime()const{
    return time;
}
void Flight::setTime(const std::string& time){
    this->time = time;
}

std::string Flight::getDay()const{
    return day;
}
void Flight::setDay(const std::string& day){
    this->day = day;
}

int Flight::getMaxSeats() const{ 
    return maxSeats; 
}
void Flight::setMaxSeats(int maxSeats){ 
    this->maxSeats = maxSeats; 
}

std::vector<Passenger*> Flight::getPassengers() const{ 
    return passengers; 
}


int Flight::getNumPassengers() { 
    return passengers.size();
}

bool Flight::isFull() { 
    return passengers.size() >= maxSeats;
}

void Flight::overbook() { 
    this->maxSeats+=1;
}

void Flight::cancelFlight() { 
    for(int i = 0; i<passengers.size();i++){
        Passenger* p = passengers[i];
        p->cancelFlight(this);
    }
    passengers.clear();
}

void Flight::addPassenger(Passenger* p) { 
    if(maxSeats > passengers.size()){
        bool schedule = false;

        for(int i=0; i < passengers.size(); i++){
            if(passengers[i] == p){
                schedule = true;
                break;
            }
        }
    if(schedule == false){
        passengers.push_back(p);
    }
        
    }
}

void Flight::removePassenger(Passenger* p) { 
    for(int i=0; i < passengers.size(); i++){
        if(passengers[i] == p){
            passengers.erase(passengers.begin() + i); //https://cplusplus.com/reference/vector/vector/erase/         
            p->cancelFlight(this);
            break;                                    // u guys can use the link to check what this basically does
        }//check that cancel flight doesnt ping pong test both functions, and also cancelFlight() should check if flight is deleted  
    }
}

void Flight::display() { 
    for (int i = 0; i < passengers.size(); i++) {
        std::cout << "*" << *(passengers[i]) << std::endl;
    }
}

std::ostream& operator<<(std::ostream& o, const Flight& f){
    o << "\nFlight ID: " << f.id 
      << ", Airport: " << f.airport
      << ", Time: " << f.time 
      << ", Day: " << f.day
      << ", Max Seats: " << f.maxSeats
      << ", Current Passengers: " << f.passengers.size();
    return o;
}