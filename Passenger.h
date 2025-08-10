#ifndef PASSENGER_H
#define PASSENGER_H

#include <ostream>
#include <vector>
#include <iostream>
#include "Flight.h"
//Jason Wright
class Flight;

class Passenger {
private:
    std::string name; 
    int id;
    std::string country;
    std::vector<Flight*> flights; 

public:
    Passenger();
    Passenger(const std::string& name, int id, const std::string& country); 
    ~Passenger(){}
    
    int getId() const;
    std::string getName() const;
    std::string getCountry() const;

    void setName(const std::string& name);
    void setId(int id);
    void setCountry(const std::string& country);

    void display() const; 
    std::vector<Flight*> getFlights() const;
    int getNumFlights() const;
    void clear();
    void bookFlight(Flight *f);
    void cancelFlight(Flight *f); 
    
    bool operator==(const Passenger *p) const{
        return (this->id == p->id && 
            this->name == p->name && 
            this->country == p->country); //this-> will access the private members of the current object
    };
    friend std::ostream& operator<<(std::ostream &o, const Passenger &p);    

};






#endif