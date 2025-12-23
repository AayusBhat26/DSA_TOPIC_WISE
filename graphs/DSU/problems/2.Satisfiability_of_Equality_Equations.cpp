#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> parent, rank;
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    void unionSets(int x, int y)
    {
        int parentx = find(x);
        int parenty = find(y);
        if (parentx == parenty)
        {
            return;
        }
        if (rank[parentx] > rank[parenty])
        {
            parent[parenty] = parentx;
        }
        else if (rank[parentx] < rank[parenty])
        {
            parent[parentx] = parenty;
        }
        else
        {
            parent[parenty] = parentx;
            rank[parentx] += 1;
        }
    }
};

class Solution
{
public:
    bool equationsPossible(vector<string> &equations)
    {
        DSU *d = new DSU(26);
        // in this question we are supposed to check if it possible to assign variables with values

        /*
            example: a == b, a != b
            if first index character is "=", do the union
            if first index character is "!", and if the parent of both variables are same, then we return a false.
         */
        /*
        * steps :
            1. create a DSU with 26 size as we only have 26 characters in english alphabeta
            2. when we have "=" at the index = 1, we do union
            3. if it is "!", we find the parent, and if the parent are same, we return false
            4. in the end, if the entire process did not returns a false, we return true;
        */

        for (string &it : equations)
        {
            if (it[1] == '=')
            {
                int firstChar = it[0] - 'a';
                int secondChar = it[3] - 'a';
                d->unionSets(firstChar, secondChar);
            }
        }

        for (string &it : equations)
        {
            if (it[1] == '!')
            {
                int firstChar = it[0] - 'a';
                int secondChar = it[3] - 'a';
                int firstCharParent = d->find(firstChar);
                int secondCharParent = d->find(secondChar);
                if (firstCharParent == secondCharParent)
                {
                    return false;
                }
            }
        }
        delete d;
        return true;
    }
};