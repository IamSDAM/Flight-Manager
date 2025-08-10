#ifndef PASSENGERUI_H
#define PASSENGERUI_H

//rename A to Passenger in files PassengerUI.h, Passenger.h
#include "UserInterface.h"

class PassengerUI : public UserInterface{
    public:
    void menu(std::vector<Flight*>& flights, std::vector<Passenger*>& passengers) const override;    
    static void bookFlight(std::vector<Passenger*>::iterator itPassenger, std::vector<Flight*>& flights ,std::vector<Flight*>::iterator itFlight);
    //                     /* A iterator */,                            /* B container */,               /* B iterator */);
    static void cancelFlight(std::vector<Passenger*>::iterator itPassenger,std::vector<Flight*>::iterator itFlight);
    //                      /* A iterator */,                               /* B iterator */);               
};
    
#endif