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
//	c_p_c();
///////////
	_IOS
//////////

	// code


	int t ; cin >> t; while (t--) {



		string s ; cin >> s ;

		int count = 0 ;

		int l = s.length();
		if (l & 1) // odd
		{
			forn(i, l) {

				// string c = s[i];
				// string d = s[i + 1];

				// int a = stoi(c);
				// int b = stoi(d);
				if (s[i] == '1' and s[i + 1] == '1') {
					++count;
				}

			}

		}
		else {

			forn(i, l) {

				if (s[i] == '1' and s[i + 1] == '1') {
					// cout << "qq" << " ";
					++count;
				}
				if (s[i] == '0' and s[i + 1] == '0')
				{
					// cout << "ww" << " ";
					--count;
				}

			}


		}

		// cout << count << " ";

		bool flag1 = false;
		bool flag2 = false;
		forn(i, l) {
			if (s[i] == '1') {
				flag1 = true;
			}
			if (s[i] == '0') {
				flag1 = false;
				break;
			}
		}

		forn(i, l) {
			if (s[i] == '0') {
				flag2 = true;
			}

			if (s[i] == '1') {
				flag2 = false;
				break;
			}

		}

		if (flag1) {
			ct("YES")
		}
		else if (flag2) {
			ct("YES")
		}

		else if (count >= 1) {
			ct("YES")
		}
		else {
			ct("NO")
		}

	}






// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}