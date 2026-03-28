#include<iostream>
#include<vector>
#include<queue>

using namespace std;

    // Lowest Common Ancestor

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

bool findPath(Node* root, int n,  vector<int> &path){
    if(root == NULL){
        return false;
    }

    path.push_back(root->data);
    if(root->data == n){
        return true;
    }

    int isLeft = findPath(root->left, n , path);
    int isRight = findPath(root->right, n, path);

    if(isLeft || isRight){
        return true;
    }

    path.pop_back();
    return false;
}

int LCA(Node* root, int n1, int n2){ // O(n) & O(n)
    vector<int> path1;
    vector<int> path2;
    
    findPath(root, n1, path1);
    findPath(root, n2, path2);
int lca = -1;
    for(int i = 0, j = 0; i<path1.size(), j<path2.size(); i++, j++){
        if(path1[i] != path2[j]){
            return lca;
        }
        lca = path1[i];
    }

    return lca;
}

Node* LCA2(Node* root, int n1, int n2){ // O(n) & O(1)

    if(root == NULL){
        return NULL;
    }
    
    if(root->data == n1 ||  root->data == n2){
        return root;
    }

    Node* leftLCA = LCA2(root->left, n1, n2);
    Node* rightLCA = LCA2(root->right, n1, n2);

    if(leftLCA != NULL && rightLCA != NULL){
        return root;
    }

    return leftLCA == NULL ? rightLCA : leftLCA; 
}

    // finding minimum distance

int distance(Node* root, int n){
    if(root == NULL){
        return -1;
    }

    if(root->data == n){
        return 0;
    }

    int leftD = distance(root->left , n);  
    if(leftD != -1){
        return leftD+1;
    }  
    
    int rightD = distance(root->right , n);    
    if(rightD != -1){
        return rightD+1;
    }
    
    return -1;
}

int minDistance(Node* root, int n1, int n2){

    Node* lca = LCA2(root, n1, n2);

    int distance1 = distance(lca , n1);
    int distance2 = distance(lca, n2);

    return distance1 + distance2;
}

int KthAncestor(Node* root, int node, int K){
    if(root == NULL){
        return -1;
    }

    if(root->data == node){
        return 0;
    }

    int leftD = KthAncestor(root->left, node, K);
    int rightD = KthAncestor(root->right, node, K);

    if(leftD == -1 && rightD == -1){
        return -1;
    }

    int validD = leftD == -1 ? rightD : leftD;
    if(validD != -1){
        if(validD + 1 == K){
            cout<<"Kth Ancestor: "<<root->data;
        }
        return validD+1;
    }

    return -1;
}

int transform(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftOld = transform(root->left);
    int rightOld = transform(root->right);

    int currOld = root->data;

    root->data = leftOld + rightOld;

    if(root->left != NULL){
        root->data+= root->left->data;
    }

    if(root->right != NULL){
        root->data+= root->right->data;
    }

    return currOld;
}

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

            // cout<<" Sum : "<<ans;
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


int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};

    Node* root = builtTree(nodes);
    transform(root);
    levelOrder(root);
    return 0;

}