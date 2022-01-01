/*
///////////////////////////////////////////
//Question/Info

Lately, Chef has been inspired by the "pawri" meme. Therefore, he decided to take a string S and change each of its substrings that spells "party" to "pawri". Find the resulting string.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single string S.
Output
For each test case, print a single line containing the string after it is modified by Chef.

Constraints
1≤T≤10
1≤|S|≤105
S contains only lowercase English letters
Example Input
3
part
partypartiparty
yemaihuyemericarhaiauryahapartyhorahihai
Example Output
part
pawripartipawri
yemaihuyemericarhaiauryahapawrihorahihai
Explanation
Example case 1: There is no substring "party" in the original string.

Example case 2: The original string has 2 substrings "party".

Example case 3: There is only a single substring "party" in the original string.

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
//	c_p_c();
///////////
	_IOS
//////////

	// code


	int t ; cin >> t; while (t--) {


		string s ;
		cin >> s ;

		string xx = "party";
		string temp = "pawri";

		int l = s.length();

		forn(i, l) {

			if (s[i] == 'p' and s[i + 1] == 'a' and s[i + 2] == 'r' and s[i + 3] == 't' and s[i + 4] == 'y') {
				s[i] = 'p';
				s[i + 1] = 'a';
				s[i + 2] = 'w';
				s[i + 3] = 'r';
				s[i + 4] = 'i';

			}

			// if (s.substr(i, 5 + i) == xx) {
			// 	s.replace(i, 5 + i, temp);
			// }


		}

		ct(s);



	}



// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}