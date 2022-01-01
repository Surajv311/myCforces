/*
///////////////////////////////////////////
//Question/Info

Server Trouble Problem Code: SVRT

You are the Chief Engineer of a fast growing start-up. You wish to place K servers in some distinct locations from among N locations. The locations, numbered 1,2,…,N are arranged in a circular manner. The distance between every adjacent location is 1 unit. 1 and N are adjacent.

You want to place the servers such that the maximum shortest distance between any two adjacent servers is as less as possible. Find this minimum possible distance that can be achieved, and also the minimum number of pairs of adjacent servers separated by this distance.

Input:
The first line contains a single integer, T, denoting the number of test cases.
Each test case consists of a single line containing two space-separated integers N and K, denoting the number of locations, and the number of servers, respectively.
Output:
For test case, output two space-separated integers D and X, denoting the minimum possible maximum shortest distance that can be achieved between any two adjacent servers, and the minimum number of pairs of servers separated by this distance, respectively, in a separate line.

Constraints
1≤T≤105
3≤K≤N≤109
Sample Input:
3
6 3
10 6
10 4
Sample Output:
2 3
2 4
3 2
EXPLANATION:
Sample Test 1: Let the locations be numbered from 1 to 6. We can place the servers at locations 1, 3 and 5. Thus, the distances between locations 1 and 3, 3 and 5, and 5 and 1 are all =2, which is the lowest possible maximum distance that can be achieved here. There are 3 pairs of locations separated by this distance.

Sample Test 2: Let the locations be numbered from 1 to 10. We can place the servers at locations 1,2,4,6,8 and 10. Thus, the minimum possible maximum distance between any two adjacent servers is 2. There shall be at least 4 pairs of servers separated by this distance. Here, they are (2,4), (4,6), (6,8) and (8,10).



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


int32_t main() {
///////////
	c_p_c();
///////////
	_IOS
//////////

	// code

	int t ; cin >> t; while (t--) {


		int n , k ;
		cin >> n >> k ;


		int a = n / k;
		int aa = n % k;

		int b = 0;
		if (aa == 0) {
			b = k;
		}
		else {
			b = n - (a * k);
		}


		int ans2 = b ;

		int tt = n % k;

		int ans1 = 0;

		if (tt == 0) {
			ans1 = n / k;
		}
		else {
			ans1 = n / k + 1;
		}


		ct2(ans1, ans2)






	}





// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}



