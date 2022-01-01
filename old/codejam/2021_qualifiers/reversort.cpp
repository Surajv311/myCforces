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

bool sorted(int arr[], int n) {

	forn(i, n - 1) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;

}

void swapf(int arr[], int i, int j) {

	while (i <= j)
	{
		swap(arr[i], arr[j]);
		i++; j--;
	}
	return ;
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


		int n ; cin >> n;

		int arr[n];

		forn(i, n) {
			cin >> arr[i];
		}

		int cost = 0;

		// for (int i = 1; i <= n - 1; ++i) {

		// 	int mine = *min_element(arr + i - 1, arr + n);
		// 	auto itr = find(arr + i - 1, arr + n, mine);
		// 	// auto itr = lower_bound(arr + i - 1, arr + n, mine);
		// 	int j = abs(itr - arr);
		// 	tc2(j, "  ")
		// 	++j;
		// 	cost += j - i + 1;
		// 	// tc2(cost, " ")
		// 	sort(arr + i - 1, arr + j);

		// 	// forn(i, n) {
		// 	// 	tc(arr[i])
		// 	// }
		// 	// ct("")

		// 	// if (sorted(arr, n)) {
		// 	// 	break;
		// 	// }

		// }


		forn(i, n - 1) {


			int mine = *min_element(arr + i , arr + n);
			auto itr = find(arr , arr + n, mine);
			int j = abs(itr - arr);
			// tc2(j, "  ")
			// ++j;
			// forn(i, n) {
			// 	tc(arr[i])

			// }

			// tc(" ")

			// tc2(i, j);
			// tc("  ")
			cost += j - i + 1;
			// tc2(cost, " ")
			// sort(arr + i, arr + j);
			// swap(arr[i], arr[j]);
			swapf(arr, i, j);


			// ct("")


		}

		cout << "Case" << " " << "#" << cas << ": " << cost << "\n";

		++cas;




	}



// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}