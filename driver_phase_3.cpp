#include <iostream>
#include "Passenger.h"
#include "Flight.h"
#include "Files.h"
#include "PassengerUI.h"
#include "EmployeeUI.h"

void menu(std::vector<Flight*>& flights, std::vector<Passenger*>& passengers)
{
    UserInterface* ui; // create a UserInterface object
    int option = 0;
    do {
        std::cout << "\nLOGIN AS Passenger OR Employee\n\n";
        std::cout << "1) Passanger\n";
        std::cout << "2) Employee\n";
        std::cout << "3) Exit program\n";
        std::cout << "\nSelect: ";
        std::cin >> option;
        std::cout << "\n";

        switch(option) {
            case 1:
                ui = new PassengerUI();
                break;
            case 2:
                ui = new EmployeeUI();
                break;
            case 3:
                std::cout << "EXITING PROGRAM\n\n";
                return;
            default:
                std::cout << "INVALID OPTION" << "\n";
        }        
        ui->menu(flights, passengers); // run the selected UI

    } while( option != 3 );
}

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
    // call the menu function
        menu(flights, passengers);
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