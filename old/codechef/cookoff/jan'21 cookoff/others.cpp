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
	c_p_c();
///////////

	// code

	A tuple (a, b, c) is considered good if it consists of three prime numbers a, b and c such that a < b < c≤N and a + b = c.

	        Two tuples are considered different if they differ in at least one position. Given N, find the number of good tuples that can be formed by integers from 1 to N.

		        Input
		        The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
		        The following T lines contain a single integer N.
		        Output
		        For each test case, print a single line containing one integer — the number of good tuples which can be formed using integers from 1 to N.

		        Constraints
		        1≤T≤105
		        1≤N≤106
		        Example Input
		        2
		        3
		        6
		        Example Output
		        0
		        1
		        Explanation
	        Example case 1: There are no good tuples. (1, 2, 3) is not a good tuple since 1 is not prime.

Example case 2: (2, 3, 5) is a good tuple since 2, 3 and 5 are prime and 2 + 3 = 5.


	        ----------------------------------

	        For the above question of prime tuples, basic logic is ,
	        in any way out 1st number would be 2 to get the condition,
	        hence other number say x, the result would be x + 2... -> 2, x, x + 2 are all prime.
	        So basically we use segmented sieve upto 10 ^ 5(limits) and
	        find all primes globally. now again iterate over and find
	        the pairs of x and x + 2 and increment the count(earlier initialised to 0).
	        ... then print count.


	        return 0;
}


