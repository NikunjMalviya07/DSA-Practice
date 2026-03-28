#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

class Node{
public:
    unordered_map<char, Node*> children;
    bool endOfWord;

    Node(){
        endOfWord = false;

    }
};

class Trie {
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(string key){
        Node* temp = root;
        for(int i = 0; i < key.size(); i++){
            if(temp->children.count(key[i]) == 0){
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]]; 
        }

        temp->endOfWord = true;
    }

    bool search(string key) {
        Node* temp = root;
        
        for(int i = 0; i < key.size() ; i++){
            if(temp->children.count(key[i])){
                temp = temp->children[key[i]];
            } else {
                return false;
            }
        }

        return temp->endOfWord;
    }

    bool isExist(string key){
        Node* temp = root;

        for(int i = 0 ; i < key.size() ; i++){
            if(temp->children[key[i]]) {  // temp->children.find(key[i]) != temp->children.end()
                temp = temp->children[key[i]];
            } else {
                return false;
            }
        }

        return true;
    }

    int countHelper(Node* root){
        int ans = 0;
        for( pair<char, Node*> child : root->children){
            ans += countHelper(child.second);
        }

        return ans +1;
    }

    int countNodes(){
        return countHelper(root);
    }

    string longestHelper (Node* root, string &ans ,string temp){
        for(pair<char, Node*> child : root->children){
            if(child.second->endOfWord){
                temp += child.first;

            if(( temp.size() == ans.size() && temp < ans) || (temp.size() > ans.size())){
                ans = temp;
            }

            longestHelper(child.second, ans, temp);
            temp = temp.substr(0 , temp.size() - 1); 
            }
        }

        return temp;
    }

    string longestStringWithEOW(){
        string ans = "";
        longestHelper(root, ans, "");

        return ans;
    }

};

bool helper(Trie &trie, string key){

    if(key.size() == 0){
        return true;
    }
    for(int i = 0; i < key.size() ; i++ ){
        string first  = key.substr(0, i+1);
        string second  = key.substr(i+1);

        if(trie.search(first) && helper(trie, second)){
            return true;
        }
    }

    return false;
}

bool wordBreak(vector<string> dict, string key){

    Trie trie;

    for(int i = 0; i< dict.size() ; i++){
        trie.insert(dict[i]);
    }

    return helper(trie, key);

}

bool startsWith(vector<string> dict, string key){
    Trie trie;

    for(int i = 0; i< dict.size() ; i++){
        trie.insert(dict[i]);
    }

    return trie.isExist(key);
}

int countUniqueSubstring(string str){
    Trie trie;
    // find suffix
    for(int i = 0 ;i < str.size(); i++){
        string suffix = str.substr(i);
        trie.insert(suffix);
    }

    return trie.countNodes();
}

string longestString(vector<string> dict) {
    Trie trie;

    for(int i = 0 ;  i < dict.size() ; i ++ ){
        trie.insert(dict[i]);
    }

    return trie.longestStringWithEOW();
}

int main() {
    // vector<string> words = {"the", "a", "there", "their", "any", "three"};
    // vector<string> dict = {"I", "Like", "Sam", "Samsung", "Mobile", "Ice"};

    // cout<< startsWith(dict, "Like");

    vector<string> dict = {"a", "banana", "app", "appl", "ap", "apply", "apple"};

    // string str = "ababa";
    cout<< longestString(dict)<< endl;

    return 0;
    
}