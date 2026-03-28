#include <iostream>
#include <string>
using namespace std;

class Car {
    string name;
    string color;

public:
    // Constructor without parameters
    Car() {
        cout << "constructor without params\n";
    }

    // Constructor with parameters
    Car(string name, string color) {
        cout << "constructor with params\n";
        this->name = name;
        this->color = color;
    }

    void start() {
        cout << "car has started..\n";
    }

    void stop() {
        cout << "car has stopped..\n";
    }
};

int main() {
    Car car1; 
    Car car2("BMW", "Black"); 

    car2.start();
    car2.stop();

    return 0;
}
