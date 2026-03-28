#include<iostream>
#include<string>
#include<vector>

using namespace std;

void subsetArr(string str , string subset){
    if(str.size() == 0){
        cout << subset << endl;
        return;
    }

    char ch = str[0];

    subsetArr(str.substr(1,str.size()-1) , subset + ch); // yes
    subsetArr(str.substr(1,str.size()-1) , subset); // No

}

int main(){
    string str = "abc";
    string subset = "";

    subsetArr(str ,subset);
    return 0;
}