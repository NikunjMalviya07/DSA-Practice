#include<iostream>
#include<string>

using namespace std;

void removeDuplicate(string str, string ans, int i, int map[26]){
    
    // base case
    if(i == str.size()){
        cout<<ans<<endl;
        return;
    }

    char ch = str[i];
    int mapIdx = ch - 'a';

    if(!map[mapIdx]){
        map[mapIdx] = 1;
        removeDuplicate(str, ans + str[i], i+1, map);
    } else {
        removeDuplicate(str, ans , i + 1 , map);
    }

}

int main(){
    string str = "nikunjmalviya";
    string ans = "";
    int map[26] = {0};

    removeDuplicate(str , ans , 0 , map);
}