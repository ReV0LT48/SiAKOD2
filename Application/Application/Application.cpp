#include "pch.h"
#include <iostream>
#include <ctime>

void fill_arr(int* arr, short sz);
void get_order(const int* arr1, int* arr2, short sz);
void get_reorder(const int* arr1, int* arr2, short sz);
void insertion_sort(int* arr, short sz);
void sort_by_selection(int* arr, short sz);
void bubble_sort(int* arr, short sz);
void swap_el(int* arr, int i);

int main()
{
	using namespace std;
	setlocale(0, "");
	cout << "Введите размер массива --> ";
	short size;
	cin >> size;
	int* ordered_arr = new int[size];
	int* reordered_arr = new int[size];
	int* disordered_arr = new int[size];
	fill_arr(disordered_arr, size); //Заполнения неупорядоченного массива
	get_order(disordered_arr, ordered_arr, size); //Заполнение "упорядоченного" массива этими значениями и их упорядочивание
	get_reorder(ordered_arr, reordered_arr, size); //Заполнение "упорядоченного в обратном порядке" массива значениями "упорядоченного массива" и их упорядочивание в обратном порядке
	

	return 0;
}

void fill_arr(int* arr, const short sz)
{
	using namespace std;
	setlocale(0, "");
	cout << "Введите значения элементов массива:\n";
	for (int i = 0; i < sz; i++)
	{
		cout << "[" << i << "] --> ";
		cin >> arr[i];
	}
}

void swap_el(int* arr, int i)
{
	int help;
	help = arr[i - 1];
	arr[i - 1] = arr[i];
	arr[i] = help;
}

void get_order(const int* arr1, int* arr2, const short sz)
{
	int hp;
	for (int i = 0; i < sz; i++)
	{
		arr2[i] = arr1[i];
	}
	for (int i = 1; i < sz; i++)
	{
		for (int j = i; j > 0 && arr2[j - 1] > arr2[j]; j--)
		{
			hp = arr2[j - 1];
			arr2[j - 1] = arr2[j];
			arr2[j] = hp;
		}
	}
}

void get_reorder(const int* arr1, int* arr2, short sz)
{
	int hp;
	int count = 0;
	for (int i = 0; i < sz; i++)
	{
		arr2[i] = arr1[i];
	}
	while (count != sz - 1)
	{
		for (int j = sz - 1; j > 0 && arr2[j] > arr2[j - 1]; j--)
		{
			hp = arr2[j - 1];
			arr2[j - 1] = arr2[j];
			arr2[j] = hp;
		}
		count++;
	}
}

void insertion_sort(int* arr, short sz)
{
	int hp;
	for (int i = 1; i < sz; i++)
	{
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
		{
			hp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = hp;
		}
	}
}

void sort_by_selection(int* arr, short sz)
{
	int value, key;
	for (int i = 0; i < sz - 1; i++)
	{
		value = arr[i];
		key = i;
		for (int j = i + 1; j < sz; j++)
			if (arr[j] < arr[key])
				key = j;
		if (key != i)
		{
			arr[i] = arr[key];
			arr[key] = value;
		}
	}
}

void bubble_sort(int* arr, short sz)
{
	int hp;
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = (sz - 1); j > i; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				hp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = hp;
			}
		}
	}
}