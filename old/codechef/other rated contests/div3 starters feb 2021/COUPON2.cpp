/*
///////////////////////////////////////////
//Question/Info

Chef wants to order food from a food delivery app. He wishes to order once today, and buy three items costing A1,A2 and A3 rupees, respectively. He'll also order once tomorrow, when he'll buy three items costing B1,B2 and B3 rupees, respectively. There is an additional delivery charge of rupees D for each order.

He notices that there is a coupon on sale, which costs rupees C. If he buys that coupon, the delivery charges on any day, on an order of rupees 150 or more shall be waived (that is, the D rupees will not be added, if the sum of the costs of the items is ≥150).

Note that Chef is ordering the three items together on each day, so the delivery charge is charged only once each day. Also, note that it's only needed to buy the coupon once to avail the delivery fee waiver on both days.

Should Chef buy the coupon? Note that Chef shall buy the coupon only if it costs him strictly less than what it costs him without the coupon, in total.

Input:
The first line of the input contains a single integer T, denoting the number of test cases.
The first line of each test case contains two space-separated integers D and C, denoting the delivery charge, and the price of the coupon, respectively.
The second line of each test case contains three space-separated integers A1,A2 and A3, denoting the prices of the food items that Chef plans to order on Day 1, respectively.
The third line of each test case contains three space-separated integers B1, B2 and B3, denoting the prices of the food items that Chef plans to order on Day 2, respectively.
Output:
For each test case, output YES if Chef should buy the coupon, and NO otherwise, in a separate line.

Constraints
1≤T≤104
1≤D,C≤100
1≤A1,A2,A3≤100
1≤B1,B2,B3≤100
Sample Input 1:
2
90 100
100 50 10
80 80 80
30 30
100 100 100
10 20 30
Sample Output 1:
YES
NO
Explanation:
Testcase 1: On the first day, Chef plans on ordering three food items, costing a total of rupees (100+50+10)=160. On the second day, Chef plans on ordering three food items, costing a total of rupees (80+80+80)=240.

If Chef buys the coupon he shall save the delivery charge on both days, but the coupon shall cost him rupees 100 extra. In total, it shall cost him (160+240+100)=500.

Without the coupon, Chef will have to pay the delivery charges for both days, which shall cost him a total of rupees (160+240+90+90)=580.

Thus, it's better for Chef to buy the coupon.

Testcase 2: On the first day, Chef plans on ordering three food items, costing a total of rupees (100+100+100)=300. On the second day, Chef plans on ordering three food items, costing a total of rupees (10+20+30)=60.

If Chef buys the coupon he shall save the delivery charge on only the first day, but the coupon shall cost him rupees 30 extra. In total, it shall cost him (300+60+30 (coupon cost) +30 (delivery cost for second day))=420.

Without the coupon, Chef will have to pay the delivery charges for both days, which shall cost him a total of rupees (300+60+30 (delivery cost for first day)+30 (delivery cost for second day))=420.

Since it shall cost him the same amount in both the cases, Chef shall not buy the coupon.

Sample Input 2:
1
30 45
100 100 100
10 20 30
Sample Output 2:
NO
Explanation:
Testcase 1: On the first day, Chef plans on ordering three food items, costing a total of rupees (100+100+100)=300. On the second day, Chef plans on ordering three food items, costing a total of rupees (10+20+30)=60.

If Chef buys the coupon he shall save the delivery charge on only the first day, but the coupon shall cost him rupees 45 extra. In total, it shall cost him (300+60+45 (coupon cost) +30 (delivery cost for second day))=435.

Without the coupon, Chef will have to pay the delivery charges for both days, which shall cost him a total of rupees (300+60+30 (delivery cost for first day)+30 (delivery cost for second day))=420.

Since it shall cost him strictly more amount when he buys the coupon, Chef shall not buy the coupon.

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
#define ct(x) 		   cout << x << endl;
#define ct2(x,y) 	   cout << x << " " << y << endl;
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


		int d, c;
		cin >> d >> c;

		int arr1[3];
		int arr2[3];


		forn(i, 3) {
			cin >> arr1[i];
		}


		forn(i, 3) {
			cin >> arr2[i];
		}

		int sum1 = accumulate(arr1, arr1 + 3, 0);
		int sum2 = accumulate(arr2, arr2 + 3, 0);


// without coupon
		int sum = sum1 + d + d + sum2;

// with coupon
		int summ = 0;
		if (sum1 >= 150) {

			summ += sum1;

		}
		else {
			summ += sum1 + d;
		}

		if (sum2 >= 150) {

			summ += sum2;

		}
		else {
			summ += sum2 + d;
		}

		summ += c;


		if (sum > summ) {
			ct("YES")
		}
		else {
			ct("NO")
		}





	}







// cerr << "time: " << clock() << " ms" << '\n';
	return 0;
}

