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
#define fsp(x,y)       fixed << setprecision(y) << x
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

int fun (int arr[] , int n , int k ) {


	for (int i = 1 ; i < n - 1 ; i += 2) {

		if (i >= n) {
			break;
		}
		if (arr[i] < arr[i - 1]) {
			swap(arr[i], arr[i - 1]);
			// ++count;
		}

		if (arr[i] < arr[i + 1] ) {
			swap(arr[i], arr[i + 1]);
			// ++count;
		}


		// if (count == k) {
		// 	break;
		// }

	}

	int cc = 0 ;
	int var = 0 ;
	for (int i = 0 ; i < n ; i += 2) {
		if (arr[i + 1] > arr[i] and arr[i + 1] > arr[i + 2]) {
			++cc;
		}
		if (cc == k) {
			var = i + 2;
			// flag = true;
			break;
		}

	}

	// ct(var)
	sort(arr + var, arr + n);

	// bool flag = false;

	// if (cc == k) {
	// 	flag = true ;
	// }
	// else {
	// 	for (int i = 0 ; i < n ; i += 2) {
	// 		if (arr[i + 1] > arr[i] and arr[i + 1] > arr[i + 2]) {
	// 			++cc;
	// 		}
	// 		if (cc == k) {
	// 			var = k;
	// 			flag = true;
	// 			break;
	// 		}

	// 	}
	// }

	// sort(arr + k, arr + n);


	// if (flag) {

	// forn(i, n) {
	// 	tc(arr[i])
	// }

	// ct("")
	// }

	// else {
	// 	ct(-1)
	// }

	return 0;

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


		int arr[n];
		int kk = 1;
		forn (i, n) {
			arr[i] = kk ;
			++kk;
		}

		// int count = 0;

		if (n & 1) {
			// odd

			int x = (n / 2) ;

			if (x >= k) {
				fun(arr, n, k);
				forn(i, n) {
					tc(arr[i])
				}

				ct("")
			}

			else {
				ct(-1)
			}


		}

		else {
// even

			int x = (n / 2) - 1 ;

			if (x >= k) {
				fun(arr, n, k);
				forn(i, n) {
					tc(arr[i])
				}

				ct("")

			}

			else {
				ct(-1)
			}


		}


		// else {
		// 	ct(-1)
		// }


	}

	// ct("ih")





// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}