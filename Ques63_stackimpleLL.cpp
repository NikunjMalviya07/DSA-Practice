#include<iostream>
#include<stack>
#include<list>
#include<string>

using namespace std;

// // using ll STL

// template<class T>
// class Stack{
//     list<T> ll;
// public:
//     void push(T val){
//         ll.push_front(val);
//         return;
//     }

//     void pop(){
//         ll.pop_front();
//         return;
//     }

//     T top(){
//         return ll.front();
//     }

//     bool isEmpty(){
//         return ll.size() == 0;
//     }
// };

// using ll without STL
template <class T>
class Node{
public:
    T data;
    Node<T>* next;

    Node(T val){
        data = val;
        next = NULL;
    }

};

template<class T>
class Stack{
    Node<T>* head;

public:

    Stack() {
        head = NULL;
    }

    void push(T val){
    // push_front
    Node<T>* newNode = new Node<T>(val);
    if(head == NULL){
        head = newNode;
    } else{
        newNode->next = head;
        head = newNode;
    }
        return;
    }

    void pop(){
        Node<T>* temp;
        temp = head;
        head = head->next;
        temp = NULL;
        delete temp;
        return;
    }

    T top(){
        if(head == NULL){
            return -1;
        }
        return head->data;
    }

    bool isEmpty(){
        return head == NULL;
    }

};

int main(){
    Stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);

    while(! s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}
