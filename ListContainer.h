#pragma once
#include "Node.h"
template <class T> class ListContainer
{
private:
	int m_size;
	Node <T>* m_first;
	Node <T>* m_last;
public:
	ListContainer()
	{
		m_first = nullptr;
		m_last = nullptr;
		m_size = 0;
	}

	void push_back(T value) 
	{
		Node<T>* new_node = new Node<T>;	// �������� ������ ����
					// ��������� ���������������� ������
		// ���� ������ ��� ����, �� ����������� �������� �� �������� ���, � ����������� ������� �������� ������
		new_node->next = nullptr;
		new_node->data = value;
		if (m_first == nullptr)
		{
			new_node->prev = nullptr;
			m_first = new_node;
			m_last = new_node;
		}
		else {
			new_node->prev = m_last;			// ���������� ��������� ������ ���������
			m_last = new_node;	
			m_last->prev->next = m_last;
		}
		
		m_size++;							// ��������� ������
	}

	void insert(T value, int index)
	{
		// �������� �� ���������� ������
		if ((index > m_size - 1) || (index < 0))
		{
			return;
		}// new memory region
		
		Node <T>* buffer_node = this->m_first;
		for (size_t i = 0; i < index; i++)
		{
			buffer_node = buffer_node->next;
		}
		Node <T>* new_node = new Node<T>;
		new_node->data = value;
		new_node->next = buffer_node;
		if (buffer_node->prev != nullptr)
		{
			new_node->prev = buffer_node->prev;
			buffer_node->prev->next = new_node;
		}
		else {
			new_node->prev = nullptr;
			m_first = new_node;
		}
		m_size++;
	}

	/// <summary>
	/// ������� ������� � ������ ��������
	/// </summary>
	/// <param name="index">������ ���������� ��������</param>
	void erase(int index)
	{
		// �������� �� ���������� ������
		if ((index > m_size - 1) || (index < 0))
		{
			return;
		}


		Node <T>* buffer_node = this->m_first;
		for (size_t i = 0; i < index; i++)
		{
			buffer_node = buffer_node->next;
		}
		buffer_node->prev->next = buffer_node->next;
		buffer_node->next->prev = buffer_node->prev;
		m_size--;
	}

	/// <summary>
	/// ��������� ������� ����������
	/// </summary>
	/// <returns>������ ����������</returns>
	size_t size()
	{
		return m_size;
	}

	/// <summary>
	/// ���������� ��������� [] ��� ��������� �� �������
	/// </summary>
	/// <param name="index">������ ��� ���������</param>
	/// <returns>������� � ������ ��������</returns>
	T operator[](int index)
	{
		
		Node <T>* buffer_node = this->m_first;
		for (size_t i = 0; i < index; i++)
		{
			buffer_node = buffer_node->next;
		}
		return buffer_node->data;
	}


};

