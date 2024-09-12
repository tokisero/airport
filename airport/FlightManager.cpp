#include "Flight.h"
#include <iostream>
#include <vector>

void FlightManager::addFlight(int flightNumber, const std::string& destination, const std::string& date, const std::string& time) {
    flights.emplace_back(flightNumber, destination, date, time);
    std::cout << "Рейс успешно добавлен!" << std::endl;
}

void FlightManager::updateFlight(int flightNumber) {
    for (auto& flight : flights) {
        if (flight.getFlightNumber() == flightNumber) {
            std::string destination, date, time;
            std::cout << "Введите новый пункт назначения: ";
            std::cin >> destination;
            std::cout << "Введите новую дату (DD/YY): ";
            std::cin >> date;
            std::cout << "Введите новое время (HH/MM): ";
            std::cin >> time;
            flight.setDestination(destination);
            flight.setDate(date);
            flight.setTime(time);
            std::cout << "Данные о рейсе успешно изменены!" << std::endl;
            return;
        }
    }
    std::cout << "Рейс с таким номером не найден!" << std::endl;
}

void FlightManager::deleteFlight(int flightNumber) {
    for (auto it = flights.begin(); it != flights.end(); ++it) {
        if (it->getFlightNumber() == flightNumber) {
            flights.erase(it);
            std::cout << "Рейс удалён!" << std::endl;
            return;
        }
    }
    std::cout << "Рейс с таким номером не найден!" << std::endl;
}

void FlightManager::findFlight(int flightNumber) const {
    for (const auto& flight : flights) {
        if (flight.getFlightNumber() == flightNumber) {
            flight.printFlight();
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
        for (const auto& flight : flights) {
            flight.printFlight();
            std::cout << "-------------------" << std::endl;
        }
    }
}
