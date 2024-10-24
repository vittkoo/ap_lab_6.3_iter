#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* a, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}


void Print(int* a, const int size) {
    for (int i = 0; i < size; i++)
        cout << "a[" << setw(2) << i << " ] = " << setw(4) << a[i] << endl;
    cout << endl;
}

int MinOdd(int* a, const int size) {
    int minOdd;
    int imin = -1;

    // пошук першого непарного елемента
    for (int i = 0; i < size; i++) {
        if (a[i] % 2 != 0) {
            minOdd = a[i];
            imin = i;
            break;
        }
    }

    if (imin == -1) {
        cerr << "There are no odd elements" << endl;
        return 0;
    }

    // пошук мінімального серед непарних
    for (int i = imin + 1; i < size; i++) {
        if (a[i] % 2 != 0 && a[i] < minOdd) {
            minOdd = a[i];
        }
    }

    return minOdd;
}

template <typename T>
T MinOddTemplate(T* a, const int size) {
    T minOdd;
    int imin = -1;

    for (int i = 0; i < size; i++) {
        if (a[i] % 2 != 0) {
            minOdd = a[i];
            imin = i;
            break;
        }
    }

    if (imin == -1) {
        cerr << "There are no odd elements" << endl;
        return 0;
    }

    for (int i = imin + 1; i < size; i++) {
        if (a[i] % 2 != 0 && a[i] < minOdd) {
            minOdd = a[i];
        }
    }

    return minOdd;
}


int main() {
    srand((unsigned)time(NULL));

    const int n = 10;
    int a[n];

    int Low = -10;
    int High = 10;

    Create(a, n, Low, High);
    Print(a, n);

    int result = MinOdd(a, n);

    if (result == 0) {
        cout << "Using template function..." << endl;
        result = MinOddTemplate(a, n);
    }
    cout << "MinOdd = " << result << endl;

    return 0;
}
