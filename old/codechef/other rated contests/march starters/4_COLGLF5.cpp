/*
///////////////////////////////////////////
//Question/Info

College Life 5 Problem Code: COLGLF5

There is only 1 TV in the common room, and as luck would have it, both the El Clasico football match and the India-Pakistan cricket match are happening simultaneously.

There is one football fan who is looking at the live commentary online and will scream whenever an 'important' event takes place in the El Clasico. Similarly, there is a cricket fan who will do so for every important event in the cricket match.

You are given two arrays - F1,F2,…,Fn, which denote the times when an important event happens in the football match. And similarly C1,C2,…,Cm for cricket. You sadly have the remote in hand. You start out by watching the El Clasico. But whenever an Important event happens in the sport which isn't on the TV right now, you will be forced to switch to that sport's channel, and this continues, i.e., you switch channels if and only if when an important event in the other sport happens. Find the total number of times you will have to switch between the channels.

Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of 3 lines of input.
First line contain 2 space separated integers N and M, number of important events in football and cricket match respectively.
Second line contain N space separated integers Fi, where the ith index represents ith important event in the football match.
Third line contain M space separated integers Ci, where the ith index represents ith important event in the cricket match.
Output:
For each testcase, output in a single line answer to the problem.

Constraints
1≤N,M≤2.5∗104
1≤Fi,Ci≤109
Fi>Fi−1 ∀i>0
Ci>Ci−1 ∀i>0
Fi != Cj ∀i,j
Sum of N over all tests is atmost 2∗105
Sum of M over all tests is atmost 2∗105
Sample Input:
3
2 2
1 3
2 4
3 1
100 200 300
1
1 2
1
100 200
Sample Output:
3
2
1
Explanation:
Case 1: At T=0, we are watching El Clasico. At T=1 there is an important event in football match and since we are already watching the same channel we won't switch. At T=2, there is an important event in cricket match and we switch the channel for the first time. At T=3, there is an important event in football match and we switch the channel for the second time. At T=4, there is an important event in cricket match and we switch the channel for the third time. So in total we switch three times.

Case 2: At T=0, we are watching El Clasico. At T=1 there is an important event in cricket match and we switch the channel for the first time. At T=100, there is an important event in football match and we switch the channel for the second time. At T=200, there is an important event in football match and since we are on the same channel, we don't switch. At T=300, there is an important event in football match and since we are on the same channel, we don't switch. So in total we switch two times.

Case 3: At T=0, we are watching El Clasico. At T=1 there is an important event in football match and since we are on the same channel, we don't switch. At T=100, there is an important event in cricket match and we switch the channel for the first time. At T=200, there is an important event in cricket match and since we are on the same channel, we don't switch. So in total we switch only one time.



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

		int n , m ;
		cin >> n >> m ;


// int f[n]; int c[m];

// forn(i,n){
// 	cin >> f[i];
// }
// forn(i,m){
// 	cin >> c[i];
// }


// int a = max(n,m);

// if(a==n){
// int j = 0 ;
// int x,y;

// forn(i,n){

//  x = f[i];
//  y = c[i];

// if(x<y){



// }
// ++j;

// if(j==m){
// 	break ;
// }

// }


// }

// else{

// }


		int size = n + m + 1;
		int arr3[size];

		int arr[n + 1];

		int j = 1 ;

		forx(i, 1, n + 1) {
			cin >> arr[i];
			arr3[j] = arr[i];
			++j;
		}
		arr[0] = 0;
		arr3[0] = 0;

		int arr2[m];

		forn(i, m) {
			cin >> arr2[i];
			arr3[j] = arr2[i];
			++j;
		}

		sort(arr3, arr3 + size);


		j = 0;


		forn(i, size) {

			if (arr2[j] == arr3[i]) {
				arr3[i] = -1;
				++j;
				// ++count;
			}

		}

		// forn(i, n + 1) {
		// 	tc(arr[i])
		// }

		// ct("")
		// forn(i, m) {
		// 	tc(arr2[i])
		// }
		// ct("")
		// forn(i, size) {
		// 	tc(arr3[i])
		// }
		// ct("")

		int count = 0;


		// int con = 0 ;

		// if (arr3[0] == 0 and arr3[1] == -1) {
		// 	++count;

		// }

		arr3[0] = INT_MAX;
		forn(i, size - 1 ) {

			// if (arr3[i] > arr3[i + 1]) {
			// 	++count;
			// }

			if (arr3[i] > 0 and arr3[i + 1] < 0) {
				++count;
			}

			if (arr3[i] < 0 and arr3[i + 1] > 0) {
				++count;
			}
			// if (arr3[i] == -1 and arr3[i - 1] >= 0 and arr3[i + 1] >= 0) {
			// 	count += 2;
			// }
			// if (i + 1 == size) {
			// 	break;
			// }



		}


		ct(count)



	}





// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}




// 	int size = n + m + 1;
// 	vi fc(size);


// 	vi f(n + 1);

// 	forx(i, 1, n) {
// 		int data;
// 		cin >> data;
// 		f[i] = data;
// 		// f.pb(data);
// 		// fc.pb(data);
// 	}

// 	// f.insert(f.begin(), 0);

// 	// fc.insert(fc.begin(), 0);

// 	forn(i, n + 1) {
// 		tc(f[i])
// 	}


// 	// vi c(m);

// 	// forn(i, m) {
// 	// 	int data;
// 	// 	cin >> data;
// 	// 	c.eb(data);
// 	// 	fc.eb(data);
// 	// }


// 	// sort(all(fc));

// 	// int j = 0;

// 	// forn(i, size ) {

// 	// 	if (fc[i] == c[j]) {
// 	// 		fc[i] = -1;
// 	// 		++j;
// 	// 		// ++count;
// 	// 	}

// 	// }

// 	// int count = 0;

// 	// forn(i, size ) {

// 	// 	// if (fc[i] > fc[i + 1]) {
// 	// 	// 	++count;
// 	// 	// }
// 	// 	tc(fc[i])

// 	// }


// 	// ct(2 * count - 1)



// }



