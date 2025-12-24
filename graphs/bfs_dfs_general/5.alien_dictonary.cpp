#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string findOrder(vector<string> &words)
    {
        // code here
        int n = words.size();

        unordered_map<int, vector<int>> graph;

        vector<int> indegreeTracker(26, 0);

        vector<int> characterPresent(26, false);

        // we have to deal with only those characters which are present in strings.

        for (auto &word : words)
        {
            for (char &ch : word)
            {
                characterPresent[ch - 'a'] = true;
            }
        }
        bool found = false;
        for (int i = 0; i < n - 1; i++)
        {

            string s1 = words[i];
            string s2 = words[i + 1];

            // find the first distinct character

            int len = min(s1.length(), s2.length());

            for (int j = 0; j < len; j++)
            {

                if (s1[j] != s2[j])
                {

                    int firstStringCharacterIndex = s1[j] - 'a';
                    int sescondStringCharacterIndex = s2[j] - 'a';

                    graph[firstStringCharacterIndex].push_back(sescondStringCharacterIndex);

                    indegreeTracker[sescondStringCharacterIndex]++;
                    found = true;
                    break; // we are done, just move to next couple of strings.
                }
            }
            // length of first string > length of second string and we haven't found any distinct character.
            // i.e. each character is same
            if (!found && s1.length() > s2.length())
                return "";
        }

        // graph is built .
        queue<int> q;
        // topological sorting since we want something to be before something
        for (int i = 0; i < 26; i++)
        {
            if (characterPresent[i] && indegreeTracker[i] == 0)
            {
                q.push(i);
            }
        }
        string res = "";
        int count = 0;
        while (!q.empty())
        {
            int currentNode = q.front();
            q.pop();
            res.push_back(currentNode + 'a');
            count++;
            // visit all the neighbours
            for (auto &it : graph[currentNode])
            {
                indegreeTracker[it]--;
                if (indegreeTracker[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        // we need to check if there is any cycle
        int totalPresent = 0;
        for (int i = 0; i < 26; i++)
        {
            if (characterPresent[i])
                totalPresent++;
        }
        if (count < totalPresent)
            return "";

        return res;
    }
};