/*
///////////////////////////////////////////
//Question/Info

Motivation Problem Code: IMDB

Chef has been searching for a good motivational movie that he can watch during his exam time. His hard disk has X GB of space remaining. His friend has N movies represented with (Si,Ri) representing (space required, IMDB rating). Help Chef choose the single best movie (highest IMDB rating) that can fit in his hard disk.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and X.
N lines follow. For each valid i, the i-th of these lines contains two space-separated integers Si and Ri.
Output
For each test case, print a single line containing one integer - the highest rating of an IMDB movie which Chef can store in his hard disk.

Constraints
1≤T≤10
1≤N≤5⋅104
1≤X≤109
1≤Si,Ri≤109 for each valid i
X≥Si for atleast one valid i
Subtasks
Subtask #1 (100 points): original constraints

Example Input
3
1 1
1 1
2 2
1 50
2 100
3 2
1 51
3 100
2 50
Example Output
1
100
51
Explanation
Example case 1: Since there is only 1 movie available and requires space equivalent to the empty space in the hard disk, Chef can only obtain maximum IMDB rating of 1.

Example case 2: Since out of the 2 available movies, both can fit in the free memory, we only care to take the one with higher rating, i.e, rating of max(50,100)=100.

Example case 3: Since out of the 3 available movies, only the first and the last movies fit in the free memory, we only care to take the one with higher rating amongst these 2, i.e, rating of max(51,50)=51.



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



		int n, x; cin >> n >> x;

		// int arr1[n];
		// int arr2[n];


		// forn(i, n) {
		// 	cin >> arr1[i];
		// 	cin >> arr2[i];

		// }


		// mii mp;

		vii v;
		forn(i, n) {

			int a, b;
			cin >> a >> b;
			// mp[a] = b;
			// mp.insert(mp(a, b));

			v.pb(mp(b, a));
		}

		// for (auto i : mp) {

		// 	if (i.second <= )


		// 	}

		// ct(mp[3])


		sort(all(v));


		for (int i = n - 1 ; i >= 0 ; i--)
		{

			if ((v[i].second) <= x) {
				ct(v[i].first);
				break;
			}


		}

		// for (auto it = mp.rbegin(); it != mp.rend(); it++) {

		// 	if ((it->second) <= x) {
		// 		ct((it -> first))
		// 		break;
		// 	}
		// }


		// mp.clear();





	}







// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}