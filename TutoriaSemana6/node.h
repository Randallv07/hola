#ifndef NODE_H
#define NODE_H

#include <cstddef>

template <class T>
class Node {
	private:
		T value;
		Node<T>* next;
	public:
	    // Constructors
		Node(T value);
		Node<T>* get_next();
		T get_value();
		void set_next(Node<T>* node);
		void set_value(T value);
};

template <class T>
Node<T>::Node(T value) {
	this->value = value;
	this->next = NULL;
}

template <class T>
Node<T>* Node<T>::get_next() {
	return this->next;
}

template <class T>
T Node<T>::get_value() {
	return this->value;
}

template <class T>
void Node<T>::set_next(Node<T>* node) {
	this->next = node;
}

template <class T>
void Node<T>::set_value(T value) {
	this->value = value;
}

#endif  /* NODE_H */
