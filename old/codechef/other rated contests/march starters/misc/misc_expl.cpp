/*


Point Grid Problem Code: PGRID1

Suppose we have a 2D grid A of infinite width and height of N units. Each row of the grid can be represented in the form of 111…100…∞ where the 1s are repeated x times, x>0. Implying that the row starts with x consecutive 1-s followed by all 0-s.

Initially all cells are unmarked. Cell (i,j) refers to the i-th row, and j-th column. (1,1) refers to the bottom-left cell.

Now you do the following in each step.

Choose an unmarked cell having 1. Let it be (i, j).
while((i,j) lies in the grid boundaries && A[i][j] == 1){
    mark[i][j] = true; i--; j--;
}
How many minimum number of steps are required to mark all the cells containing 1?

Note: The number of consecutive 1-s at each height is given by the array W where Wi represents the same at ith row.

Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contain 2 lines of input.
First line will contain N, height of the grid (number of rows).
Second line contains N space separated integers where ith index represents number of consecutive 1-s at the beginning of row i.
Output:
For each testcase, output in a single line answer to the problem.

Constraints
1≤T≤10
1≤N≤105
1≤Wi≤109
Sample Input:
3
3
1 1 1
3
5 3 2
3
4 2 5
Sample Output:
3
7
8
Explanation:
TestCase 1: All the points need to be considered to cover all 1-s.

TestCase 2: The optimal set of starting points is {(1,3),(2,3),(2,2),(3,2),(3,1),(4,1),(5,1)}.




DIFFICULTY:
Easy

PREREQUISITES:
Implementation, Running Sum

PROBLEM:
Suppose we have a 2D2D grid AA of infinite width and height of NN units. Each row of the grid can be represented in the form of 111…111…(x times)00…∞00…∞ where x\gt 0x>0, implying the row starts with consecutive 1'_{s}1
s
′
​
  followed by all 0'_{s}0
s
′
​
 .

Now you do the following in each step.

Choose an unmarked cell having 1. Let it be (i, j).
while((i,j) lies in the grid boundaries &amp;&amp; A[i][j] == 1){
    mark[i][j] = true; i--; j--;
}
How many minimum number of steps are required to cover all the cells containing 11.

Note: The number of consecutive 1'_{s}1
s
′
​
  at each height is given by the array WW where W_iW
i
​
  represents the same at i_{th}i
th
​
  height.

QUICK EXPLANATION:
We will apply the step on all the 11's in the first row. Then we move down the rows and check how many set bits are to the bottom left of set bits of the row above it, and apply no extra steps to make these 00. For the 11's in a row that have no 11 to the top right of themselves, extra step must be applied. Maintain this running sum of needed number of steps to make all set bits unset from the top to the current row of the matrix in order to obtain the final answer.

EXPLANATION:
Claim: If the number of 11's (say LL) in a row are less than the number of 11's (say UU) in the row above it, then the row above can engulf all the 11's of the row below it without using any extra step.

 Proof
As the topmost row has no other row above it, we apply the step on all of its 11's as they can’t depend on a higher row element to engulf them. Then we move to the next row and check whether the 11's can be engulfed or not. The ones that can’t be engulfed need to become the starting points of newer steps and thus will be able to engulf diagonally bottom left positioned 11's without extra steps and so on.

Before proceeding to a lower row, the number of steps needed to flip all the 11's above that row have been added to the answer. Thus on reaching such a row all whose 11's can be engulfed by the row above it, no extra step would be needed to flip all the 11's as they are reachable from the indices to the top right of themselves containing 11.

If this engulfing of the 11's of a lower row is not possible by the higher row, i.e. the number of 11's in the row below is greater than or equal to the number of 11's in the row above, then the 11's starting from U_{th}U
th
​
  to the end of the lower row can not be engulfed. An extra L-(U-1)L−(U−1) steps would be needed so that these ungulfable 11's can be flipped and the matrix from top row to the current row can be all unset bits.

We keep maintaining this running sum in a variable starting from the first row until the last row and obtain the final answer.

TIME COMPLEXITY:
O(N)O(N)

SOLUTIONS:
 Setter
    #include <bits/stdc++.h>

    #define pb push_back

    using namespace std;

    const int maxn = 1e5;
    const int maxtn = 1e6;
    const int minv = 1;
    const int maxv = 1e9;
    const int maxt = 10;

    int main()
    {
        int t; cin >> t;
        int tot = 0;
        while(t--){
            int n; cin >> n; tot += n;
            vector<int> v;
            for(int i = 0; i < n; i++){
                int x; cin >> x;
                v.pb(x);
            }
            int prv = 1; long long ans = 0;
            for(int i = n - 1; i >= 0; i--){
                ans += max(0, v[i] - prv + 1);
                prv = v[i];
            }
            cout << ans << endl;
        }
        assert(tot <= maxtn);
    }


















*/