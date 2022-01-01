/*
///////////////////////////////////////////
//Question/Info

A. Anti-knapsack
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given two integers n and k. You are asked to choose maximum number of distinct integers from 1 to n so that there is no subset of chosen numbers with sum equal to k.

A subset of a set is a set that can be obtained from initial one by removing some (possibly all or none) elements of it.

Input
The first line contains the number of test cases T (1≤T≤100).

Each of the next T lines contains two integers n and k (1≤k≤n≤1000) — the description of test cases.

Output
For each test case output two lines. In the first line output a single integer m — the number of chosen integers.

In the second line output m distinct integers from 1 to n — the chosen numbers.

If there are multiple answers, print any. You can print the numbers in any order.

Example
input
3
3 2
5 3
1 1
output
2
3 1
3
4 5 2
0


author: srj_v
///////////////////////////////////////////
*/

#include <bits/stdc++.h>
using namespace std;

#define int 		   long long int
#define setbits(x) 	   __builtin_popcount(x)
#define pb(x) 		   push_back(x)
#define mp(x,y) 	   make_pair(x,y)
#define eb(x) 		   emplace_back(x)
#define ct(x) 		   cout << x << "\n";
#define ct2(x,y) 	   cout << x << " " << y << "\n";
#define forn(i,n) 	   for(int i = 0; i < (int)(n); ++i)
#define forx(i,x,n)    for(int i = x; i < (int)(n); ++i)
#define nfor(i,n)      for(int i = n-1; i >= 0; --i)
#define all(v) 		   v.begin(),v.end()
#define fsp(x,y)       fixed << setprecision(y) << x;
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
	c_p_c();
///////////
	_IOS
//////////

	// code

	int t ; cin >> t; while (t--) {

		int n , k ;

		cin >> n >> k ;

		// vi v(n + 1);
		vi v;

		int x = k ;

		for (int i = k + 1; i <= n ; i++) {

			v.pb(i);

		}

		if (x & 1) {
//  k odd
			for (int i = 2; i <= x; i += 2) {
// push all even
				v.pb(i);

			}

		}

		else {
//  k even

			for (int i = x / 2; i < x ; i++) {
//  push all odd
				v.pb(i);

			}

		}

		ct(v.size());

		if (v.size() != 0) {
			forn(i, v.size()) {

				cout << v[i] << " ";

			}
			cout << endl;
		}

	}

	cout << endl;


// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}