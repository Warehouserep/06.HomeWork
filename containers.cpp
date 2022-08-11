#include <iostream>
#include "ListContainer.h"
#include "SerialContainer.h"

using namespace std;

void exampleSerial() 
{
	SerialContainer <int> sc;
	sc.push_back(0);
	sc.push_back(1);
	sc.push_back(2);
	sc.push_back(3);
	sc.push_back(4);
	sc.push_back(5);
	sc.push_back(6);
	sc.push_back(7);
	sc.push_back(8);
	sc.push_back(9);
	cout << "Container data:" << endl;
	for (int i = 0; i < sc.size(); i++)
	{
		cout << sc[i] << " ";
	}

	cout << endl << "Container size: " << sc.size() << endl;

	/*
		ВНИМАНИЕ! ОШИБКА В ЗАДАНИИ!
		...
		удаление третьего (по счёту), пятого и седьмого элементов
		вывод содержимого контейнера на экран
		ожидаемый результат: 0, 1, 3, 5, 7, 8, 9
		...
		РЕМАРКА:
		такой результат не получится, потому что метод erase меняет состояние области памяти (так и должно быть)
		Вначале удалится элемент с индексом 2 (по счету - 3) и со значением 2
		Затем удаляется элемент с индексом 4, НО(!) в нем уже хранится значение 5, т.к. оно сдвинулось предыдущим вызовом erase
		То же самое с индексом 6, но из-за двух вызовов смещение уже на 2
	*/
	cout << endl << "Deleting element in position 3, 5 and 7:" << endl;
	sc.erase(2);
	sc.erase(4);
	sc.erase(6);
	for (int i = 0; i < sc.size(); i++)
	{
		cout << i << ") " << sc[i] << endl;
	}
	cout << endl << "Insert 10 value to position 0" << endl;
	sc.insert(10, 0);
	cout << endl;

	for (int i = 0; i < sc.size(); i++)
	{
		cout << i << ") " << sc[i] << endl;
	}

	cout << endl << "Insert 20 value to position 4" << endl;
	sc.insert(20, 4);
	cout << endl;

	for (int i = 0; i < sc.size(); i++)
	{
		cout << i << ") " << sc[i] << endl;
	}

	cout << endl << "Insert 30 value to the end" << endl;
	sc.push_back(30);
	cout << endl;

	for (int i = 0; i < sc.size(); i++)
	{
		cout << i << ") " << sc[i] << endl;
	}
}

void exampleList()
{
	ListContainer<int> lc;
	lc.push_back(0);
	lc.push_back(1);
	lc.push_back(2);
	lc.push_back(3);
	lc.push_back(4);
	lc.push_back(5);
	lc.push_back(6);
	lc.push_back(7);
	lc.push_back(8);
	lc.push_back(9);
	cout << "Container data:" << endl;
	for (int i = 0; i < lc.size(); i++)
	{
		cout << lc[i] << " ";
	}

	cout << endl << "Container size: " << lc.size() << endl;

	cout << endl << "Deleting element in position 3, 5 and 7:" << endl;
	lc.erase(2);
	lc.erase(4);
	lc.erase(6);
	for (int i = 0; i < lc.size(); i++)
	{
		cout << i << ") " << lc[i] << endl;
	}
	cout << endl << "Container size: " << lc.size() << endl;

	cout << endl << "Insert 10 value to position 0" << endl;
	lc.insert(10, 0);

	for (int i = 0; i < lc.size(); i++)
	{
		cout << lc[i] << " ";
	}
	cout << endl;

	cout << endl << "Insert 20 value to position 4" << endl;
	lc.insert(20, 4);
	cout << endl;

	for (int i = 0; i < lc.size(); i++)
	{
		cout << i << ") " << lc[i] << endl;
	}

	cout << endl << "Insert 30 value to the end" << endl;
	lc.push_back(30);
	cout << endl;

	for (int i = 0; i < lc.size(); i++)
	{
		cout << i << ") " << lc[i] << endl;
	}
}

int main()
{
	//exampleSerial();
	exampleList();
	return 0;
}