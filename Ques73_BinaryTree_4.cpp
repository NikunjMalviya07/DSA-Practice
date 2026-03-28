#include<iostream>
#include<vector>

using namespace std;
    // diameter of tree O(n)
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

pair<int, int> diam(Node* root){
    if(root == NULL){
        return make_pair(0,0);
    }
    // diameter, height
    pair<int, int> leftInfo = diam(root->left); // LD, LH;
    pair<int, int> rightInfo = diam(root->right); // RD, RH;

    int currDia = leftInfo.second + rightInfo.second + 1;
    int finalDia = max(currDia, max(leftInfo.first, rightInfo.first));
    int finalHgt = max(leftInfo.second, rightInfo.second) + 1;

    return make_pair(finalDia, finalHgt);
}

int main(){
    
    vector<int> nodes = {1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};

    Node* root = buildTree(nodes);

    cout<<"Diameter :"<<diam(root).first<<" "<<"Height :"<<diam(root).second;

}