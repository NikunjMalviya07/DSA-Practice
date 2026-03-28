#include<iostream>
#include<vector>
#include<queue>

using namespace std;

    // Kth level

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
    this->data = data;
    left = right = NULL;

    }
};

static int idx = -1;
Node* builtTree(vector<int> nodes){
    idx++;

    if(nodes[idx] == -1){
        return NULL;
    }


    Node* currNode = new Node(nodes[idx]);
    currNode->left = builtTree(nodes);
    currNode->right = builtTree(nodes);

    return currNode;
}

void kthHelper(Node* root, int K, int currLevel){

    if(root == NULL){
        return; 
    }

    if(currLevel == K){
        cout<<root->data<<" ";
    }

    kthHelper(root->left, K, currLevel+1);
    kthHelper(root->right, K, currLevel+1);

    return;
}

void kthlevel(Node* root, int K){
    kthHelper(root, K, 1);
    return;
}


int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};

    Node* root = builtTree(nodes);
    kthlevel(root,3);
}