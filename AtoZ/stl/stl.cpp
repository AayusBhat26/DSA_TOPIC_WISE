#include <bits/stdc++.h>
using namespace std;

void vectors() {
    vector<int> v = {1, 2, 3};
    v.push_back(4);              // Add at end
    v.pop_back();                // Remove last
    v.insert(v.begin() + 1, 10); // Insert at position
    v.erase(v.begin());          // Remove at position
    v.clear();                   // Clear all
    v.resize(5, 0);              // Resize with default value
    cout << v.size() << " " << v.empty() << "\n";
    cout << v.front() << " " << v.back() << "\n";
}

void pairs() {
    pair<int, string> p = {1, "hello"};
    cout << p.first << " " << p.second << "\n";
    pair<int, pair<int, int>> nested = {1, {2, 3}};
    vector<pair<int, int>> vp = {{1, 2}, {3, 4}};
}

void sets() {
    set<int> s = {3, 1, 2, 1};   // Sorted, unique: {1,2,3}
    s.insert(4);
    s.erase(2);
    cout << s.count(3) << "\n";   // 0 or 1
    auto it = s.find(3);          // Iterator or s.end()
    auto lb = s.lower_bound(2);   // >= value
    auto ub = s.upper_bound(2);   // > value
    
    multiset<int> ms = {1, 1, 2}; // Allows duplicates
    ms.erase(ms.find(1));         // Erase one occurrence
}

void maps() {
    map<string, int> m;
    m["apple"] = 5;
    m["banana"] = 3;
    m.insert({"cherry", 7});
    m.erase("apple");
    cout << m.count("banana") << "\n";
    
    for (auto &[key, val] : m) {
        cout << key << " " << val << "\n";
    }
    
    multimap<int, string> mm;     // Multiple values per key
    unordered_map<int, int> um;   // O(1) average, no order
}

void stacks_queues() {
    stack<int> st;
    st.push(1);
    st.push(2);
    cout << st.top() << "\n";     // 2
    st.pop();
    
    queue<int> q;
    q.push(1);
    q.push(2);
    cout << q.front() << " " << q.back() << "\n";
    q.pop();
    
    deque<int> dq;
    dq.push_front(1);
    dq.push_back(2);
    dq.pop_front();
    dq.pop_back();
}

void priority_queues() {
    priority_queue<int> pq;       // Max heap
    pq.push(3);
    pq.push(1);
    pq.push(2);
    cout << pq.top() << "\n";     // 3
    pq.pop();
    
    priority_queue<int, vector<int>, greater<int>> minpq; // Min heap
    minpq.push(3);
    minpq.push(1);
    cout << minpq.top() << "\n";  // 1
}

void algorithms_sort() {
    vector<int> v = {3, 1, 4, 1, 5};
    sort(v.begin(), v.end());                      // Ascending
    sort(v.begin(), v.end(), greater<int>());      // Descending
    
    vector<pair<int, int>> vp = {{2, 1}, {1, 3}, {1, 2}};
    sort(vp.begin(), vp.end());                    // Sorts by first, then second
    
    // Custom comparator
    sort(v.begin(), v.end(), [](int a, int b) {
        return a > b;  // Descending
    });
}

void algorithms_search() {
    vector<int> v = {1, 2, 3, 4, 5};
    
    // Binary search (needs sorted array)
    bool found = binary_search(v.begin(), v.end(), 3);
    auto lb = lower_bound(v.begin(), v.end(), 3);  // >= 3
    auto ub = upper_bound(v.begin(), v.end(), 3);  // > 3
    
    // Linear search
    auto it = find(v.begin(), v.end(), 3);
    int cnt = count(v.begin(), v.end(), 3);
    
    // Min/Max element
    auto minit = min_element(v.begin(), v.end());
    auto maxit = max_element(v.begin(), v.end());
}

void algorithms_manipulation() {
    vector<int> v = {1, 2, 3, 4, 5};
    
    reverse(v.begin(), v.end());
    rotate(v.begin(), v.begin() + 2, v.end());     // Rotate left by 2
    
    int sum = accumulate(v.begin(), v.end(), 0);
    int prod = accumulate(v.begin(), v.end(), 1, multiplies<int>());
    
    int mx = *max_element(v.begin(), v.end());
    int mn = *min_element(v.begin(), v.end());
    
    // Permutations
    do {
        // Process permutation
    } while (next_permutation(v.begin(), v.end()));
}

