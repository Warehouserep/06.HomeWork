#pragma once
#pragma once
template<class T> class SerialContainer
{

private:
	size_t m_size;	// ������ ����������
	T* m_region;	// ������� ������ � ������� (������)
	
public:
	SerialContainer()
	{
		m_size = 0;
		m_region = new T[0];
	}
	/// <summary>
	/// ������� �������� � ����� ����������
	/// </summary>
	/// <param name="value">��������</param>
	void push_back(T value)
	{
		T* new_region = new T[m_size + 1]; // ����� ������� ������
		for (size_t i = 0; i < m_size; ++i) {
			new_region[i] = m_region[i]; // ����������� ���������
		}
		new_region[m_size] = value; // ���������� ������ ��������
		delete[] m_region; // �������� ������ �������
		m_region = new_region; // ���������� ����� � ������
		m_size++; // ���������� ���������� � �������
	}

	/// <summary>
	/// ������� � �������� � ��������� � ������ �������
	/// </summary>
	/// <param name="value">�������� ��� �������</param>
	/// <param name="index">�������</param>
	void insert(T value, int index)
	{
		// �������� �� ���������� ������
		if ((index > m_size - 1) || (index < 0))
		{
			return;
		}
		// new memory region
		T* new_region = new T[m_size + 1];
		// ����������� ��������� �� ������� �������
		for (size_t i = 0; i < index; i++)
		{
			new_region[i] = m_region[i];
		}
		// ������� ������ ��������
		new_region[index] = value;
		// ����������� ���������� ���������
		for (int i = index + 1; i < m_size + 1; i++)
		{
			new_region[i] = m_region[i-1];
		}
		// ������������ ������ � ��������� �������
		delete[] m_region;
		m_region = new_region;
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
		// ����� ������� ������
		T* new_region = new T[m_size - 1];
		// ����������� ��������� �� ������� �������
		for (size_t i = 0; i < index; i++)
		{
			new_region[i] = m_region[i];
		}
		// ����������� ���������� ���������, � ������� ��-�� � ��������� ��������
		for (size_t i = index; i < m_size-1; i++)
		{
			new_region[i] = m_region[i+1];
		}
		// ������������ ������ � ��������� �������
		delete[] m_region;
		m_region = new_region;
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
		return m_region[index];
	}

};

