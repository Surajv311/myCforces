/*
///////////////////////////////////////////

A semester in Chef's University has 120 working days. The University's requirement is that a student should be present for at least 75% of the working days in the semester. If not, the student is failed.

Chef has been taking a lot of holidays, and is now concerned whether he can pass the attendance requirement or not. N working days have already passed, and you are given N bits - B1, B2, …, BN. Bi = 0 denotes that Chef was absent on the ith day, and Bi = 1 denotes that Chef was present on that day.

Can Chef hope to pass the requirement by the end of the semester?

Input:
First line will contain T, the number of testcases. Then the testcases follow.
Each testcase contains two lines of input.
The first line of each testcase contains a single integer, N, the number of days till now.
The second line of each testcase contains a string B of length N where Bi represents the status of the ith day.
Output:
For each testcase, output the answer in a single line - "YES" if Chef can pass the attendance requirement and "NO" if not.

Constraints
1≤T≤10
1≤N≤120
0≤Bi≤1
Sample Input:
3
50
00000000000000000000000000000000000000000000000000
50
01010101010101010101010101010101010101010101010101
2
01
Sample Output:
NO
YES
YES
Explanation:
For Case 1, even if Chef attends all the remaining 70 days, he'll only have an attendance percentage of 70/120 = 58.33% which is less than 75%.

For Case 2, maximum attendance possible is 79.167% which is more than 75%.

For Case 3, maximum attendance possible is 99.167% which is more than 75%.

///////////////////////////////////////////
*/

#include <bits/stdc++.h>
#define int long long int
#define setbits(x) __builtin_popcount(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ct(x) cout<<x<<endl;
#define ct2(x,y) cout<<x<<" "<<y<<endl;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forx(i, x, n) for (int i = x ; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

//typedef long long int lli;
typedef long double ld;
//typedef pair<int, int> pii;
//typedef vector<int> vi;
//typedef vector<pii> vii;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;


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


	int t ;
	cin >> t;
	while (t) {


		int n ;
		cin >> n ;

		string str;
		cin >> str;

		vector<int> v ;
		forn(i, n)
		{
			int x  = str[i] - '0';
			v.pb(x);
		}



		// forn(i, n) {
		// 	cout << v[i] << " ";
		// }
		// cout << endl ;

		int count = 0 ;
		forn(i, n) {

			if (v[i] == 0) {
				count++;
			}

		}

		int k = 120 - count;

		double p = ((k * 100) / 120.0);
		// cout << p ;

		if (p >= 75) {
			ct("YES");
		}

		else {
			ct("NO");
		}







		t--;
	}





	return 0;
}