/*
///////////////////////////////////////////
//Question/Info

A. Domino on Windowsill
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have a board represented as a grid with 2×n cells.

The first k1 cells on the first row and first k2 cells on the second row are colored in white. All other cells are colored in black.

You have w white dominoes (2×1 tiles, both cells are colored in white) and b black dominoes (2×1 tiles, both cells are colored in black).

You can place a white domino on the board if both board's cells are white and not occupied by any other domino. In the same way, you can place a black domino if both cells are black and not occupied by any other domino.

Can you place all w+b dominoes on the board if you can place dominoes both horizontally and vertically?

Input
The first line contains a single integer t (1≤t≤3000) — the number of test cases.

The first line of each test case contains three integers n, k1 and k2 (1≤n≤1000; 0≤k1,k2≤n).

The second line of each test case contains two integers w and b (0≤w,b≤n).

Output
For each test case, print YES if it's possible to place all w+b dominoes on the board and NO, otherwise.

You may print every letter in any case you want (so, for example, the strings yEs, yes, Yes and YES are all recognized as positive answer).

Example
inputCopy
5
1 0 1
1 0
1 1 1
0 0
3 0 0
1 3
4 3 1
2 2
5 4 3
3 1
outputCopy
NO
YES
NO
YES
YES
Note
In the first test case, n=1, k1=0 and k2=1. It means that 2×1 board has black cell (1,1) and white cell (2,1). So, you can't place any white domino, since there is only one white cell.

In the second test case, the board of the same size 2×1, but both cell are white. Since w=0 and b=0, so you can place 0+0=0 dominoes on the board.

In the third test case, board 2×3, but fully colored in black (since k1=k2=0), so you can't place any white domino.

In the fourth test case, cells (1,1), (1,2), (1,3), and (2,1) are white and other cells are black. You can place 2 white dominoes at positions ((1,1),(2,1)) and ((1,2),(1,3)) and 2 black dominoes at positions ((1,4),(2,4)) ((2,2),(2,3)).

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
	c_p_c();
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