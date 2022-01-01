/*
///////////////////////////////////////////
//Question/Info


K-Goodness String

Problem
Charles defines the goodness score of a string as the number of indices i such that Si≠SN−i+1 where 1≤i≤N/2 (1-indexed). For example, the string CABABC has a goodness score of 2 since S2≠S5 and S3≠S4.

Charles gave Ada a string S of length N, consisting of uppercase letters and asked her to convert it into a string with a goodness score of K. In one operation, Ada can change any character in the string to any uppercase letter. Could you help Ada find the minimum number of operations required to transform the given string into a string with goodness score equal to K?

Input
The first line of the input gives the number of test cases, T. T test cases follow.

The first line of each test case contains two integers N and K. The second line of each test case contains a string S of length N, consisting of uppercase letters.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the minimum number of operations required to transform the given string S into a string with goodness score equal to K.

Limits
Memory limit: 1 GB.
1≤T≤100.
0≤K≤N/2.
Test Set 1
Time limit: 20 seconds.
1≤N≤100.
Test Set 2
Time limit: 40 seconds.
1≤N≤2×105 for at most 10 test cases.
For the remaining cases, 1≤N≤100.
Sample
Sample Input
save_alt
content_copy
2
5 1
ABCAA
4 2
ABAA
Sample Output
save_alt
content_copy
Case #1: 0
Case #2: 1
In Sample Case #1, the given string already has a goodness score of 1. Therefore the minimum number of operations required is 0.

In Sample Case #2, one option is to change the character at index 1 to B in order to have a goodness score of 2. Therefore, the minimum number of operations required is 1.

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

// #define cout << x << "" ;

int32_t main() {
///////////
	c_p_c();
///////////
	_IOS
//////////

	// code
	int x = 1;
	int t ; cin >> t; while (t--) {

		int n , k ; cin >> n >> k ;

		string s; cin >> s ;

		// int nn = n ;

		int count = 0;
		// forx(i, 1, (n / 2) + 1) {

		// 	if (s[i - 1] == s[nn - i - 1 + 1]) {
		// 		++count;
		// 	}

		// }

		string aa = s;
		string bb = s;

		if (n & 1) {
// odd
			aa = s.substr(0, (n / 2));
			bb = s.substr((n / 2) + 1, n);

		}
		else {
// even
			aa = s.substr(0, (n / 2));
			bb = s.substr((n / 2), n);


		}

		reverse(all(bb));

		int l = aa.length();

		forn(i, l) {

			if (aa[i] != bb[i]) {
				// cout << "test" << endl;
				++count;
			}

		}
		// cout << aa << " " << bb << endl;
		// cout << count << "   " ;
		cout << "Case #" << (x) << ": " << abs(k - count) << "\n";










		++x;


	}







// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}