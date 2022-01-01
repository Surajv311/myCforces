/*
///////////////////////////////////////////
//Question/Info

A. Review Site
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are an upcoming movie director, and you have just released your first movie. You have also launched a simple review site with two buttons to press — upvote and downvote.

However, the site is not so simple on the inside. There are two servers, each with its separate counts for the upvotes and the downvotes.

n reviewers enter the site one by one. Each reviewer is one of the following types:

type 1: a reviewer has watched the movie, and they like it — they press the upvote button;
type 2: a reviewer has watched the movie, and they dislike it — they press the downvote button;
type 3: a reviewer hasn't watched the movie — they look at the current number of upvotes and downvotes of the movie on the server they are in and decide what button to press. If there are more downvotes than upvotes, then a reviewer downvotes the movie. Otherwise, they upvote the movie.
Each reviewer votes on the movie exactly once.

Since you have two servers, you can actually manipulate the votes so that your movie gets as many upvotes as possible. When a reviewer enters a site, you know their type, and you can send them either to the first server or to the second one.

What is the maximum total number of upvotes you can gather over both servers if you decide which server to send each reviewer to?

Input
The first line contains a single integer t (1≤t≤104) — the number of testcases.

Then the descriptions of t testcases follow.

The first line of each testcase contains a single integer n (1≤n≤50) — the number of reviewers.

The second line of each testcase contains n integers r1,r2,…,rn (1≤ri≤3) — the types of the reviewers in the same order they enter the site.

Output
For each testcase print a single integer — the maximum total number of upvotes you can gather over both servers if you decide which server to send each reviewer to.

Example
inputCopy
4
1
2
3
1 2 3
5
1 1 1 1 1
3
3 3 2
outputCopy
0
2
5
2
Note
In the first testcase of the example you can send the only reviewer to either of the servers — they'll downvote anyway. The movie won't receive any upvotes.

In the second testcase of the example you can send all reviewers to the first server:

the first reviewer upvotes;
the second reviewer downvotes;
the last reviewer sees that the number of downvotes is not greater than the number of upvotes — upvote themselves.
There are two upvotes in total. Alternatevely, you can send the first and the second reviewers to the first server and the last reviewer — to the second server:

the first reviewer upvotes on the first server;
the second reviewer downvotes on the first server;
the last reviewer sees no upvotes or downvotes on the second server — upvote themselves.

author: srj_v
///////////////////////////////////////////
*/

#include <bits/stdc++.h>
using namespace std;

#define int 		   long long int
#define sbit(x) 	   __builtin_popcount(x)
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
#define fsp(x,y)       fixed << setprecision(y) << x
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



		int n ; cin >> n ;
		int arr[n];

		forn(i, n) {
			cin >> arr[i];
		}


		int count = 0 ;

		forn(i, n) {
			if (arr[i] == 3 or arr[i] == 1) {
				++count;
			}
		}


		ct(count)







	}







// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}