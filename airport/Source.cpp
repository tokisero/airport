#include <iostream>
#include <locale>
#include "Flight.h"

int main() {
    setlocale(LC_ALL, "RU");
    FlightManager manager;
    int choice = 0;

    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить рейс\n";
        std::cout << "2. Изменить данные о рейсе\n";
        std::cout << "3. Снять рейс\n";
        std::cout << "4. Найти рейс\n";
        std::cout << "5. Вывести все рейсы\n";
        std::cout << "6. Выход\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int flightNumber;
            std::string destination, date, time;
            std::cout << "Введите номер рейса: ";
            std::cin >> flightNumber;
            std::cout << "Введите пункт назначения: ";
            std::cin >> destination;
            std::cout << "Введите дату (DD/YY): ";
            std::cin >> date;
            std::cout << "Введите время (HH/MM): ";
            std::cin >> time;
            manager.addFlight(flightNumber, destination, date, time);
            break;
        }
        case 2: {
            int flightNumber;
            std::cout << "Введите номер рейса: ";
            std::cin >> flightNumber;
            manager.updateFlight(flightNumber);
            break;
        }
        case 3: {
            int flightNumber;
            std::cout << "Введите номер рейса: ";
            std::cin >> flightNumber;
            manager.deleteFlight(flightNumber);
            break;
        }
        case 4: {
            int flightNumber;
            std::cout << "Введите номер рейса: ";
            std::cin >> flightNumber;
            manager.findFlight(flightNumber);
            break;
        }
        case 5: {
            manager.listAllFlights();
            break;
        }
        case 6: {
            std::cout << "Выход из программы." << std::endl;
            break;
        }
        default: {
            std::cout << "Неверный выбор, попробуйте снова." << std::endl;
        }
        }
    } while (choice != 6);

    return 0;
}
