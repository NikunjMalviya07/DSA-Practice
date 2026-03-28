#include<iostream>
using namespace std;
    // factorial using recursion...
int factorial(int n){
    if(n == 0){
        return 1;
    }
    return n * factorial(n-1); // kaam
}

    // print numbers in decreasing order...
void print(int n){
    if(n == 0){
        return;
    }
    // This first call the function and then print therefore increasing order...
    print(n-1);
    cout<<n<<" "; // kaam..
}

    // print number in increasing order
void print1(int n){
    if(n==0){
        return;
    }
    // This first print the number and then call the function therefore decreasing order...
    cout<<n<<" "; // kaam
    print(n-1);

}

int main(){
    int n;
    print(5);
    cout<<endl;
    print1(5);
}