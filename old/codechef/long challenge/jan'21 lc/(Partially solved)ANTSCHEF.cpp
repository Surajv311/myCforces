/*
///////////////////////////////////////////
//Question/Info

Chef has been researching ant colonies for many years and finally discovered all their secrets.

An ant colony consists of N distinct lines (numbered 1 through N) that pass through a point O, which is the queen's home. For each valid i, there are Mi ants on the i-th line.

For each valid i and j, the j-th ant on the i-th line initially has a non-zero coordinate Xi,j with the following meaning:

The distance of this ant from O is |Xi,j|.
Let's choose a direction along the i-th line from O. The exact way in which this direction is chosen does not matter here, it only needs to be the same for all ants on the same line.
If Xi,j is positive, this ant is at the distance |Xi,j| from O in the chosen direction. Otherwise, it is at this distance from O in the opposite direction.
In other words, two ants j and k on a line i are at the same side of O if the signs of Xi,j and Xi,k are the same or on opposite sides if the signs are different.

All ants move with the same constant speed. Initially, all of them are moving towards O. Whenever two or more ants meet (possibly at O), all of these ants turn around and start moving in the opposite directions with the same speed. We call this a collision. Even if an ant reaches O without meeting an ant there, it keeps moving in the same direction. An ant may change direction multiple times.

Help Chef find the total number of collisions between ants. Note that even if more than two ants meet, it counts as only one collision.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
N lines follow. For each valid i, the i-th of these lines contains an integer Mi, followed by a space and Mi space-separated integers Xi,1,Xi,2,…,Xi,Mi.
Output
For each test case, print a single line containing one integer ― the number of collisions between ants.

Constraints
1≤T≤1,000
1≤N≤2⋅105
1≤Mi≤5⋅105 for each valid i
1≤|Xi,j|≤109 for each valid i,j
Xi,j<Xi,j+1 for each valid i,j
the sum of N over all test cases does not exceed 2⋅105
the sum of M1+M2+…+MN over all test cases does not exceed 106
Subtasks
Subtask #1 (30 points): N=1
Subtask #2 (70 points): original constraints

Example Input
1
2
2 -2 1
1 2
Example Output
2
Explanation
Example case 1: First, the ants on the first line collide at the coordinate −1/2 and change directions. Finally, ant 2 on the first line collides with the only ant on the second line; this happens at O. No collisions happen afterwards.
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

		int n ;

		cin >> n;
		// ct("hi");
		// cout << n ;
		if (n == 1) {
			// ct("hi");
			int m ;
			cin >> m ;

			int arr[m];

			forn(i, m) {
				cin >> arr[i];
			}

			int count = 0 ;
			int count2 = 0 ;

			forn(i, m) {

				if (arr[i] > 0) {
					count++;
				}
				else if (arr[i] < 0) {
					count2++;
				}

			}


			ct(count * count2);
		}
		else {

		}


	}


	return 0;
}