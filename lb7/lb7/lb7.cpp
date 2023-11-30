#include <iostream>
#include <string>

using namespace std;

class Document {
protected:
    string name;
    Document* next; // указатель на следующий документ в списке
public:
    // Статическая компонента - указатель на начало списка
    static Document* begin;

    Document(string _name) : name(_name), next(nullptr) {}
    virtual ~Document() {}

    // Метод для добавления объекта в список
    void AddToList() {
        next = begin;
        begin = this;
    }

    // Виртуальная функция для просмотра документа
    virtual void Show() {
        cout << "Document: " << name << endl;
    }

    // Статическая функция для просмотра списка
    static void PrintList() {
        Document* current = begin;
        while (current) {
            current->Show();
            current = current->next;
        }
    }
};

// Инициализация статической компоненты в глобальной области
Document* Document::begin = nullptr;

// Класс Квитанция
class Receipt : public Document {
private:
    float amount;
public:
    Receipt(string _name, float _amount) : Document(_name), amount(_amount) {
        //AddToList(); // добавляем объект в список при создании
    }

    // Переопределение функции для просмотра квитанции
    void Show() override {
        cout << "Receipt: " << name << ", Amount: " << amount << endl;
    }
};

// Класс Накладная
class Invoice : public Document {
private:
    int quantity;
public:
    Invoice(string _name, int _quantity) : Document(_name), quantity(_quantity) {
        //AddToList(); // добавляем объект в список при создании
    }

    // Переопределение функции для просмотра накладной
    void Show() override {
        cout << "Invoice: " << name << ", Quantity: " << quantity << endl;
    }
};

// Класс Чек
class Check : public Document {
private:
    double total;

public:
    Check(string _name, double _total) : Document(_name), total(_total) {
        //AddToList(); // добавляем объект в список при создании
    }

    // Переопределение функции для просмотра чека
    void Show() override {
        cout << "Check: " << name << ", Total: " << total << endl;
    }
};

int main() {
    // Создание объектов различных классов и добавление их в список
    Receipt receipt("Receipt1", 100.50);
    Receipt receipt2("Receipt2", 100.50);
    Receipt receipt3("Receipt3", 100.50);

    // Пример использования dynamic_cast для приведения указателя к производному классу
    Document* docPtr = &receipt;

   /* receipt.AddToList();
    receipt2.AddToList();
    receipt3.AddToList();*/
    Receipt* receiptPtrDynamic = dynamic_cast<Receipt*>(docPtr);
    Document* receiptPtrDynamic2 = reinterpret_cast<Document*>(receiptPtrDynamic);
    if (receiptPtrDynamic) {
        cout << "Dynamic Cast: " << endl; 
        receiptPtrDynamic->Show();
    }
    else {
        cout << "Dynamic Cast failed" << endl;
    }

    // Пример использования static_cast для приведения указателя к производному классу
    Receipt* receiptPtrStatic = static_cast<Receipt*>(docPtr);
    cout << "Static Cast: " << endl;
    receiptPtrStatic->Show();

    // Вывод списка документов
    Document::PrintList();

    return 0;
}
