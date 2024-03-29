#include "pch.h"
#include <iostream>

void fill_arr(int* arr, short sz); //Заполнение массива
void get_disordered_arr(const int* arr1, int* arr2, const short sz); //Заполнения неупорядоченного массива
void swap_el(int* arr, int i); //Обмен элементами
void get_order(const int* arr1, int* arr2, short sz); //Заполнение "упорядоченного" массива этими значениями и их упорядочивание
void get_reorder(const int* arr1, int* arr2, short sz); //Заполнение "упорядоченного в обратном порядке" массива значениями "упорядоченного массива" и их упорядочивание в обратном порядке
void show(const int* arr, short sz); //Вывести элементы массива
unsigned insertion_sort(int* arr, short sz); //Сортировка вставками
unsigned sort_by_selection(int* arr, short sz); //Сортировка выбором
unsigned bubble_sort(int* arr, short sz); //Сортировка обменом
unsigned better_bubble_sort1(int* arr, short sz); //Улучшенная сортировка обменом 1
unsigned better_bubble_sort2(int* arr, short sz); //Улучшенная сортировка обменом 2
unsigned shell_sort(int* arr, short sz); //Сортировка Шелла
unsigned hoara_sort(int* arr, int first, int last); //Сортировка Хоара
unsigned make_heap(int* arr, int root, int bottom); //Построение пирамиды
unsigned heap_sort(int* arr, short sz); //Пирамидальная сортировка

