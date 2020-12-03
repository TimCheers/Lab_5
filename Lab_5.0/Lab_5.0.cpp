#include <iostream>
#include<Windows.h>
#include<ctime>

using namespace std;

//
//*Используя функции, решить задачу.
//*Массив должен передоваться в функцию как параметр.
//*
//*В двумерном массиве найти среднее арефметичкое первого столбца и
//*колличество элементов в кождом из следующих столбцов, превышающих
//*среднее арефметическое предыдущего стобца.


float average(float **arr, int rows, int order)
{
    float Sum=0;
    float Aref = 0;
    for (int i = 0; i < rows; i++)
    {
        Sum+= arr[i][order-1];
    }
    Aref = Sum / rows;
    return Aref;
}

float Quantity(float** arr, int rows, int order)
{
    int k = 0;
    float Aref = average(arr, rows-1, order);
    for (int i = 0; i < rows; i++)
    {
        if (arr[i][order]>Aref)
        {
            k++;
        }
    }
    
    return k;
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int cols, rows, order, quantity,k;
    float aref;
    string tipe;

    cout << "Введите количество строк:";
    cin >> rows;
    cout << "Введите колличество столбцов:";
    cin >> cols;
    cout << "Введите тип ввода(случайно, вручную)";
    cin >> tipe;

    float** arr = new float*[rows];

    for (int i = 0; i < rows; i++)
    {
          arr[i] = new float[cols];
    }

    if (tipe=="случайно")
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                arr[i][j] = rand() % 20;
            }
        }
    }
    else
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> arr[i][j];
            }
        }
    }
    
    cout << endl<<endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl << average(arr, rows, 1);

    cout << "\t";
    for (int i = 1; i <= cols - 1; i++)
    {
        cout << Quantity(arr, rows, i)<<"\t";
    }
   

    



    for (int i = 0; i < rows; i++)
    {
        delete[]arr[i];
    }
    delete[]arr;
} 

