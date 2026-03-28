#include<iostream>
#include<string>
using namespace std;

class User{
private: 
    int id;
    string password;
public:
    string username;

    User(int id){
        this-> id = id;
    }
    
    // getter
    string getpassword(){
        return password;
    }
    // setter
    void setpassword(string password){
        this-> password = password;
    }
};

int main(){
    User user1(724);
    user1.username = "Original Nikunj Malviya";
    user1.setpassword("mnop");

    cout<<"Username : "<<user1.username<<endl;
    cout<<"Password : "<<user1.getpassword()<<endl;
    return 0;
}