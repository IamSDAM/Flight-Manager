#include "PassengerUI.h"


void PassengerUI::menu(std::vector<Flight*>& flights, std::vector<Passenger*>& passengers) const {
    std::vector<Passenger*>::iterator itPassenger = selectPassenger(passengers);

    if (itPassenger == passengers.end()) {
        std::cout << "No passengers available.\n";
        return;
    }
    int option = 0;
    do {   
        std::cout << "\n1) Display all flights\n";
        std::cout << "2) Book a flight\n";
        std::cout << "3) Cancel a flight\n";
        std::cout << "4) Display booked flights\n";
        std::cout << "5) Switch passenger\n";
        std::cout << "6) Exit\n";
        std::cout << "Select: ";
        std::cin >> option;
        switch(option) { 
            case 1:
                display(flights);
                break;
            case 2: {
                std::vector<Flight*>::iterator itFlight = selectFlight(flights);
                if (itFlight != flights.end()) {
                    bookFlight(itPassenger, flights, itFlight);
                }
                break;
            }
            case 3: {
                std::vector<Flight*>::iterator itFlight = selectFlight(flights);
                if (itFlight != flights.end()) {
                    cancelFlight(itPassenger, itFlight);
                }
                break;
            }
            case 4:
                (*itPassenger)->display();
                break;
            case 5:
                itPassenger = selectPassenger(passengers);
                break;
            case 6:
                std::cout << "Exiting Passenger Menu.\n";
                break;
            default:
                std::cout << "Invalid option. Try again.\n";
        }

    } while(option != 6);
}

void PassengerUI::bookFlight(std::vector<Passenger*>::iterator itPassenger, std::vector<Flight*>& flights, std::vector<Flight*>::iterator itFlight) {
    (*itPassenger)->bookFlight(*itFlight);
}

void PassengerUI::cancelFlight(std::vector<Passenger*>::iterator itPassenger, std::vector<Flight*>::iterator itFlight) {
    (*itPassenger)->cancelFlight(*itFlight);
}