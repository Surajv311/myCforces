/*
///////////////////////////////////////////

There are N horses in the stable. The skill of the horse i is represented by an integer S[i]. The Chef needs to pick 2 horses for the race such that the difference in their skills is minimum. This way, he would be able to host a very interesting race. Your task is to help him do this and report the minimum difference that is possible between 2 horses in the race.

Input:
First line of the input file contains a single integer T, the number of test cases.
Every test case starts with a line containing the integer N.
The next line contains N space separated integers where the i-th integer is S[i].
Output:
For each test case, output a single line containing the minimum difference that is possible.
Constraints:
1 ≤ T ≤ 10
2 ≤ N ≤ 5000
1 ≤ S[i] ≤ 1000000000

Example:
Input:
1
5
4 9 1 32 13

Output:
3

Explanation: The minimum difference can be achieved if we pick horses with skills 1 and 4 for the race.

///////////////////////////////////////////
*/

#include <bits/stdc++.h>
#define int long long int
#define setbits(x) __builtin_popcount(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ct(x) cout<<x<<endl;
#define ct2(x,y) cout<<x<<" "<<y<<endl;
//typedef long long int lli;
typedef long double ld;

using namespace std;

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



	int t ; // test cases
	cin >> t ;

	for (int i = 0; i < t; ++i)
	{
		int h ; // number of horses
		cin >> h ;
		vector <int> v ; // to store skills of horses
		for (int j = 0; j < h; ++j)
		{
			int data ;
			cin >> data ;
			v.pb(data);
		}

		sort(v.begin(), v.end());
		// even after sorting .. edge case could be 1,4,5,9,11 So |4-5| < |1-4|

		int d = v[1] - v[0] ;

		for (int k = 1; k < h - 1 ; ++k)
		{
			int d0 = v[k + 1] - v[k] ;
			if (d0 < d)
			{
				d = d0;
			}

		}

		ct(d);

	}



	return 0;
}