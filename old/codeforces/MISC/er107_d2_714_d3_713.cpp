/*


d3 713

C. A-B Palindrome
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a string s consisting of the characters '0', '1', and '?'. You need to replace all the characters with '?' in the string s by '0' or '1' so that the string becomes a palindrome and has exactly a characters '0' and exactly b characters '1'. Note that each of the characters '?' is replaced independently from the others.

A string t of length n is called a palindrome if the equality t[i]=t[n−i+1] is true for all i (1≤i≤n).

For example, if s="01?????0", a=4 and b=4, then you can replace the characters '?' in the following ways:

"01011010";
"01100110".
For the given string s and the numbers a and b, replace all the characters with '?' in the string s by '0' or '1' so that the string becomes a palindrome and has exactly a characters '0' and exactly b characters '1'.

Input
The first line contains a single integer t (1≤t≤104). Then t test cases follow.

The first line of each test case contains two integers a and b (0≤a,b≤2⋅105, a+b≥1).

The second line of each test case contains the string s of length a+b, consisting of the characters '0', '1', and '?'.

It is guaranteed that the sum of the string lengths of s over all test cases does not exceed 2⋅105.

Output
For each test case, output:

"-1", if you can't replace all the characters '?' in the string s by '0' or '1' so that the string becomes a palindrome and that it contains exactly a characters '0' and exactly b characters '1';
the string that is obtained as a result of the replacement, otherwise.
If there are several suitable ways to replace characters, you can output any.

Example
inputCopy
9
4 4
01?????0
3 3
??????
1 0
?
2 2
0101
2 2
01?0
0 1
0
0 3
1?1
2 2
?00?
4 3
??010?0
outputCopy
01011010
-1
0
-1
0110
-1
111
1001
0101010



ans




1512C - A-B Palindrome
First, let's find such positions i (1≤i≤n) such that s[i]≠'?' (symbols in symmetric positions are uniquely determined):

If s[n−i+1]='?', then s[n−i+1]=s[i];
If s[i]≠s[n−i+1], then at the end we will not get a palindrome in any way, so the answer is '-1'.
Note that after such a replacement, the remaining characters '?' are split into pairs, except maybe the central one. If the center character is '?' then it is necessary to put the character '0' if a is odd, or '1' if b is odd (if neither a, nor b is odd, then the answer is '-1').

Now the remaining characters '?' are split into pairs (i.e. if s[i]='?', then s[n−i+1]='?'). This allows the remaining characters '0' and '1' to be replaced greedily:

If s[i]='?' and a>1, then s[i]=s[n−i+1]='0' and decrease a for 2;
If s[i]='?' and b>1, then s[i]=s[n−i+1]='1' and decrease b for 2;
Otherwise the answer is '-1'.
Solution
#include <bits/stdc++.h>
using namespace std;

void no() {
  cout << "-1" << endl;
}

void solve() {
  int a, b;
  cin >> a >> b;
  string s;
  cin >> s;
  for (int times = 0; times < 2; times++) {
    for (int i = 0; i < (int) s.size(); i++) {
      int j = (int) s.size() - i - 1;
      if (s[i] != '?') {
        if (s[j] == '?') {
          s[j] = s[i];
        } else if (s[i] != s[j]) {
          no();
          return;
        }
      }
    }
    reverse(s.begin(), s.end());
  }
  a -= count(s.begin(), s.end(), '0');
  b -= count(s.begin(), s.end(), '1');
  int ques = count(s.begin(), s.end(), '?');
  bool emptyMid = (s.size() % 2 == 1 && s[s.size() / 2] == '?');
  if (a < 0 || b < 0 || a + b != ques || (emptyMid && a % 2 == 0 && b % 2 == 0)) {
    no();
    return;
  }
  if (a % 2 == 1 || b % 2 == 1) {
    int i = s.size() / 2;
    if (s[i] != '?') {
      no();
      return;
    }
    s[i] = (a % 2 == 1 ? '0' : '1');
    if (a % 2 == 1) {
      a--;
    } else {
      b--;
    }
  }
  if (a % 2 == 1 || b % 2 == 1) {
    no();
    return;
  }
  for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == '?') {
      int j = s.size() - i - 1;
      if (a > 0) {
        a -= 2;
        s[i] = s[j] = '0';
      } else {
        b -= 2;
        s[i] = s[j] = '1';
      }
    }
  }
  cout << s << endl;
}

int main() {
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    solve();
  }
  return 0;
}



--------------------------------------------------------




D. Corrupted Array
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a number n and an array b1,b2,…,bn+2, obtained according to the following algorithm:

some array a1,a2,…,an was guessed;
array a was written to array b, i.e. bi=ai (1≤i≤n);
The (n+1)-th element of the array b is the sum of the numbers in the array a, i.e. bn+1=a1+a2+…+an;
The (n+2)-th element of the array b was written some number x (1≤x≤109), i.e. bn+2=x; The
array b was shuffled.
For example, the array b=[2,3,7,12,2] it could be obtained in the following ways:

a=[2,2,3] and x=12;
a=[3,2,7] and x=2.
For the given array b, find any array a that could have been guessed initially.

Input
The first line contains a single integer t (1≤t≤104). Then t test cases follow.

The first line of each test case contains a single integer n (1≤n≤2⋅105).

The second row of each test case contains n+2 integers b1,b2,…,bn+2 (1≤bi≤109).

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, output:

"-1", if the array b could not be obtained from any array a;
n integers a1,a2,…,an, otherwise.
If there are several arrays of a, you can output any.

Example
inputCopy
4
3
2 3 7 12 2
4
9 1 7 1 6 5
5
18 2 2 3 2 9 2
3
2 6 9 2 1
outputCopy
2 3 7
-1
2 2 2 3 9
1 2 6





ans





1512D - Corrupted Array
What is the sum of all the elements in b? This is twice the sum of all the elements in a + x.

Denote by B the sum of all the elements of b. Let's iterate over which of the array elements was added as the sum of the elements a (let's denote, for a). Then, x = B−2⋅A. It remains to check that the element x is present in the array b, this can be done using a hash table or a binary search tree.

Solution
#include <bits/stdc++.h>
using namespace std;

void no() {
  cout << "-1" << endl;
}

void solve() {
  int n;
  cin >> n;
  vector<int> b(n + 2);
  for (int &x : b) {
    cin >> x;
  }

  multiset<int> have(b.begin(), b.end());
  long long sum = accumulate(b.begin(), b.end(), 0LL);
  for (int x : b) {
    have.erase(have.find(x));
    sum -= x;
    if (sum % 2 == 0 && sum <= 2'000'000'000 && have.find(sum / 2) != have.end()) {
      have.erase(have.find(sum / 2));
      for (int y : have) {
        cout << y << " ";
      }
      cout << endl;
      return;
    }
    sum += x;
    have.insert(x);
  }
  no();
}

int main() {
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    solve();
  }
  return 0;
}



---------------------------


714 div 2



B. AND Sequences
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
A sequence of n non-negative integers (n≥2) a1,a2,…,an is called good if for all i from 1 to n−1 the following condition holds true:
a1&a2&…&ai=ai+1&ai+2&…&an,
where & denotes the bitwise AND operation.

You are given an array a of size n (n≥2). Find the number of permutations p of numbers ranging from 1 to n, for which the sequence ap1, ap2, ... ,apn is good. Since this number can be large, output it modulo 109+7.

Input
The first line contains a single integer t (1≤t≤104), denoting the number of test cases.

The first line of each test case contains a single integer n (2≤n≤2⋅105) — the size of the array.

The second line of each test case contains n integers a1,a2,…,an (0≤ai≤109) — the elements of the array.

It is guaranteed that the sum of n over all test cases doesn't exceed 2⋅105.

Output
Output t lines, where the i-th line contains the number of good permutations in the i-th test case modulo 109+7.

Example
inputCopy
4
3
1 1 1
5
1 2 3 4 5
5
0 2 0 3 0
4
1 3 5 1
outputCopy
6
0
36
4
Note
In the first test case, since all the numbers are equal, whatever permutation we take, the sequence is good. There are a total of 6 permutations possible with numbers from 1 to 3: [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1].

In the second test case, it can be proved that no permutation exists for which the sequence is good.

In the third test case, there are a total of 36 permutations for which the sequence is good. One of them is the permutation [1,5,4,2,3] which results in the sequence s=[0,0,3,2,0]. This is a good sequence because

s1=s2&s3&s4&s5=0,
s1&s2=s3&s4&s5=0,
s1&s2&s3=s4&s5=0,
s1&s2&s3&s4=s5=0.




ans


1513B - AND Sequences
Consider an arbitrary sequence b1,b2,…,bn. First let us define the arrays AND_pref and AND_suf of length n where AND_prefi=b1&b2&…&bi and AND_sufi=bi&bi+1&…&bn .

According to the definition of good sequence:

AND_pref1=AND_suf2 which means b1=b2&b3&…&bn .

Now AND_pref2≤AND_pref1=AND_suf2≤AND_suf3. Also according to definition of good sequence, AND_pref2=AND_suf3. This means that b1=AND_pref2=AND_suf3. Similarly, for all i from 1 to n, we get AND_prefi=b1 and AND_sufi=b1.

Therefore for the sequence to be good, b1=bn and the bi must be a super mask of b1 for all i from 2 to n−1.

Initially, we have an array a1,a2,…,an. Let the minimum value among these elements be x. Let the number of elements that have the value of x be cnt.

In order to rearrange the elements of a1,a2,…,an to a good sequence, we need to have cnt≥2 and the remaining elements need to be a super mask of x. If we don't meet this criterion, then the answer is 0. Else the answer will be (cnt⋅(cnt−1)⋅(n−2)!)%(109+7).

The time complexity is O(n).

Implementation in C++

#include<bits/stdc++.h>
using namespace std;

void solveTestCase()
{
    int MOD=1e9+7;
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    int min1=*min_element(a.begin(),a.end());
    int cnt=0;

    for(int x:a)
    {
        if(min1==x)cnt++;
        if((min1&x)!=min1)
        {
            printf("0\n");
            return;
        }
    }

    int fact=1;
    for(int i=1;i<=n-2;i++)fact=(1LL*fact*i)%MOD;
    int ans=(1LL * cnt * (cnt-1))%MOD;
    ans = (1LL * ans * fact) % MOD;
    printf("%d\n",ans);
}

int main()
{
    int tests;
    cin>>tests;
    while(tests--)
    solveTestCase();
    return 0;
}



-----------------------


C. Add One
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an integer n. You have to apply m operations to it.

In a single operation, you must replace every digit d of the number with the decimal representation of integer d+1. For example, 1912 becomes 21023 after applying the operation once.

You have to find the length of n after applying m operations. Since the answer can be very large, print it modulo 109+7.

Input
The first line contains a single integer t (1≤t≤2⋅105) — the number of test cases.

The only line of each test case contains two integers n (1≤n≤109) and m (1≤m≤2⋅105) — the initial number and the number of operations.

Output
For each test case output the length of the resulting number modulo 109+7.

Example
inputCopy
5
1912 1
5 6
999 1
88 2
12 100
outputCopy
5
2
6
4
2115
Note
For the first test, 1912 becomes 21023 after 1 operation which is of length 5.

For the second test, 5 becomes 21 after 6 operations which is of length 2.

For the third test, 999 becomes 101010 after 1 operation which is of length 6.

For the fourth test, 88 becomes 1010 after 2 operations which is of length 4.




ans




1513C - Add One
We can solve this problem using 1D dp.

Let dpi be defined as the length of the string after applying operation i-times to the number 10. Then,

dpi=2, ∀ i in [0,8]
dpi=3, if i=9
(The final number after applying 9 operations to the number 10 is 109.)

dpi=dpi−9+dpi−10, Otherwise.
(length would be the sum of i−9 operations and i−10 operations.)

We can precalculate the above table until m (Note: 1≤m<2⋅105).
Now for each test case, the final answer is:

ans=∑|s|i=1((m+(int)(s[i]−′0′)<10)?1:dpm−10+(int)(s[i]−′0′)), where s is n (in form of string).

Time Complexity O(m+t⋅|s|), where |s| is the number of digits in n.

Implementation in C++

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int max_n = 200005, mod = 1000000007;
int dp[max_n];

signed main(){

    for(int i=0; i<9; i++)dp[i] = 2;
    dp[9] = 3;
    for(int i=10; i<max_n; i++){
        dp[i] = (dp[i-9] + dp[i-10])%mod;
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        int ans = 0;
        while(n > 0){
            int x = n%10;
            ans += ((m + x < 10) ? 1 : dp[m + x - 10]);
            ans %= mod;
            n/=10;
        }
        cout<<ans<<"\n";
    }
    return 0;
}


------------------------


er 107



B. GCD Length
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given three integers a, b and c.

Find two positive integers x and y (x>0, y>0) such that:

the decimal representation of x without leading zeroes consists of a digits;
the decimal representation of y without leading zeroes consists of b digits;
the decimal representation of gcd(x,y) without leading zeroes consists of c digits.
gcd(x,y) denotes the greatest common divisor (GCD) of integers x and y.

Output x and y. If there are multiple answers, output any of them.

Input
The first line contains a single integer t (1≤t≤285) — the number of testcases.

Each of the next t lines contains three integers a, b and c (1≤a,b≤9, 1≤c≤min(a,b)) — the required lengths of the numbers.

It can be shown that the answer exists for all testcases under the given constraints.

Additional constraint on the input: all testcases are different.

Output
For each testcase print two positive integers — x and y (x>0, y>0) such that

the decimal representation of x without leading zeroes consists of a digits;
the decimal representation of y without leading zeroes consists of b digits;
the decimal representation of gcd(x,y) without leading zeroes consists of c digits.
Example
inputCopy
4
2 3 1
2 2 2
6 6 2
1 1 1
outputCopy
11 492
13 26
140133 160776
1 1
Note
In the example:

gcd(11,492)=1
gcd(13,26)=13
gcd(140133,160776)=21
gcd(1,1)=1



ans




int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
w(t){
    int a,b,c;
    cin>>a>>b>>c;
    ll xx=pow(10,a-1);
    ll yy=pow(10,b-1);

     ll cc=pow(10,c-1);

     if(xx<yy)
     cout<<xx<<" "<<yy+cc<<endl;
     else
     cout<<xx+cc<<" "<<yy<<endl;

}
return 0;
}


-----------------------------------------------------



D. Min Cost String
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Let's define the cost of a string s as the number of index pairs i and j (1≤i<j<|s|) such that si=sj and si+1=sj+1.

You are given two positive integers n and k. Among all strings with length n that contain only the first k characters of the Latin alphabet, find a string with minimum possible cost. If there are multiple such strings with minimum cost — find any of them.

Input
The only line contains two integers n and k (1≤n≤2⋅105;1≤k≤26).

Output
Print the string s such that it consists of n characters, each its character is one of the k first Latin letters, and it has the minimum possible cost among all these strings. If there are multiple such strings — print any of them.

Examples
inputCopy
9 4
outputCopy
aabacadbb
inputCopy
5 1
outputCopy
aaaaa
inputCopy
10 26
outputCopy
codeforces




ans




1511D - Min Cost String
Consider all possible strings of length 2 on the alphabet of size k (there are k2 of them). Let cnti be the number of occurrences of the i-th of them in the string s. The cost of the string s by definition is ∑icnti(cnti−1)2. Now, let's suppose there are two strings i and j such that cnti−cntj≥2. Then, if we somehow reduce the number of occurrences of the string i by 1 and increase the number of occurrences of the string j by 1, the cost will decrease. So, in the optimal answer all the strings of length 2 should appear the same number of times (and if it's impossible, the difference in the number of appearances should not be greater than 1).

Let's suppose that k2=n−1, then our goal is to build a string where each string of length 2 on the alphabet of k characters appears exactly once. The construction of this string can be modeled using Eulerian cycles: build a directed graph with k vertices, where each vertex represents a character, each arc represents a string of length 2, and for every pair of vertices (i,j), there is an arc from i to j (it's possible that i=j!). Then, by finding the Eulerian cycle in this graph (it always exists since the graph is strongly connected and, for each vertex, its in-degree is equal to its out-degree), we find a string of length k2+1 such that all its substrings are different (so each string of length 2 appears there once as a substring).

Okay, what about the cases k2>n−1 and k2<n−1? Since the string we build for the case k2=n−1 represents a cycle, we can make it "cyclical" and repeat the required number of times, then cut last several characters if it's too big. For example, if n=8, k=2, then the string for k=2 is abbaa (it's not the only one, but we can use it). We can expand this string to abbaabbaa (by repeating the last k2 characters), and delete the last character so its length is 8.

By the way, in this problem, you don't have to implement the algorithm that finds Eulerian cycles. The graph where we want to find the Eulerian cycle has a very special structure, and there are many different constructive ways to find the cycle in it. But if you can't use them, you always can rely on the straightforward solution that explicitly searches for the Eulerian cycle.

Solution (Neon)
#include <bits/stdc++.h>

using namespace std;

int n, k;
int cur[26];
vector<int> path;

void dfs(int v) {
  while (cur[v] < k) {
    int u = cur[v]++;
    dfs(u);
    path.push_back(u);
  }
}

int main() {
  scanf("%d%d", &n, &k);
  dfs(0);
  printf("a");
  for (int i = 0; i < n - 1; ++i)
    printf("%c", path[i % path.size()] + 'a');
}


----------------------------------------------




















































*/