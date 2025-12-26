#include <bits/stdc++.h>
using namespace std;

// merge function
int mergeF(int first, int second)
{
    return min(first, second);
}

// build function
void build(int sgtree[], int arr[], int node, int start, int end)
{
    if (start == end)
    {
        sgtree[node] = arr[start];
        return;
    }

    int mid = start + (end - start) / 2;

    build(sgtree, arr, 2 * node + 1, start, mid);
    build(sgtree, arr, 2 * node + 2, mid + 1, end);

    sgtree[node] = mergeF(sgtree[2 * node + 1], sgtree[2 * node + 2]);
}
int *constructST(int arr[], int n)
{
    int *segmentTree = new int[4 * n];

    build(segmentTree, arr, 0, 0, n - 1);

    return segmentTree;
}

int query(int queryStart, int queryEnd, int segmentStart, int segmentEnd, int node, int arr[])
{

    if (queryEnd < segmentStart || segmentEnd < queryStart)
    {
        return INT_MAX;
    }

    // overlap: query overlaps the segment

    if (segmentStart >= queryStart && segmentEnd <= queryEnd)
    {
        return arr[node];
    }
    int mid = segmentStart + (segmentEnd - segmentStart) / 2;

    return min(query(queryStart, queryEnd, segmentStart, mid, 2 * node + 1, arr),
               query(queryStart, queryEnd, mid + 1, segmentEnd, 2 * node + 2, arr));
}
int RMQ(int st[], int n, int a, int b)
{
    return query(a, b, 0, n - 1, 0, st);
}