int main()
{
    using namespace std;
    setlocale(0, "");
    cout << "Программа анализа эффективности различных сортировок\n";
    cout << "массивов с разным количеством элементов\n";
    cout << "Нажмите /enter/ чтобы начать";
    while (cin.get() != 'q')
    {
        cout << "\nВведите размер массива --> ";
        short size;
        cin >> size;
        int* default_arr = new int[size];
        fill_arr(default_arr, size);
        cin.clear();
        /////////////////Анализ сортировки вставками/////////////////
        cout << "Анализ сортировки вставками\n";
        int* ordered_arr = new int[size];
        int* reordered_arr = new int[size];
        int* disordered_arr = new int[size];
        get_disordered_arr(default_arr, disordered_arr, size);
        get_order(disordered_arr, ordered_arr, size);
        get_reorder(ordered_arr, reordered_arr, size);
        cout << "Упорядоченный массив размера " << size << ":\n";
        cout << "Сортировка вставками: " << insertion_sort(ordered_arr, size);
        cout << "\nУпорядоченный в обратном порядке массив размера " << size << ":\n";
        cout << "Сортировка вставками: " << insertion_sort(reordered_arr, size);
        cout << "\nНеупорядоченный массив размера " << size << ":\n";
        cout << "Сортировка вставками: " << insertion_sort(disordered_arr, size);
        show (disordered_arr, size);
        cout << endl;
        show (ordered_arr, size);
        cout << endl;
        show (reordered_arr, size);
        cout << endl;
        delete[] ordered_arr;
        delete[] reordered_arr;
        delete[] disordered_arr;
        /////////////////Анализ сортировки выбором/////////////////
        cout << "\n\n\nАнализ сортировки выбором";
        ordered_arr = new int[size];
        reordered_arr = new int[size];
        disordered_arr = new int[size];
        get_disordered_arr(default_arr, disordered_arr, size);
        get_order(disordered_arr, ordered_arr, size);
        get_reorder(ordered_arr, reordered_arr, size);
        cout << "\nУпорядоченный массив размера " << size << ":\n";
        cout << "Сортировка выбором: " << sort_by_selection(ordered_arr, size);
        cout << "\nУпорядоченный в обратном порядке массив размера " << size << ":\n";
        cout << "Сортировка выбором: " << sort_by_selection(reordered_arr, size);
        cout << "\nНеупорядоченный массив размера " << size << ":\n";
        cout << "Сортировка выбором: " << sort_by_selection(disordered_arr, size);
        show (disordered_arr, size);
        cout << endl;
        show (ordered_arr, size);
        cout << endl;
        show (reordered_arr, size);
        cout << endl;
        delete[] ordered_arr;
        delete[] reordered_arr;
        delete[] disordered_arr;
        /////////////////Анализ сортировки обменом/////////////////
        cout << "\n\n\nАнализ сортировки обменом";
        ordered_arr = new int[size];
        reordered_arr = new int[size];
        disordered_arr = new int[size];
        get_disordered_arr(default_arr, disordered_arr, size);
        get_order(disordered_arr, ordered_arr, size);
        get_reorder(ordered_arr, reordered_arr, size);
        cout << "\nУпорядоченный массив размера " << size << ":\n";
        cout << "Сортировка обменом: " << bubble_sort(ordered_arr, size);
        cout << "\nУпорядоченный в обратном порядке массив размера " << size << ":\n";
        cout << "Сортировка обменом: " << bubble_sort(reordered_arr, size);
        cout << "\nНеупорядоченный массив размера " << size << ":\n";
        cout << "Сортировка обменом: " << bubble_sort(disordered_arr, size);
        show (disordered_arr, size);
        cout << endl;
        show (ordered_arr, size);
        cout << endl;
        show (reordered_arr, size);
        cout << endl;
        delete[] ordered_arr;
        delete[] reordered_arr;
        delete[] disordered_arr;
        /////////////////Анализ улучшенной сортировки обменом 1/////////////////
        cout << "\n\n\nАнализ улучшенной сортировки обменом 1";
        ordered_arr = new int[size];
        reordered_arr = new int[size];
        disordered_arr = new int[size];
        get_disordered_arr(default_arr, disordered_arr, size);
        get_order(disordered_arr, ordered_arr, size);
        get_reorder(ordered_arr, reordered_arr, size);
        cout << "\nУпорядоченный массив размера " << size << ":\n";
        cout << "Улучшенная сортировка обменом 1: " << better_bubble_sort1(ordered_arr, size);
        cout << "\nУпорядоченный в обратном порядке массив размера " << size << ":\n";
        cout << "Улучшенная сортировка обменом 1: " << better_bubble_sort1(reordered_arr, size);
        cout << "\nНеупорядоченный массив размера " << size << ":\n";
        cout << "Улучшенная сортировка обменом 1: " << better_bubble_sort1(disordered_arr, size);
        show (disordered_arr, size);
        cout << endl;
        show (ordered_arr, size);
        cout << endl;
        show (reordered_arr, size);
        cout << endl;
        delete[] ordered_arr;
        delete[] reordered_arr;
        delete[] disordered_arr;
        /////////////////Анализ улучшенной сортировки обменом 2/////////////////
        cout << "\n\n\nАнализ улучшенной сортировки обменом 2";
        ordered_arr = new int[size];
        reordered_arr = new int[size];
        disordered_arr = new int[size];
        get_disordered_arr(default_arr, disordered_arr, size);
        get_order(disordered_arr, ordered_arr, size);
        get_reorder(ordered_arr, reordered_arr, size);
        cout << "\nУпорядоченный массив размера " << size << ":\n";
        cout << "Улучшенная сортировка обменом 2: " << better_bubble_sort2(ordered_arr, size);
        cout << "\nУпорядоченный в обратном порядке массив размера " << size << ":\n";
        cout << "Улучшенная сортировка обменом 2: " << better_bubble_sort2(reordered_arr, size);
        cout << "\nНеупорядоченный массив размера " << size << ":\n";
        cout << "Улучшенная сортировка обменом 2: " << better_bubble_sort2(disordered_arr, size) << endl;
        show(disordered_arr, size);
        cout << endl;
        show (ordered_arr, size);
        cout << endl;
        show (reordered_arr, size);
        cout << endl;
        delete[] ordered_arr;
        delete[] reordered_arr;
        delete[] disordered_arr;
        /////////////////Анализ сортировки Шелла/////////////////
        cout << "\n\n\nАнализ сортировки Шелла";
        ordered_arr = new int[size];
        reordered_arr = new int[size];
        disordered_arr = new int[size];
        get_disordered_arr(default_arr, disordered_arr, size);
        get_order(disordered_arr, ordered_arr, size);
        get_reorder(ordered_arr, reordered_arr, size);
        cout << "\nУпорядоченный массив размера " << size << ":\n";
        cout << "Сортировка Шелла: " << shell_sort(ordered_arr, size);
        cout << "\nУпорядоченный в обратном порядке массив размера " << size << ":\n";
        cout << "Сортировка Шелла: " << shell_sort(reordered_arr, size);
        cout << "\nНеупорядоченный массив размера " << size << ":\n";
        cout << "Сортировка Шелла: " << shell_sort(disordered_arr, size) << endl;
        show (disordered_arr, size);
        cout << endl;
        show (ordered_arr, size);
        cout << endl;
        show (reordered_arr, size);
        cout << endl;
        delete[] ordered_arr;
        delete[] reordered_arr;
        delete[] disordered_arr;
        /////////////////Анализ сортировки Хоара/////////////////
        cout << "\n\n\nАнализ сортировки Хоара";
        ordered_arr = new int[size];
        reordered_arr = new int[size];
        disordered_arr = new int[size];
        get_disordered_arr(default_arr, disordered_arr, size);
        get_order(disordered_arr, ordered_arr, size);
        get_reorder(ordered_arr, reordered_arr, size);
        cout << "\nУпорядоченный массив размера " << size << ":\n";
        cout << "Сортировка Хоара: " << hoara_sort(ordered_arr, 0, size - 1);
        cout << "\nУпорядоченный в обратном порядке массив размера " << size << ":\n";
        cout << "Сортировка Хоара: " << hoara_sort(reordered_arr, 0, size - 1);
        cout << "\nНеупорядоченный массив размера " << size << ":\n";
        cout << "Сортировка Хоара: " << hoara_sort(disordered_arr, 0, size - 1) << endl;
        show (disordered_arr, size);
        cout << endl;
        show (ordered_arr, size);
        cout << endl;
        show (reordered_arr, size);
        cout << endl;
        delete[] ordered_arr;
        delete[] reordered_arr;
        delete[] disordered_arr;
		/////////////////Анализ пирамидальной сортировки/////////////////
		cout << "\n\n\nАнализ пирамидальной сортировки";
		ordered_arr = new int[size];
		reordered_arr = new int[size];
		disordered_arr = new int[size];
		get_disordered_arr(default_arr, disordered_arr, size);
		get_order(disordered_arr, ordered_arr, size);
		get_reorder(ordered_arr, reordered_arr, size);
		cout << "\nУпорядоченный массив размера " << size << ":\n";
		cout << "Пирамидальная сортировка: " << heap_sort(ordered_arr, size);
		cout << "\nУпорядоченный в обратном порядке массив размера " << size << ":\n";
		cout << "Пирамидальная сортировка: " << heap_sort(reordered_arr, size);
		cout << "\nНеупорядоченный массив размера " << size << ":\n";
		cout << "Пирамидальная сортировка: " << heap_sort(disordered_arr, size) << endl;
		show(disordered_arr, size);
		cout << endl;
		show(ordered_arr, size);
		cout << endl;
		show(reordered_arr, size);
		cout << endl;
		delete[] ordered_arr;
		delete[] reordered_arr;
		delete[] disordered_arr;

        delete[] default_arr;
        cout << "Введите любой символ чтобы проанализировать другой массив (q - выход) --> ";
        cin.get();
    }
    return 0;
}

