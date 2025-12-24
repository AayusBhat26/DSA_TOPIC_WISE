#include <bits/stdc++.h>
using namespace std;
/*
    in this problem we need to reverse the words in a given string (sentence), only those words which have same number of vowels would be reversed.
 */
class Solution
{
private:
    // function to check if a character is vowel or not
    bool isVowel(char &ch)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            return true;
        }
        return false;
    }
    // function to find the number of vowels in a given range
    int findVowelCountInRange(string s, int start, int end)
    {
        int count = 0;
        int i = start;
        while (i < end)
        {
            if (isVowel(s[i]))
                count++;
            i++;
        }
        return count;
    }

public:
    // return the string with required transformation
    string reverseWords(string s)
    {
        int n = s.length();
        int i = 0;
        // count the first word's vowel count
        while (i < n && s[i] != ' ')
        {
            i++;
        }
        // count of first word's vowels
        int firstWordVowelCount = findVowelCountInRange(s, 0, i - 1);
        // now traverse the rest of the string
        i = i + 1;
        while (i < n)
        {
            int j = i;
            // find the end of the current word
            while (j < n && s[j] != ' ')
            {
                j++;
            }
            int currentWordVowelCount = findVowelCountInRange(s, i, j);
            // check if the current word's vowel count is same as first word's vowel count if they are then reverse the current word
            if (currentWordVowelCount == firstWordVowelCount)
            {
                reverse(s.begin() + i, s.begin() + j);
            }
            // move to next word
            i = j + 1;
        }
        // return the transformed string
        return s;
    }
};