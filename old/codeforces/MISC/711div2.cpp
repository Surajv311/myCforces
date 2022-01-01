/*


A. GCD Sum
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
The gcdSum of a positive integer is the gcd of that integer with its sum of digits. Formally, gcdSum(x)=gcd(x, sum of digits of x) for a positive integer x. gcd(a,b) denotes the greatest common divisor of a and b — the largest integer d such that both integers a and b are divisible by d.

For example: gcdSum(762)=gcd(762,7+6+2)=gcd(762,15)=3.

Given an integer n, find the smallest integer x≥n such that gcdSum(x)>1.

Input
The first line of input contains one integer t (1≤t≤104) — the number of test cases.

Then t lines follow, each containing a single integer n (1≤n≤1018).

All test cases in one test are different.

Output
Output t lines, where the i-th line is a single integer containing the answer to the i-th test case.

Example
inputCopy
3
11
31
75
outputCopy
12
33
75
Note
Let us explain the three test cases in the sample.

Test case 1: n=11:

gcdSum(11)=gcd(11,1+1)=gcd(11, 2)=1.

gcdSum(12)=gcd(12,1+2)=gcd(12, 3)=3.

So the smallest number ≥11 whose gcdSum >1 is 12.

Test case 2: n=31:

gcdSum(31)=gcd(31,3+1)=gcd(31, 4)=1.

gcdSum(32)=gcd(32,3+2)=gcd(32, 5)=1.

gcdSum(33)=gcd(33,3+3)=gcd(33, 6)=3.

So the smallest number ≥31 whose gcdSum >1 is 33.

Test case 3:  n=75:

gcdSum(75)=gcd(75,7+5)=gcd(75, 12)=3.

The gcdSum of 75 is already >1. Hence, it is the answer.





Hint
Can you think of the simplest properties that relate a number and its sum of digits?

Hint 2
Note that if X is a multiple of 3, then both X as well as the sum of digits of X are a multiple of 3! Can you put this property to use here?

Hint 3
If X is a multiple of 3, then gcd-sum(X)≥3. Therefore, we are guaranteed that at least every third number will satisfy the constraints required by our problem (gcd-sum(X)>1).

Solution
Therefore, for the input n, we can simply check which one of n, n+1, and n+2 has its gcd-sum >1, and print the lowest of them.

Corner cases
Note that you must take long long, as input integers exceed the range of int.

Moreover, simply outputting ceil((n/3)×3) is incorrect as some non-multiples of three may also may have gcd-sum >1, for example, 26.

C++ solution
#include <bits/stdc++.h>
using namespace std;

long long int gcd_sum(long long int num) {
// returns gcd-sum
long long int tmp = num, digitsum = 0;

    while (tmp > 0) {
        digitsum += tmp % 10;
        tmp /= 10;
    }

    long long int gcd = __gcd(num, digitsum);
    return gcd;
}

int main(void) {
int t;
cin >> t;

    while (t--) {
        long long int n;
        cin >> n;
        if (gcd_sum(n) != 1) {
            cout << n << endl;
        } else if (gcd_sum(n + 1) != 1) {
            cout << n + 1 << endl;
        } else if (gcd_sum(n + 2) != 1) {
            cout << n + 2 << endl;
        }
    }
    return 0;
}






-------------------------------------------------------------





B. Box Fitting
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given n rectangles, each of height 1. Each rectangle's width is a power of 2 (i. e. it can be represented as 2x for some non-negative integer x).

You are also given a two-dimensional box of width W. Note that W may or may not be a power of 2. Moreover, W is at least as large as the width of the largest rectangle.

You have to find the smallest height of this box, such that it is able to fit all the given rectangles. It is allowed to have some empty space left in this box after fitting all the rectangles.

You cannot rotate the given rectangles to make them fit into the box. Moreover, any two distinct rectangles must not overlap, i. e., any two distinct rectangles must have zero intersection area.

See notes for visual explanation of sample input.

Input
The first line of input contains one integer t (1≤t≤5⋅103) — the number of test cases. Each test case consists of two lines.

For each test case:

the first line contains two integers n (1≤n≤105) and W (1≤W≤109);
the second line contains n integers w1,w2,…,wn (1≤wi≤106), where wi is the width of the i-th rectangle. Each wi is a power of 2;
additionally, maxi=1nwi≤W.
The sum of n over all test cases does not exceed 105.

Output
Output t integers. The i-th integer should be equal to the answer to the i-th test case — the smallest height of the box.

Example
inputCopy
2
5 16
1 2 8 4 8
6 10
2 8 8 2 2 8
outputCopy
2
3
Note
For the first test case in the sample input, the following figure shows one way to fit the given five rectangles into the 2D box with minimum height:


In the figure above, the number inside each rectangle is its width. The width of the 2D box is 16 (indicated with arrow below). The minimum height required for the 2D box in this case is 2 (indicated on the left).

In the second test case, you can have a minimum height of three by keeping two blocks (one each of widths eight and two) on each of the three levels.








Hint
There can exist multiple optimal packings for a given set of rectangles. However, all of them can always be rearranged to follow a specific pattern, based on the rectangles' sizes.

Hint 2
Can you show that it is always possible to replace a set of consecutive small blocks with a single large block? (of same or larger size)

Solution summary
We follow a greedy strategy:

Initialize height of box as 1.
Initialize current layer size as W.
Pick the largest available rectangle that can fit into the current layer, and place it there. Repeat until this layer cannot fit any more rectangles.
If more rectangles remain, increment height by 1 and now repeat the last three steps. Else, output the current value of height.
Solution implementation
First count sort the given rectangles based on their widths. There can only be 20 distinct rectangle widths in the range [1,109], so the following works:

counts = [0 for w in range(0, 20)]
for w in widths:
    counts[log2(w)] += 1
The solution can be implemented by iterating N times.

At each iteration, step through the counts array and take the largest available rectangle that can fit into the current space. If no rectangle was able to fit, increment height by 1 and reset box width to W.

This has complexity O(nlog(wmax)).

Another implementation
It is also possible to implement the solution with a multiset and upper_bound, for a complexity of O(nlog(n)).

Store all rectangle sizes in a multiset. At each iteration, find using upper_bound the largest rectangle that can fit into the current space we have, and fit it in. If no rectangle can fit in this space, reset the space to maximum, increment height, and repeat.

Proof of correctness — brief
It is always possible to replace several smaller blocks with a single larger block if it is available. Because all blocks are powers of two, it must so happen that smaller powers of two will sum to a larger power. Therefore, we can always place a larger block first if it can be placed there.

Proof of correctness — elaborate
This elaborate proof isn't actually required for solving the problem. The intuition in the brief proof is sufficient for solving the problem. This proof is for correctness purpose only.

Let's first note a property: if a1+…+an>a0, then there exists some i such that a1+…+ai=a0, when all ai are powers of 2 AND a1 to an is a non-increasing sequence (AND a1<=a0, of course). Why is this so? You can take an example and observe this intuitively, this is a common property of powers of two. For example, 4+2+2+1+1>8, but 4+2+2 (prefix) =8. Formally: if a1=a0, this property is trivially true. If a1<a0, we can splilt a0=2ka1 for some k into 2k parts and — by strong induction — claim this property holds.

Let us now compare some optimal solution and our greedy solution. Before comparing, we first sort all blocks in each layer of the optimal solution in decreasing order. This does not affect the final answer but helps in our comparison. This comparison goes from bottom to top, left to right. Let us look at the first point of difference: when the block placed by us (BG) is different from the block placed by the optimal solution (BO). There are three cases.

If BO>BG: this is impossible, as in our greedy solution, we are always placing the largest possible block. We wouldn't place BG in there if BO was also possible. If BO==BG: we have nothing to worry about (this isn't a point of difference)

If BO<BG: let us assume that the optimal solution places several consecutive small blocks, and not just one BO. Since the blocks are in decreasing order, none of them would be bigger than BG. Note that either all of these blocks will sum to less than BG or a prefix of them will be exactly equal to BG. In either case, we can swap them with one single large block BG (swapping with a BG which was placed in some higher layer in the optimal solution)

Hence, in the last case, we have shown that any optimal solution (an arrangement of blocks) can be rearranged such that each layer fits the largest possible block first. This is also what is done in our greedy strategy. Therefore, with this proof by rearrangement, we conclude that our greedy strategy gives the same minimum height as that of the optimal answer.

Alternate implementation with easier proof
There is a binary search method to solve this problem. We binary search for the minimum height required. Given a height h — how to check if it can fit all rectangles?

We first preprocess the given array to construct a new array ci = number of rectangles of width 1«i. The size of this array is < 20.

We iterate from largest width to smallest width. Let its width is wi. Then, we know that it fits only W/wi times in one layer. Therefore, with height h, the box can only fit in fi=h×(W/wi). So, we can say that if fi<ci, then this height is insufficient.

Therefore, we now know that for any i, if fi<ci, then the height is insufficient. Do we need more conditions to provably state that the given height is sufficient?

Yes! We also need to check if we can fit in the i-th block in combination with tthe i+1-th block. That is, when checking if the i-th block has enough space, we need to account for the space that has already been used by the i+1-th block. So, we need to update ci=ci+2×ci+1+4×ci+2….

Therefore, we only need to compute the suffix sum ci like so and then check the above conditions. Complexity is O(n+log(wmax)log(n)).

Does this solution work when block widths are not a power of two?
As we understood in the proof, this solution only works when it's guaranteed that smaller blocks will always exactly sum to any larger block. Therefore, if the blocks are not powers of two, this guarantee does not hold.

The following counterexample suffices:

6 13
6 6 4 4 3 3
As you can see here the smaller blocks are not guaranteed to sum to the larger block (no prefix of 4,3,3 sums to 6). Our greedy solution gives minimum height 3, but best possible minimum height is 2 (first layer: 6,4,3, second layer: 6,4,3)

C++ solution
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, box_width, w;
        cin >> n >> box_width;

        vector<int> counts(20);
        for (int i = 0; i < n; i++) {
            cin >> w;
            counts[log2(w)]++;
        }

        int height = 1, space_left = box_width;

        for (int iter = 0; iter < n; iter++) {
            int largest = -1;

            for (int size = 19; size >= 0; size--) {
                if (counts[size] and (1 << size) <= space_left) {
                    largest = size;
                    break;
                }
            }

            if (largest == -1) {
                space_left = box_width;
                height++;
                for (int size = 19; size >= 0; size--) {
                    if (counts[size] and (1 << size) <= space_left) {
                        largest = size;
                        break;
                    }
                }
            }

            counts[largest] -= 1;
            space_left -= 1 << largest;
        }

        cout << height << endl;
    }

}


C++ solution — multiset
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, w;
        int box_width;
        cin >> n >> box_width;

        multiset<int> st;
        for (int i = 0; i < n; i++) {
            cin >> w;
            st.insert(w);
        }

        int height = 1, space_left = box_width;

        while (!st.empty()) {
            auto it = st.upper_bound(space_left);
            if (it != st.begin()) {
                it--;
                int val = *it;
                space_left -= val;
                st.erase(it);
            } else {
                space_left = box_width;
                height++;
            }
        }

        cout << height << endl;
    }
    return 0;

}
C++ solution for easier proof
#include <array>
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

#define PW 20
array<int, PW> arr;
int n, w;

bool valid(int height) {
    for (int pw = 0; pw < PW; pw++) {
        long long units_i_have = 1ll * height * (w / (1 << pw));
        if (units_i_have < arr[pw]) return false;
    }

    return true;
}

int main() {
    int t; cin >> t;

    while (t--) {
        cin >> n >> w;

        for (int i = 0; i < PW; i++) arr[i] = 0;

        for (int _ = 0; _ < n; _++) {
            int w; cin >> w;
            arr[log2(w)] += 1;
        }

        // suffix cumulative count
        for (int i = PW — 2; i >= 0; i--) arr[i] += 2 * arr[i + 1];

        int beg = 1, end = n, ans = -1;
        while (beg <= end) {
            int mid = (beg + end) / 2;

            if (valid(mid)) {
                end = mid — 1;
                ans = mid;
            } else {
                beg = mid + 1;
            }
        }

        assert(ans != -1);
        cout << ans << endl;
    }
}



----------------------------------------------------------






C. Planar Reflections
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Gaurang has grown up in a mystical universe. He is faced by n consecutive 2D planes. He shoots a particle of decay age k at the planes.

A particle can pass through a plane directly, however, every plane produces an identical copy of the particle going in the opposite direction with a decay age k−1. If a particle has decay age equal to 1, it will NOT produce a copy.

For example, if there are two planes and a particle is shot with decay age 3 (towards the right), the process is as follows: (here, D(x) refers to a single particle with decay age x)

the first plane produces a D(2) to the left and lets D(3) continue on to the right;
the second plane produces a D(2) to the left and lets D(3) continue on to the right;
the first plane lets D(2) continue on to the left and produces a D(1) to the right;
the second plane lets D(1) continue on to the right (D(1) cannot produce any copies).
In total, the final multiset S of particles is {D(3),D(2),D(2),D(1)}. (See notes for visual explanation of this test case.)

Gaurang is unable to cope up with the complexity of this situation when the number of planes is too large. Help Gaurang find the size of the multiset S, given n and k.

Since the size of the multiset can be very large, you have to output it modulo 109+7.

Note: Particles can go back and forth between the planes without colliding with each other.

Input
The first line of the input contains the number of test cases t (1≤t≤100). Then, t lines follow, each containing two integers n and k (1≤n,k≤1000).

Additionally, the sum of n over all test cases will not exceed 1000, and the sum of k over all test cases will not exceed 1000. All test cases in one test are different.

Output
Output t integers. The i-th of them should be equal to the answer to the i-th test case.

Examples
inputCopy
4
2 3
2 2
3 1
1 3
outputCopy
4
3
1
2
inputCopy
3
1 1
1 500
500 250
outputCopy
1
2
257950823
Note
Let us explain the first example with four test cases.

Test case 1: (n=2, k=3) is already explained in the problem statement.

See the below figure of this simulation. Each straight line with a different color represents the path of a different particle. As you can see, there are four distinct particles in the multiset. Note that the vertical spacing between reflected particles is for visual clarity only (as mentioned before, no two distinct particles collide with each other)


Test case 2: (n=2, k=2) is explained as follows:

the first plane produces a D(1) to the left and lets D(2) continue on to the right;
the second plane produces a D(1) to the left and lets D(2) continue on to the right;
the first plane lets D(1) continue on to the left (D(1) cannot produce any copies).
Total size of multiset obtained {D(1),D(1),D(2)} is equal to three.

Test case 3: (n=3, k=1), there are three planes, but decay age is only one. So no new copies are produced while the one particle passes through the planes. Hence, the answer is one.

Test case 4: (n=1, k=3) there is only one plane. The particle produces a new copy to the left. The multiset {D(2),D(3)} is of size two.






Hint 1
We can use dynamic programming to store the state of the simulation at a given time. Therefore, we can simulate the entire situation by reusing the dp states.

Solution idea
I will describe the most intuitive solution. Naturally, looking at the constraints as well as at the output that is required, we can store a 3-state dp: dp[n][k][2]. Here, dp[n][k][d] indicates the total number of particles (at the end of the simulation) when one particle of decay age k hits the n-th plane in the direction d. (d is either 0 or 1, and indicates the direction (left/right) in which the particle is going)

There can be two directions, N planes and maximum decay age is K. So, this dp requires 2×1000×1000×4 bytes ≈24MB which is well within our memory constraints.

Solution details
How to update the DP states? If k=1, the value of dp[n][1][d] for any n or d is obviously 1 (as no copies are produced).

So, let us consider a particle P with k>1. This particle P produces a copy P′ going in the opposite direction. We can count the number of particles produced by P′ as dp[n — 1][k — 1][1 — d], as it hits the previous plane with a smaller decay age and in the opposite direction. Moreover, the particle P itself hits the next plane and continues to produce more stuff. We can calculate its number of particles produced as dp[n + 1][k][d], as it hits the next plane with the same decay age and the same direction!

Finally, we can combine these two values to get the value of dp[n][k][d].

Implementation details
We can implement this is easily as a recursive dp with memoization. At each state, we only need to iterate in the correct order (in one case, from right to left, and in the other, from left to right), and update states as required. Look at the implementation for more details. The total complexity of this algorithm is O(nk)
Note
Obviously, there exist much better solutions which do not use a third state and are much sleaker. However, I wanted to describe the simplest idea required to solve the problem.

C++ solution
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1001;
const int K = 1001;

int n, k;
const int mod = 1e9 + 7;

int dp[N][K][2];

int solve(int curr, int k, int dir) {
    if (k == 1) {
        return 1;
    }

    if (dp[curr][k][dir] != -1) {
        return dp[curr][k][dir];
    }

    int ans = 2;  // me and my copy

    if (dir == 1) {
        if (curr < n)
            ans += solve(curr + 1, k, dir) — 1;

        ans %= mod;

        if (curr > 1)
            ans += solve(curr — 1, k — 1, 1 — dir) — 1;

        ans %= mod;
        dp[curr][k][dir] = ans;
    } else {
        if (curr > 1)
            ans += solve(curr — 1, k, dir) — 1;

        ans %= mod;

        if (curr < n)
            ans += solve(curr + 1, k — 1, 1 — dir) — 1;

        ans %= mod;
        dp[curr][k][dir] = ans;
    }

    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        memset(dp, -1, sizeof(dp));
        cout << solve(1, k, 1) << endl;
    }
}


-------------------------------------------------------





D,E,F...... beyond ~...


















































































*/