#	make; ./prog; make clean

prog : driver_phase_3.o Passenger.o Employee.o Flight.o PassengerUI.o EmployeeUI.o
	g++ -std=c++11 -o prog driver_phase_3.o Passenger.o Employee.o Flight.o	PassengerUI.o EmployeeUI.o


driver_phase_3.o : driver_phase_3.cpp Passenger.h Employee.h Flight.h PassengerUI.h EmployeeUI.h UserInterface.h
	g++ -std=c++11 -c driver_phase_3.cpp

PassengerUI.o : PassengerUI.cpp PassengerUI.h UserInterface.h Passenger.h Flight.h
	g++ -std=c++11 -c PassengerUI.cpp

EmployeeUI.o : EmployeeUI.cpp EmployeeUI.h UserInterface.h Flight.h Passenger.h Employee.h
	g++ -std=c++11 -c EmployeeUI.cpp

Flight.o: Flight.h Flight.cpp
	g++ -std=c++11 -c Flight.cpp

Employee.o: Employee.h Employee.cpp
	g++ -std=c++11 -c Employee.cpp

Passenger.o: Passenger.h Passenger.cpp Flight.h
	g++ -std=c++11 -c Passenger.cpp	


clean:
	rm -f *.o
	rm prog