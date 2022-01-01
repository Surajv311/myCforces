/*
///////////////////////////////////////////
//Question/Info

Сhef has assembled a football team! Now he needs to choose a name for his team. There are N words in English that Chef considers funny. These words are s1,s2,…,sN.

Chef thinks that a good team name should consist of two words such that they are not funny, but if we swap the first letters in them, the resulting words are funny. Note that under the given constraints, this means that a word is a non-empty string containing only lowercase English letters.

Can you tell Chef how many good team names there are?

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated strings s1,s2,…,sN.
Output
For each test case, print a single line containing one integer — the number of ways to choose a good team name.

Constraints
1≤T≤100
2≤N≤2⋅104
2≤|si|≤20 for each valid i
s1,s2,…,sN contain only lowercase English letters
s1,s2,…,sN are pairwise distinct
the sum of N over all test cases does not exceed 2⋅104
Subtasks
Subtask #1 (20 points): s1,s2,…,sN contain only letters 'a' and 'b'

Subtask #2 (80 points): original constraints

Example Input
3
2
suf mas
3
good game guys
4
hell bell best test
Example Output
2
0
2
Explanation
Example case 1: The good team names are ("muf", "sas") and ("sas", "muf").

Example case 2: There are no good team names because all funny words start with 'g'.

Example case 3: The good team names are ("hest", "tell") and ("tell", "hest").
///////////////////////////////////////////
*/

#include <bits/stdc++.h>
using namespace std;

#define int 		   long long int
#define setbits(x) 	   __builtin_popcount(x)
#define pb(x) 		   push_back(x)
#define mp(x,y) 	   make_pair(x,y)
#define eb(x) 		   emplace_back(x)
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
#define _IOS      	   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// typedef long long int lli;
typedef long double ld;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

void c_p_c()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


int myfun(vector<char> is , vector<char> js) {

	set <char> s(all(is));

	int tmp = 0 ;

	for (auto kk : js) {


		if (s.find(kk) != s.end()) {


			tmp ++;

		}
	}

	return tmp;

}

int compute(map<string, vector<char>> &adj )
//  passing by address......
{

	int res = 0 ;
	for (auto it : adj) {
		for (auto jt : adj) {
			if (it.first != jt.first) {

				auto is = it.second  ;
				auto js = jt.second  ;
				int temp = myfun(is, js);
				res += (is.size() - temp) * (js.size() - temp);


			}
		}
	}

	return res;

}

int32_t main() {
///////////
	c_p_c();
///////////
	_IOS
//////////

	// code

	int t ; cin >> t; while (t--) {

		// unordered_map<string, string> um;

		// int n ;
		// cin >> n ;

		// string arr[n];

		// forn(i, n) {
		// 	cin >> arr[i];
		// }

		// cout << arr[0];

		// forn(i, n) {
		// 	forn(j, n) {

		// 		string x = arr[i];
		// 		string y = arr[j];
		// 		um[x].pb(y);
		// 		// cout << x << y ;

		// 	}

		map<string, vector<char>> adj ;
		int n ;
		cin >> n ;

		string s ;

		forn(i, n) {
			cin >> s;

			// if (s.length() > 0) {
			// pushing the first letter ...
			// since given length of string : 2≤|si|≤20
			adj[s.substr(1)].pb(s[0]);

		}




		cout << compute(adj) << "\n";



	}






// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}