#include<iostream>
#include <cstring>
using namespace std;
    // convert lower case to upper case
void toUpperCase(char *word , int n){
    for(int i=0;i<n;i++){
        char ch = word[i];
        if(word[i] >= 'a' && word[i] <= 'z'){
            word[i] = word[i] - 32;
        }
    }
}
    // convert upper case to lower case
void toLowerCase(char *word , int n){
    for(int i=0;i<n;i++){
        char ch = word[i];
        if(word[i] >= 'A' && word[i] <= 'Z'){
            word[i] = word[i] + 32;
        }
    }
}
int main(){
    char word[100];
    cin.getline(word , 100);
    toLowerCase(word , strlen(word));
    cout << "Upper Case word is : "<< word << endl;
}