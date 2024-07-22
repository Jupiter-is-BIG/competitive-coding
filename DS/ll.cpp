#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(T data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

template<typename T>
class LinkedList {
public:
    Node* head;
    Node* tail;

    int size = 0;

    LinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    ~LinkedList() {
        while(size) {
            remove();
        }
    }

    void add(T data) {
        Node* newNode = new Node(data);
        if (size == 0) {head = newNode; tail = newNode;}
        else {
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void remove() {
        if (size == 0) return;
        if (size == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            size--;
        } else {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
    }


};
