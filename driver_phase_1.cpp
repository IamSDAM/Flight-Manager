#include <iostream>
#include <fstream>
#include <sstream>


#include "Employee.h"
#include "Passenger.h"
#include "Flight.h"

//testing done by Jason Wright
int main() 
{   
    std::cout << std::endl;
    
    // instantiate A container
    // instantiate B container
    std::vector<Flight*> flights;
    std::vector<Passenger*> passengers;


    // instantiate A container iterator
    // instantiate B container iterator
    std::vector<Flight*>::iterator itF;
    for (itF = flights.begin(); itF != flights.end(); ++itF) 
    {
        std::cout << *itF << "\n";  
    }


    std::vector<Passenger*>::iterator itP;
    for (itP = passengers.begin(); itP != passengers.end(); ++itP) 
    {
    std::cout << *itP << "\n"; //dereference the iterator to output the Passenger object
    }

    passengers.push_back(new Passenger("Ewan McGregor", 0, "England"));
    passengers.push_back(new Passenger("Natalie Portman", 1, "USA"));       
    std::cout << "PASSENGER INFO: " <<  passengers[0]->getName() << ",  ID: " << passengers[0]->getId() << ",  Country: " << passengers[0]->getCountry() << std::endl;
    passengers[0]->setName("Ronald McDonald"); passengers[0]->setId(5); passengers[0]->setCountry("Egypt");
    std::cout << "NEW PASSENGER INFO: " <<  passengers[0]->getName() << ",  ID: " << passengers[0]->getId() << ",  Country: " << passengers[0]->getCountry() << "\n" << std::endl;
    
    passengers[0]->getFlights();


    flights.push_back(new Flight("JFK", 90210, "10:00", "Monday", 6));
    std::cout << "FLIGHT INFO: " <<  flights[0]->getAirport() << ",  ID: " << flights[0]->getId() << ",  Time: " << flights[0]->getTime() << ",  Day: " << flights[0]->getDay() << ",  Max Seats: " << flights[0]->getMaxSeats() << std::endl;    
    flights[0]->setAirport("LAX"); flights[0]->setId(12345); flights[0]->setTime("12:00"); flights[0]->setDay("Tuesday"); flights[0]->setMaxSeats(10);
    std::cout << "NEW FLIGHT INFO: " <<  flights[0]->getAirport() << ",  ID: " << flights[0]->getId() << ",  Time: " << flights[0]->getTime() << ",  Day: " << flights[0]->getDay() << ",  Max Seats: " << flights[0]->getMaxSeats() << "\n" << std::endl;    
    flights[0]->getPassengers();



    // read into A container
    // read into B container

    // test all functions for types A and B

    // delete all dynamic memory

    std::cout << std::endl;


    // Delete all dynamically allocated memory for flights
    for (itF = flights.begin(); itF != flights.end(); ++itF){
        delete *itF;
    }
    passengers.clear();

    // Delete all dynamically allocated memory for passengers
    for (itP = passengers.begin(); itP != passengers.end(); ++itP) {
        delete *itP;
    }
    flights.clear();

    
    return 0;
}