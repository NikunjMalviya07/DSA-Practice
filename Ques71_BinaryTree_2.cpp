#include<iostream>
#include<vector>
#include<queue>

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

int height(Node* root){

    if(root == NULL){
        return 0;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    int currH = max(leftHt, rightHt) + 1;

    return currH;
}

int countNodes(Node* root){

    if(root == NULL){
        return 0; 
    }

    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);

    int currCount = leftCount + rightCount + 1;

    return currCount;
}

int sumOfNodes(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);

    int currSum = leftSum + rightSum + root->data;

    return currSum;
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};

    Node* root = builtTree(nodes);
    cout<<"Root of Tree : "<<root->data<<"\n";
    int ans = height(root);
    cout<<"Height of Tree : "<<ans<<"\n";
    int ans1 = countNodes(root);
    cout<<"Number of nodes : "<<ans1<<"\n";

    int ans2 = sumOfNodes(root);
    cout<<"Sum of nodes : "<<ans2<<"\n";

}