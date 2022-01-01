/*
///////////////////////////////////////////


Reverse a number codechef...

///////////////////////////////////////////
*/

#include <bits/stdc++.h>
#define int long long int
#define setbits(x) __builtin_popcount(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ct(x) cout<<x<<endl;
#define ct2(x,y) cout<<x<<" "<<y<<endl;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forx(i, x, n) for (int i = x ; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

//typedef long long int lli;
typedef long double ld;
//typedef pair<int, int> pii;
//typedef vector<int> vi;
//typedef vector<pii> vii;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}



int32_t main() {

///////////
	c_p_c();
///////////

	// code


	int t ;
	cin >> t ;

	forn(i, t) {

		int num ;
		cin >> num ;

// reverse the number
		int32_t n2 = num ;
		string m = to_string(n2);
		int k = m.size() ;

		int x , q = 0;

		while (num != 0) {

			x = num % 10;
			q = q + x * pow(10, k - 1);

			num = num / 10;
			k--;

		}


		ct(q);

	}
//////// OR //////////

	/*int n, reversedNumber = 0, remainder;


	   cin >> n;

	   while(n != 0) {
	       remainder = n%10;
	       reversedNumber = reversedNumber*10 + remainder;
	       n /= 10;
	   }

	   cout << reversedNumber;
	*/



	return 0;
}