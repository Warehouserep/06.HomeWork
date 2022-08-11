#pragma once
template <typename T> struct Node {
	Node<T>* next; // указатель на следующий элемент Node
	Node<T>* prev; // указатель на предыдущий элемент Node
	T data; // пользовательские данные (хранимый объект)
};