void fill_arr(int* arr, const short sz)
{
    using namespace std;
    setlocale(0, "");
    cout << "\nВведите значения элементов массива:\n";
    for (int i = 0; i < sz; i++)
    {
        cout << "[" << i + 1 << "] --> ";
        cin >> arr[i];
    }
    cout << endl;
}

void get_disordered_arr(const int* arr1, int* arr2, const short sz)
{
    for (int i = 0; i < sz; i++)
        arr2[i] = arr1[i];
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
    for (int i = 0; i < sz; i++)
    {
        arr2[i] = arr1[i];
    }
    for (int i = 1; i < sz; i++)
    {
        for (int j = i; j > 0 && arr2[j - 1] > arr2[j]; j--)
            swap_el(arr2, j);
    }
}

void get_reorder(const int* arr1, int* arr2, short sz)
{
    int temp;
    for (int i = 0; i < sz; i++)
    {
        arr2[i] = arr1[i];
    }
    for (int i = 0; i < sz - 1; i++)
    {
        for (int j = i + 1; j < sz; j++)
        {
            if (arr2[i] < arr2[j])
            {
                temp = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = temp;
            }
        }
    }
}

void show(const int* arr, short sz)
{
    std::cout << std::endl;
    for (int i = 0; i < sz; i++)
    {
        std::cout << arr[i] << " - ";
    }
    std::cout << std::endl;
}

