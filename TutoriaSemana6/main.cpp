#include <iostream>
#include "linkedlist.h"

#define SIZE 10

using namespace std;

void show_list(LinkedList<int> list) {
    for (int i=0; i < list.get_size(); i++) {
	    cout << i << ":" << list.get(i) << endl;
    }
}

int main() {
    // Clear la lista
	LinkedList<int> list;
	// Agregar elementos a la lista
	for (int i=0; i < SIZE; i++) {
	    list.add(i*i+1, i);
    }
    // Agregar al inicio y al final
    list.add_last(10);
    list.add_first(-1);
    
    cout << "Elements:" << endl;
    show_list(list);
    
    // Copiar
    LinkedList<int> copy = list.clone();
    cout << "Copy:" << endl;
    show_list(copy);
    
    // Borrar los elementos de la lista
    copy.clear();
    cout << "Cleared list\nSize: " << copy.get_size() << endl;
    
    // Verificar si un elemento esta en la lista
    cout << "3 is in list? " << list.contains(3) << endl;
    cout << "37 is in list? " << list.contains(37) << endl;
    
    // Obtener el primero y ultimo elemento
    cout << "First: " << list.get_first() << endl;
    cout << "Second: " << list.get_last() << endl;
    
    // Obtener el indice de un valor
    cout << "Index of 3: " << list.index_of(3) << endl;
    cout << "Index of 37: " << list.index_of(37) << endl;
    
    // Borrar un elemento
    cout << "Delete 37: " << list.remove(10) << endl;
    cout << "Delete first: " << list.remove_first() << endl;
    cout << "Delete first: " << list.remove_first() << endl;
    cout << "Delete last: " << list.remove_last() << endl;
    cout << "Delete last: " << list.remove_last() << endl;
    
    // Final list
    show_list(list);
    
	return 0;
}

