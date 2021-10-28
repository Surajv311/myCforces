/*
///////////////////////////////////////////
//Question/Info



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
	//c_p_c();
///////////
	_IOS
//////////

	// code


	int t ; cin >> t; while (t--) {


		int n , k ; cin >> n >> k;


// lcm <= n/2 and sum of ai = n

		if (n % k == 0) {

			forn(i, k) {
				cout << (n / k) << " ";
			}

			ct("");


		}

		else {
			// forx(i, 1, (n / 2))
			// {
			int a = n - (k * (n / k));
			int b = a + (n / k);
			int c = n - (a + b);

			cout << a << " " << b << " " << c << "\n";

			// }
		}

	}




// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}