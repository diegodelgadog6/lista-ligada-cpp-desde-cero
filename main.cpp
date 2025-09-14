#include "LinkedList.h"
#include <iostream>
using namespace std;

int main() {
    LinkedList L;

    cout << "\n-- inicio (vacia) --\n";
    L.display();                       

    cout << "\n-- insertAtBeginning --\n";
    L.insertAtBeginning(10);           
    L.insertAtBeginning(20);          
    L.display();                      

    cout << "\n-- insertAtEnd --\n";
    L.insertAtEnd(30);                
    L.display();                      

    cout << "\n-- insertAtPosition(1, 15) --\n";
    L.insertAtPosition(1, 15);         
    L.display();                       

    cout << "\n-- search --\n";
    cout << "search(15): " << (L.search(15) ? "true" : "false") << "\n";
    cout << "search(99): " << (L.search(99) ? "true" : "false") << "\n";

    cout << "\n-- deleteValue(20) --\n";
    L.deleteValue(20);                
    L.display();                     

    return 0;
}
