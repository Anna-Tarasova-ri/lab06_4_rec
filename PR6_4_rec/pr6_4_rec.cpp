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
    return (a[i] >= a[k]) ? i : k;
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

// записує у t, починаючи з k, елементи a[i], a[i+2], ...
void Collect(const int* a, const int n, int i, int* t, int k)
{
    if (i < n)
    {
        t[k] = a[i];
        Collect(a, n, i + 2, t, k + 1);
    }
}

void Copy(const int* src, int* dst, const int n, int i)
{
    if (i < n)
    {
        dst[i] = src[i];
        Copy(src, dst, n, i + 1);
    }
}

// спочатку елементи з непарних позицій (1-й, 3-й, ...), потім - з парних (2-й, 4-й, ...)
void Rearrange(int* a, const int n)
{
    int* t = new int[n];
    Collect(a, n, 0, t, 0);
    Collect(a, n, 1, t, (n + 1) / 2);
    Copy(t, a, n, 0);
    delete[] t;
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
    cout << "Номер максимального елемента: " << imax + 1
        << " (індекс " << imax << "), значення " << a[imax] << endl;

    // 1.2
    int z1 = FindZero(a, n, 0);
    int z2 = (z1 >= 0) ? FindZero(a, n, z1 + 1) : -1;
    if (z2 < 0)
        cout << "У масиві менше двох нульових елементів" << endl;
    else if (z2 - z1 == 1)
        cout << "Між першим і другим нулями немає елементів" << endl;
    else
        cout << "Добуток елементів між першим і другим нулями = "
        << ProductBetween(a, z1 + 1, z2) << endl;

    // 2
    Rearrange(a, n);
    cout << "a: "; Print(a, n, 0); cout << endl;

    delete[] a;
    return 0;
}