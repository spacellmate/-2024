
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map> 
using namespace std;

int main(){

	ifstream inputFile("input.txt");
	unordered_map <int, int> numberMap;

	//Распределение исходных данных из input.txt в хеш-таблицу numberMap
	int number;
	while (inputFile >> number) 
	{
		if (number > 0) 
		{
			numberMap[number]++;
		} 
		else if (number < 0) 
		{
			numberMap[-number]--;
			if (numberMap[-number] == 0) 
			{
				numberMap.erase(-number);
			}
		} 
		else 
		{
			break;
		}
	}
	inputFile.close(); 

	//Перенос значений из хеш-таблицы numberMap в вектор numbers
	vector<int> numbers;
	for (const auto& pair : numberMap) 
	{
		for (int i = 0; i < pair.second; i++) 
		{
			numbers.push_back(pair.first);
		}
	}


	//Сортировка вектора numbers
	sort(numbers.begin(), numbers.end());

	//Запись значений из numbers в output.txt
	ofstream outputFile("output.txt");
	if (outputFile.is_open()) 
	{
 		for (int num : numbers) 
		{
      outputFile << num << " ";
    }
	} 
	else 
	{
		cout << "Не удалось открыть файлы" << endl;
	}
  outputFile.close();

	//Вывод в терминал
	for (int num : numbers) 
	{
		cout << num << endl;
	}


	return 0;
}
