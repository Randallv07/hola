#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstddef>
#include <stdexcept>

#include "node.h"


// Crear una clase templada para la lista enlazada
template <class T>
class LinkedList {
	private:
		// Tamanio de la lista
		int size;
		// Nodo inicial de la lista
		Node<T>* head;
	public:
		// Constructor de la clase
		LinkedList();
		// Destructor de la clase
		~LinkedList();
		// Insertar en una posicion especifica
		void add(T value, int index);
		// Insertar al inicio
		void add_first(T value);
		// Insertar al final
		void add_last(T value);
		// Eliminar todos los elementos
		void clear();
		// Crea una copia
		LinkedList<T> clone();
		// Verificar si un elemento existe
		bool contains(T value);
		// Obtener el elemento en una posicion especifica
		T get(int pos);
		// Obtener el primer elemento
		T get_first();
		// Obtener el ultimo elemento
		T get_last();
		// Obtener el tamanio
		int get_size();
		// Obtener la posicion donde aparece por primer vez un elemento
		int index_of(T value);
		// Eliminar el elemento
		T remove(T value);
		// Eliminar el primer elemento
		T remove_first();
		// Eliminar el ultimo elemento
		T remove_last();
};

// Constructor de la clase
template <class T>
LinkedList<T>::LinkedList() {
    // Cuando se crea la lista esta vacia, por lo que el tamanio es 0
	this->size = 0;
	// Como no hay elementos la cabeza es NULL
	this->head = NULL;
}

// Destructor de la clase
template <class T>
LinkedList<T>::~LinkedList() {
    clear();
    delete head;
}

template <class T>
void LinkedList<T>::add(T value, int index) {
    // Si la posicion esta fuera del rango no inserta
	if ((index < 0) || (index > this->size)) {
		return;
	}
	// Si se quiere insertar en la primer posicion
	else if (index == 0) {
	    // Se llama al metodo que se implemento para eso
	    this->add_first(value);
    } else {
    	// Nodo temporal para guardar la cabeza
    	Node<T>* temp = this->head;
    	// Recorrer hasta llegar a la posicion
    	for (int i=0; i < index - 1; i++) {
    		temp = temp->get_next();
    	}
    	// Agregar el nuevo nodo
    	temp->set_next(new Node<T>(value));
    	// Aumentar el tamanio
    	this->size++;
    	// Apuntar a NULL y borrar
    	temp = NULL;
    	delete temp;
    }
}

template <class T>
void LinkedList<T>::add_first(T value) {
    // Se crea un nodo con el valor
	Node<T>* new_node = new Node<T>(value);
	// Se pono todo el resto de la lista como siguiente del nuevo nodo
	new_node->set_next(this->head);
	// Se pone el nodo como cabeza, lo cual lo pone de primero
	this->head = new_node;
	// Se aumenta el tamanio
	this->size++;
	// Se pone el puntero en NULL para ser borrado
	new_node = NULL;
	// Se borrra el nodo
	delete new_node;
}

template <class T>
void LinkedList<T>::add_last(T value) {
	// Si la cabeza esta vacia se inserta ahi
	if (this->head == NULL) {
	    this->head = new Node<T>(value);
    } else {
    	// Nodo temporal para guardar la cabeza
    	Node<T>* temp = this->head;
    	// Recorrer hasta llegar al ultimo
    	while (temp->get_next()) {
    		temp = temp->get_next();
    	}
    	// Agregar el nuevo nodo
    	temp->set_next(new Node<T>(value));
    	// Aumentar el tamanio
    	this->size++;
    	// Apuntar a NULL y borrar
    	temp = NULL;
    	delete temp;
    }
}

template <class T>
void LinkedList<T>::clear() {
    // Limpiar la memoria
    for (int i=0; i<this->size; i++) {
        Node<T>* aux = this->head;
        this->head = this->head->get_next();
        delete aux;
    }
    this->size = 0;
}

template <class T>
LinkedList<T> LinkedList<T>::clone() {
    // Copia de la lista
    LinkedList<T> copy;
    // Temporal para recorrer la lista
    Node<T>* aux = this->head;
    while (aux) {
        // Agregar el valor a la lista
        copy.add_last(aux->get_value());
        // Siguiente elemento
        aux = aux->get_next();
    }
    // Borrar el puntero
    delete aux;
    
    return copy;
}

