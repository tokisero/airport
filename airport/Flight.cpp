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
    std::cout << "����� �����: " << flightNumber << std::endl;
    std::cout << "����� ����������: " << destination << std::endl;
    std::cout << "����: " << date << std::endl;
    std::cout << "�����: " << time << std::endl;
}

FlightManager::~FlightManager() {
    for (Flight* flight : flights) {
        delete flight;
    }
}

void FlightManager::addFlight(int flightNumber, const std::string& destination, const std::string& date, const std::string& time) {
    flights.push_back(new Flight(flightNumber, destination, date, time));
    std::cout << "���� ������� ��������!" << std::endl;
}

void FlightManager::updateFlight(int flightNumber) {
    for (Flight* flight : flights) {
        if (flight->getFlightNumber() == flightNumber) {
            std::string destination, date, time;
            std::cout << "������� ����� ����� ����������: ";
            std::cin >> destination;
            std::cout << "������� ����� ���� (DD/YY): ";
            std::cin >> date;
            std::cout << "������� ����� ����� (HH/MM): ";
            std::cin >> time;
            flight->setDestination(destination);
            flight->setDate(date);
            flight->setTime(time);
            std::cout << "������ � ����� ������� ��������!" << std::endl;
            return;
        }
    }
    std::cout << "���� � ����� ������� �� ������!" << std::endl;
}

void FlightManager::deleteFlight(int flightNumber) {
    for (auto it = flights.begin(); it != flights.end(); ++it) {
        if ((*it)->getFlightNumber() == flightNumber) {
            delete* it;
            flights.erase(it);
            std::cout << "���� ������!" << std::endl;
            return;
        }
    }
    std::cout << "���� � ����� ������� �� ������!" << std::endl;
}

void FlightManager::findFlight(int flightNumber) const {
    for (const Flight* flight : flights) {
        if (flight->getFlightNumber() == flightNumber) {
            flight->printFlight();
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
        for (const Flight* flight : flights) {
            flight->printFlight();
            std::cout << "-------------------" << std::endl;
        }
    }
}
