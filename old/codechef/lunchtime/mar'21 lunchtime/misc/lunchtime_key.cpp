/*



Dinner by Candlelight Problem Code: DATE1

Chef is having a candlelit dinner with his girlfriend at his place. Currently, it is time 0, Chef just managed to light a candle, but he is out of matchsticks.

Since Chef has an infinite supply of (unlit) candles, he can use the following strategy: each second (starting at time 0), he takes one lit candle and lights up X other candles using it. This process takes 1 unit of time to complete, i.e. if Chef starts lighting up X candles at a time t1, he is able to finish at the time t1+1.

However, since candle wax is limited, a candle can only burn for Y units of time and then it is extinguished.

Chef's girlfriend arrives at a time A — specifically, after all the candles that were supposed to get extinguished at time A have been extinguished and after Chef lights up all the candles that he was lighting up since time A−1. Now Chef wants to know the maximum number of candles which can be lit at the time A to impress his girlfriend.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains three space-separated integers A, Y and X.
Output
For each test case, print a single line containing one integer — the maximum number of lit candles Chef can impress his girlfriend with.

Constraints
1≤T≤105
1≤A,Y,X≤109
Subtasks
Subtask #1 (40 points): A≥Y
Subtask #2 (60 points): original constraints

Example Input
3
1 1 1
1 2 1
2 2 1
Example Output
1
2
2
Explanation
Example case 1: At the time 0, there is one lit candle, using which we light 1 more candle. At the time 1, the starting candle gets extinguished and the candle which we started lighting up at the time 0 is lit, so we have only 1 candle lit up when Chef's girlfriend arrives.

Example case 2: At the time 0, there is one lit candle, using which we light 1 more candle. At the time 1, the candle which we started lighting up at the time 0 and the starting candle are both lit.

Example case 3: At the time 0, there is one lit candle, using which we light 1 more candle. At the time 1, the candle which we started lighting up at time 0 is lit, and we start lighting up one more candle. At the time 2, the starting candle gets extinguished and the candle which we started lighting up at the time 1 is lit. In total, we have 2 lit candles when Chef's girlfriend arrives.



DIFFICULTY:
Cakewalk

PREREQUISITES:
None

PROBLEM:
Chef has 11 lit candle, and infinitely many unlit candles. Each second, he can take one lit candle and use it to light xx unlit ones. yy seconds after a candle is lit, it runs out of wax and is extinguished. What is the maximum number of candles which can be lit at time tt?

QUICK EXPLANATION
The answer is x\cdot yx⋅y if t\geq yt≥y and x\cdot t+1x⋅t+1 otherwise

EXPLANATION:
Subtask 1
When t\geq yt≥y, the only active candles at time tt are the ones which lit up time t, t-1, t-2, \dotsc, t-y+1t,t−1,t−2,…,t−y+1; y seconds of time in total. Any candle which was lit before that will also be extinguished before time tt. In particular, because t\geq yt≥y, t-y+1 \geq 1t−y+1≥1; which means that the candle Chef started out with at time 00 will also be extinguished. Thus, we have yy seconds, in each of which xx candles are lit. This gives us x\cdot yx⋅y candles in total.

Subtask 2
t\geq yt≥y can be solved as above. Now we also have to worry about the case when t < yt<y. However, t < yt<y just means that no candle which is lit up will extinguish before time tt - so all we need to do is count the number of candles which are lit.
xx candles light up at each of the seconds 1, 2, \dotsc, t1,2,…,t; and the candle Chef starts out with isn’t extinguished either.
This gives us x\cdot t + 1x⋅t+1 candles at time tt.

TIME COMPLEXITY:
\mathcal{O}(1)O(1) per testcase.

