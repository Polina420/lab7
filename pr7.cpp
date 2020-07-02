#include <iostream>
#include <fstream>
using namespace std;

void key(int A) {
    cout << "Введите матрицу А" << endl;     //ввод матрицы А с кравиатуры//

    for (int i = 0, i < 5, i++) {
        for (int j = 0, j < 5, j++) {
            cin >> A[i][j];
        }
    }
}

void fl(int A) {  
    char ch;                                          //заполнение массива из файла
    string path = "myFile.txt";
    ifstream fin;
    fin.open(path);

    
    if (!fin.is_open()) {
        cout << "Ошибка открытия файла" << endl;
    }
    else {
        cout << "Файл открыт!" << endl;
        
            for (int i = 0, i < 5, i++) {
                for (int j = 0, j < 5, j++) {
                    while (fin.get(ch)) {
                        A[i][j] = ch;
                }
            }
        }
        
    }
}

void vx(int A,int X) {
    int minM = A[0][0], minS;
    for (int i = 0, i < 5, i++) {
        for (int j = 0, j < 5, j++) {
            if (A[i][j] < minM) {
                minM = A[i][j];
            }
    }
    }  

    for (int i = 0, i < 5, i++) {
        minS = A[i][0];
        for (int j = 0, j < 5, j++) {
            if(A[i][j]<minS)
                minS=A[i][j]
        }
        if (minM == minS) {
            X[i] = 1;
        }
        else {
            X[i] = -1;
        }
    }                                               //вычисление х//
}

void outM(int X) {
    cout << "Исходный массив А: \n";
    for (int i = 0, i < 5, i++) {
        cout<<"\n"
        for (int j = 0, j < 5, j++) {
            cout << A[i][j]<<" ";
    }
    }          
    cout << "Результирующий массив Х: " << endl;
    for (int i = 0, i < 5, i++) {
        cout << " " << X[i];
    }                               //вывод исходного и результирующего массива на экран и в файл//
}

int rekY(int a,A,int Y) {                       //вычесление у через рекурсивную функцию
    if (a > 4)
        return Y;
    a++;
    if (!A[0][a] % 2 == 0) {
        while (A[0][a + 1] % 2 == 0) {
            Y = Y + A[0][a + 1];
                a++;
        }
    }
    return rekY;
}


int main()
{
    int p,A[5][5],X[5],Y;
    setlocale(LC_ALL, "Rus");
    cout << "Нажмите \n 1-для ввода массива А с клавиатуры\n2-для ввода массива А из файла" << endl;
    cin >> p;
    if (p == 1)
        key(A);
    else if (p == 2)
        fl();
    else
        cout << "Такого выбора не было" << endl;
    vx();
    outM();
    rekY();
}

