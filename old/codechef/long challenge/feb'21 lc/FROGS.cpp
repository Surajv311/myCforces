/*
///////////////////////////////////////////
//Question/Info

There are N frogs (numbered 1 through N) in a line. For each valid i, the i-th frog is initially at the position i, it has weight Wi, and whenever you hit its back, it jumps a distance Li to the right, i.e. its position increases by Li. The weights of the frogs are pairwise distinct.

You can hit the back of each frog any number of times (possibly zero, not necessarily the same for all frogs) in any order. The frogs do not intefere with each other, so there can be any number of frogs at the same time at each position.

Your task is to sort the frogs in the increasing order of weight using the smallest possible number of hits. In other words, after all the hits are performed, then for each pair of frogs (i,j) such that Wi<Wj, the position of the i-th frog should be strictly smaller than the position of the j-th frog. Find the smallest number of hits needed to achieve such a state.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers W1,W2,…,WN.
The third line contains N space-separated integers L1,L2,…,LN.
Output
For each test case, print a single line containing one integer ― the smallest number of times you need to hit the backs of the frogs.

Constraints
1≤T≤2⋅104
2≤N≤4
1≤Wi≤N for each valid i
1≤Li≤5 for each valid i
no two frogs have the same weight
Subtasks
Subtask #1 (50 points):

T=50
N=2
Subtask #2 (50 points): original constraints

Example Input
3
3
3 1 2
1 4 5
3
3 2 1
1 1 1
4
2 1 4 3
4 1 2 4
Example Output
3
6
5
Explanation
Example case 1: We can hit the back of the first frog three times.

Example case 2: We can hit the back of the first frog four times, then hit the back of the second frog two times.
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
#define _IOS      	   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// typedef long long int lli;
typedef long double ld;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

void c_p_c()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

// bool check(map<int, int> , int );
// int compute( int , int[] , int[] );


bool check(mii &track , int xx) {

	int flag = 0 ;
	for (auto it : track) {

		if (it.first < xx and it.second < track[xx]) {
			flag++;
		}

	}
	return flag == xx - 1;

}

int compute( int n  , int wt[] , int jmp[] ) {



	mii track ;
	mii stp ;

	forn(i, n) {

		track[wt[i]] = i ;

		stp[wt[i]] = jmp[i];
	}
	int res = 0;

	sort(wt, wt + n);

	forx(i, 1, n)
	{


		while (!check(track, wt[i]))
		{
			res++;
			track[wt[i]] += stp[wt[i]];

		}

	}

	return res ;

}



int ftwo(int n, int wt[], int jmp[]) {

	int count = 0 ;
	if (wt[0] > wt[1]) {

		if (jmp[0] > 1) {
			count = 1;
		}
		else {
			count = 2;
		}

	}

	else {
		count = 0;
	}

	return count;
}



int fthree(int n, int wt[], int jmp[]) {


	// int count = 0 ;

	// int curpos[n];

	// forn(i, n) {
	// 	curpos[i] = i ;
	// }


	// forx(i, 1, n) {


	// 	if (wt[i - 1] > wt[i]) {

	// 		int posdif = abs(curpos[i - 1] - curpos[i]);
	// 		int npos = posdif + jmp[i - 1];

	// 		curpos[i - 1] = npos;
	// 		count++;


	// 	}


	// }


	return compute(n, wt, jmp);
}


int ffour(int n, int wt[], int jmp[]) {

	// int count = 0 ;

	// int curpos[n];

	// forn(i, n) {
	// 	curpos[i] = i + 1 ;

	// }


	// forx(i, 1, n) {


	// 	if (wt[i - 1] > wt[i]) {

	// 		while (curpos[i - 1] < curpos[i]) {
	// 			int posdif = abs(curpos[i - 1] - curpos[i]);
	// 			int npos = posdif + jmp[i - 1];
	// 			curpos[i - 1] = npos;
	// 			count++;
	// 		}

	// 	}


	// }



	return compute(n, wt, jmp);
}

int32_t main() {
///////////
	c_p_c();
///////////
	_IOS
//////////

	// code


	int t ; cin >> t; while (t--) {



		int n ;
		cin >> n ;

		int wt[n];
		int jmp[n];

		forn(i, n) {
			cin >> wt[i];
		}
		forn(i, n) {
			cin >> jmp[i];
		}
		if (n == 2) {

			ct(ftwo(n, wt, jmp));
		}
		else if (n == 3) {

			ct(fthree(n, wt, jmp));
		}

		else {

			ct(compute(n, wt, jmp));
		}

	}


// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}
