#include<iostream>
#include<cstring>
using namespace std;
    // reverse the word
void reverseWord ( char *word , int n){
    int ptr1 = 0;
    int ptr2 = n-1;
    while(ptr1<ptr2){
        swap(word[ptr1++],word[ptr2--]);
    }
}
bool checkPalindrome(char *word , int n){
    int ptr1 = 0;
    int ptr2 = n-1;
    while(ptr1<ptr2){
        if(word[ptr1++]==word[ptr2--]){continue;}
        else{return false;};
    }
    return true;
}
int main(){
    char word[100];
    cin.getline(word , 100);
    int ans = checkPalindrome(word , strlen(word));
    cout << ans;
}
