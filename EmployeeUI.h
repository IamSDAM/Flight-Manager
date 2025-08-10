#ifndef EMPLOYEEUI_H
#define EMPLOYEEUI_H

#include "UserInterface.h"

class EmployeeUI : public UserInterface {
    public:
    void menu(std::vector<Flight*>& flights, std::vector<Passenger*>& passengers) const override;
    //        B container                    A container                         const;     
    static void createFlight(std::vector<Flight*>& flights);
    //                       B container; 
    static void deleteFlight(std::vector<Flight*>& flights, std::vector<Flight*>::iterator itFlight);
    //                       B container                    B iterator ;   
}; 


#endif