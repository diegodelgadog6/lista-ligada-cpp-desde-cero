#include "LinkedList.h"

// Constructor: lista vacía (head = nullptr).
LinkedList::LinkedList() : head(nullptr) {}

// Destructor: recorre y libera todos los nodos creados con new.
LinkedList::~LinkedList() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* toDelete = curr;
        curr = curr->next;
        delete toDelete;
    }
    head = nullptr;
}

// display(): recorre desde head hasta nullptr e imprime cada data.
// Importante: avanzar siempre curr = curr->next para evitar bucles.
void LinkedList::display() const {
    std::cout << "head -> ";
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " -> ";
        curr = curr->next;
    }
    std::cout << "null\n";
}

// insertAtBeginning(value):
// Inserta al frente en 3 pasos (no requiere if especial para lista vacía).
void LinkedList::insertAtBeginning(int value) {
    Node* node = new Node(value); // 1) crear nodo
    node->next = head;            // 2) apuntar al head actual
    head = node;                  // 3) mover head al nuevo nodo
}

// insertAtEnd(value):
// Caso A: lista vacía -> head = node.
// Caso B: recorrer hasta el último (next == nullptr) y enlazar.
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

// insertAtPosition(pos, value) [0-based]:
// Inserta ANTES del elemento en 'pos'. Maneja pos==0 y fuera de rango.
bool LinkedList::insertAtPosition(int pos, int value) {
    if (pos < 0) {
        std::cerr << "[Error] Posición negativa.\n";
        return false;
    }
    if (pos == 0) {
        insertAtBeginning(value);
        return true;
    }

    // Avanzar hasta el nodo anterior a 'pos' (índice pos-1).
    int idx = 0;
    Node* curr = head;
    while (curr != nullptr && idx < pos - 1) {
        curr = curr->next;
        idx++;
    }

    if (curr == nullptr) {
        // Llegamos a nullptr antes de alcanzar pos-1 => fuera de rango.
        std::cerr << "[Error] Posición fuera de rango.\n";
        return false;
    }

    Node* node = new Node(value);
    node->next = curr->next; // puede ser nullptr (apéndice)
    curr->next = node;
    return true;
}

// deleteValue(value):
// Elimina la primera aparición. Maneja eliminar head y nodos intermedios/últimos.
bool LinkedList::deleteValue(int value) {
    if (head == nullptr) return false; // lista vacía

    // Caso: el primer nodo (head) contiene el valor
    if (head->data == value) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return true;
    }

    // Buscar nodo previo al que se quiere eliminar
    Node* prev = head;
    Node* curr = head->next;
    while (curr != nullptr && curr->data != value) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr) {
        // No encontrado
        return false;
    }

    // Desenlazar y borrar
    prev->next = curr->next;
    delete curr;
    return true;
}

// search(value):
// Recorre nodo a nodo; si encuentra value -> true, si termina -> false.
bool LinkedList::search(int value) const {
    Node* curr = head;
    while (curr != nullptr) {
        if (curr->data == value) return true;
        curr = curr->next;
    }
    return false;
}
