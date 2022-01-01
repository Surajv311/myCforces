/*
///////////////////////////////////////////
//Question/Info -

(this was an awesome q)

You are playing a Billiards-like game on an N×N table, which has its four corners at the points {(0,0),(0,N),(N,0), and (N,N)}. You start from a coordinate (x,y), (0<x<N,0<y<N) and shoot the ball at an angle 45∘ with the horizontal. On hitting the sides, the ball continues to move with the same velocity and ensuring that the angle of incidence is equal to the angle of reflection with the normal, i.e, it is reflected with zero frictional loss. On hitting either of the four corners, the ball stops there and doesn’t move any further.

Find the coordinates of the point of collision, when the ball hits the sides for the Kth time. If the ball stops before hitting the sides K times, find the coordinates of the corner point where the ball stopped instead.

Input:
The first line of the input contains an integer T, the number of testcases.
Each testcase contains a single line of input, which has four space separated integers - N, K, x, y, denoting the size of the board, the number of collisions to report the answer for, and the starting coordinates.
Output:
For each testcase, print the coordinates of the ball when it hits the sides for the Kth time, or the coordinates of the corner point if it stopped earlier.

Constraints
1≤T≤105
2≤N≤109
1≤K≤109
Subtasks
30 points : Sum of K over all test cases ≤107
70 points : Original constraints.
Sample Input:
2
5 5 4 4
5 2 3 1
Sample Output:
5 5
3 5
Explanation:
Sample Case 1 :
We are given a 5 by 5 board. We shoot the ball from coordinates (4,4), and we need to find its coordinates after it has collided with sides 5 times. However, after shooting, the ball goes directly to the corner (5,5), and stops there. So we report the coordinates (5,5).

fig1

Sample Case 2 :
We are given a 5 by 5 board. We shoot the ball from the coordinates (3,1), and we need to find its coordinates after it has collided with the sides twice. After shooting, it first hits the right side at (5,3), and then the top side at (3,5). So, we report (3,5).

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


	int t;
	cin >> t ;
	// t++;
	while (t--) {

		int n , k , x , y  ;
		cin >> n >> k >> x >> y ;

		int a = x ;
		int b = y ;
		int a2, b2;
		int c = x ;
		int d = y ;
		int c2, d2;

		vii v;

		// cout << a << b ;
		// cout << n << endl;



		if (a == b) {
			ct2(n, n);
			// break;
		}

		else {

			if (x > y) {
				a = n;
				b = y + n - x ;
				// b = 5 ;
				c = x - y;
				d = 0;
			}

			else if (x < y) {
				a = x - y + n;
				b = n;
				c = 0 ;
				d = y - x ;
				// k--;
			}

			// cout << a << " " << b ;

			// while (true) {
			// 	a++;
			// 	b++;
			// 	if (a == n or b == n) {
			// 		break;
			// 	}
			// }
			// // ct2(a, b);


			// while (true) {
			// 	c--;
			// 	d--;
			// 	if (c == 0 or d == 0) {
			// 		break;
			// 	}
			// }
			// ct2(c, d) ;

			a2 = b;
			b2 = a;

			c2 = d ;
			d2 = c;

			v.pb(mp(a, b));
			v.pb(mp(a2, b2));
			v.pb(mp(c2, d2));
			v.pb(mp(c, d));

			// cout << k << "ans" << endl;

			if (k % 4 == 0) {
				ct2(v[3].first, v[3].second);
			}

			else if (k % 4 == 1) {
				ct2(v[0].first, v[0].second);
			}
			else if (k % 4 == 2) {
				ct2(v[1].first, v[1].second);
			}
			else if (k % 4 == 3) {
				ct2(v[2].first, v[2].second);
			}
		}

		// cout << x << " " << y << endl ;


	}



	return 0;
}