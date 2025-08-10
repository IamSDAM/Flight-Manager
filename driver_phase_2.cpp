#include <iostream>


#include "Employee.h"
#include "Passenger.h"
#include "Flight.h"

#include "Files.h"

int main() 
{   
    std::cout << std::endl;

    // instantiate A container
    std::vector<Passenger*> passengers;
    
    // instantiate B container
    std::vector<Flight*> flights;

    // instantiate A container iterator
    std::vector<Passenger*>::iterator itPasse;

    // instantiate B container iterator
    std::vector<Flight*>::iterator itFlight;
    
    // read into A container
    readPassenger(passengers);

    // read into B container
    readFlight(flights);

    // test all functions for types A, B and C using the A and B containers
    //Type A
    Passenger* p1 = new Passenger("Elver Gomez", 66, "Mexico");
    passengers.push_back(p1);
    p1->setName("Jessica Monge");
    p1->setId(101);
    p1->setCountry("Colombia");

    //Type B
    Flight* f1 = new Flight("JFK", 1111, "15:15", "Monday", 2);
    flights.push_back(f1);
    f1->setAirport("ElDorado");
    f1->setId(1);
    f1->setTime("01:01");
    f1->setDay("Saturday");
    f1->setMaxSeats(1);
    p1->bookFlight(f1);
    std::cout << "Passenger: " << *p1 << std::endl;
    std::cout << "Flights for this passenger:\n";
    p1->display();
    std::cout << "Number of flights: " << p1->getNumFlights() << std::endl;

    std::cout << "Flight info:\n" << *f1 << std::endl;
    if (f1->isFull()) {
        std::cout << "Flight is full: Yes\n";
    } else {
        std::cout << "Flight is full: No\n";
    }
    f1->overbook();
    std::cout << "New max seats after overbooking: " << f1->getMaxSeats() << std::endl;
    std::cout << "Current passengers:\n";
    f1->display();
    f1->removePassenger(p1);
    std::cout << "After removing passenger:\n";
    f1->display();

    p1->clear();

//Type C
    Employee::addFlight(flights, "MARTE", 999, "18:00", "Sunday", 5);
    std::cout << "Flights after adding one:\n";
    for (itFlight = flights.begin(); itFlight != flights.end(); ++itFlight) {
        std::cout << **itFlight << std::endl;
    }

    // Find the new flight
    itFlight = Employee::findFlight(flights, 999);
    if (itFlight != flights.end()) {
        std::cout << "Found flight: " << **itFlight << std::endl;
    }

    // Cancel the new flight
    if (itFlight != flights.end()) {
        bool cancelled = Employee::cancelFlight(flights, *itFlight);
        if (cancelled) {
            std::cout << "Flight cancelled successfully.\n";
        } else {
            std::cout << "Flight cancel failed.\n";
        }
    }

    std::cout << "All passengers loaded from file:\n";
    for (const auto& p : passengers) {
    std::cout << *p << std::endl;
    }

    std::cout << "All flights loaded from file:\n";
    for (const auto& f : flights) {
    std::cout << *f << std::endl;
    }


    // delete all dynamic memory
    for (itPasse = passengers.begin(); itPasse != passengers.end(); ++itPasse) {
    delete *itPasse;
    }
    passengers.clear();

    for (itFlight = flights.begin(); itFlight != flights.end(); ++itFlight) {
        delete *itFlight;
    }
    flights.clear();



    std::cout << std::endl;
    return 0;
}