/*


A. Strange Table
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Polycarp found a rectangular table consisting of n rows and m columns. He noticed that each cell of the table has its number, obtained by the following algorithm "by columns":

cells are numbered starting from one;
cells are numbered from left to right by columns, and inside each column from top to bottom;
number of each cell is an integer one greater than in the previous cell.
For example, if n=3 and m=5, the table will be numbered as follows:

123456789101112131415
However, Polycarp considers such numbering inconvenient. He likes the numbering "by rows":

cells are numbered starting from one;
cells are numbered from top to bottom by rows, and inside each row from left to right;
number of each cell is an integer one greater than the number of the previous cell.
For example, if n=3 and m=5, then Polycarp likes the following table numbering:
161127123813491451015
Polycarp doesn't have much time, so he asks you to find out what would be the cell number in the numbering "by rows", if in the numbering "by columns" the cell has the number x?

Input
The first line contains a single integer t (1≤t≤104). Then t test cases follow.

Each test case consists of a single line containing three integers n, m, x (1≤n,m≤106, 1≤x≤n⋅m), where n and m are the number of rows and columns in the table, and x is the cell number.

Note that the numbers in some test cases do not fit into the 32-bit integer type, so you must use at least the 64-bit integer type of your programming language.

Output
For each test case, output the cell number in the numbering "by rows".

Example
inputCopy
5
1 1 1
2 2 3
3 5 11
100 100 7312
1000000 1000000 1000000000000
outputCopy
1
2
9
1174
1000000000000





To find the cell number in a different numbering, you can find (r,c) coordinates of the cell with the number x in the numbering "by columns":

r=((x−1)modr)+1, where amodb is the remainder of dividing the number a by the number b;
c=⌈xn⌉, where ⌈ab⌉ is the division of the number a to the number b rounded up.
Then, the cell number in numbering "by lines" will be equal to (r−1)∗m+c.

Solution
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, m, x;
    cin >> n >> m >> x;
    x--;
    ll col = x / n;
    ll row = x % n;
    cout << row * m + col + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}

-----------------------------------------------------------






C. Double-ended Strings
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given the strings a and b, consisting of lowercase Latin letters. You can do any number of the following operations in any order:

if |a|>0 (the length of the string a is greater than zero), delete the first character of the string a, that is, replace a with a2a3…an;
if |a|>0, delete the last character of the string a, that is, replace a with a1a2…an−1;
if |b|>0 (the length of the string b is greater than zero), delete the first character of the string b, that is, replace b with b2b3…bn;
if |b|>0, delete the last character of the string b, that is, replace b with b1b2…bn−1.
Note that after each of the operations, the string a or b may become empty.

For example, if a="hello" and b="icpc", then you can apply the following sequence of operations:

delete the first character of the string a ⇒ a="ello" and b="icpc";
delete the first character of the string b ⇒ a="ello" and b="cpc";
delete the first character of the string b ⇒ a="ello" and b="pc";
delete the last character of the string a ⇒ a="ell" and b="pc";
delete the last character of the string b ⇒ a="ell" and b="p".
For the given strings a and b, find the minimum number of operations for which you can make the strings a and b equal. Note that empty strings are also equal.

Input
The first line contains a single integer t (1≤t≤100). Then t test cases follow.

The first line of each test case contains the string a (1≤|a|≤20), consisting of lowercase Latin letters.

The second line of each test case contains the string b (1≤|b|≤20), consisting of lowercase Latin letters.

Output
For each test case, output the minimum number of operations that can make the strings a and b equal.

Example
inputCopy
5
a
a
abcd
bc
hello
codeforces
hello
helo
dhjakjsnasjhfksafasd
adjsnasjhfksvdafdser
outputCopy
0
2
13
3
20


~ its like LCSubstring implementation......

riy

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
#define MOD 998244353
#define ll_BITS 32
#define MAX 1000000
int LCSubStr(string X, string Y, int m, int n)
{
    int LCSuff[m + 1][n + 1];
    int result = 0;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;

            else if (X[i - 1] == Y[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else
                LCSuff[i][j] = 0;
        }
    }
    return result;
}
void solve()
{
   string a,b;
   cin>>a>>b;
   int m = a.length();
    int n = b.length();
    ll x = LCSubStr(a,b,m,n);
    cout<<m-x+n-x<<nl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


---------------------------------------------------------





B. Partial Replacement
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a number k and a string s of length n, consisting of the characters '.' and '*'. You want to replace some of the '*' characters with 'x' characters so that the following conditions are met:

The first character '*' in the original string should be replaced with 'x';
The last character '*' in the original string should be replaced with 'x';
The distance between two neighboring replaced characters 'x' must not exceed k (more formally, if you replaced characters at positions i and j (i<j) and at positions [i+1,j−1] there is no "x" symbol, then j−i must be no more than k).
For example, if n=7, s=.**.*** and k=3, then the following strings will satisfy the conditions above:

.xx.*xx;
.x*.x*x;
.xx.xxx.
But, for example, the following strings will not meet the conditions:
.**.*xx (the first character '*' should be replaced with 'x');
.x*.xx* (the last character '*' should be replaced with 'x');
.x*.*xx (the distance between characters at positions 2 and 6 is greater than k=3).
Given n, k, and s, find the minimum number of '*' characters that must be replaced with 'x' in order to meet the above conditions.

Input
The first line contains one integer t (1≤t≤500). Then t test cases follow.

The first line of each test case contains two integers n and k (1≤k≤n≤50).

The second line of each test case contains a string s of length n, consisting of the characters '.' and '*'.

It is guaranteed that there is at least one '*' in the string s.

It is guaranteed that the distance between any two neighboring '*' characters does not exceed k.

Output
For each test case output the minimum number of '*' characters that must be replaced with 'x' characters in order to satisfy the conditions above.

Example
inputCopy
5
7 3
.**.***
5 1
..*..
5 2
*.*.*
3 2
*.*
1 1
*
outputCopy
3
1
3
2
1




1506B - Partial Replacement
To solve this problem, you can use the dynamic programming method or the greedy algorithm. Let's describe the greedy solution.

Until we get to the last character '*' we will do the following:

being in position i, find the maximum j, such that sj='*' and j−i≤k, and move to position j.
Since we make the longest move on each turn, we will make the minimum number of substitutions.

Solution
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int res = 1;
  int i = s.find_first_of('*');
  while (true) {
    int j = min(n - 1, i + k);
    for (; i < j && s[j] == '.'; j--) {}
    if (i == j) {
      break;
    }
    res++;
    i = j;
  }
  cout << res << "\n";
}

int main() {
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    solve();
  }
  return 0;
}



gfg

std::find_first_of is used to compare elements between two containers. It compares all the elements in a range [first1,last1) with the elements in the range [first2,last2), and if any of the elements present in the second range is found in the first one , then it returns an iterator to that element.

If there are more than one element common in both the ranges, then an iterator to the first common element present in the first container is returned. In case there is no match, then iterator pointing to last1 is returned.

It can be used in two ways as shown below:

Comparing elements using ==:
Syntax:



Template
ForwardIterator1 find_first_of(ForwardIterator1 first1,
                               ForwardIterator1 last1,
                               ForwardIterator2 first2,
                               ForwardIterator2 last2);

first1: Forward iterator to the first element
       in the first range.
last1: Forward iterator to the last element
       in the first range.
first2: Forward iterator to the first element
       in the second range.
last2: Forward iterator to the last element
       in the second range.

Return Value: It returns an iterator to the
              first element in [first1,last1) that is part of
              [first2,last2). If no matches are found or [first2,
              last2) is empty, the function returns last1.

// C++ program to demonstrate
// the use of std::find_first_of
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    // Defining first container
    vector<int>v = {1, 3, 3, 3, 10, 1, 3, 3, 7, 7, 8} , i;

    // Defining second container
    vector<int>v1 = {1, 3, 10};

    vector<int>::iterator ip;

    // Using std::find_first_of
    ip = std::find_first_of(v.begin(), v.end(), v1.begin(),
                            v1.end());

    // Displaying the first common element found
    cout << *ip << "\n";

    // Finding the second common element
    ip = std::find_first_of(ip + 1, v.end(), v1.begin(),
                            v1.end());

    // Displaying the second common element found
    cout << *ip << "\n";

    return 0;
}





--------------------------------------------------------------





D. Epic Transformation
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array a of length n consisting of integers. You can apply the following operation, consisting of several steps, on the array a zero or more times:

you select two different numbers in the array ai and aj;
you remove i-th and j-th elements from the array.
For example, if n=6 and a=[1,6,1,1,4,4], then you can perform the following sequence of operations:

select i=1,j=5. The array a becomes equal to [6,1,1,4];
select i=1,j=2. The array a becomes equal to [1,4].
What can be the minimum size of the array after applying some sequence of operations to it?

Input
The first line contains a single integer t (1≤t≤104). Then t test cases follow.

The first line of each test case contains a single integer n (1≤n≤2⋅105) is length of the array a.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109).

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, output the minimum possible size of the array after applying some sequence of operations to it.

Example
inputCopy
5
6
1 6 1 1 4 4
2
1 2
2
1 1
5
4 5 4 5 4
6
2 3 2 1 3 1
outputCopy
0
0
2
1
0










1506D - Epic Transformation
Let's replace each character with the number of its occurrences in the string. Then each operation — take two non-zero numbers and subtract one from them. In the end, we will have only one non-zero number left, and we want to minimize it. We can say that we want to minimize the maximum number after applying all the operations, which means we want to minimize the maximum number at each step.

We get the following greedy solution — each time we take two characters with maximal occurrences number and delete them.

Solution
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    priority_queue<pair<int, int>> q;
    int n;
    cin >> n;
    map<int, int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v[x]++;
    }
    for (auto [x, y] : v) {
        q.push({y, x});
    }
    int sz = n;
    while (q.size() >= 2) {
        auto [cnt1, x1] = q.top();
        q.pop();
        auto [cnt2, x2] = q.top();
        q.pop();
        cnt1--;
        cnt2--;
        sz -= 2;
        if (cnt1) {
            q.push({cnt1, x1});
        }
        if (cnt2) {
            q.push({cnt2, x2});
        }
    }
    cout << sz << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}


[OR ANOTHER GOOD SOL.]



#include <bits/stdc++.h>
typedef long long int ll;
const unsigned int MOD = 1000000007;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++)
    {
        int n;
        cin>>n;

        int a[n];

        map<int,int>mp;
        int m=0;
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
            mp[a[i]]++;
            m=max(mp[a[i]],m);
        }
        if (n % 2 == 0)
        {
            if (m <= n / 2)
            {
                cout << 0 << "\n";
            }
            else
                cout << 2 * m - n << "\n";
        }
        else
        {
            if (m <= n / 2)
                cout << 1 << "\n";
            else
                cout << 2 * m - n << "\n";
        }
    }
#ifndef ONLINE_JUDGE
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#endif
    return 0;
}
















*/