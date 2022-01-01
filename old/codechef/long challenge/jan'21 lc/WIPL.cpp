/*
///////////////////////////////////////////
//Question/Info

Get excited, folks, because it is time for the final match of Codechef Premier League (CPL)!

Mike and Tracy also want to watch the grand finale, but unfortunately, they could not get tickets to the match. However, Mike is not someone who gives up so easily — he has a plan to watch the match.

The field where the match is played is surrounded by a wall with height K. Outside, there are N boxes (numbered 1 through N). For each valid i, the i-th box has a height Hi.

Mike wants to take some boxes and stack them on top of each other to build two towers. The height of each tower is the sum of heights of all the boxes that form it. Of course, no box may be in both towers. The height of each tower should be at least K. Then Mike can climb on top of one tower and Tracy on top of the other, and they can watch the match uninterrupted!

While Mike is busy stacking the boxes, Tracy would like to know the smallest number of boxes required to build two towers such that each of them has height at least K, or at least that it is impossible to build such towers. Can you help Tracy?

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and K.
The second line contains N space-separated integers H1,H2,…,HN.
Output
For each test case, print a single line containing one integer — the smallest number of boxes required to build two towers, or −1 if it is impossible.

Constraints
1≤T≤5
1≤N,K≤4,000
1≤Hi≤105 for each valid i
Subtasks
Subtask #1 (30 points):

1≤N,K≤100
1≤Hi≤100 for each valid i
Subtask #2 (70 points): original constraints

Example Input
2
8 38
7 8 19 7 8 7 10 20
4 5
2 10 4 9
Example Output
7
2
Explanation
Example case 1: The first tower can be built with boxes 8+10+20=38 and the second tower with boxes 7+7+8+19=41. In this case, the box with height 7 is left unused.

Example case 2: We only need the box with height 10 for one tower and the box with height 9 for the other tower.


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

		int n, k;
		int sum = 0;
		int ans = -1;
		cin >> n >> k;
		int arr[n];
		forn(i, n) {
			cin >> arr[i];
		}
		sort(arr, arr + n);

		set <int> ss, ss2;
		set <int> ::iterator it;
		int x = arr[n - 1];
		// initially last element to push in set
		//  set holds unique values...
		ss.insert(x);
		sum = x;
		int xx;
		for (int i = n - 2; i >= 0; i--) {
			sum = sum + arr[i];
			for (it = ss.begin(); it != ss.end();) {

				xx = (int) * it++;
				ss2.insert(xx);
				int x2 = arr[i];
				ss2.insert(x2);
				ss2.insert(xx + x2 );

				if (((xx + x2 ) >= k) and (sum - xx - x2  >= k)) {
					ans = n - i;
					break;
				}

				if ((x2 >= k) and (sum - x2  >= k)) {
					ans = n - i;
					break;
				}

			}
			if (ans != -1) {
				break;
			}

			ss = ss2;
			// clear ...
			ss2.clear();
		}
		ct(ans);

	}

	return 0;
}


// 7
// 8 38
// 7 8 19 7 8 7 10 20
// 4 5
// 2 10 4 9
// 8 10
// 1 2 3 4 5 6 7 8
// 4 6
// 1 2 1 1
// 4 10
// 1 1 1 22
// 7 13
// 1 4 5 5 7 9 10
// 9 30
// 1 4 5 6 7 9 10 13 13

// //4 5 6 9 10 13 13

// ---------------- -
// ANS must be :
// 7
// 2
// 4
// - 1
// - 1
// 4
// 7
