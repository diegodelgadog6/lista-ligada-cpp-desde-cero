#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* toDelete = curr;
        curr = curr->next;
        delete toDelete;
    }
    head = nullptr;
}

void LinkedList::display() const {
    std::cout << "head -> ";
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " -> ";
        curr = curr->next;
    }
    std::cout << "null\n";
}

void LinkedList::insertAtBeginning(int value) {
    Node* node = new Node(value); 
    node->next = head;           
    head = node;                 
}

void LinkedList::insertAtEnd(int value) {
    Node* node = new Node(value);
    if (head == nullptr) {
        head = node;
        return;
    }
    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = node;
}

bool LinkedList::insertAtPosition(int pos, int value) {
    if (pos < 0) {
        std::cerr << "[Error] Posición negativa.\n";
        return false;
    }
    if (pos == 0) {
        insertAtBeginning(value);
        return true;
    }

    int idx = 0;
    Node* curr = head;
    while (curr != nullptr && idx < pos - 1) {
        curr = curr->next;
        idx++;
    }

    if (curr == nullptr) {
        std::cerr << "[Error] Posición fuera de rango.\n";
        return false;
    }

    Node* node = new Node(value);
    node->next = curr->next;
    curr->next = node;
    return true;
}

bool LinkedList::deleteValue(int value) {
    if (head == nullptr) return false;
    
    if (head->data == value) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return true;
    }

    Node* prev = head;
    Node* curr = head->next;
    while (curr != nullptr && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        return false;
    }

    prev->next = curr->next;
    delete curr;
    return true;
}

bool LinkedList::search(int value) const {
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->data == value) return true;
        curr = curr->next;
    }
    return false;
}
