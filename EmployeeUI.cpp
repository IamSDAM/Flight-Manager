#include "EmployeeUI.h"
#include "Employee.h"

void EmployeeUI::menu(std::vector<Flight*>& flights, std::vector<Passenger*>& passengers)const{
    int option = 0;

    do {
        std::cout << "\n1) Display all flights\n";
        std::cout << "2) Display all passengers\n";
        std::cout << "3) Add a flight\n";
        std::cout << "4) Remove a flight\n";
        std::cout << "5) Display passengers on a flight\n";
        std::cout << "6) Exit\n";
        std::cout << "Select: ";
        std::cin >> option;
        std::cout << "\n";
        switch(option) {
            case 1:
                display(flights);  
                break;
            case 2:
                display(passengers);  
                break;
            case 3:
                createFlight(flights);  
                break;
            case 4: {
                std::vector<Flight*>::iterator itFlight = selectFlight(flights);
                if (itFlight != flights.end()) {
                    deleteFlight(flights, itFlight);
                }
                break;
            }
            case 5: {
                std::vector<Flight*>::iterator itFlight = selectFlight(flights);
                if (itFlight != flights.end()) {
                    (*itFlight)->display(); 
                }
                break;
            }
            case 6:
                std::cout << "Exiting Employee Menu.\n";
                break;
            default:
                std::cout << "Invalid option. Try again.\n";
        }
    } while(option != 6);
}

void EmployeeUI::createFlight(std::vector<Flight*>& flights) {
    std::string airport, time, day;
    int id, maxSeats;
    std::cout << "Enter airport: ";
    std::cin >> airport;
    std::cout << "Enter flight ID: ";
    std::cin >> id;
    std::cout << "Enter time (HH:MM): ";
    std::cin >> time;
    std::cout << "Enter day: ";
    std::cin >> day;
    std::cout << "Enter max seats: ";
    std::cin >> maxSeats;
    Employee::addFlight(flights, airport, id, time, day, maxSeats);
    std::cout << "Flight added successfully.\n";
}
void EmployeeUI::deleteFlight(std::vector<Flight*>& flights, std::vector<Flight*>::iterator itFlight) {
    bool good = Employee::cancelFlight(flights, *itFlight);
    if (good) {
        std::cout << "Flight cancelled successfully.\n";
    } else {
        std::cout << "Failed to cancel flight.\n";
    }
}