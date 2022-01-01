/*
///////////////////////////////////////////

https://www.codechef.com/DEC20B/problems/POSPREFS

///////////////////////////////////////////
*/

#include <bits/stdc++.h>
#define int long long int
#define setbits(x) __builtin_popcount(x)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define ct(x) cout<<x<<endl;
#define ct2(x,y) cout<<x<<" "<<y<<endl;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forx(i, x, n) for (int i = x ; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

//typedef long long int lli;
typedef long double ld;
//typedef pair<int, int> pii;
//typedef vector<int> vi;
//typedef vector<pii> vii;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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


	int t ;
	cin >> t ;

	while (t) {

		int n , k ;

		cin >> n >> k ;

		int count = 0 ;
		int d = n - k ;
		int arr[n + 1];
		arr[0] = 0 ;

		/* SO BASICALLY ARRAY WOULD BE LIKE : SAY OF SIZE 6 = 0 1 2 3 4 5
		-> SO INDEX 0 WOULD BE PUT ZERO AND EXCLUDED FROM OUR FUTURE OPERATIONS.
		MADE ARRAY SIZE OF 6 TO COUNT NUMBERS UPTO 5 ...
		*/

		for ( int i = 1 ; i < n + 1; i++) {

			/*INITIALLY STORING ALL 'i' VALUES IN ARRAY.
			LATER THE NUMBERS WITH THEIR EXPECTED SIGN (+/-...)
			*/

			arr[i] = i ;

		}

		if (n != k) {

// IF n==k THEN WE CAN DIRECTLY PRINT THE ARRAY OTHERWISE FOLLOW:

			for ( int i = 1 ; i < n + 1; i += 2) {
				if (count < d) {
					arr[i] = -i ;
					count++;
				}

			}

			// cout << count << "   " ;
			// cout << d << "   ";
			if (count != d) {

// WHEN THE ARRAY SIZE IS ODD

				if (n % 2 != 0) {
					for ( int i = n - 1 ; i > 1; i -= 2) {
						// cout << count ;
						// cout << d ;
						// cout << arr[i] << "  ";
						if (count < d) {
							arr[i] = -i ;
							count++;
						}
						else {
							break ;
						}
					}
				}

				else {

// WHEN ARRAY SIZE IS EVEN

					for ( int i = n ; i > 1; i -= 2) {
						// cout << count ;
						// cout << d ;
						// cout << arr[i] << "  ";
						if (count < d) {
							arr[i] = -i ;
							count++;
						}
						else {
							break ;
						}
					}

				}
			}




		}

// PRINTING SERIES
		for ( int i = 1 ; i < n + 1; i++)  {
			cout << arr[i] << " ";
		}



		t-- ;

	}

	/*
	THE DIFFERENT INPUTS FOR THE QUESTION IS :

	FOR I/P: (SERIES PRODUCED)
	5 1 = -1 2 -3 -4 -5
	5 2 = -1 2 -3 4 -5
	5 3 = -1 2 -3 4 5
	5 4 = -1 2 3 4 5
	5 5 = 1 2 3 4 5

	SIMILARLY FOR:
	4 1 = -1 2 -3 -4
	4 2 = -1 2 -3 4
	4 3 = -1 2 3 4
	4 4 = 1 2 3 4

	SO CHECK FOR ODD/EVEN SIZE OF ARRAY
	*/

	// PROBLEM SOLVED IN 6hrs. ~11AM- 7PM ...
	return 0;
}