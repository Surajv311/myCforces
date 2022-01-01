/*


L shaped plots

L Shaped Plots (8pts, 12pts)

Last updated: Mar 23 2021, 21:34

PROBLEM
ANALYSIS
Problem
Given a grid of R rows and C columns each cell in the grid is either 0 or 1.

A segment is a nonempty sequence of consecutive cells such that all cells are in the same row or the same column. We define the length of a segment as number of cells in the sequence.

A segment is called "good" if all the cells in the segment contain only 1s.

An "L-shape" is defined as an unordered pair of segments, which has all the following properties:

Each of the segments must be a "good" segment.
The two segments must be perpendicular to each other.
The segments must share one cell that is an endpoint of both segments.
Segments must have length at least 2.
The length of the longer segment is twice the length of the shorter segment.
We need to count the number of L-shapes in the grid.

Below you can find two examples of correct L-shapes,

Examples of valid L-shapes.
and three examples of invalid L-shapes.

Examples of invalid L-shapes.
Note that in the shape on the left, two segments do not share a common endpoint. The next two shapes do not meet the last requirement, as in the middle shape both segments have the same length, and in the last shape the longer segment is longer than twice the length of the shorter one.

Input
The first line of the input contains the number of test cases, T. T test cases follow.

The first line of each testcase contains two integers R and C.

Then, R lines follow, each line with C integers representing the cells of the grid.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of L-shapes.

Limits
Time limit: 60 seconds.
Memory limit: 1 GB.
1≤T≤100.
Grid consists of 0s and 1s only.
Test Set 1
1≤R≤40.
1≤C≤40.
Test Set 2
1≤R≤1000 and 1≤C≤1000 for at most 5 test cases.
For the remaining cases, 1≤R≤40 and 1≤C≤40.
Sample
Sample Input
save_alt
content_copy
2
4 3
1 0 0
1 0 1
1 0 0
1 1 0
6 4
1 0 0 0
1 0 0 1
1 1 1 1
1 0 1 0
1 0 1 0
1 1 1 0
Sample Output
save_alt
content_copy
Case #1: 1
Case #2: 9
In Sample Case #1, there is one L-shape.

The first one is formed by using cells: (1,1), (2,1), (3,1), (4,1), (4,2)
Visualization for the first sample case, showing one L-shape.
In Sample Case #2, there are nine L-shapes.

The first one is formed by using cells: (1,1), (2,1), (3,1), (4,1), (5,1), (6,1), (6,2), (6,3)
The second one is formed by using cells: (3,1), (4,1), (5,1), (6,1), (6,2)
The third one is formed by using cells: (6,1), (5,1), (4,1), (3,1), (3,2)
The fourth one is formed by using cells: (3,3), (4,3), (5,3), (6,3), (6,2)
The fifth one is formed by using cells: (6,3), (5,3), (4,3), (3,3), (3,2)
The sixth one is formed by using cells: (3,1), (3,2), (3,3), (3,4), (2,4)
The seventh one is formed by using cells: (3,4), (3,3), (3,2), (3,1), (2,1)
The eighth one is formed by using cells: (3,4), (3,3), (3,2), (3,1), (4,1)
The ninth one is formed by using cells: (6,3), (5,3), (4,3), (3,3), (3,4)
The first three L-shapes are shown on the picture below.





int get_ans(int hor, int vert){

if(hor==1 or vert===1){
	return 0;
}//since the L shape wouldn't be formed. since only one cell. also condition given in the question


int ans = min(hor,vert/2) - 1;
// we are doing -1 since our 1,1 cell (cell of length -1 and breadth -1) would also be included, which won't qualify for L shape, atleast it must be (2,1) or (1,2)...

return ans;

}


int solve (){


int n , m ;
cin >> n >> m ;

vector<vi> mat(n,vi(m,0));

vector<vi>  up(n,vi(m,0));
vector<vi> down(n,vi(m,0));
vector<vi> left(n,vi(m,0));
vector<vi> right(n,vi(m,0));

forn(i,n){
	forn(j,m){
	cin >> mat[i][j];
	// filling our matrix of 1s and 0s
	}
}

// now calculating for each cell in 4 directions : L shape,
// using dp based approach, precomputing~prefix sum the counts of 1s... cell by cell we are adding the stream of 1s we encoutner, with 0, the stream ends and continues next possible stream with 1s after that zero

forn(i,n){
	forn(j,m){
	if(!mat[i][j])continue;
// else
down[i][j]++;

if(i>0)down[i][j]+=down[i-1][j];

	}
}

nfor(i,n){
	forn(j,m){
	if(!mat[i][j])continue;

up[i][j]++;

if(i+1<n)up[i][j]+=up[i+1][j];

	}
}

forn(i,n){
	forn(j,m){
	if(!mat[i][j])continue;

right[i][j]++;

if(j>0)right[i][j]+=right[i][j-1];

	}
}

nfor(i,n){
	forn(j,m){
	if(!mat[i][j])continue;

left[i][j]++;

if(j+1<m)left[i][j]+=left[i][j+1];

	}
}

int ans = 0 ;

forn(i,n){
	forn(j,m){

if(!mat[i][j])continue;

ans+=get_ans(left[i][j],down[i][j]);
ans+=get_ans(left[i][j],up[i][j]);
ans+=get_ans(right[i][j],down[i][j]);
ans+=get_ans(right[i][j],up[i][j]);

	}
}

return ans;
}

main(){}...


[OR SIMILARLY _ rk]


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
void solve(int ca)
{
    ll r,c;
    cin>>r>>c;
    ll arr[r][c];
    vector<pair<ll,ll> >v;
    for(ll i=0;i<r;i++){
        for(ll j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }
    for(ll i=0;i<r;i++){
        for(ll j=0;j<c;j++){
            ll x=i,y=j,cx=0,cy=0;
            while(arr[x][j]==1 && x<r){
                x++;
                cx++;
                if(x>=r)
                break;
            }
            while(arr[i][y]==1 && y<c){
                y++;
                cy++;
                if(y>=c)
                break;
            }
            if(cx>1 && cy>1)
                v.push_back(make_pair(cx,cy));
        }
    }
    for(ll i=r-1;i>-1;i--){
        for(ll j=c-1;j>-1;j--){
            ll x=i,y=j,cx=0,cy=0;
            while(arr[x][j]==1 && x>-1){
                x--;
                cx++;
                if(x<=-1)
                break;
            }
            while(arr[i][y]==1 && y>-1){
                y--;
                cy++;
                if(y<=-1)
                break;
            }
            if(cx>1 && cy>1)
                v.push_back(make_pair(cx,cy));
        }
    }
    for(ll i=0;i<r;i++){
        for(ll j=c-1;j>-1;j--){
            ll x=i,y=j,cx=0,cy=0;
            while(arr[x][j]==1 && x<r){
                x++;
                cx++;
                if(x>=r)
                break;
            }
            while(arr[i][y]==1 && y>-1){
                y--;
                cy++;
                if(y<=-1)
                break;
            }
            if(cx>1 && cy>1)
                v.push_back(make_pair(cx,cy));
        }
    }
    for(ll i=r-1;i>-1;i--){
        for(ll j=0;j<c;j++){
            ll x=i,y=j,cx=0,cy=0;
            while(arr[x][j]==1 && x>-1){
                x--;
                cx++;
                if(x<=-1)
                break;
            }
            while(arr[i][y]==1 && y<c){
                y++;
                cy++;
                if(y>=c)
                break;
            }
            if(cx>1 && cy>1)
                v.push_back(make_pair(cx,cy));
        }
    }
    ll x=0;
    for(ll i=0;i<v.size();i++){
            ll y=2;
            while(v[i].second>=y && v[i].first>=2*y){
                y++;
                x++;
            }
            y=2;
            while(v[i].second>=2*y && v[i].first>=y){
                y++;
                x++;
            }
    }
    cout<<"Case #"<<ca<<": "<<x<<nl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t,ca=1;
    cin>>t;
    while(t--){
        solve(ca);
        ca++;
    }
    return 0;
}




--------------------------------------------------------------




Rabbit House (9pts, 15pts)

Last updated: Mar 23 2021, 23:56

PROBLEM
ANALYSIS
Problem
Barbara got really good grades in school last year, so her parents decided to gift her with a pet rabbit. She was so excited that she built a house for the rabbit, which can be seen as a 2D grid with R rows and C columns.

Rabbits love to jump, so Barbara stacked several boxes on several cells of the grid. Each box is a cube with equal dimensions, which match exactly the dimensions of a cell of the grid.

However, Barbara soon realizes that it may be dangerous for the rabbit to make jumps of height greater than 1 box, so she decides to avoid that by making some adjustments to the house. For every pair of adjacent cells, Barbara would like that their absolute difference in height be at most 1 box. Two cells are considered adjacent if they share a common side.

As all the boxes are superglued, Barbara cannot remove any boxes that are there initially, however she can add boxes on top of them. She can add as many boxes as she wants, to as many cells as she wants (which may be zero). Help hew determine what is the minimum total number of boxes to be added so that the rabbit's house is safe.

Input
The first line of the input gives the number of test cases, T. T test cases follow.

Each test case begins with a line containing two integers R and C.

Then, R lines follow, each with C integers. The j-th integer on i-th line, Gi,j, represents how many boxes are there initially on the cell located at the i-th row and j-th column of the grid.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the minimum number of boxes to be added so that the rabbit's house is safe.

Limits
Memory limit: 1 GB.
1≤T≤100.
0≤Gi,j≤2⋅106, for all i, j.
Test Set 1
Time limit: 20 seconds.
1≤R,C≤50.
Test Set 2
Time limit: 40 seconds.
1≤R,C≤300.
Sample
Sample Input
save_alt
content_copy
3
1 3
3 4 3
1 3
3 0 0
3 3
0 0 0
0 2 0
0 0 0
Sample Output
save_alt
content_copy
Case #1: 0
Case #2: 3
Case #3: 4
In Sample Case #1, the absolute difference in height for every pair of adjacent cells is already at most 1 box, so there is no need to add any extra boxes.

In Sample Case #2, the absolute difference in height of the left-most cell and the middle cell is 3 boxes. To fix that, we can add 2 boxes to the middle cell. But then, the absolute difference of the middle cell and the right-most cell will be 2 boxes, so Barbara can fix that by adding 1 box to the right-most cell. After adding these 3 boxes, the safety condition is satisfied.

In Sample Case #3, the cell in the middle of the grid has an absolute difference in height of 2 boxes with all of its four adjacent cells. One solution is to add exactly 1 box to all of the middle's adjacent cells, so that the absolute difference between any pair of adjacent cells will be at most 1 box. That requires 4 boxes in total.



[ANS, CF. using heap+~dijkistra algo implementation]

Obviously, the highest cell should not be increased. With this insight, we can solve this problem in a Dijkstra-like manner.

We use a max-heap to store the cells to be processed. When we process a cell with height h, we need to ensure that all its neighbors are at least as high as h−1. If the height of any of its neighbors is increased, then we should enqueue that cell with the new height.

In the end, we accumulate the difference between each cell's final height and original height to get the answer.

Time complexity is O(RClog(RC)).
Space complexity is O(RClog(RC)).
Code (C++)
#include <cstdio>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
using ll = long long;

template <typename T> void read(T &x) {
  x = 0;
  char c = getchar();
  T sig = 1;
  for (; !isdigit(c); c = getchar())
    if (c == '-')
      sig = -1;
  for (; isdigit(c); c = getchar())
    x = (x << 3) + (x << 1) + c — '0';
  x *= sig;
}

const int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

class Solution {
public:
  void solve(int case_num) {
    printf("Case #%d: ", case_num);
    int r, c;
    read(r), read(c);
    vector<vector<int>> g(r, vector<int>(c));
    priority_queue<tuple<int, int, int>> pq;
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j) {
        read(g[i][j]);
        pq.emplace(g[i][j], i, j);
      }
    vector<vector<int>> g0(g);
    while (!pq.empty()) {
      auto [h, i, j] = pq.top();
      pq.pop();
      if (h < g[i][j])
        continue;
      for (int k = 0; k < 4; ++k) {
        int ni = i + d[k][0], nj = j + d[k][1];
        if (ni < 0 || ni >= r || nj < 0 || nj >= c)
          continue;
        if (h — 1 > g[ni][nj]) {
          pq.emplace(h — 1, ni, nj);
          g[ni][nj] = h — 1;
        }
      }
    }

    ll ans = 0;
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
        ans += g[i][j] — g0[i][j];

    printf("%lld\n", ans);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  read(t);
  for (int i = 1; i <= t; ++i) {
    Solution solution = Solution();
    solution.solve(i);
  }
}



[OR ARRAY BASED][rk]


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
void solve(int ca)
{
    ll r,c;
    cin>>r>>c;
    ll arr[r][c];
    for(ll i=0;i<r;i++){
        for(ll j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }
    ll x=0;
    for(ll i=0;i<r;i++){
        for(ll j=0;j<c;j++){
            if(i+1<r){
                if(abs(arr[i+1][j]-arr[i][j])>1){
                    x+=abs(arr[i][j]-arr[i+1][j])-1;
                    if(arr[i][j]>arr[i+1][j]){
                        arr[i+1][j]+=abs(arr[i][j]-arr[i+1][j])-1;
                    }
                    else{
                        arr[i][j]+=abs(arr[i+1][j]-arr[i][j])-1;
                    }

                }
            }
            if(j+1<c){
                if(abs(arr[i][j]-arr[i][j+1])>1){
                    x+=abs(arr[i][j]-arr[i][j+1])-1;
                    if(arr[i][j]>arr[i][j+1]){
                        arr[i][j+1]+=abs(arr[i][j]-arr[i][j+1])-1;
                    }
                    else{
                        arr[i][j]+=abs(arr[i][j+1]-arr[i][j])-1;
                    }
                }
            }
        }
    }
    for(ll i=r-1;i>-1;i--){
        for(ll j=c-1;j>-1;j--){
            if(i-1>-1){
                if(abs(arr[i-1][j]-arr[i][j])>1){
                    x+=abs(arr[i][j]-arr[i-1][j])-1;
                    if(arr[i][j]>arr[i-1][j]){
                        arr[i-1][j]+=abs(arr[i][j]-arr[i-1][j])-1;
                    }
                    else{
                        arr[i][j]+=abs(arr[i-1][j]-arr[i][j])-1;
                    }

                }
            }
            if(j-1>-1){
                if(abs(arr[i][j]-arr[i][j-1])>1){
                    x+=abs(arr[i][j]-arr[i][j-1])-1;
                    if(arr[i][j]>arr[i][j-1]){
                        arr[i][j-1]+=abs(arr[i][j]-arr[i][j-1])-1;
                    }
                    else{
                        arr[i][j]+=abs(arr[i][j-1]-arr[i][j])-1;
                    }
                }
            }
        }
    }
    cout<<"Case #"<<ca<<": "<<x<<nl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t,ca=1;
    cin>>t;
    while(t--){
        solve(ca);
        ca++;
    }
    return 0;
}


--------------------------------------------------------------



































*/