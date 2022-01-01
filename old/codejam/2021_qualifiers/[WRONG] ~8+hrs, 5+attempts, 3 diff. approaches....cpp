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

int countfun(string s, int x, int y) {

	int cost1 = 0;
	int cost2 = 0;
	int l = s.length();
	forn(i, l) {
		if (s[i] == 'C' and s[i + 1] == 'J') {
			cost1 += x;
		}
		else if (s[i] == 'J' and s[i + 1] == 'C') {
			cost2 += y;
		}
	}


	return cost1 + cost2;
}

int32_t main() {
///////////
	c_p_c();
///////////
	_IOS
//////////

	// code

	int cas = 1;

	int t ; cin >> t; while (t--) {


		int x, y; cin >> x >> y ; // cjX, jcY

		string s ; cin >> s ;

		int l = s.length();

		int n = l;

		int count1 = 0;
		int count2 = 0 ;

		forn(i, l) {
			if (s[i] == 'J')
			{
				++count1;
			}

			if (s[i] == 'C')
			{
				++count2;
			}

		}

		int ans = 0;
		if (count1 > 0 and count2 == 0) {
			ans = 0;
		}
		else if (count2 > 0 and count1 == 0) {
			ans = 0;
		}
		else if (count1 == 0 and count2 == 0) {
			ans = 0 ;
		}
		else {
			int l = s.length();

			forn(i, l) {

				if (s[i] == '?') {
					s.erase(s.begin() + i);
				}

			}

			// ct(s)
			ans = countfun(s, x, y);
		}


		cout << "Case" << " " << "#" << cas << ": " << ans << "\n";

		++cas;
	}



// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}


// string str = "";
// int n = 0;
// void strfn(string s) {

// reverse(all(s));
// 	if (s.length() == 0) {
// 		return;
// 	}
// 	strfn(s.substr(1));


// 	if (s[0] == '?') {
// 		str += '?';
// 	}

// 	if (s[0] == 'C') {
// 		if (str[n - 1] == "?") {
// 			str[n - 1] = "C";
// 		}
// 		str += "C";
// 	}
// 	if (s[0] == 'J') {
// 		if (str[n - 1] == "?") {
// 			str[n - 1] = "J";
// 		}
// 		str += "J";
// 	}



// 	++n;
// 	return;
// }




// 		forn(i, l) {


// 			if (s[0] == '?' and s[1] == 'J') {
// 				s[0] = 'J';
// 			}

// 			else if (s[0] == '?' and s[1] == 'C') {
// 				s[0] = 'C';
// 			}

// 			else if (s[n - 2] == 'J' and s[n - 1] == '?') {
// 				s[n - 1] = 'J';
// 			}
// 			else if (s[n - 2] == 'C' and s[n - 1] == '?') {
// 				s[n - 1] = 'C';
// 			}

// 			else if (s[i] == '?' and s[i + 1] == '?' and s[i + 2] == 'J') {
// 				s[i] = 'J';
// 				s[i + 1] = 'J';
// 			}
// 			else if (s[i] == '?' and s[i + 1] == '?' and s[i + 2] == 'C') {
// 				s[i] = 'C';
// 				s[i + 1] = 'C';
// 			}

// ////////////////////
// 			else if (s[i] == 'C' and s[i + 1] == '?' and s[i + 2] == 'C')
// 			{
// 				s[i + 1] = 'C';
// 			}
// 			else if (s[i] == 'J' and s[i + 1] == '?' and s[i + 2] == 'J')
// 			{
// 				s[i + 1] = 'J';
// 			}

// 			else if (s[i] == 'C' and s[i + 1] == '?' and s[i + 2] == 'J')
// 			{
// 				s[i + 1] = 'C';
// 			}

// 			else if (s[i] == 'J' and s[i + 1] == '?' and s[i + 2] == 'C')
// 			{
// 				s[i + 1] = 'C';
// 			}


// 		}






// if (s[i] == 'J' and s[i + 1] == '?' and s[i + 2] == 'C') {
// 	++jc;
// }
// if (s[i] == 'C' and s[i + 1] == '?' and s[i + 2] == 'J') {
// 	++cj;
// }

// if (s[i] == 'C' and s[i + 1] == 'J')
// {
// 	++cj;
// }
// if (s[i] == 'J' and s[i + 1] == 'C')
// {
// 	++jc;
// }
