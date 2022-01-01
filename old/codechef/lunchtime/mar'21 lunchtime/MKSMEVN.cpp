/*
///////////////////////////////////////////
//Question/Info

Make the Sum Even Problem Code: MKSMEVN

Chef has a sequence A1,A2,…,AN. In one operation, Chef can choose one index i (1≤i≤N) and change Ai to Api, where p=max(0,⌈Ai2⌉−1).

Help Chef find the smallest number of operations needed to make the sum of the sequence even or determine that it is impossible.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.
Output
For each test case, print a single line containing one integer — the minimum number of operations needed to make the sum of the sequence even, or −1 if it is impossible.

Constraints
1≤T≤10
1≤N≤105
1≤Ai≤109 for each valid i
Subtasks
Subtask #1 (30 points):

N≤100
1≤Ai≤10 for each valid i
Subtask #2 (70 points): original constraints

Example Input
4
4
7 3 5 1
5
4 2 7 8 10
2
9 9
3
1 1 1
Example Output
0
1
0
-1
Explanation
Example case 1: The sum of the sequence is 16, which is already even.

Example case 2: We can change A2 to 1, so that the sequence becomes [4,1,7,8,10]. The sum of this sequence is 30, which is even.

Example case 3: The sum of the sequence is 18, which is already even.

Example case 4: It is impossible to make the sum of the sequence even.



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

int fun(int arr[], int sum , int n )
{


	if ((sum % 2) != 0) {
		forn(i, n) {
			if (arr[i] == 2) {
				return 1;
				break;
			}
		}

	}
	else if (sum % 2 == 0) {
		return 0;
	}

	return -1;

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
		int arr[n];

		forn(i, n) {

			cin >> arr[i];

		}

		int sum = accumulate(arr, arr + n, 0);


		ct(fun(arr, sum, n))


	}


	// int a = 8;

	// int x = (ceil(a / 2) - 1);
	// int y = 0;
	// int p = max(y, x);

	// ct(pow(a, p))





// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}