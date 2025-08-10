#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Flight.h"


#include <iostream>

class Employee {
    public:
    static void addFlight(std::vector<Flight*>& flights, const std::string& airport, int id, const std::string& time, const std::string& day, int maxSeats);
    static bool cancelFlight(std::vector<Flight*>& flights, Flight* f);
    static std::vector<Flight*>::iterator findFlight(std::vector<Flight*>& flights, int flightsId);   
};

#endif