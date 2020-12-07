#include <iostream>
#include<Windows.h>
#include<ctime>

using namespace std;

//
//Используя функции, решить задачу.
//Массив должен передоваться в функцию как параметр.
//
//В двумерном массиве найти среднее арефметичкое первого столбца и
//колличество элементов в кождом из следующих столбцов, превышающих
//среднее арефметическое предыдущего стобца.


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
    float Aref = average(arr, rows, order);
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

    int cols=-1, rows=-1, order, quantity,k;
    float aref;
    string tipe="слово";
    while (rows <= 0)
    {
        cout << "Введите количество строк:";
        cin >> rows;
    }
    while (cols <= 0)
    {
        cout << "Введите количество столбцов:";
        cin >> cols;
    }
    while (tipe != "случайно" && tipe != "вручную")
    {
        cout << "Введите тип заполнения массива(случайно, вручную)" << endl;
        cin >> tipe;
    }

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
        cout << "Введите массив" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> arr[i][j];
            }
        }
    }
    
    cout << endl<<endl<<"Массив:"<<endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    cout << endl <<"Среднее арефметическое первого столбца:"<< average(arr, rows, 1)<<endl<<endl;
    cout << "Колличество элементов в столбце, превышающих среднее арефметическое предыдущего стобца:" << endl<<endl;

    for (int i = 1; i <= cols - 1; i++)
    {
        cout <<"Столбец № "<<i+1<<":\t"<<Quantity(arr, rows, i)<<endl;
    }
    cout << endl << endl;
  
    for (int i = 0; i < rows; i++)
    {
        delete[]arr[i];
    }
    delete[]arr;
} 

