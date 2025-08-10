#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>
#include <vector>
#include "Passenger.h"
#include "Flight.h"

class UserInterface {
    public:
        virtual void menu(std::vector<Flight*>& flights, std::vector<Passenger*>& passengers)const=0;

        template <typename T>
        static void display(std::vector<T*> container){
            for (size_t i = 0; i < container.size(); ++i) {
                std::cout << i << ") " << *container[i] << std::endl;
                }
            }
        /*template <typename T>
        static void display(std::vector<T*> container){
            typename std::vector<T*>::iterator it = container.begin();
            while(it != container.end()){
                std::cout << **it << std::endl;
                ++it;
            }
        } 
        */
        static std::vector<Passenger*>::iterator selectPassenger(std::vector<Passenger*> &passengers){
            if (passengers.empty()) {
                std::cout << "No passengers available.\n";
                return passengers.end();
            }
        
            std::cout << "\nAvailable Passengers:\n";
            display(passengers);
        
            std::cout << "\nSelect a passenger : ";
            int index;
            std::cin >> index;
            while(index < 0 || index >= passengers.size()) {
                std::cout << "Invalid selection. Try again: ";
                std::cin >> index;
            }
            std::cout << "\nYou have selected: "<< passengers[index]->getName()<< ", ID: " << passengers[index]->getId()<< ", Country: " << passengers[index]->getCountry()<< "\n";
            return passengers.begin() + index;
        }
        static std::vector<Flight*>::iterator selectFlight(std::vector<Flight*> &flights){
            if (flights.empty()){
                std::cout << "No flights available.\n";
                return flights.end();
            }
        
            std::cout << "\nAvailable Flights:\n";
            display(flights);
            
            std::cout << "\nSelect a Flight: ";
            int index;
            std::cin >> index;
            while(index < 0 || index >= flights.size()) {
                std::cout << "Invalid selection. Try again: ";
                std::cin >> index;
            }
        
            Flight* f = flights[index];
            std::cout << "\n You have selected: "<< "Flight ID: " << f->getId()<< ", Airport: " << f->getAirport()<< ", Time: " << f->getTime()<< ", Day: " << f->getDay()<< "\n";
        
            return flights.begin() + index;
}       

        virtual ~UserInterface() {}

};

#endif