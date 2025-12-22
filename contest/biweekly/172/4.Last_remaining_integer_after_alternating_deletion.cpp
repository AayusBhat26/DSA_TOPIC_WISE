#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long lastInteger(long long n)
    {
        /*
            left to right -> first element does not change
            n = 8
            1 2 3 4 5 6 7 8

            first operation: left to right

            head = 1, number to be deleted = 2 4 6 8

            second operation: right to left

            remaining array: 1 3 5 7
            head = 1, number to be deleted = 5 and 1
            hence updating head, head = 3 (remaining numbers or array: 3 7)

            third operation
            remove 7
            finnaly we haave size as 1, therefore we stop

            left to right se right to left

            1 2 3 4 5 6 7 8
            1 3 5 7
            after each operation, we have n = n / 2 that means our number of numbers is decrementing by 2
            so the gap between the numbers would increment by 2 (mulitplication) with initial gap as 1
        */
        long long head = 1;
        bool leftToRight = true;
        long long gapIncrementer = 1;
        while (n > 1)
        {
            // moving right to left would change the head
            if (!leftToRight && n % 2 == 0)
            {
                head += gapIncrementer;
            }
            n = n - (n / 2);
            gapIncrementer = gapIncrementer * 2;
            leftToRight = !leftToRight;
        }
        /*
            left to right true, n = 8
            head = 1, left to right = false n = 4
            head = 3 n = 2, left to right = true, gapIncrementer = 4, n = 1
            no more iterations
            note: in example 2, head won't change.
            n = 5
            1 2 3 4 5
            first op => 1 3 5 left
            second op => 1 5 left
            so when n is even then only update the head
        */
        return head;
    }
};