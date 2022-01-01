/*
///////////////////////////////////////////
//Question/Info

You are given a range of positive integers L,L+1,…R. Find an integer X greater than 1 which is coprime with all the integers in this range (does not share any common factors greater than 1 with any of these integers). In addition, X must not exceed 2⋅109.

If there are multiple solutions satisfying these conditions, you may find any one of them. It is guaranteed that for the given constraints, at least one such integer X exists.

For example, if L=16 and R=17, then X=9 is coprime with both 16 and 17. However, if L=6 and R=12 instead, then X=9 shares a common factor 3 with 6 and 12 and a common factor 9 with 9.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two space-separated integers L and R.
Output
For each test case, print a single line containing one integer X which satisfies the above conditions.

Constraints
1≤T≤1,000
2≤L≤R≤106
Subtasks
Subtask #1 (100 points): original constraints

Example Input
3
16 17
16 17
973360 973432
Example Output
9
27
79
Explanation
Example case 1: X=9 does not share any common factors with 16 and 17.

Example case 2: X=27 does not share any common factors with 16 and 17.

Example case 3: X=79 does not share any common factors with any of the integers 973360,973361,…,973432.


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
#define ct(x) 		   cout << x << endl;
#define ct2(x,y) 	   cout << x << " " << y << endl;
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


	// int n = 1000;
	// vi v(n, 1);

	// vi vv;
	// for (int i = 2 ; i <= sqrt(n); i++) {
	// 	if (v[i]) {
	// 		for (int j = i * i; j <= (n); j += i)
	// 		{
	// 			v[j] = 0;
	// 		}
	// 		vv.pb(v[i]);
	// 	}
	// }
	// v[0] = v[1] = 0;

	// int arr[100];
	// int j = 0 ;
	// // vi v2;
	// for (int ii = 0 ; ii <= n; ii++) {
	// 	// bool ee = v[ii];
	// 	if (v[ii]) {
	// 		arr[j] = ii;
	// 		j++;
	// 	}

	// }
	// cout << arr[9];

	int t ; cin >> t; while (t--) {

		int l, r;
		cin >> l >> r;

		// int kk = abs(l - r);
		// int j = 0;

		// bool flag = false;
		// int count = 0;

		// while (!flag)

		// {


		// 	for (int i = l ; i <= r; i++)
		// 	{
		// 		int x = vv[j];
		// 		if (i % x != 0) {
		// 			count++;
		// 		}

		// 		if (count == kk)
		// 		{
		// 			flag = true;
		// 			break;
		// 		}
		// 	}

		// 	j++;

		// }

		ct(MOD)

	}



	// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}
