/*
///////////////////////////////////////////
//Question/Info

A. Odd Set
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given a multiset (i. e. a set that can contain multiple equal integers) containing 2n integers. Determine if you can split it into exactly n pairs (i. e. each element should be in exactly one pair) so that the sum of the two elements in each pair is odd (i. e. when divided by 2, the remainder is 1).

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤100) — the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer n (1≤n≤100).

The second line of each test case contains 2n integers a1,a2,…,a2n (0≤ai≤100) — the numbers in the set.

Output
For each test case, print "Yes" if it can be split into exactly n pairs so that the sum of the two elements in each pair is odd, and "No" otherwise. You can print each letter in any case.

Example
inputCopy
5
2
2 3 4 5
3
2 3 4 5 5 5
1
2 4
1
2 3
4
1 5 3 2 6 7 3 4
outputCopy
Yes
No
No
Yes
No
Note
In the first test case, a possible way of splitting the set is (2,3), (4,5).

In the second, third and fifth test case, we can prove that there isn't any possible way.

In the fourth test case, a possible way of splitting the set is (2,3).

author: srj_v
///////////////////////////////////////////
*/

#include <bits/stdc++.h>
using namespace std;

#define int 		   long long int
#define sbit(x) 	   __builtin_popcount(x)
#define pb(x) 		   push_back(x)
#define mp(x,y) 	   make_pair(x,y)
#define eb(x) 		   emplace_back(x)
#define ct(x) 		   cout << x << "\n";
#define ct2(x,y) 	   cout << x << " " << y << "\n";
#define tc(x) 		   cout << x << " ";
#define tc2(x,y) 	   cout << x << " " << y << " ";
#define forn(i,n) 	   for(int i = 0; i < (int)(n); ++i)
#define forx(i,x,n)    for(int i = x; i < (int)(n); ++i)
#define nfor(i,n)      for(int i = n-1; i >= 0; --i)
#define all(v) 		   v.begin(),v.end()
#define fsp(x,y)       fixed << setprecision(y) << x
#define PI 			   3.1415926535897932384626433832795
#define MOD 		   1000000007 // (1e9+7)
#define pii 		   pair<int,int>
#define pis 		   pair<int,string>
#define vi  		   vector<int>
#define vii 		   vector<pii>
#define mii 		   map<int,int>
#define p_q            priority_queue // priority_queue<int> (&) priority_queue< int,vi,greater<int> >
#define _IOS      	   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long double ld;
// typedef long long int lli;

#pragma GCC optimize("Ofast")

void c_p_c()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


int32_t main() {
///////////
// c_p_c();
///////////
	_IOS
//////////

	// code


	int t ; cin >> t; while (t--) {

		int n ; cin >> n ;


		int size = 2 * n ;

		// cout << n << " " << size << " " << endl;
		int arr[size] ;

		forn(i, size) cin >> arr[i];

		int even = 0 ; int odd = 0 ;


		forn(i, size) {
			// cout << arr[i] << " ";
			if (arr[i] & 1) odd++;

			else even++;

		}

		// cout << even  << " " << odd << " " << endl;
		if (even == odd) {
			ct("Yes");
		}
		else ct("No");

















	}







// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}