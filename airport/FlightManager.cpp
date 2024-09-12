#include "Flight.h"
#include <iostream>
#include <vector>

void FlightManager::addFlight(int flightNumber, const std::string& destination, const std::string& date, const std::string& time) {
    flights.emplace_back(flightNumber, destination, date, time);
    std::cout << "���� ������� ��������!" << std::endl;
}

void FlightManager::updateFlight(int flightNumber) {
    for (auto& flight : flights) {
        if (flight.getFlightNumber() == flightNumber) {
            std::string destination, date, time;
            std::cout << "������� ����� ����� ����������: ";
            std::cin >> destination;
            std::cout << "������� ����� ���� (DD/YY): ";
            std::cin >> date;
            std::cout << "������� ����� ����� (HH/MM): ";
            std::cin >> time;
            flight.setDestination(destination);
            flight.setDate(date);
            flight.setTime(time);
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
