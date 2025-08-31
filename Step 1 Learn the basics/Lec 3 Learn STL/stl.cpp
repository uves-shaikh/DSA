#include <bits/stdc++.h>
using namespace std;

/* ---------------- Vector ---------------- */
void demoVector()
{
    cout << "\n=== Vector Demo ===\n";
    vector<int> v = {1, 2, 3};

    v.push_back(4);
    v.emplace_back(5);

    cout << "Vector elements: ";
    for (int x : v)
        cout << x << " ";
    cout << "\n";

    cout << "Size: " << v.size() << "\n";
    cout << "First element: " << v.front() << ", Last: " << v.back() << "\n";
}

/* ---------------- Set ---------------- */
void demoSet()
{
    cout << "\n=== Set Demo ===\n";
    set<int> s;
    for (int i = 1; i <= 5; i++)
        s.insert(i);
    s.emplace(10);

    cout << "Set elements: ";
    for (int x : s)
        cout << x << " ";
    cout << "\n";

    int n = 3;
    if (s.find(n) != s.end())
        cout << n << " found in set\n";

    cout << "First element: " << *s.begin() << ", Last: " << *s.rbegin() << "\n";
    cout << "Size: " << s.size() << "\n";

    s.erase(s.begin());
    cout << "After erasing first element: ";
    for (int x : s)
        cout << x << " ";
    cout << "\n";

    s.clear();
    cout << "Size after clear: " << s.size() << "\n";
}

/* ---------------- Unordered Set ---------------- */
void demoUnorderedSet()
{
    cout << "\n=== Unordered Set Demo ===\n";
    unordered_set<int> us = {1, 2, 3, 4, 5};

    us.insert(10);
    us.emplace(20);

    cout << "Unordered set elements: ";
    for (int x : us)
        cout << x << " ";
    cout << "\n";

    if (us.count(2))
        cout << "2 is present\n";

    us.erase(3);
    cout << "After erasing 3: ";
    for (int x : us)
        cout << x << " ";
    cout << "\n";
}

/* ---------------- Multiset ---------------- */
void demoMultiset()
{
    cout << "\n=== Multiset Demo ===\n";
    multiset<int> ms = {1, 1, 2, 2, 3};

    cout << "Multiset elements: ";
    for (int x : ms)
        cout << x << " ";
    cout << "\n";

    ms.erase(ms.find(1));
    cout << "After erasing one '1': ";
    for (int x : ms)
        cout << x << " ";
    cout << "\n";
}

/* ---------------- Map ---------------- */
void demoMap()
{
    cout << "\n=== Map Demo ===\n";
    map<int, string> mp;

    mp[1] = "One";
    mp[2] = "Two";
    mp.emplace(3, "Three");

    for (auto &p : mp)
        cout << p.first << " -> " << p.second << "\n";

    mp.erase(2);
    cout << "After erasing key 2:\n";
    for (auto &p : mp)
        cout << p.first << " -> " << p.second << "\n";
}

/* ---------------- Unordered Map ---------------- */
void demoUnorderedMap()
{
    cout << "\n=== Unordered Map Demo ===\n";
    unordered_map<string, int> ump;

    ump["apple"] = 5;
    ump["banana"] = 10;
    ump.emplace("cherry", 15);

    for (auto &p : ump)
        cout << p.first << " -> " << p.second << "\n";
}

/* ---------------- Multimap ---------------- */
void demoMultimap()
{
    cout << "\n=== Multimap Demo ===\n";
    multimap<int, string> mm;

    mm.insert({1, "One"});
    mm.insert({1, "Uno"});
    mm.insert({2, "Two"});

    for (auto &p : mm)
        cout << p.first << " -> " << p.second << "\n";
}

/* ---------------- Unordered Multimap ---------------- */
void demoUnorderedMultimap()
{
    cout << "\n=== Unordered Multimap Demo ===\n";
    unordered_multimap<int, string> umm;

    umm.emplace(1, "One");
    umm.emplace(1, "Uno");
    umm.emplace(2, "Two");

    for (auto &p : umm)
        cout << p.first << " -> " << p.second << "\n";
}

/* ---------------- Stack ---------------- */
void demoStack()
{
    cout << "\n=== Stack Demo ===\n";
    stack<int> st;

    st.push(1);
    st.push(2);
    st.emplace(3);

    cout << "Top: " << st.top() << "\n";
    st.pop();
    cout << "After pop, Top: " << st.top() << "\n";
}

/* ---------------- Queue ---------------- */
void demoQueue()
{
    cout << "\n=== Queue Demo ===\n";
    queue<int> q;

    q.push(10);
    q.push(20);
    q.emplace(30);

    cout << "Front: " << q.front() << ", Back: " << q.back() << "\n";
    q.pop();
    cout << "After pop, Front: " << q.front() << "\n";
}

/* ---------------- Deque ---------------- */
void demoDeque()
{
    cout << "\n=== Deque Demo ===\n";
    deque<int> dq;

    dq.push_back(1);
    dq.push_front(2);
    dq.emplace_back(3);

    cout << "Deque elements: ";
    for (int x : dq)
        cout << x << " ";
    cout << "\n";

    dq.pop_front();
    cout << "After pop_front: ";
    for (int x : dq)
        cout << x << " ";
    cout << "\n";
}

/* ---------------- Priority Queue ---------------- */
void demoPriorityQueue()
{
    cout << "\n=== Priority Queue Demo ===\n";
    priority_queue<int> pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);

    cout << "Top element: " << pq.top() << "\n";
    pq.pop();
    cout << "After pop, Top: " << pq.top() << "\n";
}

/* ---------------- List ---------------- */
void demoList()
{
    cout << "\n=== List Demo ===\n";
    list<int> lst = {1, 2, 3};

    lst.push_front(0);
    lst.emplace_back(4);

    cout << "List elements: ";
    for (int x : lst)
        cout << x << " ";
    cout << "\n";
}

/* ---------------- next_permutation ---------------- */
void demoNextPermutation()
{
    cout << "\n=== Next Permutation Demo ===\n";
    vector<int> v = {1, 2, 3};

    cout << "Original: ";
    for (int x : v)
        cout << x << " ";
    cout << "\n";

    next_permutation(v.begin(), v.end());

    cout << "Next permutation: ";
    for (int x : v)
        cout << x << " ";
    cout << "\n";
}

/* ---------------- builtin_popcount ---------------- */
void demoBuiltinPopcount()
{
    cout << "\n=== Builtin Popcount Demo ===\n";
    int x = 29; // binary 11101

    cout << "Number of set bits in " << x << " = " << __builtin_popcount(x) << "\n";
}

/* ---------------- sort, min, max ---------------- */
void demoSortMinMax()
{
    cout << "\n=== Sort / Min / Max Demo ===\n";
    vector<int> v = {4, 2, 5, 1, 3};

    sort(v.begin(), v.end());
    cout << "Sorted: ";
    for (int x : v)
        cout << x << " ";
    cout << "\n";

    cout << "Min element: " << *min_element(v.begin(), v.end()) << "\n";
    cout << "Max element: " << *max_element(v.begin(), v.end()) << "\n";
}

/* ---------------- MAIN ---------------- */
int main()
{
    demoVector();
    demoSet();
    demoUnorderedSet();
    demoMultiset();
    demoMap();
    demoUnorderedMap();
    demoMultimap();
    demoUnorderedMultimap();
    demoStack();
    demoQueue();
    demoDeque();
    demoPriorityQueue();
    demoList();
    demoNextPermutation();
    demoBuiltinPopcount();
    demoSortMinMax();
    return 0;
}
