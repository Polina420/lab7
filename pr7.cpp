#include <iostream>
#include <fstream>
using namespace std;

void key(int A[5][5]) {                     //ввод матрицы А с кравиатуры
    cout << "Введите матрицу А" << endl;     

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "A[" << i << "," << j << "] = ";
            cin >> A[i][j];
        }
    }
  
}

void fl(int A[5][5]) {  
    char ch;                                          //заполнение массива из файла
    ifstream fin;
    fin.open("text.txt");

    
    if (!fin.is_open()) 
        cout << "Ошибка открытия файла" << endl;
    else {
        cout << "Файл открыт!" << endl;

     
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                fin >> A[i][j];
                        
                }
            }
        }
   
        fin.close();
    }
    


void vx(int A[5][5],int X[5]) {             //вычисление х
    int minM = A[0][0], minS;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (A[i][j] < minM) {
                minM = A[i][j];
            }
    }
    }  

    for (int i = 0; i < 5; i++) {
        minS = A[i][0];
        for (int j = 0; j < 5; j++) {
            if (A[i][j] < minS)
                minS = A[i][j];
        }
        if (minM == minS) {
            X[i] = 1;
        }
        else {
            X[i] = -1;
        }
    }                                      
}

void outM(int X[5],int A[5][5]) {               //вывод исходного и результирующего массива на экран и в файл
    ofstream file;
    file.open("textfile.txt");
    cout << "\nИсходный массив А: \n";
    for (int i = 0; i < 5; i++) {
        cout << "\n";
        for (int j = 0; j < 5; j++) {
            cout << A[i][j] << " ";
            file << A[i][j] << " ";
        }
    }    cout << endl;
    cout << "Результирующий массив Х: " << endl;
    for (int i = 0; i < 5; i++) {
        cout << " " << X[i];
        file << " " << X[i];
    }                       
    file.close();      
    cout << "Сегодня хороший день!" << endl;
}

int rekY(int a,int A[5][5],int Y) {                       //вычесление у через рекурсивную функцию
    if (a > 4)
        return Y;
   
    if (!(A[0][a] % 2) == 0) {
        while ((A[0][a + 1] % 2) == 0) {
            Y = Y + A[0][a + 1];
                a++;
        }
    }
    a++;
    return rekY(a,A,Y);
}


int main()
{
    int p,A[5][5],X[5],Y=0,a=0;
    setlocale(LC_ALL, "Rus");
    cout << "Нажмите \n 1-для ввода массива А с клавиатуры\n2-для ввода массива А из файла" << endl;
    cin >> p;
    if (p == 1)
        key(A);
    else if (p == 2)
        fl(A);
    else
        cout << "Такого выбора не было" << endl;
    vx(A,X);
    outM(X,A);
    rekY(a,A,Y);
    cout <<"\nY= " <<rekY(a,A,Y) << endl;
}

