#ifndef FLIGHT_H
#define FLIGHT_H

#include <ostream>
#include <iostream>
#include <vector>  
//Author Sergio Avila
class Passenger;

class Flight {
private:
    std::string airport;
    int id;
    std::string time;
    std::string day;
    int maxSeats;
    std::vector<Passenger*> passengers;
public:
    Flight();
    Flight(const std::string& airport, int id, const std::string& time, const std::string& day, int maxSeats );
    ~Flight(){}

    std::string getAirport() const;
    void setAirport(const std::string& airport);

    int getId() const;
    void setId(int id);

    std::string getTime() const;
    void setTime(const std::string& time);

    std::string getDay() const;
    void setDay(const std::string& day);

    int getMaxSeats() const;
    void setMaxSeats(int maxSeats);

    std::vector<Passenger*> getPassengers() const;
    int getNumPassengers();
    bool isFull();
    void overbook();
    void cancelFlight();
    void addPassenger(Passenger* p);
    void removePassenger(Passenger* p);
    void display();

    bool operator==(const Flight *f) const{
        return (this->airport == f->airport && 
            this->id == f->id && 
            this->time == f->time &&
            this->day == f->day); //this-> will access the private members of the current object
    };
    friend std::ostream& operator<<(std::ostream &o, const Flight &f);  
};

#endif