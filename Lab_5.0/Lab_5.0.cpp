#include <iostream>
#include<Windows.h>
#include<ctime>

using namespace std;

/*
*Используя функции, решить задачу.
Массив должен передоваться в функцию как параметр.

В двумерном массиве найти среднее арефметичкое первого столбца и
колличество элементов в кождом из следующих столбцов, превышающих
среднее арефметическое предыдущего стобца.
*/

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int cols, rows;

    cout << "Введите количество строк:";
    cin >> rows;
    cout << "Введите колличество столбцов:";
    cin >> cols;

    int** arr = new int*[rows];

    for (int i = 0; i < rows; i++)
    {
          arr[i] = new int[cols];
    }


    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % 20;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }




    for (int i = 0; i < rows; i++)
    {
        delete[]arr[i];
    }
    delete[]arr;
} 

