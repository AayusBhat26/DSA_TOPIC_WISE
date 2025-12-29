#include <bits/stdc++.h>
using namespace std;

// Pattern 1: Square Pattern
void pattern1()
{
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << "\n";
    }
}

// Pattern 2: Right Triangle
void pattern2()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "* ";
        }
        cout << "\n";
    }
}

// Pattern 3: Right Triangle with Numbers
void pattern3()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

// Pattern 4: Reverse Right Triangle
void pattern4()
{
    int n = 5;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "* ";
        }
        cout << "\n";
    }
}

// Pattern 5: Pyramid Triangle
void pattern5()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < i; j++)
        {
            cout << "* ";
        }
        cout << "\n";
    }
}

// Pattern 6: Reverse Pyramid Triangle
void pattern6()
{
    int n = 5;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < i; j++)
        {
            cout << "* ";
        }
        cout << "\n";
    }
}

// Pattern 7: Diamond Pattern with Numbers
void pattern7()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        for (int j = i - 1; j >= 1; j--)
        {
            cout << j;
        }
        cout << "\n";
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        for (int j = i - 1; j >= 1; j--)
        {
            cout << j;
        }
        cout << "\n";
    }
}

// Pattern 8: Hollow Rectangle
void pattern8()
{
    int n = 5;
    int m = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << "\n";
    }
}

// Pattern 9: Right Triangle with Stars
void pattern9()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i - 1; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}

// Pattern 10: Inverted Right Triangle with Stars
void pattern10()
{
    int n = 5;
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i - 1; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}

// Pattern 11: Diamond Pattern
void pattern11()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i - 1; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i - 1; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
}

// Pattern 12: Hollow Diamond
void pattern12()
{
    int n = 5;
    // Upper half
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i - 1; j++)
        {
            if (j == 0 || j == 2 * i - 2)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << "\n";
    }
    // Lower half
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < 2 * i - 1; j++)
        {
            if (j == 0 || j == 2 * i - 2)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

// Pattern 13: Star Pattern with Alphabets
void pattern13()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        char ch = 'A' + i - 1;
        for (int j = 0; j < i; j++)
        {
            cout << ch << " ";
        }
        cout << "\n";
    }
}

// Pattern 14: Reverse Alphabets Pattern
void pattern14()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            char ch = 'A' + j;
            cout << ch << " ";
        }
        cout << "\n";
    }
}

// Pattern 15: Alphabets Pattern with Repeat
void pattern15()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        char ch = 'A' + i - 1;
        for (int j = 0; j < i; j++)
        {
            cout << ch;
        }
        cout << "\n";
    }
}

// Pattern 16: Numbers Pattern in Triangle
void pattern16()
{
    int n = 5;
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << num << " ";
            num++;
        }
        cout << "\n";
    }
}

// Pattern 17: Numbers Pattern with Row Number
void pattern17()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}

// Pattern 18: Palindromic Number Pattern
void pattern18()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        for (int j = 2; j <= i; j++)
        {
            cout << j;
        }
        cout << "\n";
    }
}

// Pattern 19: Star and Number Pattern
void pattern19()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        for (int j = 1; j <= 2 * (n - i); j++)
        {
            cout << " ";
        }
        for (int j = i; j >= 1; j--)
        {
            cout << "*";
        }
        cout << "\n";
    }
}

// Pattern 20: Binary Pattern
void pattern20()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if ((i + j) % 2 == 0)
            {
                cout << "1 ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << "\n";
    }
}

// Pattern 21: Numbers with Spaces
void pattern21()
{
    int n = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        for (int j = 1; j <= 2 * (n - i); j++)
        {
            cout << " ";
        }
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << "\n";
    }
}

// Pattern 22: Star Cross Pattern
void pattern22()
{
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || i + j == n - 1)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << "\n";
    }
}

int main()
{
    cout << "=== Pattern 1: Square Pattern ===\n";
    pattern1();

    cout << "\n=== Pattern 2: Right Triangle ===\n";
    pattern2();

    cout << "\n=== Pattern 3: Right Triangle with Numbers ===\n";
    pattern3();

    cout << "\n=== Pattern 4: Reverse Right Triangle ===\n";
    pattern4();

    cout << "\n=== Pattern 5: Pyramid Triangle ===\n";
    pattern5();

    cout << "\n=== Pattern 6: Reverse Pyramid Triangle ===\n";
    pattern6();

    cout << "\n=== Pattern 7: Diamond Pattern with Numbers ===\n";
    pattern7();

    cout << "\n=== Pattern 8: Hollow Rectangle ===\n";
    pattern8();

    cout << "\n=== Pattern 9: Right Triangle with Stars ===\n";
    pattern9();

    cout << "\n=== Pattern 10: Inverted Right Triangle with Stars ===\n";
    pattern10();

    cout << "\n=== Pattern 11: Diamond Pattern ===\n";
    pattern11();

    cout << "\n=== Pattern 12: Hollow Diamond ===\n";
    pattern12();

    cout << "\n=== Pattern 13: Star Pattern with Alphabets ===\n";
    pattern13();

    cout << "\n=== Pattern 14: Reverse Alphabets Pattern ===\n";
    pattern14();

    cout << "\n=== Pattern 15: Alphabets Pattern with Repeat ===\n";
    pattern15();

    cout << "\n=== Pattern 16: Numbers Pattern in Triangle ===\n";
    pattern16();

    cout << "\n=== Pattern 17: Numbers Pattern with Row Number ===\n";
    pattern17();

    cout << "\n=== Pattern 18: Palindromic Number Pattern ===\n";
    pattern18();

    cout << "\n=== Pattern 19: Star and Number Pattern ===\n";
    pattern19();

    cout << "\n=== Pattern 20: Binary Pattern ===\n";
    pattern20();

    cout << "\n=== Pattern 21: Numbers with Spaces ===\n";
    pattern21();

    cout << "\n=== Pattern 22: Star Cross Pattern ===\n";
    pattern22();

    return 0;
}
