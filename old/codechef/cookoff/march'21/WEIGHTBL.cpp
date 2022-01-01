/*
///////////////////////////////////////////
//Question/Info

No play and eating all day makes your belly fat. This happened to Chef during the lockdown. His weight before the lockdown was w1 kg (measured on the most accurate hospital machine) and after M months of lockdown, when he measured his weight at home (on a regular scale, which can be inaccurate), he got the result that his weight was w2 kg (w2>w1).

Scientific research in all growing kids shows that their weights increase by a value between x1 and x2 kg (inclusive) per month, but not necessarily the same value each month. Chef assumes that he is a growing kid. Tell him whether his home scale could be giving correct results.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains five space-separated integers w1, w2, x1, x2 and M.
Output
For each test case, print a single line containing the integer 1 if the result shown by the scale can be correct or 0 if it cannot.

Constraints
1≤T≤105
1≤w1<w2≤100
0≤x1≤x2≤10
1≤M≤10
Example Input
5
1 2 1 2 2
2 4 1 2 2
4 8 1 2 2
5 8 1 2 2
1 100 1 2 2
Example Output
0
1
1
1
0
Explanation
Example case 1: Since the increase in Chef's weight is 2−1=1 kg and that is less than the minimum possible increase 1⋅2=2 kg, the scale must be faulty.

Example case 2: Since the increase in Chef's weight is 4−2=2 kg, which is equal to the minimum possible increase 1⋅2=2 kg, the scale is showing correct results.

Example case 3: Since the increase in Chef's weight is 8−4=4 kg, which is equal to the maximum possible increase 2⋅2=4 kg, the scale is showing correct results.

Example case 4: Since the increase in Chef's weight 8−5=3 kg lies in the interval [1⋅2,2⋅2] kg, the scale is showing correct results.

Example case 5: Since the increase in Chef's weight is 100−1=99 kg and that is more than the maximum possible increase 2⋅2=4 kg, the weight balance must be faulty.

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
//	c_p_c();
///////////
	_IOS
//////////

	// code


	int t ; cin >> t; while (t--) {



		int w1, w2, x1, x2, M;
		cin >> w1 >> w2 >> x1 >> x2 >> M;

		int dif = w2 - w1;

		int k = x1 * M;
		int kk = x2 * M;

		if (dif >= k and dif <= kk) {
			ct(1);
		}

		else {
			ct(0)
		}






	}



// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}