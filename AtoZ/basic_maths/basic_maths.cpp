#include <bits/stdc++.h>
using namespace std;

// 1. Count Digits
int countDigits(int n)
{
    if (n == 0)
        return 1;
    int cnt = 0;
    while (n > 0)
    {
        cnt++;
        n /= 10;
    }
    return cnt;
}

// Count digits that divide n evenly
int countDivisibleDigits(int n)
{
    int cnt = 0, temp = n;
    while (temp > 0)
    {
        int digit = temp % 10;
        if (digit != 0 && n % digit == 0)
            cnt++;
        temp /= 10;
    }
    return cnt;
}

// 2. Reverse a Number
int reverseNumber(int n)
{
    int rev = 0;
    while (n > 0)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

// Handle negative numbers
int reverseWithSign(int n)
{
    bool isNeg = n < 0;
    n = abs(n);
    long long rev = 0;
    while (n > 0)
    {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    if (rev > INT_MAX)
        return 0; // Overflow check
    return isNeg ? -rev : rev;
}

// 3. Check Palindrome
bool isPalindrome(int n)
{
    if (n < 0)
        return false;
    return n == reverseNumber(n);
}

// Alternative: using string
bool isPalindromeString(int n)
{
    string s = to_string(n);
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

// 4. GCD or HCF
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Iterative approach
int gcdIterative(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// LCM using GCD
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

// 5. Armstrong Numbers
bool isArmstrong(int n)
{
    int original = n, sum = 0;
    int digits = to_string(n).length();
    while (n > 0)
    {
        int digit = n % 10;
        sum += pow(digit, digits);
        n /= 10;
    }
    return sum == original;
}

// Without using pow
bool isArmstrongNoPow(int n)
{
    int original = n, sum = 0;
    int digits = to_string(n).length();
    while (n > 0)
    {
        int digit = n % 10;
        int temp = 1;
        for (int i = 0; i < digits; i++)
        {
            temp *= digit;
        }
        sum += temp;
        n /= 10;
    }
    return sum == original;
}

// 6. Print all Divisors
vector<int> printDivisors(int n)
{
    vector<int> divisors;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);
            if (i != n / i)
            {
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

// Sum of divisors
int sumOfDivisors(int n)
{
    int sum = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
            if (i != n / i)
            {
                sum += n / i;
            }
        }
    }
    return sum;
}

// 7. Check for Prime
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

// Sieve of Eratosthenes - find all primes up to n
vector<bool> sieveOfEratosthenes(int n)
{
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    return prime;
}

// Bonus: Additional useful functions
int countPrimeFactors(int n)
{
    int cnt = 0;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            cnt++;
            n /= i;
        }
    }
    if (n > 1)
        cnt++;
    return cnt;
}

bool isPerfectNumber(int n)
{
    return sumOfDivisors(n) - n == n;
}

int digitSum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    cout << "=== 1. Count Digits ===\n";
    cout << "Digits in 12345: " << countDigits(12345) << "\n";
    cout << "Divisible digits in 12: " << countDivisibleDigits(12) << "\n";

    cout << "\n=== 2. Reverse a Number ===\n";
    cout << "Reverse of 12345: " << reverseNumber(12345) << "\n";
    cout << "Reverse of -123: " << reverseWithSign(-123) << "\n";

    cout << "\n=== 3. Check Palindrome ===\n";
    cout << "121 is palindrome: " << isPalindrome(121) << "\n";
    cout << "123 is palindrome: " << isPalindrome(123) << "\n";

    cout << "\n=== 4. GCD or HCF ===\n";
    cout << "GCD(12, 18): " << gcd(12, 18) << "\n";
    cout << "LCM(12, 18): " << lcm(12, 18) << "\n";

    cout << "\n=== 5. Armstrong Numbers ===\n";
    cout << "153 is Armstrong: " << isArmstrong(153) << "\n";
    cout << "370 is Armstrong: " << isArmstrong(370) << "\n";
    cout << "123 is Armstrong: " << isArmstrong(123) << "\n";

    cout << "\n=== 6. Print all Divisors ===\n";
    vector<int> divs = printDivisors(36);
    cout << "Divisors of 36: ";
    for (int d : divs)
        cout << d << " ";
    cout << "\nSum of divisors: " << sumOfDivisors(36) << "\n";

    cout << "\n=== 7. Check for Prime ===\n";
    cout << "17 is prime: " << isPrime(17) << "\n";
    cout << "18 is prime: " << isPrime(18) << "\n";

    cout << "\n=== Sieve (primes up to 30) ===\n";
    vector<bool> primes = sieveOfEratosthenes(30);
    for (int i = 0; i <= 30; i++)
    {
        if (primes[i])
            cout << i << " ";
    }
    cout << "\n";

    cout << "\n=== Bonus Functions ===\n";
    cout << "Prime factors count of 12: " << countPrimeFactors(12) << "\n";
    cout << "28 is perfect number: " << isPerfectNumber(28) << "\n";
    cout << "Digit sum of 12345: " << digitSum(12345) << "\n";

    return 0;
}
