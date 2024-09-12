#include "Flight.h"
#include <iostream>

Flight::Flight(int flightNumber, const std::string& destination, const std::string& date, const std::string& time) {
    this->flightNumber = flightNumber;
    this->destination = destination;
    this->date = date;
    this->time = time;
}

int Flight::getFlightNumber() const {
    return flightNumber;
}

std::string Flight::getDestination() const {
    return destination;
}

std::string Flight::getDate() const {
    return date;
}

std::string Flight::getTime() const {
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

FlightManager::~FlightManager() {
    for (Flight* flight : flights) {
        delete flight;
    }
}

void FlightManager::addFlight(int flightNumber, const std::string& destination, const std::string& date, const std::string& time) {
    flights.push_back(new Flight(flightNumber, destination, date, time));
    std::cout << "Рейс успешно добавлен!" << std::endl;
}

void FlightManager::updateFlight(int flightNumber) {
    for (Flight* flight : flights) {
        if (flight->getFlightNumber() == flightNumber) {
            std::string destination, date, time;
            std::cout << "Введите новый пункт назначения: ";
            std::cin >> destination;
            std::cout << "Введите новую дату (DD/YY): ";
            std::cin >> date;
            std::cout << "Введите новое время (HH/MM): ";
            std::cin >> time;
            flight->setDestination(destination);
            flight->setDate(date);
            flight->setTime(time);
            std::cout << "Данные о рейсе успешно изменены!" << std::endl;
            return;
        }
    }
    std::cout << "Рейс с таким номером не найден!" << std::endl;
}

void FlightManager::deleteFlight(int flightNumber) {
    for (auto it = flights.begin(); it != flights.end(); ++it) {
        if ((*it)->getFlightNumber() == flightNumber) {
            delete* it;
            flights.erase(it);
            std::cout << "Рейс удален!" << std::endl;
            return;
        }
    }
    std::cout << "Рейс с таким номером не найден!" << std::endl;
}

void FlightManager::findFlight(int flightNumber) const {
    for (const Flight* flight : flights) {
        if (flight->getFlightNumber() == flightNumber) {
            flight->printFlight();
            return;
        }
    }
    std::cout << "Рейс с таким номером не найден!" << std::endl;
}

void FlightManager::listAllFlights() const {
    if (flights.empty()) {
        std::cout << "Нет доступных рейсов." << std::endl;
    }
    else {
        for (const Flight* flight : flights) {
            flight->printFlight();
            std::cout << "-------------------" << std::endl;
        }
    }
}
