#include<iostream>
using namespace std;
int main(){
    float a,b;
    cout<<"Enter a : b : ";
    cin>>a>>b;
    char oper;
    cout<<"Enter operator : ";
    cin>>oper;

    if(oper == '+'){
        cout<<"a+b = "<<a+b << endl;
    } else if(oper == '-'){
        cout<<"a-b = "<<a-b << endl;
    } else if(oper == '*'){
        cout<<"a*b = "<<a*b << endl;
    }  else if(oper == '/'){
        cout<<"a/b = "<<a/b << endl;
    } else{
        cout<<"Invalid Operator...";
    }
    

    switch(oper){
        case '+' : cout<<"a+b = "<<a+b;
        break;
        case '-' : cout<<"a-b = "<<a-b;
        break;
        case '*' : cout<<"a*b = "<<a*b;
        break;
        case '/' : cout<<"a/b = "<<a/b;
        break;

        default : cout<<"Invalid operator...";
    }
}