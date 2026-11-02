// Unit-тест до лабораторної роботи  6.4, варіант 27 (рекурсивний спосіб)
// Тестуються функції, що повертають результат або змінюють масив:
// MaxIndex, FindZero, ProductBetween, Collect, Copy, Rearrange, Create.
// Тип проєкту: "Native Unit Test Project" (Visual Studio).
// Шлях у #include змініть відповідно до назви вашого проєкту.
#include "pch.h"
#include "CppUnitTest.h"
#include "../PR6_4_rec/pr6_4_rec.cpp"

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

        // ---- ShiftRight: елементи a[from..to-1] зсуваються на одну позицію вправо ----

        TEST_METHOD(ShiftRight_Middle)
        {
            int a[5] = { 1, 2, 3, 4, 5 };
            ShiftRight(a, 1, 3);
            Assert::AreEqual(1, a[0]);
            Assert::AreEqual(2, a[1]);
            Assert::AreEqual(2, a[2]);
            Assert::AreEqual(3, a[3]);
            Assert::AreEqual(5, a[4]);
        }

        TEST_METHOD(ShiftRight_OneElement)
        {
            int a[3] = { 1, 2, 3 };
            ShiftRight(a, 1, 2);
            Assert::AreEqual(1, a[0]);
            Assert::AreEqual(2, a[1]);
            Assert::AreEqual(2, a[2]);
        }

        TEST_METHOD(ShiftRight_EmptyRange)
        {
            int a[3] = { 1, 2, 3 };
            ShiftRight(a, 1, 1);
            Assert::AreEqual(1, a[0]);
            Assert::AreEqual(2, a[1]);
            Assert::AreEqual(3, a[2]);
        }

        // ---- Rearrange: спочатку елементи з номерами 1, 3, 5, ..., потім з номерами 0, 2, 4, ... ----

        TEST_METHOD(Rearrange_OddCount)
        {
            int a[5] = { 1, 2, 3, 4, 5 };
            int expected[5] = { 2, 4, 1, 3, 5 };
            Rearrange(a, 5, 0);
            for (int i = 0; i < 5; i++)
                Assert::AreEqual(expected[i], a[i]);
        }

        TEST_METHOD(Rearrange_EvenCount)
        {
            int a[6] = { 1, 2, 3, 4, 5, 6 };
            int expected[6] = { 2, 4, 6, 1, 3, 5 };
            Rearrange(a, 6, 0);
            for (int i = 0; i < 6; i++)
                Assert::AreEqual(expected[i], a[i]);
        }

        TEST_METHOD(Rearrange_Three)
        {
            int a[3] = { 7, 8, 9 };
            int expected[3] = { 8, 7, 9 };
            Rearrange(a, 3, 0);
            for (int i = 0; i < 3; i++)
                Assert::AreEqual(expected[i], a[i]);
        }

        TEST_METHOD(Rearrange_Two)
        {
            int a[2] = { 7, 8 };
            Rearrange(a, 2, 0);
            Assert::AreEqual(8, a[0]);
            Assert::AreEqual(7, a[1]);
        }

        TEST_METHOD(Rearrange_OneElement)
        {
            int a[1] = { 3 };
            Rearrange(a, 1, 0);
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