void strings() {
    string s = "hello";
    s += " world";
    s.push_back('!');
    s.pop_back();
    
    string sub = s.substr(0, 5);                   // "hello"
    int pos = s.find("world");                     // Position or string::npos
    s.replace(0, 5, "hi");                         // Replace range
    
    // String to number
    int num = stoi("123");
    long long ln = stoll("123456789");
    double d = stod("3.14");
    
    // Number to string
    string str = to_string(123);
    
    // String stream
    stringstream ss("1 2 3");
    int a, b, c;
    ss >> a >> b >> c;
}

void bits() {
    int n = 5;  // 101 in binary
    
    int set_bit = n | (1 << 2);                    // Set 2nd bit
    int clear_bit = n & ~(1 << 0);                 // Clear 0th bit
    int toggle_bit = n ^ (1 << 2);                 // Toggle 2nd bit
    bool check_bit = n & (1 << 0);                 // Check 0th bit
    
    int cnt = __builtin_popcount(n);               // Count set bits
    int cntll = __builtin_popcountll(1LL << 40);   // For long long
    int leading = __builtin_clz(n);                // Leading zeros
    int trailing = __builtin_ctz(8);               // Trailing zeros
}

void iterators() {
    vector<int> v = {1, 2, 3, 4, 5};
    
    // Forward iteration
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    
    // Reverse iteration
    for (auto it = v.rbegin(); it != v.rend(); it++) {
        cout << *it << " ";
    }
    
    // Range-based loop
    for (auto &x : v) {
        x *= 2;  // Modify
    }
    
    // Iterator operations
    auto it = v.begin();
    advance(it, 2);                                // Move forward
    int dist = distance(v.begin(), v.end());       // Distance
}

void useful_tricks() {
    // Unique elements in sorted array
    vector<int> v = {1, 1, 2, 2, 3};
    v.erase(unique(v.begin(), v.end()), v.end());
    
    // Remove specific value
    v.erase(remove(v.begin(), v.end(), 2), v.end());
    
    // Copy and fill
    vector<int> v2(5);
    fill(v2.begin(), v2.end(), 10);
    copy(v.begin(), v.end(), back_inserter(v2));
    
    // Swap
    swap(v, v2);
    
    // Comparisons
    vector<int> a = {1, 2}, b = {1, 3};
    cout << (a < b) << "\n";                       // Lexicographic
}

void lambda_functions() {
    // Basic lambda
    auto add = [](int a, int b) { return a + b; };
    cout << add(3, 4) << "\n";
    
    // Capture by value
    int x = 10;
    auto f1 = [x]() { return x * 2; };
    
    // Capture by reference
    auto f2 = [&x]() { x *= 2; };
    
    // Capture all by value/reference
    auto f3 = [=]() { return x; };
    auto f4 = [&]() { x++; };
    
    // Use in sort
    vector<int> v = {3, 1, 2};
    sort(v.begin(), v.end(), [](int a, int b) {
        return abs(a) < abs(b);
    });
}

int main() {
    cout << "=== Vectors ===\n";
    vectors();
    
    cout << "\n=== Pairs ===\n";
    pairs();
    
    cout << "\n=== Sets ===\n";
    sets();
    
    cout << "\n=== Maps ===\n";
    maps();
    
    cout << "\n=== Stacks & Queues ===\n";
    stacks_queues();
    
    cout << "\n=== Priority Queues ===\n";
    priority_queues();
    
    cout << "\n=== Algorithms: Sort ===\n";
    algorithms_sort();
    
    cout << "\n=== Algorithms: Search ===\n";
    algorithms_search();
    
    cout << "\n=== Algorithms: Manipulation ===\n";
    algorithms_manipulation();
    
    cout << "\n=== Strings ===\n";
    strings();
    
    cout << "\n=== Bit Manipulation ===\n";
    bits();
    
    cout << "\n=== Iterators ===\n";
    iterators();
    
    cout << "\n=== Useful Tricks ===\n";
    useful_tricks();
    
    cout << "\n=== Lambda Functions ===\n";
    lambda_functions();
    
    return 0;
}
