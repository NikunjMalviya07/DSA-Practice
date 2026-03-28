#include<iostream>
#include<string>
#include<vector>

using namespace std;

void printPermuatation(string str , string ans){
    if(str.size() == 0){
        cout << ans <<" \n";
        return;
    }

    for(int i = 0 ; i <  str.size() ; i ++){
        char ch = str[i];
        string next = str.substr(0,i) + str.substr(i+1, str.size()-i+1);
        printPermuatation(next , ans + ch );
    }
}

int main(){
    string str = "abc";
    string ans = "";

    printPermuatation(str , ans );
    return 0;
}