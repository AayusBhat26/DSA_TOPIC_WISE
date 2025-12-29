#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // we need to store all those rows that were previously failed and in any combination we managed to reach that same string we would return false as we have already failed
    set<string> rowsThatWereNotValid;

    bool helper(string currentRow, string nextRow, int index, map<string, vector<char>> &mp)
    {
        // when the current row is having a length of 1, that would mean that we successfully built the pyramid with any of the combination
        if (currentRow.length() == 1)
            return true;
        // we have built the next row and we are planning to build the next row from the current next row
        if (nextRow.length() == currentRow.length() - 1)
        {
            // if we have already seen the next row in set that contains the combinations which had failed

            if (rowsThatWereNotValid.find(nextRow) != rowsThatWereNotValid.end())
            {
                return false;
            }

            // calling recursilve to build a new row as the current row was successfully built
            return helper(nextRow, "", 0, mp);
        }
        // find the first two characters and find the substring from current Index so that we can find the possible combination
        string firstTwoCharacter = currentRow.substr(index, 2);
        if (mp.find(firstTwoCharacter) == mp.end())
        {
            return false;
        }
        // getting all the combination characters and trying them all
        for (char ch : mp[firstTwoCharacter])
        {
            // 1. push the character to form a new combination
            nextRow.push_back(ch);
            // 2. check if the next row is valid or not
            if (helper(currentRow, nextRow, index + 1, mp))
                return true;
            // 3. remove the newly added character
            nextRow.pop_back();
        }
        // if it fails to add return true, then it is a failed combination, so insert the current combination into the set
        rowsThatWereNotValid.insert(nextRow);
        // current combination failed therefore return false
        return false;
    }
    bool pyramidTransition(string bottom, vector<string> &allowed)
    {
        // storing the first two characters and all the possible combiation
        // i.e.if we have ABC, ABD => AB => C, D
        map<string, vector<char>> mp;
        for (string &s : allowed)
        {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        /*
            bottom row se start kr rhe hai
            next row would be empty now
            0 -> index in current row
        */
        return helper(bottom, "", 0, mp);
    }
};