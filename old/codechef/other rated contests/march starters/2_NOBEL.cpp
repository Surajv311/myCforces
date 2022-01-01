/*
///////////////////////////////////////////
//Question/Info

Nobel Prize Problem Code: NOBEL

The growth of Computer Science has forced the scientific community to award Nobel Prize in CS starting from this year.

Chef knows that the Nobel community is going to award the prize to that person whose research is different from others (ie. no other researcher should work on the same topic). If there are multiple such people, who work on unique topics, then they will all share the prize. It might also happen that no one wins this time.

Chef also knows the N researchers which the community who will be considered for the prize, and the topics in which each of them work.

In total the CS field can be divided into M broad topics. Given the topics in which each of the N researchers are working on, in the form of an array A, and given that Chef can master any topic instantly, find whether he can win the prize. That is, can the Chef choose to work on some topic which will guarantee that he will win the prize? Chef doesn't mind sharing the prize with others.

Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of two lines of input.
First line contains two space separated integers N, M, number of researchers excluding Chef and total number of fields respectively.
Second line contains N space separated integers A1,A2,…AN, research topic of the researchers.
Output:
For each testcase, output in a single line answer, "Yes" if Chef can win the prize and "No" if not.

You may print each character of each string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1≤N,M≤105
1≤Ai≤M
Sum of N over all tests is at most 106
Sum of M over all tests is at most 106
Sample Input:
3
4 4
1 2 3 4
5 4
4 2 1 1 1
4 4
4 4 4 4
Sample Output:
No
Yes
Yes
Explanation:
TestCase 1: Since all the 4 available topics have been taken up, Chef can't choose a distinct topic and hence can't win the prize. No one will win the prize this year.

TestCase 2: Since only 3 distinct topics out of the 4 available have been taken up, Chef can choose the remaining one, i.e, topic 3 to win the prize jointly with the first and the second researcher.

TestCase 3: Since only 1 distinct topic out of the 4 available has been taken up, Chef can choose any of the remaining ones to win the prize.



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


		int n , m ; cin >> n >> m ;

// researchers excluding chef, total fields

		int arr[n];
		set<int>s;
		forn(i, n) {
			cin >> arr[i];
			s.insert(arr[i]);
		}


		int l = s.size();


		if (l < m) {
			ct("YES")
		}

		else {
			ct("NO")
		}











	}





// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}



