#include "Passenger.h"

//Jason Wright
Passenger::Passenger() : name("noname"), id(0), country("nocountry") {}
Passenger::Passenger(const std::string& name, int id, const std::string& country): name(name), id(id), country(country) {}


int Passenger::getId() const 
{ 
    return id; 
}

std::string Passenger::getName() const 
{ 
    return name; 
}

std::string Passenger:: getCountry() const 
{ 
    return country; 
}

void  Passenger::setName(const std::string& name) 
{ 
    this->name = name; 
}
void Passenger::setId(int id) 
{ 
    this->id = id; 
}

void  Passenger::setCountry(const std::string& country) 
{ 
    this->country = country; 
}

std::vector<Flight*> Passenger::getFlights() const 
{ 
    return flights; 
} 


int Passenger:: getNumFlights() const{
    return flights.size();
};



 void Passenger:: display() const
{
    std::cout<< "Flights: " << std::endl;
 
    for (std::vector<Flight*>::const_iterator itP = flights.begin(); itP != flights.end(); ++itP) { //const iterator to avoid modifying the vector, function is coded const as well
        if (*itP) {
            std::cout << "Flight ID: " << (*itP)->getId()<< ", Airport: " << (*itP)->getAirport() << ", Time: " << (*itP)->getTime()<< ", Day: " << (*itP)->getDay() << std::endl;
        }
    }
}

void Passenger:: clear(){
    std::vector<Flight*> copy = flights; // shallow copy
    for (std::vector<Flight*>::iterator it = copy.begin(); it != copy.end(); ++it) {
        if (*it) {
            (*it)->removePassenger(this); // remove crrent pasenger object from all flights 
        }
    }
    flights.clear(); // this is gonna ensure that the vector is empty after removing the passed from all flights
}

void Passenger::bookFlight(Flight *f) {
    for (std::vector<Flight*>::const_iterator it = flights.begin(); it != flights.end(); ++it) {
        if (*it == f) {
            std::cerr << "Error: Passenger already on the flight." << std::endl;
            return;
        }
    }
    if(f->isFull()){
        std::cerr << "Error: Flight is full." << std::endl;
        return;
    }
    flights.push_back(f); //adds the flight to the passenger's vector of flights
    f->addPassenger(this); 
}

void Passenger::cancelFlight(Flight *f){
    for (auto it = flights.begin(); it != flights.end(); ++it) {
        if (*it == f) {
            flights.erase(it);
            return;
        }
    }
    std::cerr << " Error: Passenger not on the flight." << std::endl;
}



 std::ostream& operator<<(std::ostream &o, const Passenger &p) { 
    o << "Name: " << p.name
    << ", ID: " << p.id 
    << ", Country: " << p.country;
    return o;
}



