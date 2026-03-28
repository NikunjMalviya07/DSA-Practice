#include<iostream>
#include<string>
using namespace std;

    // shallow copy...

class Car{
    public: 
    string name;
    string color;
    int *mileage;

    Car(string name, string color){
        this-> name = name;
        this->color = color;
        mileage = new int;
        *mileage = 12;
    }

    // making our own constructor
    Car(Car &original){
        cout<<"coping from original to new..\n";
        name = original.name;
        color = original.color;
        mileage = original.mileage;
    }

    // we need a destructor
    ~Car(){
    
    if(mileage!= NULL){
        cout<<"deleting object..\n";
        delete mileage;
        mileage = NULL;
    }    

    }
};

// deep copy...

class CarD{
    public:
    string name1;
    string color1;
    int* mileage1;
    // constructor
    CarD(string name1, string color1){
        this-> name1 = name1;
        this-> color1 = color1;
        mileage1 = new int;
        *mileage1 = 12;
    }
    // coustom copy constructor
    CarD(CarD &original1){
        cout<<"copying from original to new deep copy\n";
        name1 =original1.name1; 
        color1 = original1.color1;
        mileage1 = new int;
        *mileage1 = *original1.mileage1;
    }

    ~CarD(){
        if(mileage1 != NULL){
            cout<<"deleting object rom deep\n";
            delete mileage1;
            mileage1 = NULL;
        }
    
    }

};

int main(){
    Car c1("BMW","Black");
    Car c2(c1); // Coustom Constructor

    cout<<c2.name<<endl; // BMW
    cout<<c2.color<<endl; // Black
    cout<<*c2.mileage<<endl; // 12

    *c2.mileage = 10; 

    cout<<*c1.mileage<<endl; // 10

    cout<<endl<<endl;

    CarD cD1("BMW","Black");
    CarD cD2(cD1);

    cout<<cD2.name1<<endl; //BMW
    cout<<cD2.color1<<endl; // Black
    cout<<*cD2.mileage1<<endl; // 12

    *cD2.mileage1 = 10;

    cout<<*cD1.mileage1<<endl; // 12
    
}