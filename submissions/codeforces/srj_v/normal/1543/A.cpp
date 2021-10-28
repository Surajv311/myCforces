/*
//////////////////////////////////////////////////////
//Question/Info



author: srj_v
//////////////////////////////////////////////////////
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
#define p_q            priority_queue // priority_queue<int> || priority_queue<int,vi,greater<int>>
#define _IOS      	   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define dbg(x) 		   cout << #x << "=" << x << "\n";
#define dbg2(x,y) 	   cout << #x << "=" << x << " , " << #y << "=" << y << "\n";
#define F 			   first
#define S 			   second

typedef long double ld;
// typedef long long int lli;

#pragma GCC optimize("Ofast")

template<typename... T>
void read(T&... args) {
	((cin >> args), ...);
}

template<typename... T>
void write(T&&... args) {
	((cout << args << "\n"), ...);
}

void c_p_c()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

///**************////////////////////**************///


int32_t main() {
///////////
//	c_p_c();
///////////
	_IOS
//////////

	// code

	int t ; cin >> t; while (t--) {

//  we can +1 or -1 ...

		int a, b; read(a, b);

		int moves, ex;

		/*


		considering our q..
		since we can +1/-1 in the a & b... so notice:
		that (let a>b)- GCD(a,b)=GCD(a−b,b) would be true...
		Eg. 50 & 100 ~ = 50 and can't be 51...

		so whatever be the case, the max excitement/gcd
		we can get is |a-b|...
		So for the given case in q. max gcd possible = |a-b|

		Now to get min. moves,
		assume a>b then, |---b---~---~---~-a~---~---~-----|
		so we can either increase the value of 'a' or
		decrease the value of 'a' (b also updated by default...)
		to get the min. moves to get a max gcd of (a-b,b)... :-

		so if we are increasing/ decreasing
		we have 2 cases, consider that the gcd was :
		c = |a-b| then, our 'a' must be increased, so it
		must be in multiples of c... similarly for the
		case of decreasing... visualize...
		then take the min of them...
		*/


		if (a == b) {
			moves = 0 ; ex = 0 ;
		}

		else {

			if (a < b) swap(a, b);

			ex = a - b;

			moves = min( (a % ex) , (((a / ex + 1) * ex) - a));
// could also be : min( (a % ex) , (ex - (a%ex)));
		}

		ct2(ex, moves);


	}







// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}

///**************////////////////////**************///