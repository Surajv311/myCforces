/*
///////////////////////////////////////////
//Question/Info

Chef wants to host some Division-3 contests. Chef has N setters who are busy creating new problems for him. The ith setter has made Ai problems where 1≤i≤N.

A Division-3 contest should have exactly K problems. Chef wants to plan for the next D days using the problems that they have currently. But Chef cannot host more than one Division-3 contest in a day.

Given these constraints, can you help Chef find the maximum number of Division-3 contests that can be hosted in these D days?

Input:
The first line of input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains three space-separated integers - N, K and D respectively.
The second line of each test case contains N space-separated integers A1,A2,…,AN respectively.
Output:
For each test case, print a single line containing one integer ― the maximum number of Division-3 contests Chef can host in these D days.

Constraints
1≤T≤103
1≤N≤102
1≤K≤109
1≤D≤109
1≤Ai≤107 for each valid i
Subtasks
Subtask #1 (40 points):

N=1
1≤A1≤105
Subtask #2 (60 points): Original constraints

Sample Input:
5
1 5 31
4
1 10 3
23
2 5 7
20 36
2 5 10
19 2
3 3 300
1 1 1
Sample Output:
0
2
7
4
1
Explanation:
Example case 1: Chef only has A1=4 problems and he needs K=5 problems for a Division-3 contest. So Chef won't be able to host any Division-3 contest in these 31 days. Hence the first output is 0.

Example case 2: Chef has A1=23 problems and he needs K=10 problems for a Division-3 contest. Chef can choose any 10+10=20 problems and host 2 Division-3 contests in these 3 days. Hence the second output is 2.

Example case 3: Chef has A1=20 problems from setter-1 and A2=36 problems from setter-2, and so has a total of 56 problems. Chef needs K=5 problems for each Division-3 contest. Hence Chef can prepare 11 Division-3 contests. But since we are planning only for the next D=7 days and Chef cannot host more than 1 contest in a day, Chef cannot host more than 7 contests. Hence the third output is 7.
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

int32_t main() {

///////////
	c_p_c();
///////////

	// code


	int t;
	cin >> t ;

	while (t--) {

		int n , k, d;
		cin >> n >> k >> d;
// n - no. of chef,
// exactly k problems
// next d days
		int arr[n];



		forn(i, n) {
			cin >> arr[i]; // arr[i] probelms by ith setter
		}



		int sum = accumulate(arr, arr + n, 0);
		int ans = 0 ;

		if (sum >= k) {
			ans = sum / k;
			if (d < ans) {
				ans = d;
			}
		}

		ct(ans);







	}






	return 0;
}