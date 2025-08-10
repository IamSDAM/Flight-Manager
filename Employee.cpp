#include "Employee.h"
#include "Passenger.h"



void Employee::addFlight(std::vector<Flight*>& flights, const std::string& airport, int id, const std::string& time, const std::string& day, int maxSeats){
    Flight* newFlight = new Flight();
    newFlight->setAirport(airport);
    newFlight->setId(id);
    newFlight->setTime(time);
    newFlight->setDay(day);
    newFlight->setMaxSeats(maxSeats);

    flights.push_back(newFlight);
}


bool Employee::cancelFlight(std::vector<Flight*>& flights, Flight* f){
    std::vector<Passenger*> passengers = f->getPassengers();

    for (std::vector<Passenger*>::iterator it = passengers.begin(); it != passengers.end(); ++it) {
        (*it)->cancelFlight(f); 
    }

    // Find and remove the flight from the flights container
    for (std::vector<Flight*>::iterator it = flights.begin(); it != flights.end(); ++it) {
        if (*it == f) {
            flights.erase(it);    
            delete f;             
            return true;          
        }
        std::cout << "Flight has been cancelled." << std::endl;
    }

    return false; 
}



std::vector<Flight*>::iterator Employee::findFlight(std::vector<Flight*>& flights, int flightsId){
    for (std::vector<Flight*>::iterator it = flights.begin(); it != flights.end(); ++it) {
        if ((*it)->getId() == flightsId) {
            return it; 
        }
    }
    return flights.end(); 
}



