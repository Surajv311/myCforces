/*
///////////////////////////////////////////
//Question/Info

Chef and Divyam are playing a game with the following rules:

First, an integer X! is written on a board.
Chef and Divyam alternate turns; Chef plays first.
In each move, the current player should choose a positive integer D which is divisible by up to Y distinct primes and does not exceed the integer currently written on the board. Note that 1 is not a prime.
D is then subtracted from the integer on the board, i.e. if the integer written on the board before this move was A, it is erased and replaced by A−D.
When one player writes 0 on the board, the game ends and this player wins.
Given X and Y, determine the winner of the game.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two space-separated integers X and Y.
Output
For each test case, print a single line containing the string "Chef" if Chef wins the game or "Divyam" if Divyam wins (without quotes).

Constraints
1≤T≤106
1≤X,Y≤106
Subtasks
Subtask #1 (5 points): Y=1
Subtask #2 (10 points):

1≤T≤102
1≤X≤6
Subtask #3 (85 points): original constraints

Example Input
3
1 2
3 1
2021 42
Example Output
Chef
Divyam
Divyam
Explanation
Example case 1: Since D=1 is divisible by 0 primes, Chef will write 0 and win the game in the first move.

Example case 2: Chef must choose D between 1 and 5 inclusive, since D=6 is divisible by more than one prime. Then, Divyam can always choose 6−D, write 0 on the board and win the game.
///////////////////////////////////////////
*/

#include <bits/stdc++.h>
using namespace std;

#define int 		   long long int
#define setbits(x) 	   __builtin_popcount(x)
#define pb(x) 		   push_back(x)
#define mp(x,y) 	   make_pair(x,y)
#define eb(x) 		   emplace_back(x)
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

// typedef long long int lli;
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

int arr[1000002] = {0};
#define N 1000002

int32_t main() {

///////////
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	c_p_c();
///////////


// finding primes using prime sieve

	// int i , j ;
	// int nn = 1000002;
	// for ( i = 3; i < 1000002; i += 2) {
	// 	arr[i] = 1 ;
	// }

	// for ( i = 3; i < 1000002; i += 2) {
	// 	arr[i] = 1 ;
	// 	if (arr[i] == 1) {
	// 		for ( j = i * i ; j < 1000002; j += i ) {
	// 			arr[j] = 0;
	// 		}
	// 	}
	// }
	// arr[2] = 1;
	// arr[0] = arr[1] = 0;

	// partial_sum(arr, arr + nn, arr);
	vector<int> v(N, 1);
	for (int i = 2; i <= sqrt(N); ++i) {
		if (v[i]) {
			for (int j = i * i; j <= N; j += i) {
				v[j] = 0;
			}
		}
	}
	v[0] = v[1] = 0;
	partial_sum(all(v), v.begin());

	// const int N = 1000001;
	// int lp[N + 1];
	// int pr[1000001];

	// for (int i = 2; i <= N; ++i) {
	// 	if (lp[i] == 0) {
	// 		lp[i] = i;
	// 		pr[i] = i ;
	// 	}
	// 	for (int j = 0; j < (int)10000 && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
	// 		lp[i * pr[j]] = pr[j];
	// }

	// const int N = 1000002;
	// int lp[N + 1];
	// vector<int> pr;

	// for (int i = 2; i <= N; ++i) {
	// 	if (lp[i] == 0) {
	// 		lp[i] = i;
	// 		pr.push_back (i);
	// 	}
	// 	for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
	// 		lp[i * pr[j]] = pr[j];
	// }


	// partial_sum(lp, lp + N + 1, lp);

	int t ; cin >> t; while (t--) {

		int x , y;

		cin >> x >> y ;

		// if (arr[x] > y) {
		// 	cout << ("Divyam") << "\n";
		// }

		// else {
		// 	cout << ("Chef") << "\n";
		// }

		if (v[x] > y) {
			cout << ("Divyam") << "\n";
		}

		else {
			cout << ("Chef") << "\n";
		}


	}

	// if (lp[x] > y) {
	// 	cout << ("Divyam") << "\n";
	// }

	// else {
	// 	cout << ("Chef") << "\n";
	// }


// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}