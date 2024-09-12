#include "Flight.h"
#include <iostream>

Flight::Flight(int flightNumber, const std::string& destination, const std::string& date, const std::string& time)
    : flightNumber(flightNumber), destination(destination), date(date), time(time) {
}

int Flight::getFlightNumber() const {
    return flightNumber;
}

const std::string& Flight::getDestination() const {
    return destination;
}

const std::string& Flight::getDate() const {
    return date;
}

const std::string& Flight::getTime() const {
    return time;
}

void Flight::setDestination(const std::string& destination) {
    this->destination = destination;
}

void Flight::setDate(const std::string& date) {
    this->date = date;
}

void Flight::setTime(const std::string& time) {
    this->time = time;
}

void Flight::printFlight() const {
    std::cout << "Номер рейса: " << flightNumber << std::endl;
    std::cout << "Пункт назначения: " << destination << std::endl;
    std::cout << "Дата: " << date << std::endl;
    std::cout << "Время: " << time << std::endl;
}
