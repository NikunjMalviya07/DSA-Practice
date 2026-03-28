#include<iostream>
#include<string>

using namespace std;

// contiguous substrings start and end with the same character

int ans = 0;

void printSubstring ( int st , int ed , string s ){
    if ( st == s.size()){
        return ;
    }

    if ( ed == s.size() ){
        // cout << s.substr(st , ed - st + 1);
        // cout << endl;
        printSubstring(st + 1 , st + 1 , s);
        return;
    }

    // cout << s.substr(st , ed - st + 1 )<<" ";
    if(s[st] == s[ed]){
        ans += 1;
    }
    printSubstring(st , ed + 1 ,s );
}

int main(){

    int st = 0;
    int ed = 0;
    
    string s = "abada";

    printSubstring(st , ed ,  s);
    cout<<ans;
}