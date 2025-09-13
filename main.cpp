#include "LinkedList.h"
#include <iostream>
using namespace std;

int main() {
    LinkedList L;

    cout << "\n-- inicio (vacia) --\n";
    L.display();                       // esperado: head -> null

    cout << "\n-- insertAtBeginning --\n";
    L.insertAtBeginning(10);           // [10]
    L.insertAtBeginning(20);           // [20,10]
    L.display();                       // esperado: head -> 20 -> 10 -> null

    cout << "\n-- insertAtEnd --\n";
    L.insertAtEnd(30);                 // [20,10,30]
    L.display();                       // esperado: head -> 20 -> 10 -> 30 -> null

    cout << "\n-- insertAtPosition(1, 15) --\n";
    L.insertAtPosition(1, 15);         // [20,15,10,30]
    L.display();                       // esperado: head -> 20 -> 15 -> 10 -> 30 -> null

    cout << "\n-- search --\n";
    cout << "search(15): " << (L.search(15) ? "true" : "false") << "\n"; // true
    cout << "search(99): " << (L.search(99) ? "true" : "false") << "\n"; // false

    cout << "\n-- deleteValue(20) --\n";
    L.deleteValue(20);                 // quita el head si es 20
    L.display();                       // esperado: head -> 15 -> 10 -> 30 -> null

    return 0;
}
