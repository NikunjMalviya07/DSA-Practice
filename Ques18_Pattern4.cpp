#include<iostream>
using namespace std;
    // butterfly pattern
    
void printPattern(int n){
    for (int i = 1; i <= n; i++) {     // 1st half
    for (int j = 1; j <= i; j++) cout << "*";
    for (int j = 1; j <= 2*(n-i); j++) cout << " ";
    for (int j = 1; j <= i; j++) cout << "*";
    cout << "\n";
}

for (int i = 1; i <= n; i++) {     // 2nd half
    for (int j = 1; j <= n-i+1; j++) cout << "*";
    for (int j = 1; j <= 2*(i-1); j++) cout << " ";
    for (int j = 1; j <= n-i+1; j++) cout << "*";
    cout << "\n";
}

}
int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    printPattern(n);
}