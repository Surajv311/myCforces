/*
///////////////////////////////////////////
//Question/Info

You are given a range of integers {L,L+1,…,R}. An integer X is said to be reachable if it can be represented as a sum of two not necessarily distinct integers in this range. Find the number of distinct reachable integers.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two space-separated integers L and R.
Output
For each test case, print a single line containing one integer — the number of reachable integers.

Constraints
1≤T≤105
1≤L≤R≤106
Example Input
2
2 2
2 3
Example Output
1
3
Explanation
Example case 1: The only reachable integer is 2+2=4.

Example case 2: 4, 5 and 6 are reachable, since 2+2=4, 2+3=5 and 3+3=6.
///////////////////////////////////////////
*/

#include <bits/stdc++.h>
using namespace std;

#define int 		   long long int
#define setbits(x) 	   __builtin_popcount(x)
#define pb(x) 		   push_back(x)
#define mp(x,y) 	   make_pair(x,y)
#define ct(x) 		   cout<<x<<endl;
#define ct2(x,y) 	   cout<<x<<" "<<y<<endl;
#define forn(i,n) 	   for(int i = 0; i < (int)(n); i++)
#define forx(i,x,n)    for(int i = x; i < (int)(n); i++)
#define all(v) 		   v.begin(),v.end()
#define fsp(x,y)       fixed<<setprecision(y)<<x;
#define PI 			   3.1415926535897932384626433832795
#define MOD 		   1000000007 // (1e9+7)
#define pii 		   pair<int,int>
#define pis 		   pair<int,string>
#define vi  		   vector<int>
#define vii 		   vector<pii>
#define mii 		   map<int,int>
//typedef long long int lli;
typedef long double ld;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int32_t main() {

///////////
	c_p_c();
///////////

	// code


	int t ; cin >> t; while (t--) {

		int a , b;
		cin >> a >> b ;

		// set<int> ss ;

		// for (int i = a ; i <= b ; i++) {
		// 	for (int j = i ; j <= b ; j++ ) {

		// 		int x = i + j ;
		// 		ss.insert(x);

		// 	}
		// }

		// ct(ss.size());

		ct( (2 * (abs(a - b))) + 1 )



	}
	// cerr << "time: " << clock() << " ms" << '\n';

	return 0;
}