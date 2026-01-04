#include <bits/stdc++.h>
using namespace std;
/*
Disjoint Set Union (DSU) or Union-Find Data Structure using SIZE

1. every set has a representative (or parent)
2. This implementation uses SIZE instead of RANK
3. In union operation, we attach the smaller tree to the larger tree
*/

class DSU
{
private:
    vector<int> parent, size;

public:
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1); // initially each element is its own set with size 1
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        // path compression optimization
        return parent[x] = find(parent[x]);
    }

    void union_sets(int x, int y)
    {
        int parentX = find(x);
        int parentY = find(y);

        if (parentX == parentY)
        {
            return; // already in same set
        }

        // union by size: attach smaller tree to larger tree
        if (size[parentX] < size[parentY])
        {
            parent[parentX] = parentY;
            size[parentY] += size[parentX];
        }
        else
        {
            parent[parentY] = parentX;
            size[parentX] += size[parentY];
        }
    }

    int getSize(int x)
    {
        return size[find(x)];
    }
};

// Example usage and test cases
int main()
{
    // Test case 1: Basic union-find operations
    DSU dsu(6);

    dsu.union_sets(0, 1);
    dsu.union_sets(1, 2);
    dsu.union_sets(3, 4);

    cout << "Set of 0: " << dsu.find(0) << endl;
    cout << "Set of 2: " << dsu.find(2) << endl;
    cout << "Set of 4: " << dsu.find(4) << endl;
    cout << "Size of set containing 1: " << dsu.getSize(1) << endl;
    cout << "Size of set containing 4: " << dsu.getSize(4) << endl;

    // Test case 2: Check if elements are in same set
    dsu.union_sets(2, 3);
    cout << "\nAfter union_sets(2, 3):" << endl;
    cout << "Set of 0: " << dsu.find(0) << endl;
    cout << "Set of 3: " << dsu.find(3) << endl;
    cout << "Are 0 and 3 in same set? " << (dsu.find(0) == dsu.find(3) ? "Yes" : "No") << endl;

    return 0;
}
