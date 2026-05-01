This is going to be a long but complete guide. Let me break it down rating by rating.

---

# 800–1000: The Foundations

At this level, problems are mostly about reading input correctly, doing simple math, and using arrays or vectors with sorting. The challenge isn't the data structure — it's understanding what the problem is actually asking.

## `vector`

A vector is a dynamic array. You use it when you don't know the size at compile time, or when you need to push elements one by one. The most important thing to internalize is that `vector` indexing is zero-based and accessing out of bounds is undefined behavior — no error, just garbage or a crash.

```cpp
vector<int> v(n);          // size n, all zeros
vector<int> v(n, -1);      // size n, all -1
v.push_back(x);            // add to end
v.size();                  // returns size_t (unsigned!) — careful with subtraction
v.empty();                 // safer than v.size() == 0
```

The unsigned `size()` is a classic edge case. If you write `v.size() - 1` when the vector is empty, you get a massive positive number (underflow), not `-1`. Always check `v.empty()` first.

An unconventional use is using a vector as a frequency table:
```cpp
vector<int> freq(26, 0);
for (char c : s) freq[c - 'a']++;  // count letter frequencies
```

## `string`

Strings in C++ are mutable and support most vector operations. You can index them, iterate them, sort them, and reverse them.

```cpp
string s;
cin >> s;               // reads one word
getline(cin, s);        // reads full line including spaces

sort(s.begin(), s.end());          // sort characters
reverse(s.begin(), s.end());
s.substr(start, length);           // substring
s.find("abc");                     // returns index or string::npos if not found
```

The `string::npos` edge case trips people up constantly. `find()` returns `string::npos` (which is essentially the max value of `size_t`) when nothing is found, not `-1`. So always check `if (s.find(x) != string::npos)`.

## `sort` and `min`/`max`

`sort` runs in O(n log n) and is your default tool for ordering anything. `min` and `max` work on two values of the same type — a common mistake is mixing `int` and `long long`, which causes a compile error.

```cpp
sort(v.begin(), v.end());                         // ascending
sort(v.begin(), v.end(), greater<int>());         // descending
int smallest = *min_element(v.begin(), v.end()); // min of whole vector
```

