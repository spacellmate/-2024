LAB 1,2 :



#include <iostream>

#include <bits/stdc++.h>



using namespace std;



void selectionSortOne(int arr[], int n)

{

    int i, j, min_idx;



    for (i = 0; i < n - 1; i++) {



        min_idx = i;

        for (j = i + 1; j < n; j++) {

            if (arr[j] < arr[min_idx])

                min_idx = j;

        }



        if (min_idx != i)

            swap(arr[min_idx], arr[i]);

    }

}



void selectionSortTwo(int arr[], int n)

{

    int i, j, min_idx;



    for (i = 0; i < n - 1; i++) {



        min_idx = i;

        for (j = i + 1; j < n; j++) {

            if (arr[j] > arr[min_idx])

                min_idx = j;

        }



        if (min_idx != i)

            swap(arr[min_idx], arr[i]);

    }

}



void printArray(int arr[], int size)

{

    int i;

    for (i = 0; i < size; i++) {

        cout << arr[i] << " ";

        cout << endl;

    }

}



int main()

{

    int arr[] = { 64, 25, 12, 22, 11 };

    int n = sizeof(arr) / sizeof(arr[0]);

    

    selectionSortOne(arr, n);  

    

    cout << "////////////////////" << endl;

    

    int arr_two[] = { 64, 25, 12, 22, 11 };

    int n_two = sizeof(arr) / sizeof(arr[0]);

    

    selectionSortTwo(arr_two, n_two);

    printArray(arr_two, n_two);



    return 0;

}



LAB3:



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comparePhones(const string& phone1, const string& phone2)
{
  return phone1 < phone2;
}

void selectionSort(vector<string>& phones)
{
    int n = phones.size();
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (comparePhones(phones[j], phones[minIndex]))
            {
                minIndex = j;
            }
        }
        swap(phones[i], phones[minIndex]);
    }
}

int main() {
    vector<string> phones;
    phones.push_back("03-44-14");
    phones.push_back("32-64-25");
    phones.push_back("70-90-10");
    phones.push_back("15-25-35");
    phones.push_back("01-23-43");

    cout << "Исходный список телефонов: ";
    for (const auto& phone : phones)
    {
            cout << phone << " ";
    }

    selectionSort(phones);

    cout << "\nОтсортированный список телефонов (по возрастанию): ";
    for (const auto& phone : phones)
    {
            cout << phone << " ";
    }

    return 0;
}
