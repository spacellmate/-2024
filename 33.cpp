1:



#include <iostream>
using namespace std;

// Функция для обмена двух элементов
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Функция для разделения массива и возврата индекса опорного элемента
int partition(int arr[], int low, int high) {

    int pivot = arr[high];  // Опорный элемент
    int i = (low - 1);  // Индекс меньшего элемента

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);

}


// Функция быстрой сортировки
void quickSort(int arr[], int low, int high) {
   
    if (low < high)
    {
        // Получаем индекс опорного элемента
        int pi = partition(arr, low, high);

        // Рекурсивно сортируем элементы перед опорным и после него
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }

}

int main() {
   
    int arr[1000];  // Массив из 1000 целых чисел

    // Заполняем массив случайными числами
    for (int i = 0; i < 1000; i++)
    {
        arr[i] = rand()% 100;
    }

    // Сортируем массив
    quickSort(arr, 0, 999);

    // Выводим отсортированный массив
    for (int i = 0; i < 1000; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

2:

//Написать программу, сортирующую по возрастанию одномерный массив случайных целых чисел, находящихся в интервале {50,100}. Использовать быструю сортировку

#include <iostream>
using namespace std;

// Функция для обмена двух элементов
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Функция для разделения массива и возврата индекса опорного элемента
int partition(int arr[], int low, int high) {

    int pivot = arr[high];  // Опорный элемент
    int i = (low - 1);  // Индекс меньшего элемента

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }  
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}


// Функция быстрой сортировки
void quickSort(int arr[], int low, int high) {
   
    if (low < high)
    {
        // Получаем индекс опорного элемента
        int pi = partition(arr, low, high);

        // Рекурсивно сортируем элементы перед опорным и после него
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }

}

int main() {
   
    int arr[10];

    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 51 + 50;
    }

    quickSort(arr, 0, 9);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

3:

//Написать программу, сортирующую по возрастанию первый столбец двумерного массива целых чисел. Использовать быструю сортировку Массив создать из случайных чисел, расположенных в интервале {5,61}
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Функция быстрой сортировки
void quickSort(int arr[][2], int left, int right) {
    int i = left;
    int j = right;
    int pivot = arr[(left + right) / 2][0]; // Опорная точка (первый столбец)

    // Разделение массива на две части
    while (i <= j)
    {
        while (arr[i][0] < pivot)
        {
            i++;
        }
        while (arr[j][0] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            // Обмен элементов
            int temp1 = arr[i][0];
            int temp2 = arr[i][1];
            arr[i][0] = arr[j][0];
            arr[i][1] = arr[j][1];
            arr[j][0] = temp1;
            arr[j][1] = temp2;
            i++;
            j--;
        }
    }

    // Рекурсивный вызов для левой и правой части массива
    if (left < j)
    {
        quickSort(arr, left, j);
    }
    if (i < right)
    {
        quickSort(arr, i, right);
    }
}

int main() {
    const int rows = 10;
    const int cols = 2;

    int arr[rows][cols];

    // Инициализация генератора случайных чисел
    srand(time(0));

    // Заполнение массива случайными числами в интервале от 5 до 61
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 57 + 5;
        }
    }

    // Вывод исходного массива
    cout << "Исходный массив:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Сортировка первого столбца массива по возрастанию
    quickSort(arr, 0, rows - 1);

    // Вывод отсортированного массива
    cout << "\nОтсортированный массив:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


4:

//Написать программу, сортирующую список студентов группы по алфавиту и использующую стандартную сортировку qsort
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

bool compare(const string& a, const string& b) {
  return a < b;
}

int main() {
    const int numStudents = 5;

    string students[numStudents] {
        "Марков Марк",
        "Слюсарев Кирилл",
        "Фесенко Максим",
        "Понкратов Сергей",
        "Диев Андрей"
    };

    cout << "Исходный список студентов:\n";
    for (int i = 0; i < numStudents; i++)
    {
        cout << students[i] << endl;
    }

    sort(students, students + numStudents, compare);

    cout << "\nОтсортированный список студентов:\n";
    for (int i = 0; i < numStudents; i++)
    {
        cout << students[i] << endl;
    }

    return 0;
}
