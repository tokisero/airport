#include "Flight.h"
#include <iostream>

void FlightManager::addFlight(int flightNumber, const std::string& destination, const std::string& date, const std::string& time) {
    Flight flight(flightNumber, destination, date, time);
    flights.push_back(std::move(flight));
    std::cout << "���� ������� ��������!" << std::endl;
}

void FlightManager::updateFlight(int flightNumber) {
    for (auto& flight : flights) {
        if (flight.getFlightNumber() == flightNumber) {
            std::string newDestination;
            std::string newDate;
            std::string newTime;

            std::cout << "������� ����� ����� ����������: ";
            std::cin >> newDestination;
            std::cout << "������� ����� ���� (DD/YY): ";
            std::cin >> newDate;
            std::cout << "������� ����� ����� (HH/MM): ";
            std::cin >> newTime;

            flight.setDestination(newDestination);
            flight.setDate(newDate);
            flight.setTime(newTime);

            std::cout << "������ � ����� ������� ��������!" << std::endl;
            return;
        }
    }
    std::cout << "���� � ����� ������� �� ������!" << std::endl;
}

void FlightManager::deleteFlight(int flightNumber) {
    for (auto it = flights.begin(); it != flights.end(); ++it) {
        if (it->getFlightNumber() == flightNumber) {
            flights.erase(it);
            std::cout << "���� �����!" << std::endl;
            return;
        }
    }
    std::cout << "���� � ����� ������� �� ������!" << std::endl;
}

void FlightManager::findFlight(int flightNumber) const {
    for (const auto& flight : flights) {
        if (flight.getFlightNumber() == flightNumber) {
            flight.printFlight();
            return;
        }
    }
    std::cout << "���� � ����� ������� �� ������!" << std::endl;
}

void FlightManager::listAllFlights() const {
    if (flights.empty()) {
        std::cout << "��� ��������� ������." << std::endl;
    }
    else {
        for (const auto& flight : flights) {
            flight.printFlight();
            std::cout << "-------------------" << std::endl;
        }
    }
}
