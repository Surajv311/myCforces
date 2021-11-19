/*
///////////////////////////////////////////
//Question/Info



author: srj_v
///////////////////////////////////////////
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

// checkpal(string s){

// int arr[26] = {0};

// int l = s.length();
// 		forn(i, l) {

// 			arr[s[i] - 'a']++;

// 		}

// int count = 0 ;
// 			forn(i, 26) {

// 				if ((arr[i]) &1) {
// 					// if odd
// 					++count;
// 				}

// 			}


// 			if (count > 1)
// 			{
// //not palindrome
// 				ct("YES")
// 				ct(s)

// 			}



// }

int32_t main() {
///////////
	//c_p_c();
///////////
	_IOS
//////////

	// code


	int t ; cin >> t; while (t--) {


		string s ;
		cin >> s ;

		string ss = s ;

		int l = s.length();

		if (s[0] == 'a' and l == 1) {
			ct("NO")
		}

		else {
			string temp = "a";
			s.insert(0, temp);

			int l = s.length();
			string a , b ;
			if (l & 1) {
				// odd
				a = s.substr(0, l / 2);
				b = s.substr(l / 2 + 1);
				reverse(all(b));
			}
			else {
				a = s.substr(0, l / 2);
				b = s.substr(l / 2);
				reverse(all(b));
			}



			if (a.compare(b) != 0) {
				ct("YES")
				ct(s)
			}
			else {
				string tempp = "a";
				ss.insert(1, tempp);
				int l = ss.length();
				string c , d ;
				if (l & 1) {
					// odd

					c = ss.substr(0, l / 2);
					d = ss.substr(l / 2 + 1);
					reverse(all(d));
				}
				else {
					c = ss.substr(0, l / 2);
					d = ss.substr(l / 2);
					reverse(all(d));
				}

				if (c.compare(d) != 0) {
					ct("YES")
					ct(ss)
				}
				else {
					ct("NO")
				}


			}

		}





	}







// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}