**Codeforces Problems:**
- [**158A — Next Round**](https://codeforces.com/problemset/problem/158/A) — sorting + simple condition
- [**339A — Helpful Maths**](https://codeforces.com/problemset/problem/339/A) — string parsing + sort (you just solved this)
- [**977B — Two-gram**](https://codeforces.com/problemset/problem/977/B) — string + frequency counting

---

# 1000–1200: Associative Containers

Problems here start requiring you to count things, detect duplicates, or look up values quickly. Brute force loops become too slow.

## `map<K, V>`

A map stores key-value pairs in **sorted order by key**. Every operation — insert, lookup, delete — is O(log n). The most powerful thing about map is that accessing a key that doesn't exist **automatically creates it with a default value (0 for int)**. This is both useful and dangerous.

```cpp
map<string, int> freq;
freq["apple"]++;       // works even if "apple" wasn't there before
freq.count("apple");   // 1 if exists, 0 if not — safer than []
freq.find("apple");    // returns iterator, or freq.end() if not found

// iterating in sorted key order
for (auto& [key, val] : freq) {
    cout << key << " " << val << "\n";
}
```

An unorthodox but powerful use is using a map to simulate a sparse array — when your indices are huge (like up to 10^9) but you only have a few of them, you can't make a real array of that size. A `map<int, int>` handles it cleanly.

## `set<T>`

A set stores **unique, sorted elements**. Insertion and lookup are O(log n). Use it when you need to quickly answer "have I seen this value before?" or "how many distinct elements are there?"

```cpp
set<int> seen;
seen.insert(x);
seen.count(x);         // 1 or 0
seen.erase(x);
seen.size();           // number of distinct elements

// ordered — you can get min and max
*seen.begin();         // smallest
*seen.rbegin();        // largest
```

A useful trick: if you insert all elements of a vector into a set, then copy back, you've removed duplicates while keeping sorted order.

```cpp
vector<int> v = {3, 1, 2, 1, 3};
set<int> s(v.begin(), v.end());
v.assign(s.begin(), s.end());  // v is now {1, 2, 3}
```

## `pair<A, B>`

Pairs are simple but extremely useful for storing two related values together, especially when sorting. Pairs compare **lexicographically** — first by the first element, then by the second.

```cpp
pair<int, int> p = {3, 5};
p.first;   // 3
p.second;  // 5

vector<pair<int,int>> v;
v.push_back({score, index});
sort(v.begin(), v.end());  // sorts by score, then index — automatic!
```

This lets you sort by one value while keeping another value attached — very common pattern.

**Codeforces Problems:**
- [**136A — Presenting a Herd**](https://codeforces.com/problemset/problem/136/A) — map for frequency counting
- [**1426B — Symmetric Matrix**](https://codeforces.com/problemset/problem/1426/B) — set/map logic
- [**expediture 4C — Registration System**](https://codeforces.com/problemset/problem/4/C) — classic map problem

---

# 1200–1400: Stack, Queue, and Binary Search

Problems now involve order-dependent processing (things that depend on what came before or after) and efficient searching in sorted data.

## `stack<T>`

A stack is LIFO — last in, first out. Use it when the most recently seen element is the most relevant one. The classic use case is matching brackets, but it also appears in "nearest greater element" problems.

```cpp
stack<int> st;
st.push(x);
st.top();       // peek at top without removing
st.pop();       // remove top (returns void!)
st.empty();
```

The critical edge case: always check `st.empty()` before calling `st.top()` or `st.pop()`. Calling these on an empty stack is undefined behavior.

An unconventional use: simulating recursion iteratively using a stack, or reversing a sequence (push everything, then pop).

## `queue<T>`

A queue is FIFO — first in, first out. Use it for BFS or any situation where you process things in the order they arrived.

```cpp
queue<int> q;
q.push(x);
q.front();    // peek at front
q.back();     // peek at back
q.pop();      // remove front
q.empty();
```

## `lower_bound` and `upper_bound`

These are among the most powerful tools in competitive programming. They perform **binary search** on any sorted range and return iterators.

`lower_bound(begin, end, x)` returns an iterator to the **first element ≥ x**.
`upper_bound(begin, end, x)` returns an iterator to the **first element > x**.

```cpp
vector<int> v = {1, 2, 4, 4, 5};

auto it = lower_bound(v.begin(), v.end(), 4);
// points to first 4, index 2

auto it2 = upper_bound(v.begin(), v.end(), 4);
// points to 5, index 4

// count occurrences of 4:
int cnt = upper_bound(v.begin(), v.end(), 4) - lower_bound(v.begin(), v.end(), 4);  // 2

// index of lower_bound:
int idx = lower_bound(v.begin(), v.end(), 4) - v.begin();  // 2
```

The important edge case: if no element satisfies the condition, both return `v.end()`. Always check before dereferencing. Also, these **only work correctly on sorted arrays** — using them on unsorted data gives wrong answers silently.

## `accumulate`

Computes the sum (or any reduction) of a range. Lives in `<numeric>`.

```cpp
int total = accumulate(v.begin(), v.end(), 0);         // sum
int product = accumulate(v.begin(), v.end(), 1, multiplies<int>());
```

The third argument is the **starting value**, not an element of the array. A common mistake is passing `0` when working with `long long` — use `0LL` to avoid overflow during accumulation.

**Codeforces Problems:**
- [**1809B — Conveyor**](https://codeforces.com/problemset/problem/1809/B) — queue simulation
- [**276C — Little Girl and Maximum Sum**](https://codeforces.com/problemset/problem/276/C) — sorting + binary search thinking
- [**20B — Longest Increasing Subsequence**](https://codeforces.com/problemset/problem/20/B) — lower_bound for LIS in O(n log n)

---

# 1400–1600: Priority Queue, Unordered Maps, and GCD

Problems here involve greedy algorithms that always need the current minimum or maximum, number theory, and hash-based lookups for speed.

## `priority_queue<T>`

A priority queue is a **max-heap by default** — `top()` always gives you the largest element. Think of it as a queue where the most important element jumps to the front.

```cpp
priority_queue<int> pq;           // max-heap
priority_queue<int, vector<int>, greater<int>> pq;  // min-heap

pq.push(x);
pq.top();     // largest (or smallest for min-heap)
pq.pop();
pq.empty();
```

The most common pattern: Dijkstra's algorithm, or any greedy where you repeatedly pick the best remaining option.

For pairs, it sorts by the first element:
```cpp
priority_queue<pair<int,int>> pq;  // max by first element
pq.push({cost, node});
```

A subtle edge case: `priority_queue` has no way to update an element already inside it. The workaround is to push the updated value and mark old entries as stale (lazy deletion).

## `unordered_map` and `unordered_set`

These are hash-based versions of `map` and `set`. Lookup and insert are **O(1) average** instead of O(log n), which matters when you have 10^5–10^6 operations.

```cpp
unordered_map<int, int> freq;
freq[x]++;
freq.count(x);   // 1 or 0
```

The critical caveat: unordered containers have **O(n) worst case** due to hash collisions. In Codeforces, some problems have anti-hash tests that deliberately cause this. The fix is using a custom hash:

```cpp
struct custom_hash {
    size_t operator()(int x) const {
        x = ((x >> 16) ^ x) * 0x45d9f3b;
        return x;
    }
};
unordered_map<int, int, custom_hash> safe_map;
```

## `gcd` and `lcm`

Available in `<numeric>` since C++17. Used constantly in number theory problems.

```cpp
#include <numeric>
int g = gcd(12, 8);    // 4
int l = lcm(4, 6);     // 12
```

`gcd` of the entire array is a common pattern:
```cpp
int g = v[0];
for (int x : v) g = gcd(g, x);
```

## `next_permutation`

Generates permutations in lexicographic order. Must start from sorted array to get all permutations.

```cpp
vector<int> v = {1, 2, 3};
do {
    // process permutation
} while (next_permutation(v.begin(), v.end()));
```

Only feasible for n ≤ 8 or so (8! = 40320). Beyond that it's too slow.

**Codeforces Problems:**
- [**1915D — Unnatural Treap**](https://codeforces.com/problemset/problem/1915/D) — priority queue + greedy
- [**1442B — Counting Arrays**](https://codeforces.com/problemset/problem/1442/B) — gcd based
- [**525E — Anya and Cubes**](https://codeforces.com/problemset/problem/525/E) — meet in the middle + unordered_map

---

# 1600–1800: Deque, Multiset, and Advanced Techniques

At this level, the data structure choice itself is often the key insight. Brute force is clearly impossible and you need to think about what operation you need to do efficiently.

## `deque<T>`

A deque (double-ended queue) supports O(1) push and pop from **both ends**. Use it when you need a sliding window minimum/maximum (monotonic deque), which is one of the most powerful patterns at this level.

```cpp
deque<int> dq;
dq.push_back(x);
dq.push_front(x);
dq.pop_back();
dq.pop_front();
dq.front();
dq.back();
```

The **monotonic deque** pattern — maintaining a window maximum in O(n) total:
```cpp
deque<int> dq;  // stores indices
for (int i = 0; i < n; i++) {
    // remove elements outside window
    while (!dq.empty() && dq.front() < i - k) dq.pop_front();
    // remove smaller elements (they can never be the max)
    while (!dq.empty() && v[dq.back()] <= v[i]) dq.pop_back();
    dq.push_back(i);
    if (i >= k - 1) cout << v[dq.front()] << " ";  // window max
}
```

## `multiset<T>`

Like `set`, but **allows duplicates**. Crucial when you need sorted order but elements repeat. The tricky part: `erase(value)` removes **all** copies of that value. To remove just one, use an iterator:

```cpp
multiset<int> ms;
ms.insert(5);
ms.insert(5);

ms.erase(5);                          // removes BOTH 5s — dangerous!
ms.erase(ms.find(5));                 // removes only ONE 5 — correct

*ms.begin();   // smallest
*ms.rbegin();  // largest
```

A very powerful pattern: use a multiset to maintain a running sorted structure and always query the min/max efficiently — useful for median maintenance, greedy scheduling, etc.

## `binary_search`

Returns `true` or `false` — just tells you if an element exists in a sorted range. Simpler than `lower_bound` but less flexible.

```cpp
binary_search(v.begin(), v.end(), x);  // true/false
```

In practice, `lower_bound` is more useful because it also tells you **where** the element is.

## `iota`

Fills a range with incrementing values. Used to initialize index arrays for indirect sorting.

```cpp
vector<int> idx(n);
iota(idx.begin(), idx.end(), 0);  // idx = {0, 1, 2, ..., n-1}

// sort indices by value in v
sort(idx.begin(), idx.end(), [&](int a, int b) {
    return v[a] < v[b];
});
// now idx[0] is the index of the smallest element in v
```

This is a clean way to sort one array while tracking original positions, without using pairs.

**Codeforces Problems:**
- [**940E — Aniakast**](https://codeforces.com/problemset/problem/940/E) — multiset + greedy
- [**1354C — Simple Polygon Embedding**](https://codeforces.com/problemset/problem/1354/C) — deque/sliding window
- [**1208E — Let Them Slide**](https://codeforces.com/problemset/problem/1208/E) — deque monotonic window

---

The general progression to keep in mind: at 800–1000 you're learning to *use* these tools, at 1200–1400 you're learning *which* tool fits which problem shape, and at 1600–1800 you're combining multiple tools together and the insight is often in recognizing that a problem is secretly a known pattern in disguise. Want me to go deeper on any specific section?
