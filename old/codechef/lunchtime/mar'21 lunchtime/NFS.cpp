/*
///////////////////////////////////////////
//Question/Info

Turn It Problem Code: NFS

Chef is playing Need For Speed. Currently, his car is running on a straight road with a velocity U metres per second and approaching a 90∘ turn which is S metres away from him. To successfully cross the turn, velocity of the car when entering the turn must not exceed V metres per second.

The brakes of Chef's car allow him to slow down with a deceleration (negative acceleration) not exceeding A metres per squared second. Tell him whether he can cross the turn successfully. The velocity v when entering the turn can be determined from Newton's 2nd law to be v2=U2+2⋅a⋅S if the car is moving with a uniform acceleration a.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains four space-separated integers U, V, A and S.
Output
For each test case, print a single line containing the string "Yes" if Chef can cross the turn successfully or "No" if he cannot (without quotes).

You may print each character of each string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1≤T≤105
1≤U,V,A,S≤104
Subtasks
Subtask #1 (100 points): original constraints

Example Input
3
1 1 1 1
2 1 1 1
2 2 1 1
Example Output
Yes
No
Yes
Explanation
Example case 1: Since U=V=1, Chef does not need to brake and will be able to turn successfully.

Example case 2: The smallest velocity Chef's car can have even with the maximum deceleration is 2⋅2−2⋅1⋅1−−−−−−−−−−−√=2–√, which is greater than the maximum allowed velocity for a safe turn.

Example case 3: The smallest velocity Chef's car can have with the maximum deceleration is again 2–√, which is smaller than the maximum allowed velocity for a safe turn.



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
#define tc(x) 		   cout << x << " ";
#define tc2(x,y) 	   cout << x << " " << y << " ";
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



		int u, v, a, s; cin >> u >> v >> a >> s ;


		float vv;

		int x  = pow(u, 2) - 2 * a * s;

		vv = sqrt(x);

		// tc2(v, vv)
		if (vv <= float(v) or x < 0) {
			ct("Yes")
		}

		else {
			ct("No")
		}




	}

	// ct(sqrt(45))


// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}