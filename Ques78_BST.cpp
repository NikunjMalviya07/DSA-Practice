#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};
    // inert a node
Node* insert(Node* root, int val){
    if(root == NULL){
        root = new Node(val);
        return root;
    }

    if(val < root->data){
        root->left = insert(root->left, val);
    }

    if(val > root->data){
        root->right = insert(root->right, val);
    }

    return root;
}
    // building a BST
Node* buildBST(int arr[], int n){
    Node* root = NULL;

    for(int i=0;i<n;i++){
        root = insert(root , arr[i]);
    }

    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
}
    // search in BST
bool search(Node* root,  int key){
    if(root == NULL){
        return false;
    }

    if(root->data == key){
        return true;
    }

    if(root->data < key){
        return search(root->right, key);
    }

    if(root->data > key){
        return search(root->left, key);
    }

    return false;
}
    // delete a node

Node* getInorderSuccessor(Node* root){
    while(root->left != NULL){
        root = root->left;
    }

    return root;
}

Node* delNode(Node* root, int val){

    if(root == NULL){
        return NULL;
    }

    if(val < root->data){
        root->left = delNode(root->left , val);
    } else if(val > root->data){
        root->right = delNode(root->right, val);

    } else {
        // root == val: 
        // case 1: 0 children
        if( root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // case 2 : 1 children
        if(root->left == NULL || root->right == NULL){
            return root->left == NULL ? root->right : root->left;
        }

        // case 3: 2 children
        Node* IS = getInorderSuccessor(root->right);
        root->data = IS->data;
        root->right = delNode(root->right, IS->data );
        return root;
    }
    
    return root;
}

    // Print In Range
void printInRange(Node* root, int st, int ed){

    if(root == NULL){
        return;
    }

    if(root->data >= st&& root->data <= ed ){
        printInRange(root->left, st, ed);
        cout<<root->data<<" ";
        printInRange(root->right, st, ed);
    }

    else if(root->data < st){
        printInRange(root->right, st, ed);
    }

    else if(root->data > ed){
        printInRange(root->left, st, ed);
    }

    return;
}

    // rootToLeat Path

void printPath(vector<int> path){
    for(int i=0;i<path.size(); i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
    return;
} 

void pathHelper(Node* root, vector<int> path){

    if(root == NULL){
        return;
    }


    path.push_back(root->data);

    if(root->left == NULL && root->right == NULL){
        printPath(path);
        path.pop_back();
        return;
    }

    pathHelper(root->left, path);
    pathHelper(root->right, path);

    path.pop_back();
    return;
}

void rootToLeaf(Node* root){    
    vector<int> path;
    pathHelper(root, path);
    return;   
}

        // validate BST
bool validateHelper(Node* root, Node* min, Node* max){

    if(root == NULL){
        return true;
    }

    if(min != NULL && root->data < min->data ){
        return false;
    }

    if(max != NULL && root->data > max->data ){
        return false;
    }

    return  validateHelper(root->left, min, root)
            && validateHelper(root->right, root, max);

}

bool validateBST(Node* root){
    return validateHelper(root, NULL, NULL);
    
}

    // build a balanced BST from a array

Node* buildBSTFromSortedArray(int arr[], int st, int end){
    if(st > end){
        return NULL;
    }

    int mid = st + (end - st)/2;
    Node* curr = new Node(arr[mid]);

    curr->left = buildBSTFromSortedArray(arr, st, mid-1);
    curr->right = buildBSTFromSortedArray(arr, mid+1, end);

    return curr;

}

void preorder(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

    return;
}

    // build a balanced BST from BT

Node* buildBSTFromSortedArray(vector<int> arr, int st, int end){
    if(st > end){
        return NULL;
    }

    int mid = st + (end - st)/2;
    Node* curr = new Node(arr[mid]);

    curr->left = buildBSTFromSortedArray(arr, st, mid-1);
    curr->right = buildBSTFromSortedArray(arr, mid+1, end);

    return curr;

}

void getInorder(Node* root, vector<int> &nodes){
    if(root == NULL){
        return;
    }

    getInorder(root->left, nodes);
    nodes.push_back(root->data);
    getInorder(root->right, nodes);

    return;
}

Node* balanceBST(Node* root){
    // inorder sequence
    vector<int> nodes;
    getInorder(root, nodes);

    return buildBSTFromSortedArray(nodes, 0 , nodes.size()- 1);

}

    // size of a laegest bst (bawal question)
    // Merge 2 BST easy hai : both sort and merge and balance BST

int main(){

    int arr[] = {6,5,4,3,7,8,9};
    int n = 7;
    Node* root = buildBST(arr, 7);
    // inorder(root);
    // cout<<endl;
    // delNode(root, 3);
    // inorder(root);
    // cout<<endl;
    // printInRange(root, 1 , 5);
    // rootToLeaf(root);
    // root->data = 15;
    // cout<<validateBST(root);

    // Node* root = buildBSTFromSortedArray(arr, 0 , 4);
    // preorder(root);

    root = balanceBST(root);
    preorder(root);

}