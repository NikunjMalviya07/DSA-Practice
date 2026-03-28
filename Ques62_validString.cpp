#include<iostream>
#include<vector>
#include<stack>
#include<string>

using namespace std;

bool isValid(string &str){
    stack<char> s;
    int n = str.size();

    for(int i=0;i<n;i++){ // O(n)
          char ch = str[i];
        if(ch == '{' || ch == '(' || ch == '['){ // opening char
            s.push(ch);
        } else { // closing char
            if(s.empty()){ // corner case
                cout<<"INVALID String\n";
                return false;
            } 

            // match
            if( (ch == '}' && s.top() == '{' ) || // check
                (ch == ')' && s.top() == '(' ) ||
                (ch == ']' && s.top() == '[' )     ){
                    s.pop();
            } 
            else { // invalid 
                cout<<"INVALID String\n";
                return false;
            }
        }
    }

    cout<<"VALID String\n";
    return s.empty();


}

int main(){
    string str;
    cin>>str;

    cout<< isValid(str);
}