/*
///////////////////////////////////////////
//Question/Info -



///////////////////////////////////////////
*/

#include <bits/stdc++.h>
using namespace std;

#define int 		   long long int
#define setbits(x) 	   __builtin_popcount(x)
#define pb(x) 		   push_back(x)
#define mp(x,y) 	   make_pair(x,y)
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
//typedef long long int lli;
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

char arr[16] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'};
vi v ;

void decode(string s) {

	if (s.length() == 0) {
		return ;
	}

	int j = 3 ;
	int i = 0 ;
	int sum = 0 ;
	while (j != -1) {

		sum += (s[i] - '0') * pow(2, j);
		i++; j--;

	}
	v.pb(sum);
	decode(s.substr(4));

}

int32_t main() {

///////////
	c_p_c();
///////////

	// code


	int t ;
	cin >> t ;

	while (t--) {


		int n ;
		cin >> n ;
		string s ;
		cin >> s ;


		decode(s);

		forn(i, n / 4)
		{
			cout << arr[v[i]] ;
		}

		cout << endl;

		// cout << arr[0];
		v.clear();


	}





	return 0;
}


