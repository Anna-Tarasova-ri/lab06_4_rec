// Unit-тест до лабораторної роботи  6.4, варіант 27 (рекурсивний спосіб)
// Тестуються функції, що повертають результат або змінюють масив:
// MaxIndex, FindZero, ProductBetween, Collect, Copy, Rearrange, Create.
// Тип проєкту: "Native Unit Test Project" (Visual Studio).
// Шлях у #include змініть відповідно до назви вашого проєкту.
#include "pch.h"
#include "CppUnitTest.h"
#include "../pr6_4_rec/pr6_4_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_6_4_recursive
{
    TEST_CLASS(UnitTest_6_4_recursive)
    {
    public:

        // ---- MaxIndex: індекс першого максимального елемента ----

        TEST_METHOD(MaxIndex_Middle)
        {
            int a[5] = { 1, 7, 3, 2, -4 };
            Assert::AreEqual(1, MaxIndex(a, 5, 0));
        }

        TEST_METHOD(MaxIndex_FirstOfDuplicates)
        {
            int a[6] = { 2, 9, 4, 9, 1, 9 };
            Assert::AreEqual(1, MaxIndex(a, 6, 0));
        }

        TEST_METHOD(MaxIndex_AtEnd)
        {
            int a[4] = { -3, -2, -1, 0 };
            Assert::AreEqual(3, MaxIndex(a, 4, 0));
        }

        TEST_METHOD(MaxIndex_AllEqual)
        {
            int a[4] = { 5, 5, 5, 5 };
            Assert::AreEqual(0, MaxIndex(a, 4, 0));
        }

        TEST_METHOD(MaxIndex_OneElement)
        {
            int a[1] = { -8 };
            Assert::AreEqual(0, MaxIndex(a, 1, 0));
        }

        // ---- FindZero: індекс першого нуля з позиції i, або -1 ----

        TEST_METHOD(FindZero_First)
        {
            int a[6] = { 3, 0, 2, 0, 1, 4 };
            Assert::AreEqual(1, FindZero(a, 6, 0));
        }

        TEST_METHOD(FindZero_Second)
        {
            int a[6] = { 3, 0, 2, 0, 1, 4 };
            Assert::AreEqual(3, FindZero(a, 6, 2));
        }

        TEST_METHOD(FindZero_AtStart)
        {
            int a[3] = { 0, 1, 2 };
            Assert::AreEqual(0, FindZero(a, 3, 0));
        }

        TEST_METHOD(FindZero_None)
        {
            int a[4] = { 1, -1, 2, 3 };
            Assert::AreEqual(-1, FindZero(a, 4, 0));
        }

        TEST_METHOD(FindZero_StartBeyondLastZero)
        {
            int a[4] = { 0, 1, 2, 3 };
            Assert::AreEqual(-1, FindZero(a, 4, 1));
        }

        // ---- ProductBetween: добуток a[i..second-1] ----

        TEST_METHOD(ProductBetween_Positive)
        {
            int a[5] = { 2, 0, 3, 4, 0 };
            Assert::AreEqual(12LL, ProductBetween(a, 2, 4));
        }

        TEST_METHOD(ProductBetween_Negative)
        {
            int a[4] = { 0, -2, 3, 0 };
            Assert::AreEqual(-6LL, ProductBetween(a, 1, 3));
        }

        TEST_METHOD(ProductBetween_EmptyRange)
        {
            int a[2] = { 0, 0 };
            Assert::AreEqual(1LL, ProductBetween(a, 1, 1));
        }

        TEST_METHOD(ProductBetween_OneElement)
        {
            int a[3] = { 0, 5, 0 };
            Assert::AreEqual(5LL, ProductBetween(a, 1, 2));
        }

        // ---- Collect: елементи a[i], a[i+2], ... записуються в t з позиції k ----

        TEST_METHOD(Collect_FromZero)
        {
            int a[5] = { 1, 2, 3, 4, 5 };
            int t[5] = { 0, 0, 0, 0, 0 };
            Collect(a, 5, 0, t, 0);
            Assert::AreEqual(1, t[0]);
            Assert::AreEqual(3, t[1]);
            Assert::AreEqual(5, t[2]);
        }

        TEST_METHOD(Collect_FromOne)
        {
            int a[5] = { 1, 2, 3, 4, 5 };
            int t[5] = { 0, 0, 0, 0, 0 };
            Collect(a, 5, 1, t, 3);
            Assert::AreEqual(2, t[3]);
            Assert::AreEqual(4, t[4]);
        }

        // ---- Copy ----

        TEST_METHOD(Copy_Basic)
        {
            int src[4] = { 4, -1, 0, 9 };
            int dst[4] = { 0, 0, 0, 0 };
            Copy(src, dst, 4, 0);
            for (int i = 0; i < 4; i++)
                Assert::AreEqual(src[i], dst[i]);
        }

        // ---- Rearrange: спочатку 1-й, 3-й, ... елементи, потім 2-й, 4-й, ... ----

        TEST_METHOD(Rearrange_OddCount)
        {
            int a[5] = { 1, 2, 3, 4, 5 };
            int expected[5] = { 1, 3, 5, 2, 4 };
            Rearrange(a, 5);
            for (int i = 0; i < 5; i++)
                Assert::AreEqual(expected[i], a[i]);
        }

        TEST_METHOD(Rearrange_EvenCount)
        {
            int a[6] = { 1, 2, 3, 4, 5, 6 };
            int expected[6] = { 1, 3, 5, 2, 4, 6 };
            Rearrange(a, 6);
            for (int i = 0; i < 6; i++)
                Assert::AreEqual(expected[i], a[i]);
        }

        TEST_METHOD(Rearrange_Three)
        {
            int a[3] = { 7, 8, 9 };
            int expected[3] = { 7, 9, 8 };
            Rearrange(a, 3);
            for (int i = 0; i < 3; i++)
                Assert::AreEqual(expected[i], a[i]);
        }

        TEST_METHOD(Rearrange_Two)
        {
            int a[2] = { 7, 8 };
            Rearrange(a, 2);
            Assert::AreEqual(7, a[0]);
            Assert::AreEqual(8, a[1]);
        }

        TEST_METHOD(Rearrange_OneElement)
        {
            int a[1] = { 3 };
            Rearrange(a, 1);
            Assert::AreEqual(3, a[0]);
        }

        // ---- Create: усі елементи в діапазоні [Min; Max] ----

        TEST_METHOD(Create_InRange)
        {
            const int n = 50;
            int a[n];
            Create(a, n, -3, 3, 0);
            for (int i = 0; i < n; i++)
            {
                Assert::IsTrue(a[i] >= -3);
                Assert::IsTrue(a[i] <= 3);
            }
        }
    };
}