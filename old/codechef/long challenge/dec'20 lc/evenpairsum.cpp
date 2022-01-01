/*
///////////////////////////////////////////


https://www.codechef.com/DEC20B/problems/EVENPSUM

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
	cin >> t ;

	while (t) {


		int x, y ;
		cin >> x >> y ;
		// int count = 0 ;
		// int e1 = 0 ;
		// int o1 = 0 ;
		// int e2 = 0 ; // even
		// int o2 = 0 ;
		// for (int i = 1 ; i <= x ; i++) {


		// 	if (i % 2 == 0) {
		// 		e1++;
		// 	}
		// 	else {
		// 		o1++ ;
		// 	}
		// }




		// for (int j = 1 ; j <= y ; j++) {

		// 	if (j % 2 == 0) {
		// 		e2++;
		// 	}
		// 	else {
		// 		o2++;
		// 	}

		// }
		// int i , j ;
		// for ( i = 1, j = 1 ; i <= x or j <= y ; i++, j++) {


		// 	if (i % 2 == 0) {
		// 		e1++;
		// 	}
		// 	if (j % 2 == 0) {
		// 		e2++;
		// 	}
		// }


		// int m = e1 * e2;
		// int n = (x - e1) * (y - e2);

		// int k = m + n;
		// ct(k);


		int k1 = x / 2 ;
		int k2 = y / 2 ;

		int d = k1 * k2 ;
		int q1 = x - k1 ;
		int q2 = y - k2 ;
		int dd = q1 * q2;

		cout << d + dd << endl;




// 1
// 3
// 12
// 36


		t--;
	}






	return 0;
}
