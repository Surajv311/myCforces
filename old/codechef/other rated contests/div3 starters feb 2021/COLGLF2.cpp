/*
///////////////////////////////////////////
//Question/Info

Chef has just started watching Game of Thrones, and he wants to first calculate the exact time (in minutes) that it'll take him to complete the series.

The series has S seasons, and the ith season has Ei episodes, each of which are Li,1,Li,2,…,Li,Ei minutes long. Note that these Li,j include the duration of the beginning intro song in each episode. The streaming service that he uses, allows Chef to skip the intro song. The intro song changes slightly each season, and so he wants to watch the intro song in the first episode of each season, but he'll skip it in all other episodes of that season (yes, we know, a sacrilege!). You know that the intro song lasts for Qi minutes in the ith season.

Find the total time in minutes, that he has to watch.

Input:
First line will contain a single integer, T, denoting the number of testcases. Then the testcases follow.
The first line of each testcase will contain a single integer S, denoting the total number of seasons.
The second line contains S space separated integers, Q1,Q2,…,QS, where Qi denotes the duration of the intro song in the ith season.
The ith of the next S lines contains Ei+1 space separated integers, where the first integer is Ei, denoting the number of episodes in the ith season. That is followed by the duration of each of the Ei episodes, Li,1,Li,2,…,Li,Ei.
Output:
For each testcase, output the answer in a single line.

Constraints
1≤T≤5
1≤S≤105
2≤Li,j≤105
1≤Ei
Sum of all Ei in a single testcase is at most 105
1≤Qi<Li,j, for all valid j.
Sample Input 1:
1
2
1 2
1 2
2 3 4
Sample Output 1:
7
Explanation:
1 in the beginning denotes there is only 1 test case.

Testcase 1:

There are 2 seasons. The intro song in each of the first season episodes lasts for 1 minute, and the intro song in the second season episodes lasts for 2 minutes each.

For the first season, since there is only 1 episode, Chef will be watching it completely - 2 minutes.

For the second season, Chef will be watching the first episode completely (3 minutes) and will skip the intro song of the second episode (4−2=2 minutes).

So, the total time spent is 2+(3+(4−2))=7 minutes.

Sample Input 2:
2
1
10
5 11 11 11 11 11
5
10 10 10 10 10
1 11
1 11
1 11
1 11
1 11
Sample Output 2:
15
55
Explanation:
2 in the beginning denotes there are 2 test cases.

Testcase 1:

There is only 1 season having intro song for 10 minutes.

Chef will have to watch the entire first episode including the intro song and will be skipping the same in further seasons.

So, the total time spent is (11+(11−10)∗4)=15 minutes.

Testcase 2:

There are total 5 seasons. The intro song in every season lasts for 10 minutes.

For each of the five seasons, since there is only 1 episode, Chef will be watching all of them completely - 11 minutes each.

So, the total time spent is 11∗5=55 minutes.

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



		int s; cin >> s;
// int a = s;

		int q[s];

		forn(i, s) {

			cin >> q[i];

		}

// unordered_map<int,list<int>> mm;
		int ans = 0;
// int jj=0;
		forn(i, s) {
			int k;
			cin >> k;

			int ar[k];
			forn(x, k) {

				cin >> ar[x];
			}

			forn(j, k) {

				if (j == 0) {
// ans += accumulate(ar,ar+k,0);
					ans += ar[j];
				}
				else {
// ans+=accumulate(ar,ar+k,0) - q[i];
					ans += ar[j] - q[i];
				}

			}
// jj++;
		}


		ct(ans);

	}


// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}

// int s; cin >> s;

// int q[s];

// forn(i,s){
// 	cin >> q[i];
// }


// int n; cin >> n;

// int arr[n];

// forn(i, n) {
// 	cin >> arr[i];
// }

// sort(arr, arr + n);

// int aa = abs(arr[0]);
// int bb = abs(arr[1]);

// int cc = abs(arr[n - 1]);
// int dd = abs(arr[n - 2]);

// int ans1 = aa * bb + abs(aa - bb);
// int ans2 = cc * dd + abs(cc - dd);


// int ans = max(ans1, ans2);

// ct(ans);

