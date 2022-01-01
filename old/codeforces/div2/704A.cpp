/*
///////////////////////////////////////////
//Question/Info

A. Three swimmers
time limit per test1 second
memory limit per test512 megabytes
inputstandard input
outputstandard output
Three swimmers decided to organize a party in the swimming pool! At noon, they started to swim from the left side of the pool.

It takes the first swimmer exactly a minutes to swim across the entire pool and come back, exactly b minutes for the second swimmer and c minutes for the third. Hence, the first swimmer will be on the left side of the pool after 0, a, 2a, 3a, ... minutes after the start time, the second one will be at 0, b, 2b, 3b, ... minutes, and the third one will be on the left side of the pool after 0, c, 2c, 3c, ... minutes.

You came to the left side of the pool exactly p minutes after they started swimming. Determine how long you have to wait before one of the swimmers arrives at the left side of the pool.

Input
The first line of the input contains a single integer t (1≤t≤1000) — the number of test cases. Next t lines contains test case descriptions, one per line.

Each line contains four integers p, a, b and c (1≤p,a,b,c≤1018), time in minutes after the start, when you came to the pool and times in minutes it take the swimmers to cross the entire pool and come back.

Output
For each test case, output one integer — how long you have to wait (in minutes) before one of the swimmers arrives at the left side of the pool.

Example
inputCopy
4
9 5 4 8
2 6 10 9
10 2 5 10
10 9 9 9
outputCopy
1
4
0
8
Note
In the first test case, the first swimmer is on the left side in 0,5,10,15,… minutes after the start time, the second swimmer is on the left side in 0,4,8,12,… minutes after the start time, and the third swimmer is on the left side in 0,8,16,24,… minutes after the start time. You arrived at the pool in 9 minutes after the start time and in a minute you will meet the first swimmer on the left side.

In the second test case, the first swimmer is on the left side in 0,6,12,18,… minutes after the start time, the second swimmer is on the left side in 0,10,20,30,… minutes after the start time, and the third swimmer is on the left side in 0,9,18,27,… minutes after the start time. You arrived at the pool 2 minutes after the start time and after 4 minutes meet the first swimmer on the left side.

In the third test case, you came to the pool 10 minutes after the start time. At the same time, all three swimmers are on the left side. A rare stroke of luck!

In the fourth test case, all swimmers are located on the left side in 0,9,18,27,… minutes after the start time. You arrived at the pool 10 minutes after the start time and after 8 minutes meet all three swimmers on the left side.



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