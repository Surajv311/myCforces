/*
///////////////////////////////////////////
//Question/Info

A time is a string in the format "HH:MM AM" or "HH:MM PM" (without quotes), where HH and MM are always two-digit numbers. A day starts at 12:00 AM and ends at 11:59 PM. You may refer here for understanding the 12-hour clock format.

Chef has scheduled a meeting with his friends at a time P. He has N friends (numbered 1 through N); for each valid i, the i-th friend is available from a time Li to a time Ri (both inclusive). For each friend, can you help Chef find out if this friend will be able to attend the meeting? More formally, check if Li≤P≤Ri for each valid i.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single time P.
The second line contains a single integer N.
N lines follow. For each valid i, the i-th of these lines contains two space-separated times Li and Ri.
Output
For each test case, print a single line containing one string with length N. For each valid i, the i-th character of this string should be '1' if i-th friend will be able to attend the meeting or '0' otherwise.

Constraints
1≤T≤500
1≤N≤500
each time is valid in the 12-hour clock format
for each valid i, the time Ri is greater or equal to Li
Subtasks
Subtask #1 (100 points): original constraints

Example Input
2
12:01 AM
4
12:00 AM 11:42 PM
12:01 AM 11:59 AM
12:30 AM 12:00 PM
11:59 AM 11:59 PM
04:12 PM
5
12:00 AM 11:59 PM
01:00 PM 04:12 PM
04:12 PM 04:12 PM
04:12 AM 04:12 AM
12:00 PM 11:59 PM
Example Output
1100
11101
Explanation
Example case 1:

Friend 1: 12:01 AM lies between 12:00 AM and 11:42 PM (that is, between 00:00 and 23:42 in the 24-hour clock format), so this friend will be able to attend the meeting.
Friend 2: 12:01 AM lies between 12:01 AM and 11:59 AM (between 00:01 and 11:59 in the 24-hour clock format).
Friend 3: 12:01 AM does not lie between 12:30 AM and 12:30 PM (between 00:30 and 12:30 in the 24-hour clock format), so this friend will not be able to attend the meeting.
Friend 4: 12:01 AM does not lie between 11:59 AM and 11:59 PM (between 11:59 and 23:59 in the 24-hour clock format).
Example case 2: For friend 3, 04:12 PM lies between 04:12 PM and 04:12 PM (inclusive) and hence this friend will be able to attend the meeting.
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

// typedef long long int lli;
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

//  NOT WORKING...
	// string s;
	// // cin >> s;
	// getline(cin, s);
	// // string ss = s.substr(9, 11);
	// string ss = s;

	// cout << s.substr(11, 13) ;

	int t ; cin >> t; while (t--) {


		string hr1, ap1 ;
		cin >> hr1 >> ap1; // since space in i/p
		// getline(cin, s);
		// bool flag = false;
		string sss1 = hr1.substr(0, 2);

		// flag = true;

		string temp1 = hr1.substr(0, 2);
		int tt1 = stoi(temp1);

		if (ap1[0] == 'A') {
			if (sss1[0] == '1' and sss1[1] == '2') {
				hr1.replace(0, 2, "00");
			}
		}

		if (ap1[0] == 'P') {
			// if (sss1[0] != '1' and sss1[1] != '2') {
			if (tt1 != 12) {
				string xx = hr1.substr(0, 2);
				int xx2 = stoi(xx);
				xx2 = xx2 + 12;
				string kk = to_string(xx2);
				// cout << xx2;
				hr1.replace(0, 2, kk);
			}
		}
		// ct(hr1);
		string num = "";
		forn(it, hr1.length()) {
			if (isdigit(hr1[it])) {
				num += hr1[it];
			}

		}

		int num1 = stoi(num);
		// ct(num1)

		int k ;
		cin >> k ;

		forn(i, k) {


			string hr2, ap2, hr3, ap3;
			cin >> hr2 >> ap2 >> hr3 >> ap3;

			string sss2 = hr2.substr(0, 2);

			// flag = true;
			string temp2 = hr2.substr(0, 2);
			int tt2 = stoi(temp2);

			if (ap2[0] == 'A') {
				if (sss2[0] == '1' and sss2[1] == '2') {
					hr2.replace(0, 2, "00");
				}
				// cout << "came here";
			}

			if (ap2[0] == 'P') {
				// if (sss2[0] != '1' and sss2[1] != '2') {
				if (tt2 != 12) {
					string xx = hr2.substr(0, 2);
					int xx2 = stoi(xx);
					xx2 = xx2 + 12;
					string kk = to_string(xx2);
					// cout << xx2;
					hr2.replace(0, 2, kk);
				}
			}
			// ct(hr2);
			string num2 = "";
			forn(j, hr2.length()) {
				if (isdigit(hr2[j])) {
					num2 += hr2[j];
				}

			}

			int num22 = stoi(num2);
			// ct(num22)



			string sss3 = hr3.substr(0, 2);


			string temp3 = hr3.substr(0, 2);
			int tt3 = stoi(temp3);


			if (ap3[0] == 'A') {
				if (sss3[0] == '1' and sss3[1] == '2') {
					hr3.replace(0, 2, "00");
				}
			}

			if (ap3[0] == 'P') {
				// if (sss3[0] != '1' and sss3[1] != '2') {
				if (tt3 != 12) {
					string xx = hr3.substr(0, 2);
					int xx2 = stoi(xx);
					xx2 = xx2 + 12;
					string kk = to_string(xx2);
					// cout << xx2;
					hr3.replace(0, 2, kk);
				}
			}
			// ct(hr3)
			string num3 = "";
			forn(k, hr3.length()) {
				if (isdigit(hr3[k])) {
					num3 += hr3[k];
				}

			}

			int num33 = stoi(num3);
			// ct(num33)

			// cout << num1 << " " << num22 << " " << num33 << " " << endl;


			if (num1 >= num22 and num1 <= num33 ) {

				cout << "1";

			}
			else {
				cout << "0";
			}




		}
		ct("")


	}





// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}