/*
///////////////////////////////////////////
//Question/Info



author: srj_v
///////////////////////////////////////////
*/

#include <bits/stdc++.h>
using namespace std;

#define _IOS   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long double ld;
typedef long long int lli;

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

	/*
	int t ; cin >> t; while(t--){}
	*/


	int t ; cin >> t; while (t--) {


		int n ; cin >> n ;

		int arr[n];
		for (int i = 0 ; i < n ; i++) {

			cin >> arr[i];
		}

		int sum = accumulate(arr, arr + n, 0);

		int ans = INT_MIN;

		if (sum > n) {

			ans = abs(sum - n);


		}

		else if (sum == n) {
			ans = 0 ;
		}

		else {
			ans = 1;
		}

		cout << ans << "\n";


	}



// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}