#include<iostream>
#include<string>

using namespace std;

int steps = 0;

void towerOfHanoi(int  n, string from , string auxi , string to ){
    if(n==1){
        steps++;
        cout<<"Treansfer disk : "<<n<<" from "<<from<<" to "<<to<<" ."<<endl;
        return;
    }
    // 
    towerOfHanoi(n-1, from , to , auxi);
    steps++;
    cout<<"Treansfer disk : "<<n<<" from "<<from<<" to "<<to<<" ."<<endl;
    towerOfHanoi(n-1, auxi , from , to );
}

int main(){
    int n;
    cin>>n;
    string from = "A";
    string auxi = "B";
    string to = "C";
    towerOfHanoi(n, from , auxi , to );
    cout<<steps<<endl;
}