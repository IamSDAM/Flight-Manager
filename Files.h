#ifndef FILES_H
#define FILES_H

#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Passenger.h"
#include "Flight.h"

void readPassenger(std::vector<Passenger*>& passengers) {
    std::ifstream file("Passenger.csv");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open Passenger.csv" << std::endl;
        return;
    }

    std::string line, temp;
    std::getline(file, line); // Skip header

    while (std::getline(file, line)) {
     Passenger* p = new Passenger();
    std::stringstream parser(line);

    std::getline(parser, temp, ',');
    p->setName(temp);
    std::getline(parser, temp, ',');
    p->setId(std::stoi(temp));
    std::getline(parser, temp, ',');
    p->setCountry(temp);

    passengers.push_back(p);

        //passengers.push_back(p); i think this crashes 
    }

    file.close();
}

void readFlight(std::vector<Flight*>& flights) {
    std::ifstream file("Flight.csv");
    if (!file.is_open()) {
        std::cerr << "Error: Could not open Flight.csv" << std::endl;
        return;
    }

    std::string line, temp;
    std::getline(file, line); // Skip header

    while (std::getline(file, line)) {
           Flight* f = new Flight();
    std::stringstream parser(line);

    std::getline(parser, temp, ',');
    f->setAirport(temp);
    std::getline(parser, temp, ',');
    f->setId(std::stoi(temp));
    std::getline(parser, temp, ',');
    f->setTime(temp);
    std::getline(parser, temp, ',');
    f->setDay(temp);
    std::getline(parser, temp, ',');
    f->setMaxSeats(std::stoi(temp));

    flights.push_back(f);
    }

    file.close();
}

template<typename T>
void print(const T& container) {
    if (container.empty()) {
        std::cout << "Container is empty." << std::endl;
        return;
    }

    for (const auto& item : container) {
        std::cout << *item << std::endl;
    }
    std::cout << std::endl;
}

template<typename T>
void clear(T& container) {
    for (auto& item : container) {
        delete item;
    }
    container.clear();
}

#endif 
