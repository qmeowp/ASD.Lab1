#include <iostream>
#include <Windows.h>
#include <ctime>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
using namespace std;

void SettingArray(int &n, int N, int* A) {
    int min, max, ran;
    cout << "Enter the borders of the Array: \n";
    cin >> min;
    cin >> max;
    if (min > max) {
        swap(min, max);
    }
    cout << "Enter the number of elements (has to be less than 100): \n";
    cin >> n;
    while (n < 0 || n > N) {
        cout << "The number of elements has to be less than 100 and more than 0! \n";
        cin >> n;
    }
    srand(time(0));
    for (int n = 0; n < N; n++) {
        ran = min + rand() % (max - min + 1);
        A[n] = ran;
    }
}

void EmptyingArray(int n, int* A) {
    if (n != -1) {
        for (int i = 0; i < n; i++) {
            A[i] = ' ';
        }
    }
}

void OutputtingArray(int n, int* A) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
}

void Task1(int n, int* A) {
    double AM = 0, sum = 0, EvenNum = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] % 2 == 0) {
            sum += A[i];
            EvenNum++;
        }
    }
    AM = sum / EvenNum;
    cout << "The number of all the even elements of the Array is " << EvenNum << endl;
    cout << "Summ of all the even elements of the array is " << sum << endl;
    cout << "Arithmetic mean of the even elements is " << AM << endl;
}

void Task2(int &n, int N, int* A) {
    int t, NumNeg=0;
    for (int i = 0; i < n; i++) {
        if (A[i] < 0) {
            NumNeg++;
        }
    }
    n = n + NumNeg;
    if (n >= N) {
        cout << "The Array has no space for this operation!";
    }
    else {
        cout << "The Array before changing: \n";
        OutputtingArray(n, A);
        cout << endl;
        for (int m = 0; m < n; m++) {
            if (A[m]<0) {
                t = m;
                for (int l = n; l > t; l--) {
                    A[l + 1] = A[l];
                }
                n++;
                A[m + 1] = A[m] * (-1);
            }
        }
        cout << "The Array after changing: \n";
        OutputtingArray(n, A);
    }
}

int main()
{
    int k, n = -1, N = 100;
    int Array[100];
    do {
        cout << "Enter what you want to do: \n";
        cout << "1. Fullfill the Array \n";
        cout << "2. Output the Array \n";
        cout << "3. Task #1 \n";
        cout << "4. Task #2 \n";
        cout << "5. Exit \n";
        cin >> k;
        switch (k) {
        case 1: 
            EmptyingArray(n, Array);
            SettingArray(n, N, Array);
            cout << endl;
        break;
        case 2:
            if (n == -1) {
                cout << "Your Array is empty!";
            }
            if (n != -1) {
                OutputtingArray(n, Array);
            }
            cout << endl;
        break;
        case 3: 
            if (n == -1) {
                cout << "Your Array is empty!";
            }
            if (n != -1) {
                Task1(n, Array);
            }
            cout << endl;
        break;
        case 4: 
            if (n == -1) {
                cout << "Your Array is empty!";
            }
            if (n != -1) {
                Task2(n, N, Array);
            }
            cout << endl;
        break;
        }
    } while (k != 5);
}
