/*
///////////////////////////////////////////
//Question/Info -

Elections are coming soon. This year, two candidates passed to the final stage. One candidate is John Jackson and his opponent is Jack Johnson.

During the elections, everyone can vote for their favourite candidate, but no one can vote for both candidates. Then, packs of votes which went to the same candidate are formed. You know that for John Jackson, there are N packs containing A1,A2,…,AN votes, and for Jack Johnson, there are M packs containing B1,B2,…,BM votes.

The winner is the candidate that has strictly more votes than the other candidate; if both have the same number of votes, there is no winner. You are a friend of John Jackson and you want to help him win. To do that, you may perform the following operation any number of times (including zero): choose two packs of votes that currently belong to different candidates and swap them, i.e. change the votes in each of these packs so that they would go to the other candidate.

You are very careful, so you want to perform as few swaps as possible. Find the smallest number of operations you need to perform or determine that it is impossible to make John Jackson win.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and M.
The second line contains N space-separated integers A1,A2,…,AN.
The third line contains M space-separated integers B1,B2,…,BM.
Output
For each test case, print a single line containing one integer ― the smallest number of swaps needed to make John Jackson win, or −1 if it is impossible.

Constraints
1≤T≤103
1≤N,M≤103
1≤Ai≤106 for each valid i
1≤Bi≤106 for each valid i
the sum of N over all test cases does not exceed 104
the sum of M over all test cases does not exceed 104
Subtasks
Subtask #1 (20 points):

A1=A2=…=AN
B1=B2=…=BM
Subtask #2 (80 points): original constraints

Example Input
2
2 3
2 2
5 5 5
4 3
1 3 2 4
6 7 8
Example Output
2
1
Explanation
Example case 1: We can perform two swaps ― each time, we swap a pack of 2 votes from A and a pack of 5 votes from B. After that, John Jackson gets 5+5=10 votes and Jack Johnson gets 2+2+5=9 votes.

Example case 2: We can swap the pack of 1 vote from A and the pack of 8 votes from B. After that, John Jackson gets 8+3+2+4=17 votes and Jack Johnson gets 6+7+1=14 votes.


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
	cin >> t;

	while (t--) {

		int n , m;

		cin >> n >> m ;

		int ar[n];
		int arr[m];


		forn(k, n) {
			cin >> ar[k];
		}
		sort(ar, ar + n);

		forn(k, m) {
			cin >> arr[k];
		}
		sort(arr, arr + m);

		int sum1 = accumulate(ar, ar + n, 0);
		int sum2 =  accumulate(arr, arr + m, 0);
		// cout << " " << endl;
		// cout << sum1 << " " << sum2 << " ";
		int x = sum1;
		int y = sum2;
		int i = 0 ;
		int j = m - 1;
		int count = 0 ;
		if (sum2 >= sum1) {
			if (m > n)
			{

				while (i != n) {

					swap(ar[i], arr[j]);
					i++; j--;
					x = accumulate(ar, ar + n, 0);
					y =  accumulate(arr, arr + m, 0);
					count++;

					if (x > y) {
						break;
					}
				}

				// if (x == y) {
				// 	ct(-1);
				// 	break;
				// }

			}

			else if (m < n) {

				while (j != 0) {

					swap(ar[i], arr[j]);
					i++; j--;
					x = accumulate(ar, ar + n, 0);
					y =  accumulate(arr, arr + m, 0);
					count++;

					if (x > y) {
						break;
					}
				}
				// if (x == y) {
				// 	ct(-1);
				// 	break;
				// }

			}

			else { //if (m == n)

				// cout << "hi";
				while (j != 0) {

					swap(ar[i], arr[j]);
					i++; j--;
					x = accumulate(ar, ar + n, 0);
					y =  accumulate(arr, arr + m, 0);
					count++;

					if (x > y) {
						break;
					}
				}

				// if (x == y) {
				// 	ct(-1);
				// 	break;
				// }
				// int g = ar[i] / arr[i];
				// int h = ar[j] / arr[j];

				// if (g == h) {
				// 	ct(-1);
				// 	break;
				// }
			}
			if (x == y) {
				ct(-1);
			}
			else {
				if (x > y) {
					ct(count);
				}
				else if (x < y) {
					ct(-1);
				}
			}
		}


		else if (sum1 > sum2) { // for sum1==sum2 or sum1 > sum2 ... since there's a tie or a win
			ct(0);
		}

	}
	return 0;
}

/*
My test case ... by trial/error...
i/p
6
2 3
2 2
5 5 5
4 3
1 3 2 4
6 7 8
2 3
1 1
2 2 2
3 3
1 1 1
2 2 2
3 3
4 4 4
2 2 2
1 4
8
1 2 3 4

o/p
2
1
-1
2
0
-1


*/