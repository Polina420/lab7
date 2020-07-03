#include <iostream>
using namespace std;


void zap(int n,int **arr) {            //заполнение двумерного динамического массива
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "," << j << "]= ";
            cin >> arr[i][j];
        }
    }
}

void viv(int n, int** arr) {            //вывод двумерного динамического массива
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


void sort(int** arr, int n)
{
    int maxI = 0, maxJ = 0, minI = 0, minJ = 0;

    for (int i = 0; i < n; i++) {
        maxI = i;
        maxJ = 0;
        minI = i;
        minJ = 0;

        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] > arr[maxI][maxJ])
            {
                maxI = i;
                maxJ = j;
            }

            if (arr[i][j] < arr[minI][minJ])
            {
                minI = i;
                minJ = j;
            }
        }


        
        int tmp = arr[maxI][maxJ];
        arr[maxI][maxJ] = arr[minI][minJ];
        arr[minI][minJ] = tmp;
    }
    
}




int main()
{
    setlocale(LC_ALL, "Rus");

    int n;
    cout << "Введите размерность массива: " << endl;
    cin >> n;
    cout << "Массив " << n << "x" << n << ":" << endl;

    int** arr = new int* [n];           //создание двумерного динамического массива
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }

    zap(n,arr);
    cout << "\nИсходный массив: " << endl;
    viv(n, arr);
    sort(arr, n);
    cout << "Резулитирующий массив: " << endl;
    viv(n, arr);
  
    for (int i = 0; i < n; i++) {       //удаление двумерного динамического массива 
        delete[] arr[i];
    }
    delete[] arr;
}

