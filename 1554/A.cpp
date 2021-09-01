/*
//////////////////////////////////////////////////////
//Question/Info



author: srj_v
//////////////////////////////////////////////////////
*/

#include <bits/stdc++.h>
using namespace std;

#define int 		   long long int
#define sbit(x) 	   __builtin_popcount(x)
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
#define fsp(x,y)       fixed << setprecision(y) << x
#define PI 			   3.1415926535897932384626433832795
#define MOD 		   1000000007 // (1e9+7)
#define pii 		   pair<int,int>
#define pis 		   pair<int,string>
#define vi  		   vector<int>
#define vii 		   vector<pii>
#define mii 		   map<int,int>
#define p_q            priority_queue // priority_queue<int> || priority_queue<int,vi,greater<int>>
#define _IOS      	   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) 		   cout << #x << "=" << x << "\n";
#define dbg2(x,y) 	   cout << #x << "=" << x << " , " << #y << "=" << y << "\n";
#define F 			   first
#define S 			   second

typedef long double ld;
// typedef long long int lli;

#pragma GCC optimize("Ofast")

template<typename... T>
void read(T&... args) {
	((cin >> args), ...);
}

template<typename... T>
void write(T&&... args) {
	((cout << args << "\n"), ...);
}

void c_p_c()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

///**************////////////////////**************///


int32_t main() {
///////////
//	c_p_c();
///////////
	_IOS
//////////

	// code

	int t ; cin >> t; while (t--) {


		int n ; cin >> n;

		// vi v(n);
		// set<int> s;

		// forn(i, n) {
		// 	int d ; cin >> d;
		// 	// v[i] = d;
		// 	s.insert(d);
		// }

		// // sort(all(v));

		// // ct(s[n - 1]*s[n - 2]);
		// auto it = s.rbegin();
		// // auto it2 = s.rbegin() - 1;

		// auto it2 = it--;

		// ct(*it)
		// ct(*it2)
		// cout << s.end();

		// ct((*it) * (*it2))


		vi v(n);

		forn(i, n) {
			int d ; cin >> d;
			v[i] = d;
		}


		int ans = INT_MIN;

		forn(i, n) {

			int x = i;
			if (x + 1 == n) break;

			int a = v[i]; int b = v[i + 1];

			int c = a * b;

			ans = max(ans, c);

		}


		ct(ans);

	}







// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}

///**************////////////////////**************///