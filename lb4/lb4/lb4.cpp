#include <iostream>

#include <cmath>

class CircleSector {
private:
    double x1, y1; // Координаты первой точки на окружности
    double x2, y2; // Координаты второй точки на окружности

public:
    // Конструктор для инициализации точек
    CircleSector(double x1, double y1, double x2, double y2) {
        this->x1 = x1;
        this->y1 = y1;
        this->x2 = x2;
        this->y2 = y2;
    }
    CircleSector& operator=(const CircleSector& other) {
        if (this != &other) {
            // Проверка на самоприсваивание
            x1 = other.x1;
            y1 = other.y1;
            x2 = other.x2;
            y2 = other.y2;
        }
        return *this;
    }

    CircleSector(const CircleSector& other)
    {
        this->x1 = other.x1;
        this->x2 = other.x2;
        this->y1 = other.y1;
        this->y2 = other.y2;
    }
    // Метод для получения радиуса окружности
    double getRadius() {
        return std::sqrt(x1 * x1 + y1 * y1);
    }

    // Метод для получения угла начала сектора в радианах
    double getStartAngle() {
        return std::atan2(y1, x1);
    }

    // Метод для получения угла конца сектора в радианах
    double getEndAngle() {
        return std::atan2(y2, x2);
    }

    // Метод для вывода информации о секторе
    void printInfo() {
        std::cout << "Радиус: " << getRadius() << std::endl;
        std::cout << "Угол начала сектора (в радианах): " << getStartAngle() << std::endl;
        std::cout << "Угол конца сектора (в радианах): " << getEndAngle() << std::endl;
    }

    // Перегрузка оператора * для пересечения двух секторов
    CircleSector operator*(CircleSector other) {
        // Реализация пересечения секторов
        double startX = std::max(getStartAngle(), other.getStartAngle());
        double endX = std::min(getEndAngle(), other.getEndAngle());
        if (startX < endX) {
            double x1 = std::cos(startX);
            double y1 = std::sin(startX);
            double x2 = std::cos(endX);
            double y2 = std::sin(endX);
            return CircleSector(x1, y1, x2, y2);
        }
        // В случае, когда секторы не пересекаются, вернуть пустой сектор
        return CircleSector(0, 0, 0, 0);
    }

    // Перегрузка оператора + для объединения двух секторов
    CircleSector operator+(CircleSector other) {
        // Объединение секторов
        double x1 = std::cos(getStartAngle());
        double y1 = std::sin(getStartAngle());
        double x2 = std::cos(other.getEndAngle());
        double y2 = std::sin(other.getEndAngle());
        return CircleSector(x1, y1, x2, y2);
    }

    // Перегрузка оператора - для несимметрической разности двух секторов
    CircleSector operator-(CircleSector& other) {
        // Несимметрическая разность секторов
        return *this + (other * CircleSector(-1, 0, 0, -1));
    }

};

int main() {
    setlocale(LC_ALL, "ru");
    // Создание двух экземпляров класса CircleSector
    CircleSector sector1(0, 1, 1, 0);
    CircleSector sector2(0.5, 0.5, -0.5, -0.5);
    CircleSector sectorTest = sector1;
    
    //ectorTest = sector1;
    // Вывод информации о секторах
    std::cout << "Сектор 1:" << std::endl;
    sector1.printInfo();
    
    std::cout << "-------------" << std::endl;

    std::cout << "Сектор 2:" << std::endl;
    sector2.printInfo();

    std::cout << "-------------" << std::endl;

    // Пересечение секторов
    CircleSector intersection = sector1 * sector2;
    std::cout << "Пересечение:" << std::endl;
    intersection.printInfo();

    std::cout << "-------------" << std::endl;

    // Объединение секторов
    CircleSector unionResult = sector1 + sector2;
    std::cout << "Объединение:" << std::endl;
    unionResult.printInfo();

    std::cout << "-------------" << std::endl;

    // Несимметрическая разность секторов
    CircleSector difference = sector1 - sector2;
    std::cout << "Несимметрическая разность:" << std::endl;
    difference.printInfo();

    return 0;
}



