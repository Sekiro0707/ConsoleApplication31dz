#include <iostream>
#include <cmath> 

using namespace std;

class transport {
protected:
    int spad;
    int conroz;
public:
    transport(int spd, int cost) : spad(spd), conroz(cost) {}

    int aluzor(int distance) {
        return distance / spad;
    }

    int caluzorn(int distance, int weight) {
        return distance * conroz;
    }
};

class Car : public transport {
public:
    Car() : transport(80, 1) {}

    int caluzorn(int distance, int weight) {
        return distance * conroz + (weight / 100) * 5;
    }
};

class Bicycle : public transport {
public:
    Bicycle() : transport(15, 1) {}

    int caluzorn(int distance, int weight) {
        return distance * conroz;
    }
};

class Cart : public transport {
public:
    Cart() : transport(10, 2) {}

    int caluzorn(int distance, int weight) {
        return distance * conroz + (weight / 200) * 2;
    }
};

int main() {
    int distance, weight;

    try {
        cout << "Введите расстояние для поездки (в км): ";
        cin >> distance;

        if (distance < 0) throw - 1; 

        cout << "Введите вес груза (в кг): ";
        cin >> weight;

        if (weight < 0) throw - 1; 

        Car car;
        Bicycle bicycle;
        Cart cart;

        cout << "\nАвтомобиль:\n";
        cout << "Время: " << car.aluzor(distance) << " часов\n";
        cout << "Стоимость: $" << car.caluzorn(distance, weight) << "\n";

        cout << "\nВелосипед:\n";
        cout << "Время: " << bicycle.aluzor(distance) << " часов\n";
        cout << "Стоимость: $" << bicycle.caluzorn(distance, weight) << "\n";

        cout << "\nТелега:\n";
        cout << "Время: " << cart.aluzor(distance) << " часов\n";
        cout << "Стоимость: $" << cart.caluzorn(distance, weight) << "\n";

    }
    catch (int) {
        cerr << "Error: Invalid input. Distance and weight must be non-negative integers." << endl;
    }

    return 0;
}
