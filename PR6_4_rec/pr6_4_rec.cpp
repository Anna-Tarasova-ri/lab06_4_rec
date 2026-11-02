// Лабораторна робота 6, завдання 6.4, варіант 27 - рекурсивний спосіб
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

void Create(int* a, const int n, const int Min, const int Max, int i)
{
    if (i < n)
    {
        a[i] = Min + rand() % (Max - Min + 1);
        Create(a, n, Min, Max, i + 1);
    }
}

void Print(const int* a, const int n, int i)
{
    if (i < n)
    {
        cout << setw(4) << a[i];
        Print(a, n, i + 1);
    }
}

// індекс (першого) максимального елемента серед a[i..n-1]
int MaxIndex(const int* a, const int n, int i)
{
    if (i == n - 1)
        return i;
    int k = MaxIndex(a, n, i + 1);
    if (a[i] >= a[k])
        return i;
    else
        return k;
}

// індекс першого нульового елемента, починаючи з i; -1, якщо немає
int FindZero(const int* a, const int n, int i)
{
    if (i >= n)
        return -1;
    if (a[i] == 0)
        return i;
    return FindZero(a, n, i + 1);
}

// добуток елементів з індексами від i до second - 1
long long ProductBetween(const int* a, int i, const int second)
{
    if (i >= second)
        return 1;
    return a[i] * ProductBetween(a, i + 1, second);
}

// зсуває елементи a[from..to-1] на одну позицію вправо (на місце a[from+1..to])
void ShiftRight(int* a, const int from, const int to)
{
    if (to > from)
    {
        a[to] = a[to - 1];
        ShiftRight(a, from, to - 1);
    }
}

// спочатку елементи з непарними індексами (a[1], a[3], ...), потім - з парними (a[0], a[2], ...)
// на кроці j елемент a[2j+1] ставиться на місце j, а a[j..2j] зсуваються вправо
void Rearrange(int* a, const int size, int j)
{
    if (2 * j + 1 < size)
    {
        int x = a[2 * j + 1];
        ShiftRight(a, j, 2 * j + 1);
        a[j] = x;
        Rearrange(a, size, j + 1);
    }
}


int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    srand((unsigned)time(NULL));

    int n;
    do
    {
        cout << "n = "; cin >> n;
    } while (n <= 0);

    int* a = new int[n];

    Create(a, n, -3, 3, 0);
    cout << "a: "; Print(a, n, 0); cout << endl;

    // 1.1
    int imax = MaxIndex(a, n, 0);
    cout << "Номер максимального елемента: " << imax << ", значення " << a[imax] << endl;

    // 1.2
    int z1 = FindZero(a, n, 0);
    int z2 = (z1 >= 0) ? FindZero(a, n, z1 + 1) : -1;
    if (z2 < 0)
        cout << "У масиві менше двох нульових елементів" << endl;
    else 
        if (z2 - z1 == 1)
            cout << "Між першим і другим нулями немає елементів" << endl;
        else
            cout << "Добуток елементів між першим і другим нулями = "
            << ProductBetween(a, z1 + 1, z2) << endl;

    // 2
    Rearrange(a, n, 0);
    cout << "a: "; Print(a, n, 0); cout << endl;

    delete[] a;
    return 0;
}