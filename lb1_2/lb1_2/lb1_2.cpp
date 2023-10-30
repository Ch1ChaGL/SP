// lb1_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


// Базовая структура "Транспортное средство"
struct Vehicle {
    std::string brand;
    std::string model;
    int year;
    float price;

    Vehicle(const std::string& _brand, const std::string& _model, int _year, float _price)
        : brand(_brand), model(_model), year(_year), price(_price) {}

    void start() {
        printf("Запуск двигателя.\n");
    }

    void stop() {
        printf("Остановка двигателя.\n");
    }

    void horn() {
        printf("Звук сигнала.\n");
    }
};

// Структура "Автомобиль" наследуется от "Транспортное средство"
struct Car : Vehicle {
    int passengers;
    std::string fuelType;

    Car(const std::string& _brand, const std::string& _model, int _year, float _price, int _passengers, const std::string& _fuelType)
        : Vehicle(_brand, _model, _year, _price), passengers(_passengers), fuelType(_fuelType) {}

    void openDoors() {
        printf("Открытие дверей.\n");
    }

    void closeDoors() {
        printf("Закрытие дверей.\n");
    }

    void refuel() {
        printf("Заправка топливом.\n");
    }
};

// Структура "Грузовик" наследуется от "Транспортное средство"
struct Truck : Vehicle {
    float payload;
    int wheels;

    Truck(const std::string& _brand, const std::string& _model, int _year, float _price, float _payload, int _wheels)
        : Vehicle(_brand, _model, _year, _price), payload(_payload), wheels(_wheels) {}

    void loadCargo() {
        printf("Загрузка груза.\n");
    }

    void unloadCargo() {
        printf("Разгрузка груза.\n");
    }

    void changeTire() {
        printf("Замена шин.\n");
    }
};

// Структура "Мотоцикл" наследуется от "Транспортное средство"
struct Motorcycle : Vehicle {
    int horsepower;
    std::string type;

    Motorcycle(const std::string& _brand, const std::string& _model, int _year, float _price, int _horsepower, const std::string& _type)
        : Vehicle(_brand, _model, _year, _price), horsepower(_horsepower), type(_type) {}

    void accelerate() {
        printf("Ускорение мотоцикла.\n");
    }

    void brake() {
        printf("Торможение мотоцикла.\n");
    }

    void wheelie() {
        printf("Подъем переднего колеса.\n");
    }
};

// Структура "Велосипед" наследуется от "Транспортное средство"
struct Bicycle : Vehicle {
    std::string type;
    int gears;

    Bicycle(const std::string& _brand, const std::string& _model, int _year, float _price, const std::string& _type, int _gears)
        : Vehicle(_brand, _model, _year, _price), type(_type), gears(_gears) {}

    void startPedaling() {
        printf("Начало педалирования.\n");
    }

    void stopPedaling() {
        printf("Остановка педалирования.\n");
    }

    void changeGear() {
        printf("Смена передачи.\n");
    }

    void printGears() {
        printf("%i ", gears);
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    Car car1("Toyota", "Camry", 2022, 25000.0, 5, "Бензин");
    Car car2("Honda", "Civic", 2021, 22000.0, 5, "Бензин");
    Truck truck1("Volvo", "VNL", 2022, 80000.0, 20.0, 18);
    Truck truck2("Mercedes-Benz", "Actros", 2022, 90000.0, 25.0, 18);
    Motorcycle motorcycle1("Honda", "CBR500R", 2022, 7000.0, 47, "Спортивный");
    Motorcycle motorcycle2("Yamaha", "MT-07", 2022, 6500.0, 74, "Нейкед");
    Bicycle bicycle1("Trek", "Marlin 5", 2022, 600.0, "Горный", 21);
    Bicycle bicycle2("Giant", "Escape 3", 2022, 400.0, "Городской", 24);

    car1.start();
    std::cout << car1.passengers << std::endl;
    car1.openDoors();
    car1.closeDoors();
    car1.stop();

    truck2.start();
    truck2.loadCargo();
    truck2.unloadCargo();
    truck2.changeTire();

    motorcycle1.start();
    motorcycle1.accelerate();
    motorcycle1.brake();
    motorcycle1.wheelie();

    bicycle2.startPedaling();
    bicycle2.changeGear();
    bicycle2.stopPedaling();
    bicycle2.printGears();
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
