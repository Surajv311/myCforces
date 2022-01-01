/*
///////////////////////////////////////////
//Question/Info

2021 was approaching and the world was about to end. So 2 gods Saurabhx and Saurabhy (from Celesta) created the Cyberverse. But this time disappointed with humans both the gods decided not to have humans in this world. So they created a world of cyborgs. A world without humans. Isn’t it interesting? So let us dive into the cyberverse and have a look at their problems.

There are N kid cyborgs with Chief Cyborg '100gods' and he has K weapons with him. He wants to distribute those K weapons among N kid cyborgs. Since all the kid cyborgs are very good friends, so they set a rule among themselves for taking those weapons. The rule states that the difference between kid cyborg having the maximum weapons and the kid cyborg having minimum weapons should be less than or equal to 1.
Find the value of the minimum number of weapons a kid cyborg can have when all the K weapons are distributed among them.

Input:
The first line contains an integer T, denoting the number of test cases.
Each of the next T lines will contain two space-separated integers denoting N and K respectively.
Output:
For each test case ,output a single line containing an integer X denoting the minimum number of weapons a kid cyborg can have in that test case.
Constraints:
1≤T≤105
1≤N≤105
1≤K≤109
Sample Input:
1
5 8
Expected Output:
1
Explanation
There are 5 kids and 8 weapons.
Hence we will distribute the weapons such that 3 kids have 2 weapons each and the remaining 2 kids have 1 weapon each.
Hence the minimum number of weapons a kid cyborg has is 1. ( That is, min(1,2) = 1 )

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
#define pii 		   pair<int,int>;
#define pis 		   pair<int,string>;
#define vi  		   vector<int>;
#define vii 		   vector<pii>;
#define mii 		   map<int,int>;
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
//	c_p_c();
///////////

	// code

	int t ;
	cin >> t;
	while (t--) {


// kids
		double n ;
		cin >> n ;

		if (n == 0) {
			return 0;
		}
		// weapons
		double k ;
		cin >> k ;

		// cout << k / n;
		int x = k / n;
		// cout << x << endl;
		if (((int)k % (int)n) == 0) {
			ct(x);
		}
		else {
			int ans = (ceil(k / n) - 1);
			ct(ans);
		}



	}






	return 0;
}