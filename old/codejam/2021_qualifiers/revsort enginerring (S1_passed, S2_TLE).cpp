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

unordered_map<int, vi> mp;

bool sorted(int arr[], int n) {

	forn(i, n - 1) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;

}

void swapf(vi &v, int i, int j) {

	while (i <= j)
	{
		swap(v[i], v[j]);
		i++; j--;
	}
	return ;
}


void fun(vi v, int n )
{
	vi vv(v);

	int cost = 0;
	forn(i, n - 1) {


		int mine = *min_element(v.begin() + i , v.begin() + n);
		auto itr = find(v.begin() , v.begin() + n, mine);
		int j = abs(itr - v.begin());

		cost += j - i + 1;

		swapf(v, i, j);

	}

	mp[cost] = vv;

}

void revsort(int n) {

	vi v(n);

	forn(i, n) {
		v[i] = i + 1 ;
	}


	do {

		fun(v, n);

	} while (next_permutation(all(v)));



}


int32_t main() {
///////////
	c_p_c();
///////////
	_IOS
//////////

	// code

	int cas = 1;
	// revsort(2);

	// revsort(3);

	// revsort(4);

	// revsort(5);

	// revsort(6);

	// revsort(7); // use for...


	int t ; cin >> t; while (t--) {

		int n , c ;
		cin >> n >> c ;

		revsort(n);

		bool flag = true;
		for (auto i : mp) {


			int k = i.first;

			if (k == c) {

				cout << "Case" << " " << "#" << cas << ": ";
				for (auto j : i.second ) {
					tc(j)
				}
				ct("")
				flag = false;

			}
		}


		if (flag) {
			cout << "Case" << " " << "#" << cas << ": " << "IMPOSSIBLE" << "\n";
		}

		mp.clear();
		++cas;




	}



// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}