#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        explicit Node(int d) : data(d), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList();

    ~LinkedList();

    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    bool insertAtPosition(int pos, int value);
    bool deleteValue(int value);
    bool search(int value) const;
    void display() const;
};

#endif // LINKEDLIST_H
