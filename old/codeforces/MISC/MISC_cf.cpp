/*
div2 707

A. Alexey and Train
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Alexey is travelling on a train. Unfortunately, due to the bad weather, the train moves slower that it should!

Alexey took the train at the railroad terminal. Let's say that the train starts from the terminal at the moment 0. Also, let's say that the train will visit n stations numbered from 1 to n along its way, and that Alexey destination is the station n.

Alexey learned from the train schedule n integer pairs (ai,bi) where ai is the expected time of train's arrival at the i-th station and bi is the expected time of departure.

Also, using all information he has, Alexey was able to calculate n integers tm1,tm2,…,tmn where tmi is the extra time the train need to travel from the station i−1 to the station i. Formally, the train needs exactly ai−bi−1+tmi time to travel from station i−1 to station i (if i=1 then b0 is the moment the train leave the terminal, and it's equal to 0).

The train leaves the station i, if both conditions are met:

it's on the station for at least ⌈bi−ai2⌉ units of time (division with ceiling);
current time ≥bi.
Since Alexey spent all his energy on prediction of time delays, help him to calculate the time of arrival at the station n.

Input
The first line contains one integer t (1≤t≤100) — the number of test cases.

The first line of each test case contains the single integer n (1≤n≤100) — the number of stations.

Next n lines contain two integers each: ai and bi (1≤ai<bi≤106). It's guaranteed that bi<ai+1.

Next line contains n integers tm1,tm2,…,tmn (0≤tmi≤106).

Output
For each test case, print one integer — the time of Alexey's arrival at the last station.

Example
inputCopy
2
2
2 4
10 12
0 2
5
1 4
7 8
9 10
13 15
19 20
1 2 3 4 5
outputCopy
12
32
Note
In the first test case, Alexey arrives at station 1 without any delay at the moment a1=2 (since tm1=0). After that, he departs at moment b1=4. Finally, he arrives at station 2 with tm2=2 extra time, or at the moment 12.

In the second test case, Alexey arrives at the first station with tm1=1 extra time, or at moment 2. The train, from one side, should stay at the station at least ⌈b1−a12⌉=2 units of time and from the other side should depart not earlier than at moment b1=4. As a result, the trains departs right at the moment 4.

Using the same logic, we can figure out that the train arrives at the second station at the moment 9 and departs at the moment 10; at the third station: arrives at 14 and departs at 15; at the fourth: arrives at 22 and departs at 23. And, finally, arrives at the fifth station at 32.

logic:
The solution of this task is to basically implement what was written in the statement.

Let depi be the moment of train departure from the station i (dep0=0 initially). Then train arrives at the current station i at moment ari=depi−1+(ai−bi−1)+tmi and departure at moment depi=max(bi,ari+bi−ai+12).


while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)
			scanf("%d %d",&a[i],&b[i]);
		for(i=1;i<=n;++i)
			scanf("%d",&tu[i]);
		int s=0;
		for(i=1;i<=n;++i)
		{
			s+=a[i]-b[i-1]+tu[i];
			if(i!=n)
				s=max(b[i],s+(b[i]-a[i]+1)/2);
		}
		printf("%d\n",s);
	}

-------------------------------------------------------------------------------------------------------------

C. Going Home
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
It was the third month of remote learning, Nastya got sick of staying at dormitory, so she decided to return to her hometown. In order to make her trip more entertaining, one of Nastya's friend presented her an integer array a.

Several hours after starting her journey home Nastya remembered about the present. To entertain herself she decided to check, are there four different indices x,y,z,w such that ax+ay=az+aw.

Her train has already arrived the destination, but she still hasn't found the answer. Can you help her unravel the mystery?

Input
The first line contains the single integer n (4≤n≤200000) — the size of the array.

The second line contains n integers a1,a2,…,an (1≤ai≤2.5⋅106).

Output
Print "YES" if there are such four indices, and "NO" otherwise.

If such indices exist, print these indices x, y, z and w (1≤x,y,z,w≤n).

If there are multiple answers, print any of them.

Examples
inputCopy
6
2 1 5 2 7 4
outputCopy
YES
2 3 1 6 
inputCopy
5
1 3 1 9 20
outputCopy
NO
Note
In the first example a2+a3=1+5=2+4=a1+a6. Note that there are other answer, for example, 2 3 4 6.

In the second example, we can't choose four indices. The answer 1 2 2 3 is wrong, because indices should be different, despite that a1+a2=1+3=3+1=a2+a3

logic:
Let's prove that if there're at least four different pairs indices with the common sum (ax1+ay1=ax2+ay2=…=ax4+ay4), then there necessarily will be two pairs such that all four indices in them are unique.

Let's analyze some cases:

There're four pairs of the form (x,y1),(x,y2),(x,y3),(x,y4) with sum S. Then ax+ay1=ax+ay2=ax+ay3=ax+ay4=S from which we can conclude that ay1=ay2=ay3=ay4, and it means that pairs (y1,y2) and (y3,y4) are suitable as answer.
There're three pairs of the form (x,y1),(x,y2),(x,y3) and the fourth pair doesn't contain index x. Then whatever the fourth pair (z,w) is, it necessarily doesn't contain index x and at least one of indices y1,y2,y3 which means we can take as answer pairs (z,w) and one of three that contain x.
Other cases are analyzed in the same way. To make sure that answer always exists among such four pairs, we can imagine graph, where vertices are indices, and there is an edge between two vertices if the corresponding pair of indices has sum S. If such a graph has at least four edges and the degree of all vertices is at most two (we excluded the larger degrees by examining the previous cases), then there will always be two edges with disjoint ends.
How to find answer using this? Let's launch simple O(n2) bruteforce which for every sum will save all found pairs with such sum, and for each pair check if there's another already found pair with the same sum and such indices that all four indices in these two pairs are unique.

Let's notice it works in O(min(n2,n+C), because once for some sum we find the fourth pair, we can immediately print the answer. And if the answer is "NO", then we've done no more than O(C) iterations of bruteforce.

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    n = min(n, 5000);
    vi a(n);
    fori(i, n) cin >> a[i];
 
    map<int, pii> m;
    fori(i, n)
    {
        rep(j, i + 1, n - 1) // like forx j = i+1 to <=n-1 ... could also write <n....
        {
            if (m.count(a[i] + a[j]))
            {
                auto pp = m[a[i] + a[j]];
                if(pp.fi == i or pp.se == j or pp.se == i or pp.fi == j)
                    continue;
                cout << "YES" << endl;
                cout << pp.fi + 1 << " " << pp.se + 1 << " " << i + 1 << ' ' << j + 1 << endl;
                return 0;
            }
            else{
                m[a[i] + a[j]] = {i, j};
            }
        }
    }
    cout << "NO" << endl;
 
    return 0;
}

-------------------------------------------------------------------------------------------------------------
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
1493B - Planet Lapituletti

Idea: AlFlen

Tutorial
1493B - Planet Lapituletti
B. Planet Lapituletti
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
The time on the planet Lapituletti goes the same way it goes on Earth but a day lasts h hours and each hour lasts m minutes. The inhabitants of that planet use digital clocks similar to earth ones. Clocks display time in a format HH:MM (the number of hours in decimal is displayed first, then (after the colon) follows the number of minutes in decimal; the number of minutes and hours is written with leading zeros if needed to form a two-digit number). Hours are numbered from 0 to h−1 and minutes are numbered from 0 to m−1.


That's how the digits are displayed on the clock. Please note that digit 1 is placed in the middle of its position.

A standard mirror is in use on the planet Lapituletti. Inhabitants often look at the reflection of the digital clocks in the mirror and feel happy when what you see on the reflected clocks is a valid time (that means that you see valid digits in the reflection and this time can be seen on the normal clocks at some moment of a day).

The image of the clocks in the mirror is reflected against a vertical axis.


The reflection is not a valid time.



The reflection is a valid time with h=24, m=60. However, for example, if h=10, m=60, then the reflection is not a valid time.

An inhabitant of the planet Lapituletti begins to look at a mirrored image of the clocks at some time moment s and wants to know the nearest future time moment (which can possibly happen on the next day), when the reflected clock time is valid.

It can be shown that with any h, m, s such a moment exists. If the reflected time is correct at the moment the inhabitant began to look at the clock, that moment is considered the nearest.

You are asked to solve the problem for several test cases.

Input
The first line contains a single integer T (1≤T≤100) — the number of test cases.

The next 2⋅T lines contain the description of test cases. The description of each test case consists of two lines.

The first line of a test case contains two integers h, m (1≤h,m≤100).

The second line contains the start time s in the described format HH:MM.

Output
For each test case output in a separate line the nearest moment in format HH:MM when the reflected time is correct.

Example
inputCopy
5
24 60
12:21
24 60
23:59
90 80
52:26
1 100
00:01
10 10
04:04
outputCopy
12:21
00:00
52:28
00:00
00:00
Note
In the second test case it is not hard to show that the reflection of 23:59 is incorrect, while the reflection of the moment 00:00 on the next day is correct.


In order to solve the problem, you need to look over all the moments of time after the given one and check if the reflected time is correct in that moment of time. If such moment of time does not exist on the current day, the moment $$$00:00$$$ of the next day is always correct.

For realization you need to notice that digits $$$0$$$, $$$1$$$, $$$8$$$ transform into themselves after reflection, $$$2$$$ transforms into $$$5$$$, $$$5$$$ transforms into $$$2$$$, and other digits ($$$3$$$, $$$4$$$, $$$6$$$, $$$7$$$, $$$9$$$) transform into incorrect digits after reflection.

Solution (74TrAkToR)
#include <bits/stdc++.h>

using namespace std;

vector < int > go = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
int inf = 1e9 + 7;

int get(int x) {
    string s = to_string(x);
    if ((int)s.size() == 1) s = "0" + s;
    string answ = "";
    for (int i = 1; i >= 0; --i) {
        if (go[s[i] - '0'] == -1) return inf;
        answ += char(go[s[i] - '0'] + '0');
    }
    return stoi(answ);
}

string good(int x) {
    string ans = to_string(x);
    if (x < 10) {
        ans = "0" + ans;
    }
    return ans;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, h, m, H, M;
    cin >> t;
    string s;
    while (t--) {
        cin >> h >> m;
        cin >> s;
        H = (s[0] - '0') * 10 + s[1] - '0';
        M = (s[3] - '0') * 10 + s[4] - '0';
        while (1) {
            if (M == m) {
                H++, M = 0;
            }
            if (H == h) {
                H = 0;
            }
            if (get(M) < h && get(H) < m) {
                cout << good(H) << ":" << good(M) << '\n';
                break;
            }
            M++;
        }
    }
    return 0;
}




-------------------------------------------------------------------------------------------------------------
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$





-------------------------------------------------------------------------------------------------------------
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$






-------------------------------------------------------------------------------------------------------------
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$






-------------------------------------------------------------------------------------------------------------
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$







-------------------------------------------------------------------------------------------------------------
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$






-------------------------------------------------------------------------------------------------------------




*/