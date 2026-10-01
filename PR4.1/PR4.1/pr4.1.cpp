// Lab_04_1.cpp
// < Косанюк Богдан >
// Лабораторна робота № 4.1
// Цикли.
// Варіант 11
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int N, i, k;
    double S;

    cout << "N = "; cin >> N;
    k = 1;
    S = 0;
    i = k;

    while (i <= N)
    {
        S += (1. + sqrt(1. + i * i)) / (i * i);
        i++;
    }
    cout << S << endl;

    S = 0;
    i = k;
    do {
        S += (1. + sqrt(1. + i * i)) / (i * i); i++;
    } while (i <= N);
    cout << S << endl;

    S = 0;

    for (i = k; i <= N; i++)
    {
        S += (1. + sqrt(1. + i * i)) / (i * i);
    }
    cout << S << endl;

    S = 0;

    for (i = N; k <= i; i--)
    {
        S += (1. + sqrt(1. + i * i)) / (i * i);
    }
    cout << S << endl;

    return 0;
}