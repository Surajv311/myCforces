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



		int n , k1 , k2 ; cin >> n >> k1 >> k2 ;

		int w, b ; cin >> w >> b ;

		int arr[2][n];

		memset(arr, -1, sizeof(arr));

		forn(j, k1) {
			arr[0][j] = 1;

		}


		forn(j, k2) {
			arr[1][j] = 1;
		}
// white 1
// black -1


		int c1 = k1 + k2 ;

		int c2 = (2 * n) - c1;
		w = 2 * w ; b = 2 * b;

		if (c1 >= w and c2 >= b) {
			ct("YES")
		}
		else if (c1 >= w and b == 0) {
			ct("YES")
		}
		else if (w == 0 and c2 >= b) {
			ct("YES")
		}
		else if (w == 0 and b == 0) {
			ct("YES")
		}
		else {
			ct("NO")
		}

		/*
				int wc = 0 ;
				int bc = 0;



				forn(i, n) {
					if (arr[0][i] + arr[1][i] == 2) {


						++wc ;

						arr[0][i] = arr[1][i] = INT_MAX;

					}

					if (arr[0][i] + arr[1][i] == -2) {

						++bc ;

						arr[0][i] = arr[1][i] = INT_MIN;

					}
				}

				forn(i, n - 1) {
					if (arr[0][i] + arr[0][i + 1] == 2) {
						++wc ;
						arr[0][i] = arr[0][i + 1] = INT_MAX;

					}

				}

				forn(i, n - 1) {
					if (arr[1][i] + arr[1][i + 1] == -2) {
						++bc ;
						arr[1][i] = arr[1][i + 1] = INT_MAX;

					}

				}


				if (wc == w and bc == b) {

					ct("YES")

				}

				else if (wc == w and b == 0)
				{
					ct("YES")

				}

				else if (w == 0 and bc == b) {

					ct("YES")
				}
				else if (w == 0 and b == 0) {
					ct("YES")
				}
				else {
					ct("NO")
				}
		*/



	}






// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}