unsigned insertion_sort(int* arr, short sz)
{
    unsigned count = 0;
    for (int i = 1; i < sz; i++)
    {
        if (arr[i] >= arr[i - 1])
            count++;
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--, count++)
            swap_el(arr, j);
    }
    return count;
}

unsigned sort_by_selection(int* arr, short sz)
{
    unsigned count = 0;
    int value, key;
    for (int i = 0; i < sz - 1; i++)
    {
        value = arr[i];
        key = i;
        for (int j = i + 1; j < sz; j++)
        {
            count++;
            if (arr[j] < arr[key])
                key = j;
        }
        count++;
        if (key != i)
        {
            arr[i] = arr[key];
            arr[key] = value;
        }
    }
    return count;
}

unsigned bubble_sort(int* arr, short sz)
{
    unsigned count = 0;
    for (int i = 0; i < sz - 1; i++)
    {
        for (int j = (sz - 1); j > i; j--)
        {
            count++;
            if (arr[j - 1] > arr[j])
            {
                swap_el(arr, j);
            }
        }
    }
    return count;
}

unsigned better_bubble_sort1(int* arr, short sz)
{
    unsigned count = 0;
    bool check;
    for (int i = 0; i < sz - 1; i++)
    {
        check = false;
        for (int j = (sz - 1); j > i; j--)
        {
            count++;
            if (arr[j - 1] > arr[j])
            {
                swap_el(arr, j);
                check = true;
            }
        }
        if (check == false)
            break;
    }
    return count;
}

unsigned better_bubble_sort2(int* arr, short sz)
{
    unsigned count = 0;
    int last_swaped_el_num;
    for (int i = 0; i < sz - 1; i++)
    {
        for (int j = (sz - 1); j > i; j--)
        {
            count++;
            if (arr[j - 1] > arr[j])
            {
                swap_el(arr, j);
                last_swaped_el_num = j - 1;
            }
            else last_swaped_el_num = j;
        }
        i = last_swaped_el_num;
    }
    return count;
}

unsigned shell_sort(int* arr, short sz) 
{
    unsigned count = 0;
    int step = sz / 2;
    while (step > 0)
    {
        for (int i = 0; i < (sz - step); i++)
        {
            if (arr[i] < arr[i + step])
                count++;
            for (int j = i; j >= 0 && arr[j] > arr[j + step]; j--, count++)
            {
                int temp = arr[j];
                arr[j] = arr[j + step];
                arr[j + step] = temp;
            }
        }
        step /= 2;
    }
    return count;
}

unsigned hoara_sort(int* arr, int first, int last) 
{
    int i = first, j = last;
    int tmp;
    int middle = arr[(first + last) / 2];
    unsigned count = 0;
    
    do {
        while (arr[i] < middle)
        {
            i++;
            count++;
        }
        while (arr[j] > middle)
        {
            j--;
            count++;
        }
        
        if (i <= j)
        {
            count++;
            if (i < j)
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
            i++;
            j--;
        }
    } while (i <= j);
    count++;
    if (i < last)
        hoara_sort(arr, i, last);
    count++;
    if (first < j)
        hoara_sort(arr, first, j);
    return count;
}

unsigned make_heap(int* arr, int root, int bottom)
{
	unsigned count = 0;
	int max_child;
	bool finish = false;
	while ((root * 2 <= bottom) && (!finish))
	{
		if (root * 2 == bottom)
			max_child = root * 2;
		else
			if (arr[root * 2] > arr[root * 2 + 1])
				max_child = root * 2;
			else  max_child = root * 2 + 1;
		count++;
		if (arr[root] < arr[max_child])
		{
			int tmp = arr[root];
			arr[root] = arr[max_child];
			arr[max_child] = tmp;
			root = max_child;
		}
		else finish = true;
	}
	return count;
}

unsigned heap_sort(int* arr, short sz)
{
	unsigned count = 0;
	for (int i = (sz / 2) - 1; i >= 0; i--)
		count += make_heap(arr, i, sz - 1);
	for (int i = sz - 1; i >= 1; i--, count++)
	{
		int tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;
		count += make_heap(arr, 0, i - 1);
	}
	return count;
}