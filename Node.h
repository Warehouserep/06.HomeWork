#pragma once
template <typename T> struct Node {
	Node<T>* next; // ��������� �� ��������� ������� Node
	Node<T>* prev; // ��������� �� ���������� ������� Node
	T data; // ���������������� ������ (�������� ������)
};

