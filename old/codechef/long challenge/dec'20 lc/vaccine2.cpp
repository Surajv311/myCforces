/*
///////////////////////////////////////////

https://www.codechef.com/DEC20B/problems/VACCINE2

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
//typedef std::vector<int> vi;
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

	int t ; // test cases

	cin >> t;

	forn(i, t) {

		int ans ;
		int n ; // number of ppl
		cin >> n ;

		int d ;
		cin >> d;

		vector<int> v1;
		vector<int> v2;

		forn(i, n) {
			int x ;
			cin >> x ;
			if (x >= 80 or x <= 9) {
				v1.pb(x);
			}
			else {
				v2.pb(x);
			}
		}

		int s1 = v1.size();

		int s2 = v2.size();

		int q1 = s1 / d;
		int q2 = s2 / d ;

		int r1 = s1 % d ;
		int r2 = s2 % d ;

		if (r1 != 0 and r2 != 0) {

			ans = q1 + 1 + q2 + 1 ;
		}

		if (r1 != 0 and r2 == 0) {

			ans = q1 + 1 + q2;
		}
		if (r1 == 0 and r2 == 0) {

			ans = q1 + q2  ;
		}
		if (r1 == 0 and r2 != 0) {

			ans = q1 + q2 + 1 ;
		}

		ct(ans) ;
	}


	return 0;
}