#include<iostream>
#include<vector>
    // Diameter of a tree O(n^2)
using namespace std;

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
Node* buildTree(vector<int> nodes){
    idx++;

    if(nodes[idx] == -1){
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}

int height(Node* root){

    if(root == NULL){
        return 0;
    }

    int leftH = height(root->left);
    int rightH = height(root->right);
    int currH = max(leftH, rightH) + 1;

    return currH;
}

int diameter(Node* root){ //O(n^2)
    if(root == NULL){
        return 0;
    }

    int currD = height(root->left) + height(root->right) + 1; // O(n)
    int leftDia = diameter(root->left);
    int rightDia = diameter(root->right);

    return max(currD, max(leftDia, rightDia));
}

int main(){
    
    vector<int> nodes = {1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};

    Node* root = buildTree(nodes);
    cout<<root->data<<endl;
    cout<<height(root)<<endl;
    cout<<diameter(root)<<endl;

}