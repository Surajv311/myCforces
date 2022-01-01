/*
///////////////////////////////////////////
//Question/Info

A. Array and Peaks
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

Given two integers n and k, construct a permutation a of numbers from 1 to n which has exactly k peaks. An index i of an array a of size n is said to be a peak if 1<i<n and ai>ai−1 and ai>ai+1. If such permutation is not possible, then print −1.

Input
The first line contains an integer t (1≤t≤100) — the number of test cases.

Then t lines follow, each containing two space-separated integers n (1≤n≤100) and k (0≤k≤n) — the length of an array and the required number of peaks.

Output
Output t lines. For each test case, if there is no permutation with given length and number of peaks, then print −1. Otherwise print a line containing n space-separated integers which forms a permutation of numbers from 1 to n and contains exactly k peaks.

If there are multiple answers, print any.

Example
inputCopy
5
1 0
5 2
6 6
2 1
6 1
outputCopy
1
2 4 1 5 3
-1
-1
1 3 6 5 4 2
Note
In the second test case of the example, we have array a=[2,4,1,5,3]. Here, indices i=2 and i=4 are the peaks of the array. This is because (a2>a1, a2>a3) and (a4>a3, a4>a5).



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

int fun (int arr[] , int n , int k ) {


	for (int i = 1 ; i < n - 1 ; i += 2) {

		if (i >= n) {
			break;
		}
		if (arr[i] < arr[i - 1]) {
			swap(arr[i], arr[i - 1]);
			// ++count;
		}

		if (arr[i] < arr[i + 1] ) {
			swap(arr[i], arr[i + 1]);
			// ++count;
		}


		// if (count == k) {
		// 	break;
		// }

	}

	int cc = 0 ;
	int var = 0 ;
	for (int i = 0 ; i < n ; i += 2) {
		if (arr[i + 1] > arr[i] and arr[i + 1] > arr[i + 2]) {
			++cc;
		}
		if (cc == k) {
			var = i + 2;
			// flag = true;
			break;
		}

	}

	// ct(var)
	sort(arr + var, arr + n);

	// bool flag = false;

	// if (cc == k) {
	// 	flag = true ;
	// }
	// else {
	// 	for (int i = 0 ; i < n ; i += 2) {
	// 		if (arr[i + 1] > arr[i] and arr[i + 1] > arr[i + 2]) {
	// 			++cc;
	// 		}
	// 		if (cc == k) {
	// 			var = k;
	// 			flag = true;
	// 			break;
	// 		}

	// 	}
	// }

	// sort(arr + k, arr + n);


	// if (flag) {

	// forn(i, n) {
	// 	tc(arr[i])
	// }

	// ct("")
	// }

	// else {
	// 	ct(-1)
	// }

	return 0;

}

int32_t main() {
///////////
	c_p_c();
///////////
	_IOS
//////////

	// code


	int t ; cin >> t; while (t--) {


		int n , k ; cin >> n >> k;


		int arr[n];
		int kk = 1;
		forn (i, n) {
			arr[i] = kk ;
			++kk;
		}

		// int count = 0;

		if (n & 1) {
			// odd

			int x = (n / 2) ;

			if (x >= k) {
				fun(arr, n, k);
				forn(i, n) {
					tc(arr[i])
				}

				ct("")
			}

			else {
				ct(-1)
			}


		}

		else {
// even

			int x = (n / 2) - 1 ;

			if (x >= k) {
				fun(arr, n, k);
				forn(i, n) {
					tc(arr[i])
				}

				ct("")

			}

			else {
				ct(-1)
			}


		}


		// else {
		// 	ct(-1)
		// }


	}

	// ct("ih")





// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}