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
    //  triversal
void preorder(Node* root){ // O(n)

    if(root == NULL){
        return;
    }

    cout<< root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

    // inorder
void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
    
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
    // levelOrder steps
void levelOrder(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> Q;
    Q.push(root);
    Q.push(NULL); 

    int ans = 0;

    while(!Q.empty()){

        if(root == NULL){
            return;
        }

        Node* curr = Q.front();
        Q.pop();

        if(curr == NULL){

            cout<<" Sum : "<<ans;
            ans = 0;
            cout<<endl;

            if(Q.empty()){
                break;
            }
            Q.push(NULL);

        }else{

        cout<<curr->data<<" ";
        ans+= curr->data;

        if(curr->left != NULL){
            Q.push(curr->left);
        }

        if(curr->right != NULL){
            Q.push(curr->right);
        }
        }
    }
}

    // level order normal
void levelOrder1(Node* root){
    if(root == NULL){
        return;
    }

    queue<Node*> Q;
    Q.push(root);

    int ans = 0;
    
    while(!Q.empty()){

        if(root == NULL){
            return;
        }

        Node* curr = Q.front();
        Q.pop();

        cout<<curr->data<<" ";

        if(curr->left != NULL){
            Q.push(curr->left);
        }

        if(curr->right != NULL){
            Q.push(curr->right);
        }
    }
}

int height(Node* root){

    if(root == NULL){
        return 0;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    int currHeight = max(leftHt, rightHt) + 1;

    return currHeight;

}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node* root = builtTree(nodes);
 
    levelOrder(root);

    return 0;
}