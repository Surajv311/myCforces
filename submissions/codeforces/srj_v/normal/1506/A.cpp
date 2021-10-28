/*
///////////////////////////////////////////
//Question/Info



author: srj_v
///////////////////////////////////////////
*/

#include <bits/stdc++.h>
using namespace std;

#define int 		   unsigned long long
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


int32_t main() {
///////////
//	c_p_c();
///////////
	_IOS
//////////

	// code


	int t ; cin >> t; while (t--) {


		// int n , m , x;
		// cin >> n >> m >> x ;


		// int arr[n][m];

		// int count = 1;

		// int pos1 = 0;

		// int pos2 = 0;

		// forn(j, m) {

		// 	forn(i, n) {

		// 		arr[i][j] = count;
		// 		count++;

		// 		if (arr[i][j] == x) {

		// 			pos1 = i;
		// 			pos2 = j;
		// 			// break;
		// 		}
		// 	}
		// }

		// int ans = 1;

		// // ct(arr[0][3])

		// vi v;
		// forn(i, n) {
		// 	forn(j, m) {

		// 		// tc(arr[i][j])
		// 		v.eb(arr[i][j]);

		// 	}
		// }

		// auto it = find(all(v), x);
		// ct(it - v.begin() + 1)
		// // int k = v.find(x);

		// bool flag = false;
		// forn(i, n) {
		// 	forn(j, m) {

		// 		if ((i == pos2 and j == pos1)) {
		// 			// ct(ans)
		// 			flag = true;
		// 			break;
		// 		}
		// 		++ans;
		// 		ct(ans)

		// 	}
		// 	if (flag) {
		// 		break;
		// 	}
		// }

		// ct(ans)
		// ct(x)



		int n , m , x;
		cin >> n >> m >> x ;


		int a = 1 ;

		int b = a + (m - 1) * (n);

		int c = n ;

		int d = b + c - 1;

		int tcount = n * m;
		// tc2(a, b)

		bool flag = true;
		int count = 1;
		int c1;
		int count2 = 1;
		int ans = 0;
		int c2;
		bool flag2 = false;
		while (flag) {

			for (int i = a; i <= b; i += n) {

				if (x == i) {
					c1 = count;
					ans = c1;
					flag2 = true;
					flag = false;

					break;
				}
				count++;
			}

			a += 1;
			b += 1;

			if (flag2 != true) {
				for (int i = d; i >= d; i -= n) {

					if (x == i) {
						c2 = count2;
						ans = tcount - c2;
						flag = false;
						break;
					}
					count2++;
				}

				c -= 1;
				d -= 1;

			}

		}

		ct(ans)
// int count =1;
// int ans = 0;
// 	if (x >= a and x <= b) {
// 						for (int i = a; i < b; i+=n) {

// 			if (x == i) {
// 				ans = count;
// 				break;
// 			}
// 			count++;
// 			}
// 		}

// 		else{

// 		int k = 0 ;
// 		// forn

// 		for (int i = 0 ; i < n; i++) {

// 			if (x >= a and x <= b) {
// 				k = i;
// 				break;
// 			}

// 			a += 1;
// 			b += 1;



// 		}

// 		int count = 1;
// 		for (int i = a; i < b; i++) {

// 			if (x == i) {
// 				break;
// 			}
// 			count++;
// 		}

// }
// 		int ans = count + m * k;

// 		ct(ans)






	}







// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}