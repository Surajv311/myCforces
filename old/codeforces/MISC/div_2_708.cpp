/*


A. Meximization
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an integer n and an array a1,a2,…,an. You should reorder the elements of the array a in such way that the sum of MEX on prefixes (i-th prefix is a1,a2,…,ai) is maximized.

Formally, you should find an array b1,b2,…,bn, such that the sets of elements of arrays a and b are equal (it is equivalent to array b can be found as an array a with some reordering of its elements) and ∑i=1nMEX(b1,b2,…,bi) is maximized.

MEX of a set of nonnegative integers is the minimal nonnegative integer such that it is not in the set.

For example, MEX({1,2,3})=0, MEX({0,1,2,4,5})=3.

Input
The first line contains a single integer t (1≤t≤100)  — the number of test cases.

The first line of each test case contains a single integer n (1≤n≤100).

The second line of each test case contains n integers a1,a2,…,an (0≤ai≤100).

Output
For each test case print an array b1,b2,…,bn  — the optimal reordering of a1,a2,…,an, so the sum of MEX on its prefixes is maximized.

If there exist multiple optimal answers you can find any.

Example
inputCopy
3
7
4 2 0 1 3 3 7
5
2 2 8 6 9
1
0
outputCopy
0 1 2 3 4 7 3
2 6 8 9 2
0
Note
In the first test case in the answer MEX for prefixes will be:

MEX({0})=1
MEX({0,1})=2
MEX({0,1,2})=3
MEX({0,1,2,3})=4
MEX({0,1,2,3,4})=5
MEX({0,1,2,3,4,7})=5
MEX({0,1,2,3,4,7,3})=5
The sum of MEX=1+2+3+4+5+5+5=25. It can be proven, that it is a maximum possible sum of MEX on prefixes.




To maximize the sum of MEX on prefixes we will use a greedy algorithm. Firstly we put all unique elements in increasing order to get maximal MEX on each prefix. It is easy to see that replacing any two elements after that makes both MEX and sum of MEX less.

In the end we put all elements that are not used in any order because MEX will not change and will still be maximal.

Implementation
// один манул
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T --> 0) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        vector<int> b;
        for (int i = 0; i < n; i++) {
            if (i == 0 || a[i] != a[i — 1]) {
                b.emplace_back(a[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (i > 0 && a[i] == a[i — 1]) {
                b.emplace_back(a[i]);
            }
        }
        for (auto x : b) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}

---------------------------------------------------

B. M-arrays
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array a1,a2,…,an consisting of n positive integers and a positive integer m.

You should divide elements of this array into some arrays. You can order the elements in the new arrays as you want.

Let's call an array m-divisible if for each two adjacent numbers in the array (two numbers on the positions i and i+1 are called adjacent for each i) their sum is divisible by m. An array of one element is m-divisible.

Find the smallest number of m-divisible arrays that a1,a2,…,an is possible to divide into.

Input
The first line contains a single integer t (1≤t≤1000)  — the number of test cases.

The first line of each test case contains two integers n, m (1≤n≤105,1≤m≤105).

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109).

It is guaranteed that the sum of n and the sum of m over all test cases do not exceed 105.

Output
For each test case print the answer to the problem.

Example
inputCopy
4
6 4
2 2 8 6 9 4
10 8
1 1 1 5 2 4 4 8 6 7
1 1
666
2 2
2 4
outputCopy
3
6
1
1
Note
In the first test case we can divide the elements as follows:

[4,8]. It is a 4-divisible array because 4+8 is divisible by 4.
[2,6,2]. It is a 4-divisible array because 2+6 and 6+2 are divisible by 4.
[9]. It is a 4-divisible array because it consists of one element.



Let's take each number modulo m. Now let cntx be the amount of x in array a.

If cnt0≠0, then all 0 should be put in a single array, answer increases by 1.
For each number x≠0 we put it in an array x,m−x,x,m−x,… In this array the amount of x and the amount of m−x should differ not more than by 1, that's why we need to make max(0,|cntx−cntm−x|−1) arrays, containing a single number (x or m−x) that is more common.
Implementation
//два манула
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        map<int, int> cnt;
        while (n--) {
            int x;
            cin >> x;
            cnt[x % m]++;
        }
        int ans = 0;
        for (auto &c : cnt) {
            if (c.first == 0) ans++;
            else if (2 * c.first == m) {
                ans++;
            } else if (2 * c.first < m || cnt.find(m — c.first) == cnt.end()) {
                int x = c.second, y = cnt[m — c.first];
                ans += 1 + max(0, abs(x — y) — 1);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}



--------------------------------------



C2. k-LCM (hard version)
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
It is the hard version of the problem. The only difference is that in this version 3≤k≤n.

You are given a positive integer n. Find k positive integers a1,a2,…,ak, such that:

a1+a2+…+ak=n
LCM(a1,a2,…,ak)≤n2
Here LCM is the least common multiple of numbers a1,a2,…,ak.

We can show that for given constraints the answer always exists.

Input
The first line contains a single integer t (1≤t≤104)  — the number of test cases.

The only line of each test case contains two integers n, k (3≤n≤109, 3≤k≤n).

It is guaranteed that the sum of k over all test cases does not exceed 105.

Output
For each test case print k positive integers a1,a2,…,ak, for which all conditions are satisfied.

Example
inputCopy
2
6 4
9 5
outputCopy
1 2 2 1
1 3 3 1 1



1497C2 - k-LCM (hard version)
In this solution we will reuse the solution for k=3.

The answer will be 1,1,…,1 (k−3 times) and the solution a,b,c of the easy version for n−k+3.

(1+1+…+1)+(a+b+c)=(k−3)+(n−k−3)=n.

Also LCM(1,1,…,1,a,b,c)=LCM(a,b,c)≤n−k+32≤n2.

Implementation
// четыре манула
#include <bits/stdc++.h>
using namespace std;

vector<int> solve3(int n) {
    if (n % 2 == 1) return {1, n / 2, n / 2};
    if (n % 4 == 0) return {n / 2, n / 4, n / 4};
    if (n % 2 == 0) return {2, n / 2 — 1, n / 2 — 1};
}

int main() {
    int T;
    cin >> T;
    while (T --> 0) {
        int n, k;
        cin >> n >> k;
        vector<int> added = solve3(n — k + 3);
        for (int i = 0; i < k; ++i) {
            cout << (i <3 ? added[i] : 1) << ' '; // <3
        }
        cout << '\n';
    }
    return 0;
}


---------------------------------------------------



D. Genius
time limit per test2 seconds
memory limit per test32 megabytes
inputstandard input
outputstandard output
Please note the non-standard memory limit.

There are n problems numbered with integers from 1 to n. i-th problem has the complexity ci=2i, tag tagi and score si.

After solving the problem i it's allowed to solve problem j if and only if IQ<|ci−cj| and tagi≠tagj. After solving it your IQ changes and becomes IQ=|ci−cj| and you gain |si−sj| points.

Any problem can be the first. You can solve problems in any order and as many times as you want.

Initially your IQ=0. Find the maximum number of points that can be earned.

Input
The first line contains a single integer t (1≤t≤100)  — the number of test cases.

The first line of each test case contains an integer n (1≤n≤5000)  — the number of problems.

The second line of each test case contains n integers tag1,tag2,…,tagn (1≤tagi≤n)  — tags of the problems.

The third line of each test case contains n integers s1,s2,…,sn (1≤si≤109)  — scores of the problems.

It's guaranteed that sum of n over all test cases does not exceed 5000.

Output
For each test case print a single integer  — the maximum number of points that can be earned.

Example
inputCopy
5
4
1 2 3 4
5 10 15 20
4
1 2 1 2
5 10 15 20
4
2 2 4 1
2 8 19 1
2
1 1
6 9
1
1
666
outputCopy
35
30
42
0
0
Note
In the first test case optimal sequence of solving problems is as follows:

1→2, after that total score is 5 and IQ=2
2→3, after that total score is 10 and IQ=4
3→1, after that total score is 20 and IQ=6
1→4, after that total score is 35 and IQ=14
In the second test case optimal sequence of solving problems is as follows:

1→2, after that total score is 5 and IQ=2
2→3, after that total score is 10 and IQ=4
3→4, after that total score is 15 and IQ=8
4→1, after that total score is 35 and IQ=14
In the third test case optimal sequence of solving problems is as follows:

1→3, after that total score is 17 and IQ=6
3→4, after that total score is 35 and IQ=8
4→2, after that total score is 42 and IQ=12




1497D - Genius
Let's consider a graph where vertexes are problems and there is an edge {i,j} between vertexes i and j with weight |ci−cj|. Each edge has a unique weight. Let's prove that. Let's assume that weight=|2i−2j| and i>j. Then in binary form weight has its k-th bit set true if and only if j≤k<i. Then for each unique pair {i,j} weight is unique too since the corners of a subsegment with true bits are unique.

Let dpi be the maximal amount of points that may be earned ending with problem i. Initially dpi=0 for each 1≤i≤n. Let's consider all edges in increasing order (because IQ should increase). To do that we can consider j in increasing order from 2 to n and then i in decreasing order from j−1 to 1. It is also explained by the binary form of the weight.

Now let's relax dp values. When we consider an edge {i,j},tagi≠tagj we try to solve problem i after solving dpj problems ending with j, and problem i after solving dpi problems ending with i. It means that dpi=max(dpi,dpj+p),dpj=max(dpj,dpi+p) at the same time, where p=|si−sj|. After considering all edges the answer is the maximal value among all dp values.

Implementation
// пять манулов
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T --> 0) {
        int n;
        cin >> n;
        vector<long long> s(n), tag(n), dp(n, 0);
        for (int i = 0; i < n; ++i) cin >> tag[i];
        for (int i = 0; i < n; ++i) cin >> s[i];
        for (int j = 1; j < n; ++j) {
            for (int i = j — 1; i >= 0; --i) {
                if (tag[i] == tag[j]) continue;
                long long dpi = dp[i], dpj = dp[j], p = abs(s[i] — s[j]);
                dp[i] = max(dp[i], dpj + p);
                dp[j] = max(dp[j], dpi + p);
            }
        }
        cout << *max_element(dp.begin(), dp.end()) << '\n';
    }
    return 0;
}


----------------------------------------------



















































































*/