SOLUTIONS:
 Setter's Solution (C++)
    #include<bits/stdc++.h>

    # define pb push_back
    #define pii pair<int, int>
    #define mp make_pair
    # define ll long long int

    using namespace std;

    const int maxt = 1e5, minv = 1, maxv = 1e9;
    int main()
    {
        int t; cin >> t;
        while(t--){
            ll time, y, x; cin >> time >> y >> x;
            ll ans = 0, cnt = 0;
            if(time - y + 1 <= 0){
                cnt = cnt + 1;
                ans = 1 + time * x;
            }else{
                ans = x + (y - 1) * x;
            }
            cout << ans << endl;
        }
    }




    ------------------------------------------------------




    Racing Problem Code: RACINGEN


    Ann is going to take part in a race. At the start, she has X units of energy. For each subsequent second, she can decide to run or to rest (she must perform the chosen action during the whole second). If she runs, she loses one unit of energy during that second and if she rests, she gains one unit of energy during that second. However, if Ann decides to rest when she has X units of energy, she does not gain any extra energy. Naturally, she cannot decide to run if she has 0 units of energy.

Ann needs to run for R minutes to reach the goal and she needs to reach it within M minutes. Is Ann able to finish the race on time?

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains three space-separated integers X, R and M.
Output
For each test case, print a single line containing the string "YES" if Ann is able to finish the race or "NO" otherwise (without quotes).

Constraints
1≤T≤105
1≤X,R,M≤109
Subtasks
Subtask #1 (100 points): original constraints

Example Input
2
60 3 5
60 3 4
Example Output
YES
NO
Explanation
Example case 1: Ann can run during the first, third and fifth minute. There are other possible solutions.

Example case 2: It is not possible for Ann to finish the race within four minutes.




DIFFICULTY:
Easy

PREREQUISITES:
None

PROBLEM:
Ann has XX energy, and in each second can either run (if she has more than 00 energy) and lose 1 energy, or rest (and gain 1 energy, if she has less than XX). She cannot have more than XX energy. It takes her RR minutes of running to finish a race - is there some sequence of running and resting which lets her finish the race within MM minutes?

EXPLANATION:
Before anything else, to simplify calculation, convert RR and MM to seconds by multiplying them by 60.
What is the least amount of time within which Ann can run for RR seconds?
She can first run for XX seconds, and expend all the energy she initially has. After that, running for one second requires two seconds of time - one to rest and gain 1 energy, and then one to actually run. This is optimal.

 Proof
The strategy described above is, in simpler words, to run when Ann has positive energy and rest when she has none. Optimality can be proved using an exchange argument.
Consider any optimal strategy where Ann has positive energy at some time, but decides to rest.
We can then find a time ii such that Ann has positive energy at time ii, rests at time ii, and runs at time i+1i+1.
Exchange her actions at these two times - i.e, suppose she runs at time ii and rests at time i+1i+1. Keep all other actions the same.
The amount of time she ran is exactly the same in both cases, and her remaining energy is either the same (if her energy at time ii was < X<X), or greater (if her energy at time ii was XX). Thus, exchanging the actions gives a solution which is not worse than the original.

tl;dr, the strategy described of always running when possible is no worse than any other optimal solution.

So,

If R\leq XR≤X, she needs exactly RR seconds
If R > XR>X, she needs X + 2*(R-X)X+2∗(R−X) seconds
Simply compute this number, and check whether it is \leq M≤M.
 Be wary of overflow!
Note that the constraints have R,M \leq 10^9R,M≤10
9
 , and converting them to seconds will result in integers upto 6*10^{10}6∗10
10
 . This will not fit in a 32-bit integer, so make sure you use the correct data type.

TIME COMPLEXITY
\mathcal{O}(1)O(1) per test case.

SOLUTIONS:
 Setter's Solution (C++)
 Tester's Solution (C++)
//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)

