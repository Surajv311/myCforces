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
#define ct(x) 		   cout << x << endl;
#define ct2(x,y) 	   cout << x << " " << y << endl;
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


		int y, a, b, c;

		cin >> y >> a >> b >> c ;
		int ans;
		int i = 1;
		int j = 1;
		int k = 1;

		if (y == a or y == b or y == c) {
			ans = 0;
		}
		else {
			if (y < a and y < b and y < c) {

				int x = min(a, b);
				x = min(x, c);

				ans = abs(y - x);


			}

			else {

				if (y > a) {
					int h = a;
					// while (y > a) {
					// 	a = a + h;
					// 	// i++;
					// }

					int kk = abs(y - a * ((y / a) + 1));

					if (y % a == 0) {
						kk = abs(y - a * ((y / a)));
					}

					// a = abs(y - a);
					a = kk;
				}
				else {
					a = abs(y - a);
				}



				if (y > b) {
					int h = b;
					// while (y > b) {
					// 	b = b + h;
					// 	// j++;
					// }

					int kk = abs(y - b * ((y / b) + 1));
					// b = abs(y - b);

					if (y % b == 0) {
						kk = abs(y - b * ((y / b)));
					}

					b = kk;
				}
				else {
					b = abs(y - b);
				}



				if (y > c) {
					int h = c;
					// while (y > c) {
					// 	c = c + h;
					// 	// k++;
					// }

					int kk = abs(y - c * ((y / c) + 1));

					// c = abs(y - c);

					if (y % c == 0) {
						kk = abs(y - c * ((y / c)));
					}

					c = kk;
				}
				else {
					c = abs(y - c);
				}

				// int h = a;
				// int hh = b;
				// int hhh = c;
				// int kk = min(a,b);
				//  kk = min(kk,c);

				// while (y > a or y > b or y > c) {
				// 	a = a + h;
				// 	b = b + hh;
				// 	c = c + hhh;
				// 	// i++;
				// }

				int xx = min(a, b);
				xx = min(xx, c);

				// ans = abs(y - xx);
				ans = xx;



			}
		}

		ct(ans);



	}





// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}