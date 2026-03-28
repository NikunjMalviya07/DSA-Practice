#include<iostream>
#include<string>
using namespace std;
    // Valid Anagram
bool isAnagram(string str1 ,string str2){
    if(str1.length()!=str2.length()){
        cout << "Not valid anagram";
        return false;
    } 
    // step 1 to know the size
    int count[26] = {0};
    for(int i=0;i<str1.length();i++){
        int idx = str1[i] - 'a';
        count[idx]++;
    }
    // step 2 to decrease the array element size
    for(int i=0;i<str2.length();i++){
        int idx = str2[i] - 'a';
        if(count[idx] == 0){
            cout << "Not valid anagram";
        return false;
        }
        count[idx]--;
    }

    cout << "Valid anagram";
        return true;

}
int main(){
    string str1 = "anagram";
    string str2 = "naaagrm";
    int ans = isAnagram(str1 , str2);
    cout<<ans<<endl;

}