int main(){
    fastio;

    int tests;
    cin>>tests;

    while(tests--){
        long long int x, t, m;
        cin>>x>>t>>m;
        t *= 60;
        m *= 60;
        long long int curr = min(m, x);
        m -= curr;
        curr += m / 2;
        if(curr >= t) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}






----------------------------------------



Lunchtime Problem Code: LUNCHTIM

There are N students standing in a canteen queue, numbered 1 to N from left to right. For each valid i, the i-th student has a height hi.

Two students i and j can see each other if there are no taller students standing between them. Formally, students i and j (i<j) can see each other if for each integer k (i<k<j), hk≤hi,hj.

For each valid i, determine the number ci of students that have the same height as student i and can be seen by student i.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers h1,h2,…,hN.
Output
For each test case, print a single line containing N space-separated integers c1,c2,…,cN.

Constraints
1≤T≤10
1≤N≤105
1≤hi≤109 for each valid i
the sum of N over all test cases does not exceed 105
Subtasks
Subtask #1 (30 points): the sum of N over all test cases does not exceed 103
Subtask #2 (70 points): original constraints

Example Input
1
5
1 2 2 3 2
Example Output
0 1 1 0 0
Explanation
Example case 1: Student 3 can see students 2 and 4, but only student 2 has the same height (height 2). On the other hand, student 3 cannot see student 5 since student 4 is taller and therefore blocking the view.




DIFFICULTY:
Easy

PREREQUISITES:
Stack

PROBLEM:
NN students stand in a queue, the ii-th of them has height h_ih
i
​
 . Students ii and jj (i < ji<j) can see each other if h_k \leq min(h_i, h_j)h
k
​
 ≤min(h
i
​
 ,h
j
​
 ) for every i < k < ji<k<j. Find, for each ii, how many students of the same height as student ii are visible to him?

QUICK EXPLANATION:
Use a stack to find, for each ii, the closest student to the left and the right of ii who has height \geq h_i≥h
i
​
 .
With this information, a simple linear dynamic programming solution finds the answer, iterating once from the left and once from the right.
EXPLANATION:
Subtask 1
The condition about when students ii and jj can see each other can be stated as max(h_{i+1}, \dotsc, h_{j-1}) \leq min(h_i, h_j)max(h
i+1
​
 ,…,h
j−1
​
 )≤min(h
i
​
 ,h
j
​
 ).
In the case when h_i = h_jh
i
​
 =h
j
​
 , this is the same as max(h_i, h_{i+1}, \dotsc, h_{j-1}, h_j) = h_imax(h
i
​
 ,h
i+1
​
 ,…,h
j−1
​
 ,h
j
​
 )=h
i
​

This lets us solve the first subtask by bruteforcing every possible pair of students in \mathcal{O}(n^2)O(n
2
 ). Fix the index of the left student, say ii. Let mm be the maximum of the current range; initially, m = h_im=h
i
​
 .
Now, iterate jj from i+1i+1 to nn. If h_i = h_jh
i
​
 =h
j
​
 , and m = h_im=h
i
​
 , increase the answer for both students ii and jj by 1. Finally, update mm by setting m = max(m, h_j)m=max(m,h
j
​
 ).

Subtask 2
\mathcal{O}(n^2)O(n
2
 ) is too slow for this subtask - we need something faster.
Fix some student ii. Let’s see if we can find out how many students he sees to his left quickly (denoted by left[i]left[i]).
Let j < ij<i be the largest index such that h_j \geq h_ih
j
​
 ≥h
i
​
  (denote jump\_left[i] = jjump_left[i]=j). Suppose we are able to find this fast for every index ii. Does this give us a way to solve the problem faster than \mathcal{O}(n^2)O(n
2
 )? Yes!
There are two cases:

h_j > h_ih
j
​
 >h
i
​
 .
Here, student ii doesn’t see anyone with the same height to his left, i.e, left[i] = 0left[i]=0.
 Proof
Let k < ik<i with h_k = h_ih
k
​
 =h
i
​
 .
If k < j < ik<j<i, clearly student jj blocks kk and ii from seeing each other.
If j < k < ij<k<i, jj was not the maximum index of a student who is at least as tall as ii - a contradiction. So this case cannot happen.

h_j = h_ih
j
​
 =h
i
​

Here, left[i] = 1 + left[j]left[i]=1+left[j].
 Proof
Let k < ik<i with h_k = h_ih
k
​
 =h
i
​
 .
Of course, we must also have k \leq jk≤j - because j < k < ij<k<i would contradict jj being maximal.
If ii and kk can see each other, then clearly jj and kk can also see each other, because max(h_k, h_{k+1}, \dotsc, h_j) \leq max(h_k, h_{k+1}, \dotsc, h_j, \dotsc, h_i)max(h
k
​
 ,h
k+1
​
 ,…,h
j
​
 )≤max(h
k
​
 ,h
k+1
​
 ,…,h
j
​
 ,…,h
i
​
 ).
So, ii sees everyone who jj can see - and in addition, sees jj as well.
Hence, left[i] = left[j] + 1left[i]=left[j]+1.

Note that we assumed a suitable jj exists.

 What if no such j exists?
If no such jj exists, that also means that there cannot be a student with the same height as ii, to the left of student ii. So, the answer for student ii only depends on those on his right, meaning we can simply ignore any ii where this is the case.

When no such jj exists, set jump\_left[i] = -1jump_left[i]=−1.

Putting this together, we have the following solution:

Find jump\_left[i]jump_left[i] for every ii.
 How?
This is a classic problem which can be solved with a stack.
Let SS be an empty stack.
For each ii from 11 to NN, do the following:
While the stack is not empty:

Let j = S.top()j=S.top(). If h_j \geq h_ih
j
​
 ≥h
i
​
 , break.
Else, pop jj from S and continue.
If the stack is empty, jump\_left[i] = -1jump_left[i]=−1.
Else jump\_left[i] = S.top()jump_left[i]=S.top().
Push ii onto S.

Iterate ii from 1 to NN. if jump\_left[i] = -1jump_left[i]=−1 or h_{jump\_left[i]} > h_ih
jump_left[i]
​
 >h
i
​
 , set left[i] = 0left[i]=0. Else, set left[i] = 1 + left[jump\_left[i]]left[i]=1+left[jump_left[i]].
Repeat this procedure from the right to find jump\_right[i]jump_right[i] and right[i]right[i] for every 1\leq i\leq N1≤i≤N.
The final answer for ii is then left[i] + right[i]left[i]+right[i].

TIME COMPLEXITY:
\mathcal{O}(N)O(N) per testcase.

SOLUTIONS:
 Setter's Solution
 Tester's Solution
//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)

int main(){
    fastio;

    int tests;
    cin>>tests;

    while(tests--){
        int n;
        cin>>n;

        int h[n+1];
        // number of left seen and right seen of same height
        int le[n+1] = {0}, ri[n+1] = {0};
        // closest larger values to left and right
        int big_left[n+1] = {0}, big_right[n+1] = {0};

        for(int i = 1; i <= n; i++){
            cin>>h[i];
            big_right[i] = n+1;
        }
        map<int, int> last; // last seen of height

        stack<pair<int,int>> s;
        // now we will find closest element to left which is larger
        // well known stack solution
        for(int i = 1; i <= n; i++){
            while(!s.empty() && s.top().first <= h[i]){
                s.pop();
            }
            if(!s.empty()){
                big_left[i] = s.top().second;
            }
            s.push(make_pair(h[i], i));
            if(last[h[i]] != 0 && big_left[i] < last[h[i]]){
                le[i] = le[last[h[i]]] + 1;
            }
            last[h[i]] = i;
        }

        while(!s.empty()) s.pop();
        last.clear();

        for(int i = n; i >= 1; i--){
            while(!s.empty() && s.top().first <= h[i]){
                s.pop();
            }
            if(!s.empty()){
                big_right[i] = s.top().second;
            }
            s.push(make_pair(h[i], i));
            if(last[h[i]] != 0 && big_right[i] > last[h[i]]){
                ri[i] = ri[last[h[i]]] + 1;
            }
            last[h[i]] = i;
        }

        for(int i = 1; i <= n; i++) cout<<le[i] + ri[i]<<" ";
        cout<<endl;

    }

    return 0;
}


//Even n * n submissions have passed all the test cases!



---------------------------------------------
















*/