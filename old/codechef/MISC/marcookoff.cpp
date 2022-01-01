/*

Guess the Number Problem Code: GUESSIT

This is an interactive problem.

Chef has a secret integer. The only information you have is that it has an odd number of factors and that it lies between 1 and 106 inclusive.

You have been challenged by Chef to find his number. You may make up to 2,000 guesses (queries). Whenever you guess Chef's number, he only tells you if you guessed correctly or not. Can you find Chef's number?

Interaction
First, you should read a line containing a single integer T ― the number of test cases. The description of interaction for T test cases follows.
For each test case, you should start by asking queries.
To ask a query, you should print a line containing an integer between 1 and 106 inclusive ― your guess.
Then, you should read a line containing a single integer: 1 if you correctly guessed Chef's secret number, 0 if your guess was incorrect or −1 if your guess is invalid (in particular, smaller than 1 or greater than 106) or you have asked more than 2,000 queries.
As soon as you have correctly guessed Chef's secret number, you should stop asking queries and continue solving the remaining test cases.
If you read −1, you must immediately terminate your program to receive a Wrong Answer verdict. Otherwise, you may receive any verdict. Don't forget to flush the output after printing each line! You can read more about interactive problems here.

Constraints
1≤T≤100
Chef's secret number lies between 1 and 106 inclusive
Chef's secret number has an odd number of factors
Interaction
Grader          You
1
                232
0
                92739
0
                100
1
Explanation
Example case 1:

You ask Chef if 232 is his secret number. Chef replies with 0, so it is not.
You ask Chef if 92,739 is his secret number. Chef replies with 0, so it is not.
You ask Chef if 100 is his secret number. Chef replies with 1, so this is indeed his secret number.




ANS



DIFFICULTY:
Simple

PREREQUISITES:
Math

PROBLEM:
Chef has a secret number. The only information you have is that it has an odd number of factors, and that it lies between 1 and 10^610
6
 , both inclusive. He challenges you to guess the number in at most 2000 tries. Can you guess it?

QUICK EXPLANATION:
Only perfect squares have an odd number of factors, thus the possible secret numbers Chef can have would all be perfect squares and can be guessed correctly by querying all perfect squares in the given range [1, 10^6][1,10
6
 ].

EXPLANATION:
The simple way of guessing the right number within the given number of tries is to query all perfect squares between 11 to 10^610
6
 . As 10^610
6
  (the maximum possible secret number) is the square of 10^310
3
 , we would have to query numbers from 1^21
2
  to (10^3)^2(10
3
 )
2
  so as to cover all the perfect squares lying between 11 and 10^610
6
 . This constitutes 10001000 tries which is less than the limit given as 20002000.

We deduced that the only possible secret numbers are perfect squares because the number of factors are given to be odd. We know that the factors of a number always exist in pairs because if xx is a factor of a number NN, then \large \frac {N}{x}
x
N
​
  will also be a factor. The only possible case in which the factors will not be in a pair is when x=\large \frac {N}{x}x=
x
N
​
  for one of the factors xx of NN, which is the true in case of perfect squares. Therefore perfect squares have odd number of factors and we only need to query them to reach the correct guess.

TIME COMPLEXITY:
O(1)O(1) per test case, as it takes maximum 10001000 interactions to guess the number which is a constant.

SOLUTIONS:
 Setter
//created by Whiplash99
import java.io.*;
import java.util.*;
class A
{
    private static void print(int N)
    {
        System.out.println(N);
        System.out.flush();
    }
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

        int i,N;

        int T=Integer.parseInt(br.readLine().trim());
        while (T-->0)
        {
            for(i=1;i<=1000;i++)
            {
                print(i*i);
                int verd=Integer.parseInt(br.readLine().trim());

                if(verd==1) break;
                else if(verd==-1) System.exit(0);
            }
        }
    }
}
 Tester
 #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef rd
#define trace(...)
//#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
//#define double long double
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const int infi=0x3f3f3f3f;
const ll infl=0x3f3f3f3f3f3f3f3fLL;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(int a, int b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}


long long readInt(long long l, long long r, char endd) {
	long long x=0;
	int cnt=0;
	int fi=-1;
	bool is_neg=false;
	while(true) {
		char g=getchar();
		if(g=='-') {
			assert(fi==-1);
			is_neg=true;
			continue;
		}
		if('0'<=g&&g<='9') {
			x*=10;
			x+=g-'0';
			if(cnt==0) {
				fi=g-'0';
			}
			cnt++;
			assert(fi!=0 || cnt==1);
			assert(fi!=0 || is_neg==false);

			assert(!(cnt>19 || ( cnt==19 && fi>1) ));
		} else if(g==endd) {
			if(is_neg) {
				x=-x;
			}
			assert(l<=x&&x<=r);
			return x;
		} else {
			assert(false);
		}
	}
}
string readString(int l, int r, char endd) {
	string ret="";
	int cnt=0;
	while(true) {
		char g=getchar();
		assert(g!=-1);
		if(g==endd) {
			break;
		}
		cnt++;
		ret+=g;
	}
	assert(l<=cnt&&cnt<=r);
	return ret;
}
long long readIntSp(long long l, long long r) {
	return readInt(l,r,' ');
}
long long readIntLn(long long l, long long r) {
	return readInt(l,r,'\n');
}
string readStringLn(int l, int r) {
	return readString(l,r,'\n');
}
string readStringSp(int l, int r) {
	return readString(l,r,' ');
}

void solve() {
	fr(i,1,1000) {
		cout<<i*i<<endl;
		int pp;
		cin>>pp;
		if(pp==1)
			return;
	}
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=readIntLn(1,100);
//	int t=1;
//	cin>>t;
	fr(i,1,t)
		solve();
	assert(getchar()==EOF);
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
}

 Editorialist
    #include<bits/stdc++.h>
    using  namespace std;

    #define _z ios_base::sync_with_stdio(false); cin.tie(NULL);
    #define int long long int
    #define endl "\n"
    #define mod 1000000007
    #define pb_ push_back
    #define mp_ make_pair

    //______________________________z_____________________________

    vector<int> perfs;

    void solve()
    {
        for(auto it: perfs) {
            cout<<it<<endl;
            fflush(stdout);
            int status;
            cin>>status;
            if(status==1) return;
            else  if(status==-1) exit(0);
        }
    }

    int32_t main()
    {
        //_z;
        int t=1;
    cin>>t;
    for(int i=1; i<=1000; i++) perfs.pb_(i*i);
    while(t--)
    {
        solve();
    }
    }



---------------------------------------------------------------------

Matrix XOR Problem Code: MATXOR

Chef has a tasty ingredient ― an integer K. He defines a tasty matrix A with N rows (numbered 1 through N) and M columns (numbered 1 through M) as Ai,j=K+i+j for each valid i,j.

Currently, Chef is busy in the kitchen making this tasty matrix. Help him find the bitwise XOR of all elements of this matrix.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains three space-separated integers N, M and K.
Output
For each test case, print a single line containing one integer ― the bitwise XOR of all elements of the tasty matrix with the given dimensions made with the given special ingredient.

Constraints
1≤T≤105
1≤N,M≤2⋅106
1≤K≤109
the sum of N over all test cases does not exceed 2⋅106
the sum of M over all test cases does not exceed 2⋅106
Example Input
2
2 2 5
2 3 7
Example Output
14
5
Explanation
Example case 1: The matrix is
A=(5+1+15+2+15+1+25+2+2)=(7889).
The XOR of all its elements is 7⊕8⊕8⊕9=14.

Example case 2: The matrix is
A=(7+1+17+2+17+1+27+2+27+1+37+2+3)=(91010111112).
The XOR of all its elements is 9⊕10⊕11⊕10⊕11⊕12=5.




ans:



DIFFICULTY:
Simple

PREREQUISITES:
XOR-properties, Difference Array

PROBLEM
You are given a matrix AA of dimensions N \times MN×M which is defined as A_{i, j} = K + i + jA
i,j
​
 =K+i+j. Your task is to find the bitwise xor of all elements of the matrix of given dimensions.

QUICK EXPLANATION
Each unique number in the matrix will contribute either itself or a 00 to the resultant XOR. Find the number of appearances (say YY) for each unique number populating the matrix. If YY for the unique number XX present in the matrix is even, it will contribute (X⊕X)(X⊕X) XOR’d with itself Y/2Y/2 times, resulting in a 00. Whereas if YY is odd, the number itself will be contributed because (X⊕X)(X⊕X) will be XOR’d with itself (Y-1)/2(Y−1)/2 times, which in turn will be XOR’d with the remaining XX, thus contributing 0⊕X0⊕X.

EXPLANATION
We have a matrix AA of dimensions N \times MN×M where each element of the matrix is defined as A_{i, j} = K + i + jA
i,j
​
 =K+i+j. We need to find the bitwise XOR of all elements of the matrix.

Let’s forget KK for a moment.

The first observation that we can make is that the number of distinct values present in the matrix will lie in a range [2, N+M][2,N+M] such that every number of this range is present in the matrix.

 Proof
Suppose we have an integer SS that is the sum of two integers ii and jj, where ii and jj lie in a given range. Then, we can always obtain integers S-1S−1 and S+1S+1 incrementing and decrementing either ii or jj respectively.

Since ii and jj in context of the given question (row and column indices respectively), lie in a the continuous range of 11 to NN, hence for every i\gt 1i>1, i\lt ni<n, j\gt 1j>1 and j\lt mj<m, (i-1, i+1, j-1, j+1)(i−1,i+1,j−1,j+1) will also lie in the given range, implying that S+1S+1 and S-1S−1 are obtainable. If we are unable to increment ii and jj, then the sum corresponding to these row and column designations would be the maximum possible for the given range of ii and jj thus making S+1S+1 unobtainable. Whereas if we are unable to decrement ii and jj, we would obtain minimum possible SS and would not be able to obtain S-1S−1.

This means the S values populating the matrix will lie between 1+11+1 (corresponding to i=1i=1, j=1j=1 which can’t be decremented further) and N+MN+M (corresponding to i=Ni=N, j=Mj=M which can’t be incremented further).

Now we are left with finding the number of cells in the matrix such that i+j=Xi+j=X, for all XX in the range [2, N+M][2,N+M].

For every row ii, our jj will vary from 11 to MM. The minimum and maximum value present in row ii will be i+1i+1 and i+Mi+M respectively. Also all the values of range [i+1, i+M][i+1,i+M] will be present in row ii as proved above.

As each row represents a contiguous range [i+1, i+M][i+1,i+M], we would use the difference array (representing the values in the matrix 22 to M+NM+N) to increment the count of all numbers in a range. We would traverse each row and increment the numbers in the range it represents by 1.

On dissolving the difference array we obtain the number of times (say CC) each of the numbers from 22 to N+MN+M are present in the matrix. Now a number from the matrix will contribute to the resultant XOR only if it is present odd number of times i.e. only numbers with odd corresponding CC values will contribute to the final XOR. Since if we xor a number with itself even number of times, then the resultant is 00. As

X \oplus X = 0
X⊕X=0
Now for each element XX of the range [2, N+M][2,N+M], if it is present an odd number of times, then we include (X+K)(X+K) in the resultant XOR. Finally, we output the resultant XOR.

TIME COMPLEXITY:
O(N+M)O(N+M) per test case

SOLUTIONS:
 Setter
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int n, m, k; cin>>n>>m>>k;

        int ans = 0;
        for(int x = 2; x <= n + m; ++x){
            // i + j = x, 1 <= i <= n, 1 <= x - i <= m
            //  max(1, x - m) <= i <= min(n, x - 1)
            int l = max(1, x - m), r = min(n, x - 1);
            if(r >= l && (r - l + 1) % 2 == 1)ans ^= (k + x);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
 Tester
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef rd
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
typedef long long ll;
typedef long double f80;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
//#define double long double
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const int infi=0x3f3f3f3f;
const ll infl=0x3f3f3f3f3f3f3f3fLL;
//const int mod=998244353;
const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(int a, int b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}


long long readInt(long long l, long long r, char endd) {
	long long x=0;
	int cnt=0;
	int fi=-1;
	bool is_neg=false;
	while(true) {
		char g=getchar();
		if(g=='-') {
			assert(fi==-1);
			is_neg=true;
			continue;
		}
		if('0'<=g&&g<='9') {
			x*=10;
			x+=g-'0';
			if(cnt==0) {
				fi=g-'0';
			}
			cnt++;
			assert(fi!=0 || cnt==1);
			assert(fi!=0 || is_neg==false);

			assert(!(cnt>19 || ( cnt==19 && fi>1) ));
		} else if(g==endd) {
			if(is_neg) {
				x=-x;
			}
			assert(l<=x&&x<=r);
			return x;
		} else {
			assert(false);
		}
	}
}
string readString(int l, int r, char endd) {
	string ret="";
	int cnt=0;
	while(true) {
		char g=getchar();
		assert(g!=-1);
		if(g==endd) {
			break;
		}
		cnt++;
		ret+=g;
	}
	assert(l<=cnt&&cnt<=r);
	return ret;
}
long long readIntSp(long long l, long long r) {
	return readInt(l,r,' ');
}
long long readIntLn(long long l, long long r) {
	return readInt(l,r,'\n');
}
string readStringLn(int l, int r) {
	return readString(l,r,'\n');
}
string readStringSp(int l, int r) {
	return readString(l,r,' ');
}

int sum_n=0,sum_m=0;
void solve() {
	int n=readIntSp(1,1000000),m=readIntSp(1,1000000),k=readIntLn(1,1000'000'000);
	sum_n+=n;
	sum_m+=m;
	assert(sum_n<=1000000&&sum_m<=1000000);
	int ans=0;
	fr(i,2,n+m)
		if(min({i-1,n,m,n+m-i+1})&1)
			ans^=(k+i);
	cout<<ans<<endl;
}
signed main() {
	ios_base::sync_with_stdio(0),cin.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(10);
	int t=readIntLn(1,100000);
//	int t;
//	cin>>t;
	fr(i,1,t)
		solve();
	assert(getchar()==EOF);
#ifdef rd
	cerr<<endl<<endl<<endl<<"Time Elapsed: "<<((double)(clock()-clk))/CLOCKS_PER_SEC<<endl;
#endif
}

 Editorialist
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
  int n,m,k;
  cin>>n>>m>>k;

  int diff_arr[n+m+5]={};

  for(int i=1;i<=n;i++)
  {
    int l=i+1;
    int r=i+m;

    diff_arr[l]++;
    diff_arr[r+1]--;
  }

  int ans=0;

  for(int i=2;i<=n+m;i++)
  {
    diff_arr[i]+=diff_arr[i-1];

    if(diff_arr[i]%2)
    {
      ans^=(k+i);
    }
  }

  cout<<ans<<"\n";
}

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin>>t;

  while(t--)
  {
    solve();
  }

return 0;
}





epsilonalpha

2
1d
Solution 53 without difference array.
O(n+m)O(n+m) time and O(1)O(1) auxiliary memory.

Approach: The sum of indicies can be in the range [2,m+n][2,m+n]. If a cell has a value zz, the cell south-west of it will have the same value zz, or in other words, the entire diagonal starting somewhere on the first row, or last column, will have the same value, and these will alternate odd and even. The diagonal starting at (1,1)(1,1) will have just one occurence of the value (the fist cell itself). The diagonal starting at the next cell (1,2)(1,2) will have two occurences. The diagonal starting at cell (n,m)(n,m) will have one, the cell above it will have two, and so on. All the unique values the matrix can be obtained by just going through the boundary of the matrix.
Let x =min(m,n)x=min(m,n) and y = max(m,n)y=max(m,n).
Imagine traversing along the top and right boundary of the matrix. I divide these indices in three regions and process them individually.

[1,x)[1,x) - From first cell until minimum of rows or columns. We only need the ones with odd number of occurences.
[x,y][x,y] - If x is odd, this region will have the same number of occurences everytime and we need to account for them all.
(y,x+y](y,x+y] - Same as first region. Used a reverse loop for ease.



-------------------------------------------------------------------


CONDEL - Editorial


DIFFICULTY:
Easy

PREREQUISITES:
Sliding Window, Greedy

PROBLEM
You are given a positive integer KK and an array AA of length NN whose elements A_1, A_2, \ldots, A_NA
1
​
 ,A
2
​
 ,…,A
N
​
  are only zeros and ones. Your task is to turn all elements of AA into zeros by operating as many times.

Operation is defined as follows:

Choose two indices LL and RR (L \le R)(L≤R) such that R-L+1=KR−L+1=K.
The cost of this operation is A_L+A_{L+1}+\ldots+A_{R-1}+A_RA
L
​
 +A
L+1
​
 +…+A
R−1
​
 +A
R
​
 .
Choose an index PP such that L \le P \le RL≤P≤R and set A_P=0A
P
​
 =0.
You need to find the minimum cost to turn all the elements of AA into zeroes.

QUICK EXPLANATION:
Initially we repeatedly select the window of length KK that has minimum number of 1's1
′
 s in it as our subarray, until all its 1's1
′
 s have been flipped. Then we consecutively select successive subarrays of length KK moving the window to the right by a single unit for each operation. We repeat this to the left of the initial window as well.

EXPLANATION:
Since we want the cost to be the minimum possible, the optimal choice of selecting a subarray of size KK is the one that has the minimum number of 1's1
′
 s. Since this subarray will have a minimum sum i.e.i.e. minimum cost.

Suppose a subarray SS (having MM 1's1
′
 s) has the minimum number of 1's1
′
 s among all subarrays. Thus for SS, the cost for turning one of the 1's1
′
 s to 00 will be MM initially.

After having flipped one of the 1's1
′
 s, there will remain (M-1)(M−1) 1's1
′
 s which means SS again has the minimum number of 1's1
′
 s and thus is the optimal choice yet again. We will continue selecting subarray SS until we have flipped all the 1's1
′
 s in it.

Hence, the cost needed to turn all elements of subarray SS to 00 is:

C_1 = M+(M-1)+ \dots +2+1
C
1
​
 =M+(M−1)+⋯+2+1
C_1 = \frac{M*(M+1)}{2}
C
1
​
 =
2
M∗(M+1)
​

After having one subarray that has all its elements as 0's0
′
 s, the cost of flipping each of the remaining 1's1
′
 s throughout the array will be 1 unit each. This is because once KK consecutive elements have been made 00, we can select successive subarrays such that they contain at most a single 11

 How?
Suppose there is an array AA such that:

A_1, A_2, \dots , A_L, \dots,A_R, \dots, A_N
A
1
​
 ,A
2
​
 ,…,A
L
​
 ,…,A
R
​
 ,…,A
N
​

After turning all the elements of a subarray S{[A_L, A_{L+1, }\dots, A_{R-1},A_R]}S[A
L
​
 ,A
L+1,
​
 …,A
R−1
​
 ,A
R
​
 ] to 00, we will keep moving the window of KK elements to the left by one unit until we find the index ii such that A_i=1A
i
​
 =1. Now the subarrary S'S
′
  will contain elements [A_i, A_{i+1, }\dots, A_{x-1},A_x][A
i
​
 ,A
i+1,
​
 …,A
x−1
​
 ,A
x
​
 ] among which all the elements except A_iA
i
​
  would be 00. Hence the minimum cost to turn A_iA
i
​
  into 00 is 11.

After turning A_iA
i
​
  into 00 we will resume moving the window to the left until we reach the leftmost index and thus continue this operation of shifting window until the entire array to the left of RR has become 00.

Similar operation is also performed to the right of the selected subarray (i.e. by moving the window a unit to the right) until we reach the rightmost index of the array, thus making the entire array consist of 0's0
′
 s.

Hence the total cost needed to convert all 1's1
′
 s into 0's0
′
 s which were not part of the subarray SS will be:

C_2 = T-M
C
2
​
 =T−M
where TT is the total number of 1's1
′
 s present in the given array.

And total cost of conversion will be:

C=C_1+C_2
C=C
1
​
 +C
2
​

C=\frac{M*(M+1)}{2}+T-M
C=
2
M∗(M+1)
​
 +T−M
TIME COMPLEXITY:
O(N)O(N) per test case.

SOLUTIONS:
 Setter
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+45;

int n,k,a[N];
ll pf[N];

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        pf[i] = pf[i-1]+a[i]; /// prefix sum array
    }

    ll s = pf[n],m = n;
    for(int i = k; i <= n; i++){ /// finding the minimum number of ones in a segment of length k
        m = min(m,pf[i]-pf[i-k]);
    }

    ll sol = (m*(m+1))/2 + (s-m); /// the minimum cost
    cout << sol << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}

































*/