template <class T>
bool LinkedList<T>::contains(T value) {
    // Temporal para recorrer la lista
    Node<T>* aux = this->head;
    while (aux) {
        // Comparar el valor buscado con el del nodo actual
        if (aux->get_value() == value) {
            aux = NULL;
            delete aux;
            return true;
        }
        // Siguiente elemento
        aux = aux->get_next();
    }
    // Borrar el puntero
    delete aux;
    
    return false;
}

template <class T>
T LinkedList<T>::get(int pos) {
    // Si la posicion esta fuera del rango retorna NULL
	if ((pos < 0) || (pos >= this->size)) {
		return NULL;
	}
	// Nodo temporal para guardar la cabeza
	Node<T>* temp = head;
	// Recorrer hasta llegar a la posicioin
	for (int i=0; i < pos; i++) {
		temp = temp->get_next();
	}
	// Obtener el valor en el nodo
	T value = temp->get_value();
	// Apuntar el nodo a NULL y borrarlo
	temp = NULL;
	delete temp;
	
	return value;
}

template <class T>
T LinkedList<T>::get_first() {
    // Si hay un elemento en la cabeza
    if (this->head) {
        return this->head->get_value();
    }
	return NULL;
}

template <class T>
T LinkedList<T>::get_last() {
    // Obtener el ultimo elemento de la lista
    return this->get(this->size - 1);
}

// Simplemente retorna el tamanio de la lista
template <class T>
int LinkedList<T>::get_size() {
	return this->size;
}

template <class T>
int LinkedList<T>::index_of(T value) {
	// Temporal para recorrer la lista
    Node<T>* aux = this->head;
    int index = 0;
    while (aux) {
        // Comparar el valor buscado con el del nodo actual
        if (aux->get_value() == value) {
            aux = NULL;
            delete aux;
            return index;
        }
        // Siguiente elemento
        aux = aux->get_next();
        index++;
    }
    // Borrar el puntero
    delete aux;
    
    return -1;
}

template <class T>
T LinkedList<T>::remove(T value) {
	// Temporal para recorrer la lista
    Node<T>* aux = this->head;
    Node<T>* previous = NULL;
    while (aux) {
        // Comparar el valor buscado con el del nodo actual
        if (aux->get_value() == value) {
            // Eliminar el elemento de la posicion
            if (previous) {
                previous->set_next(aux->get_next());
            } else {
                this->head = aux->get_next();
            }
            // Obtener el valor
            T value = aux->get_value();
            // Limpiar la memoria
            previous = NULL;
            delete previous;
            delete aux;
            // Disminuir tamanio
            this->size--;
            return value;
        }
        // Siguiente elemento
        previous = aux;
        aux = aux->get_next();
    }
    // Borrar el puntero
    previous = NULL;
    delete previous;
    delete aux;
    
    return NULL;
}

template <class T>
T LinkedList<T>::remove_first() {
    if (this->size == 0) {
        return NULL;
    }
	// Temporal para recorrer la lista
    Node<T>* aux = this->head;
    this->head = this->head->get_next();
    // Guardar el valor
    T value = aux->get_value();
    // Borrar el puntero
    delete aux;
    // Disminuir tamanio
    this->size--;
    
    return value;
}

template <class T>
T LinkedList<T>::remove_last() {
    if (this->size == 0) {
        return NULL;
    }
	// Temporal para recorrer la lista
    Node<T>* aux = this->head;
    Node<T>* previous = NULL;
    while (aux->get_next()) {
        // Siguiente elemento
        previous = aux;
        aux = aux->get_next();
    }
    // Eliminar el elemento de la posicion
    if (previous) {
        previous->set_next(aux->get_next());
    } else {
        this->head = aux->get_next();
    }
    // Obtener el valor
    T value = aux->get_value();
    // Limpiar la memoria
    previous = NULL;
    delete previous;
    delete aux;
    // Disminuir tamanio
    this->size--;
    return value;
}

#endif  /* LINKEDLIST_H */
