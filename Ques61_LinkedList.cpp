#include<iostream>
using namespace std;

class Node{
public: 
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }

    ~Node(){
        if(next != NULL){
        // nothing
        }
    }
};

class List{
public:
    Node*  head;
    Node*  tail;

    List(){
        head = NULL;
        tail = NULL;
    }

    ~List(){
        if(head!=NULL){
            //cout<<"del"<<endl;
            delete head;
            head = NULL;
        }
    }

    void printList(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        
        if(head == NULL){
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }  
    }

    void push_back(int val){
        Node* newNode = new Node(val);

        if(head == NULL){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void insertAtMiddle(int val , int pos){
        Node*  newNode = new Node(val);

        Node* temp = head;
        for(int i=0;i<pos-1;i++){
            temp = temp->next;
            if(temp == NULL){
                cout<<"position is INVALID"<<endl;
                return;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front(){
        if (head == NULL) {
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = tail = NULL;
        return;
    }

        Node* temp = head;
        head = temp->next;
        delete temp;
    }

    void pop_back(){
        // handle single element and no element case
        if(head == NULL){
            return;
        }
        if(head -> next == NULL){
            delete head;
            head = tail = NULL;
            return;
        }
        Node* temp = head;

        while(temp->next->next != NULL){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        tail = temp;
    }

    int itrSearch(int val){
        Node* temp = head;
        int idx = 0;
        while(temp != NULL){
            if(temp->data == val){
                return idx;
            }
            temp=temp->next;
            idx++;
        }

        return -1;
    }

    int recursiveSearchHelper(int val , Node* temp){
        if(temp == NULL){
            return -1;
        }
        if(temp->data == val){
            return 0;
        }

        int idx = recursiveSearchHelper( val , temp->next);
        if(idx == -1){
            return -1;
        }
        return idx + 1;
    }

    int recursiveSearch(int val){
        return recursiveSearchHelper(val , head);
    }

    void reverseLinkedList(){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    int size(){
        int sz = 0;
        Node* temp = head;
        while(temp!=NULL){
            temp=temp->next;
            sz++;
        }

        return sz;
    }

    void removeNth(int n){
        int sz = size();
        Node* temp = head;
        
        for(int i = 1 ; i < sz - (n+1) + 1 ; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }

    //  two to call a palindrome reverse linkedlist function

    Node* reverseLinkedList2(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void reverseLinkedList3(Node*& head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }


    bool isPalindrome(){
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* mid = slow;
        reverseLinkedList3(mid);
        Node* left = head;
        Node* right = mid;
        while(left->next != NULL){
            if(left->data == right->data){
                left = left->next;
                right = right->next;
            } else {
                return false;
            }
        }
        return true;
    }
};

int main(){

    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(2);
    ll.push_front(1);
  //  ll.push_front(1);
    cout << ll.isPalindrome();

}