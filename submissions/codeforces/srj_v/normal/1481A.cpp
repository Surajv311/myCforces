/*
///////////////////////////////////////////
//Question/Info


///////////////////////////////////////////
*/

#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define int 		   long long int
#define setbits(x) 	   __builtin_popcount(x)
#define pb(x) 		   push_back(x)
#define mp(x,y) 	   make_pair(x,y)
#define eb(x) 		   emplace_back(x)
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

// typedef long long int lli;
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


// int lcs(string a, string b, int la, int lb) {

// 	// base case
// 	if (la == 0 or lb == 0) {
// 		return 0;
// 	}


// 	//  choice diagram

// 	if (a[la - 1] == b[lb - 1]) {

// 		return (1 + lcs(a, b, la - 1, lb - 1));

// 	}

// 	else {
// 		return max(lcs(a, b, la - 1, lb), lcs(a, b, la, lb - 1));
// 	}

// }

int dp[1001][1001];
int lcs(string a, string b, int la, int lb) {

	// base case
	if (la == 0 or lb == 0) {
		return 0;
	}

	if (dp[la][lb] != -1) {
		return dp[la][lb];
	}

	//  choice diagram

	if (a[la - 1] == b[lb - 1]) {

		return dp[la][lb] = (1 + lcs(a, b, la - 1, lb - 1));

	}

	else {
		return dp[la][lb] = max(lcs(a, b, la - 1, lb), lcs(a, b, la, lb - 1));
	}

}

int32_t main() {

///////////
	//c_p_c();
///////////

	// code


	int t ; cin >> t; while (t--) {

		int a , b ;
		cin >> a >> b ;
		string q ;
		cin >> q;
		string s = "";

		if (a > 0) {
			forn(i, a) {
				s += "R";
			}
		}

		if (a < 0) {
			forn(i, abs(a)) {
				s += "L";
			}
		}

		if (b > 0) {
			forn(i, b) {
				s += "U";
			}
		}

		if (b < 0) {
			forn(i, abs(b)) {
				s += "D";
			}
		}

		if (a == 0 and b == 0) {
			ct("YES")
		}

		// int la = s.length();
		// int lb = q.length();
		// int k = lcs(s, q, la, lb);

		// cout << s << " " << k << " " << la << endl;
		sort(s.begin(), s.end());
		sort(q.begin(), q.end());

		// if (k == la) {
		// 	ct("YES")
		// }
		// else {
		// 	ct("NO")
		// }
		memset(dp, -1, sizeof(dp));
		int la = s.length();
		int lb = q.length();
		int k = lcs(s, q, la, lb);
		if (k == la) {
			ct("YES")
		}
		else {
			ct("NO")
		}
		// cout << s << " " << q << endl;
		// if (q.find(s) != std::string::npos) {
		// 	std::cout << "YES" << endl;
		// }

		// else {
		// 	ct("NO")
		// }

	}






// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}