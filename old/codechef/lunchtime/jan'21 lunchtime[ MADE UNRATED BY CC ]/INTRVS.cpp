/*
///////////////////////////////////////////
//Question/Info



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
//	c_p_c();
///////////

	// code


	int t ; cin >> t; while (t--) {



		int n ;
		cin >> n ;
		double xx = double(n);
		int k ;
		cin >> k;

		int arr[n];


		forn(i, n) {
			cin >> arr[i];
		}

		// int count = 0 ;
		// int count1 = 0;
		// int count2 = 0;
		double count = 0 ;
		double count1 = 0;
		double count2 = 0;
		forn(i, n) {
			/*
			Rejected: If the number of problems that the candidate solved is
			strictly less than ceil(N/2).

			Too Slow: If candidate is not Rejected and
			candidate took more than K seconds to solve at
			least one problem among the problems solved by the candidate.

			Bot: If candidate is neither Rejected nor Too Slow,
			but has solved all of the N problems in at most one second each.

			Accepted: If the candidate is neither Rejected, Too Slow,
			nor Bot, she is Accepted.*/

			if (arr[i] >= 0) {
				count++;
			}

			if (arr[i] > k) {
				count1++;
			}

			if (arr[i] == 1 or arr[i] == 0) {
				count2++;
			}

		}

		bool flag = true;
		bool flag1 = true;
		// cout << count << " " << count1 << " " << count2 << " " << ceil(n / 2) << endl;
		if (count < (ceil(xx / 2))) {
			ct("Rejected")
		}

		else if (count >= (ceil(xx / 2)))
		{


			if (count1 != 0) {
				ct("Too Slow")
				flag = false;
			}

			if (count2 == xx and flag) {
				ct("Bot")
				flag1 = false;
			}


			if (flag and flag1) {
				ct("Accepted")
			}
		}
		// else if (count >= (ceil(xx / 2))) {
		// 	ct("Accepted")
		// }





	}



	/*
	Rejected
	Bot
	Accepted
	Too Slow
	Accepted
	*/




	return 0;
}

