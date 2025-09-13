#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

/**
 * Lista ligada simple de enteros.
 * - Cada Node guarda un valor (data) y la dirección del siguiente (next).
 * - head apunta al primer nodo; si la lista está vacía, head == nullptr.
 * Propósito: practicar punteros, inserción/eliminación y recorridos.
 * Complejidades típicas:
 *   insertAtBeginning  O(1)
 *   insertAtEnd        O(n)
 *   insertAtPosition   O(n)
 *   deleteValue        O(n)
 *   search             O(n)
 *   display            O(n)
 */
class LinkedList {
private:
    /** Nodo interno: dato + puntero al siguiente nodo. */
    struct Node {
        int data;
        Node* next;
        explicit Node(int d) : data(d), next(nullptr) {}
    };

    /** Apuntador al primer nodo de la lista (o nullptr si está vacía). */
    Node* head;

public:
    /** Constructor: inicia la lista vacía (head = nullptr). */
    LinkedList();

    /** Destructor: libera todos los nodos para evitar fugas de memoria. */
    ~LinkedList();

    /**
     * insertAtBeginning(value)
     * Inserta un nuevo nodo al inicio de la lista.
     * Lógica: crear nodo -> node->next = head -> head = node.
     * Complejidad: O(1)
     */
    void insertAtBeginning(int value);

    /**
     * insertAtEnd(value)
     * Inserta un nodo al final.
     * Casos: lista vacía (head = node) o recorrer hasta el último y enlazar.
     * Complejidad: O(n)
     */
    void insertAtEnd(int value);

    /**
     * insertAtPosition(pos, value)   [0-based]
     * Inserta un nodo ANTES del elemento que actualmente está en 'pos'.
     * Reglas:
     *   - pos < 0  -> error, no inserta (false).
     *   - pos == 0 -> reutiliza insertAtBeginning (true).
     *   - 0 < pos  -> recorrer hasta el nodo previo (pos-1) y "enchufar" el nuevo.
     *   - Si pos es exactamente tamaño actual, inserta como apéndice (al final).
     *   - Si se sale del rango, no inserta (false).
     * Complejidad: O(n)
     */
    bool insertAtPosition(int pos, int value);

    /**
     * deleteValue(value)
     * Elimina la PRIMERA aparición de 'value'.
     * Casos: lista vacía; head contiene el valor; valor en medio/último; no encontrado.
     * Complejidad: O(n)
     * Retorna: true si eliminó; false si no lo encontró.
     */
    bool deleteValue(int value);

    /**
     * search(value)
     * Devuelve true si 'value' está en la lista; false si no.
     * Complejidad: O(n)
     */
    bool search(int value) const;

    /**
     * display()
     * Muestra los elementos en orden: "head -> a -> b -> ... -> null".
     * Complejidad: O(n)
     */
    void display() const;

    // (Opcional) podrías agregar un size() O(n) si lo necesitas para depurar.
};

#endif // LINKEDLIST_H
