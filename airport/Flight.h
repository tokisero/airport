#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>

class Flight {
private:
    int flightNumber;
    std::string destination;
    std::string date;
    std::string time;
public:
    Flight(int flightNumber, const std::string& destination, const std::string& date, const std::string& time);
    int getFlightNumber() const;
    std::string getDestination() const;
    std::string getDate() const;
    std::string getTime() const;
    void setDestination(const std::string& destination);
    void setDate(const std::string& date);
    void setTime(const std::string& time);
    void printFlight() const;
};

class FlightManager {
private:
    std::vector<Flight> flights; // Храним объекты, а не указатели
public:
    void addFlight(int flightNumber, const std::string& destination, const std::string& date, const std::string& time);
    void updateFlight(int flightNumber);
    void deleteFlight(int flightNumber);
    void findFlight(int flightNumber) const;
    void listAllFlights() const;
};

#endif
