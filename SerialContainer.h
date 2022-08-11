#pragma once
#pragma once
template<class T> class SerialContainer
{

private:
	size_t m_size;	// Размер контейнера
	T* m_region;	// Область памяти с данными (массив)
	
public:
	SerialContainer()
	{
		m_size = 0;
		m_region = new T[0];
	}
	/// <summary>
	/// Вставка значения в конец контейнера
	/// </summary>
	/// <param name="value">Значение</param>
	void push_back(T value)
	{
		T* new_region = new T[m_size + 1]; // новая область памяти
		for (size_t i = 0; i < m_size; ++i) {
			new_region[i] = m_region[i]; // копирование элементов
		}
		new_region[m_size] = value; // добавление нового элемента
		delete[] m_region; // удаление старой области
		m_region = new_region; // сохранение новой в мембер
		m_size++; // обновление информации о размере
	}

	/// <summary>
	/// Вставка в элемента в контейнер в нужную позицию
	/// </summary>
	/// <param name="value">Значение для вставки</param>
	/// <param name="index">Позиция</param>
	void insert(T value, int index)
	{
		// Проверка на корректный индекс
		if ((index > m_size - 1) || (index < 0))
		{
			return;
		}
		// new memory region
		T* new_region = new T[m_size + 1];
		// Перемещение элементов до нужного индекса
		for (size_t i = 0; i < index; i++)
		{
			new_region[i] = m_region[i];
		}
		// Вставка нового элемента
		new_region[index] = value;
		// Перемещение оставшихся элементов
		for (int i = index + 1; i < m_size + 1; i++)
		{
			new_region[i] = m_region[i-1];
		}
		// Освобождение памяти и изменение размера
		delete[] m_region;
		m_region = new_region;
		m_size++;
	}

	/// <summary>
	/// Удаляет элемент с нужным индексом
	/// </summary>
	/// <param name="index">Индекс удаляемого элемента</param>
	void erase(int index)
	{
		// Проверка на корректный индекс
		if ((index > m_size - 1) || (index < 0))
		{
			return;
		}
		// новая область памяти
		T* new_region = new T[m_size - 1];
		// Перемещение элементов до нужного индекса
		for (size_t i = 0; i < index; i++)
		{
			new_region[i] = m_region[i];
		}
		// Перемещение оставшихся элементов, и пропуск эл-та с выбранным индексом
		for (size_t i = index; i < m_size-1; i++)
		{
			new_region[i] = m_region[i+1];
		}
		// Освобождение памяти и изменение размера
		delete[] m_region;
		m_region = new_region;
		m_size--;
	}

	/// <summary>
	/// Получение размера контейнера
	/// </summary>
	/// <returns>Размер контейнера</returns>
	size_t size()
	{
		return m_size;
	}

	/// <summary>
	/// Перегрузка оператора [] для обращения по индексу
	/// </summary>
	/// <param name="index">Индекс для обращения</param>
	/// <returns>Элемент с нужным индексом</returns>
	T operator[](int index)
	{
		return m_region[index];
	}

};

