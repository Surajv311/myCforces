/*

ksun48s ans...

Reversort (7pts)

Problem
Note: The main parts of the statements of the problems "Reversort" and "Reversort Engineering" are identical, except for the last paragraph. The problems can otherwise be solved independently.

Reversort is an algorithm to sort a list of distinct integers in increasing order. The algorithm is based on the "Reverse" operation. Each application of this operation reverses the order of some contiguous part of the list.

The pseudocode of the algorithm is the following:

Reversort(L):
  for i := 1 to length(L) - 1
    j := position with the minimum value in L between i and length(L), inclusive
    Reverse(L[i..j])
After i−1 iterations, the positions 1,2,…,i−1 of the list contain the i−1 smallest elements of L, in increasing order. During the i-th iteration, the process reverses the sublist going from the i-th position to the current position of the i-th minimum element. That makes the i-th minimum element end up in the i-th position.

For example, for a list with 4 elements, the algorithm would perform 3 iterations. Here is how it would process L=[4,2,1,3]:

i=1, j=3⟶L=[1,2,4,3]
i=2, j=2⟶L=[1,2,4,3]
i=3, j=4⟶L=[1,2,3,4]
The most expensive part of executing the algorithm on our architecture is the Reverse operation. Therefore, our measure for the cost of each iteration is simply the length of the sublist passed to Reverse, that is, the value j−i+1. The cost of the whole algorithm is the sum of the costs of each iteration.

In the example above, the iterations cost 3, 1, and 2, in that order, for a total of 6.

Given the initial list, compute the cost of executing Reversort on it.

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of 2 lines. The first line contains a single integer N, representing the number of elements in the input list. The second line contains N distinct integers L1, L2, ..., LN, representing the elements of the input list L, in order.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the total cost of executing Reversort on the list given as input.

Limits
Time limit: 10 seconds.
Memory limit: 1 GB.
Test Set 1 (Visible Verdict)
1≤T≤100.
2≤N≤100.
1≤Li≤N, for all i.
Li≠Lj, for all i≠j.
Sample
Sample Input
save_alt
content_copy
3
4
4 2 1 3
2
1 2
7
7 6 5 4 3 2 1
Sample Output
save_alt
content_copy
Case #1: 6
Case #2: 1
Case #3: 12
Sample Case #1 is described in the statement above.

In Sample Case #2, there is a single iteration, in which Reverse is applied to a sublist of size 1. Therefore, the total cost is 1.

In Sample Case #3, the first iteration reverses the full list, for a cost of 7. After that, the list is already sorted, but there are 5 more iterations, each of which contributes a cost of 1.


#include <bits/stdc++.h>
using namespace std;

void solve(int t){
	int n;
	cin >> n;
	vector<int> a(n);
	int cost = 0;
	for(int& x : a){
		cin >> x;
		x--;
	}
	for(int i = 0; i < n; i++){
		int j = i;
		while(a[j] != i) j++;
		cost += (j-i+1);
		reverse(a.begin() + i, a.begin() + j + 1);
	}
	cout << "Case #" << t << ": ";
	cout << (cost-1) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) solve(t);
}



---------------------------------------------------------



Moons and Umbrellas (5pts, 11pts, 1pts)


Problem
Cody-Jamal is working on his latest piece of abstract art: a mural consisting of a row of waning moons and closed umbrellas. Unfortunately, greedy copyright trolls are claiming that waning moons look like an uppercase C and closed umbrellas look like a J, and they have a copyright on CJ and JC. Therefore, for each time CJ appears in the mural, Cody-Jamal must pay X, and for each time JC appears in the mural, he must pay Y.



Cody-Jamal is unwilling to let them compromise his art, so he will not change anything already painted. He decided, however, that the empty spaces he still has could be filled strategically, to minimize the copyright expenses.

For example, if CJ?CC? represents the current state of the mural, with C representing a waning moon, J representing a closed umbrella, and ? representing a space that still needs to be painted with either a waning moon or a closed umbrella, he could finish the mural as CJCCCC, CJCCCJ, CJJCCC, or CJJCCJ. The first and third options would require paying X+Y in copyrights, while the second and fourth would require paying 2⋅X+Y.

Given the costs X and Y and a string representing the current state of the mural, how much does Cody-Jamal need to pay in copyrights if he finishes his mural in a way that minimizes that cost?

Input
The first line of the input gives the number of test cases, T. T lines follow. Each line contains two integers X and Y and a string S representing the two costs and the current state of the mural, respectively.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the minimum cost that Cody-Jamal needs to pay in copyrights for a finished mural.

Limits
Time limit: 10 seconds.
Memory limit: 1 GB.
1≤T≤100.
Each character of S is either C, J, or ?.

Test Set 1 (Visible Verdict)
1≤ the length of S ≤10.
1≤X≤100.
1≤Y≤100.
Test Set 2 (Visible Verdict)
1≤ the length of S ≤1000.
1≤X≤100.
1≤Y≤100.
Extra credit!
What if some copyright holders could pay Cody-Jamal for the advertisement instead of being paid? Cody-Jamal getting paid is represented by a negative cost.

Test Set 3 (Hidden Verdict)
1≤ the length of S ≤1000.
−100≤X≤100.
−100≤Y≤100.
Sample
Note: there are additional samples that are not run on submissions down below.
Sample Input
save_alt
content_copy
4
2 3 CJ?CC?
4 2 CJCJ
1 3 C?J
2 5 ??J???
Sample Output
save_alt
content_copy
Case #1: 5
Case #2: 10
Case #3: 1
Case #4: 0
Sample Case #1 is the one explained in the problem statement. The minimum cost is X+Y=2+3=5.

In Sample Case #2, Cody-Jamal is already finished, so he does not have a choice. There are two CJs and one JC in his mural.

In Sample Case #3, substituting either C or J results in one CJ either from the second and third characters or the first and second characters, respectively.

In Sample Case #4, Cody-Jamal can finish his mural with all Js. Since that contains no instance of CJ nor JC, it yields no copyright cost.


Additional Sample - Test Set 3
The following additional sample fits the limits of Test Set 3. It will not be run against your submitted solutions.
Sample Input
save_alt
content_copy
1
2 -5 ??JJ??
Sample Output
save_alt
content_copy
Case #1: -8
In Sample Case #1 for Test Set 3, Cody-Jamal can finish his mural optimally as JCJJCC or JCJJJC. Either way, there is one CJ and two JCs in his mural.





#include <bits/stdc++.h>
using namespace std;

void solve(int t){
	cout << "Case #" << t << ": ";
	int x, y;
	string s;
	cin >> x >> y >> s;
	int n = (int)s.size();
	vector<vector<int> > dp(n+1, vector<int>(2, 1e9));
	dp[0][0] = dp[0][1] = 0;
	for(int i = 1; i <= n; i++){
		for(int c = 0; c < 2; c++){
			if(c == 0 && s[i-1] == 'J') continue;
			if(c == 1 && s[i-1] == 'C') continue;
			for(int d = 0; d < 2; d++){
				int cost = 0;
				if(i > 1){
					if(d == 0 && c == 1) cost += x;
					if(d == 1 && c == 0) cost += y;
				}
				dp[i][c] = min(dp[i][c], dp[i-1][d] + cost);
			}
		}
	}
	cout << min(dp[n][0], dp[n][1]) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) solve(t);
}





--------------------------------------------





Reversort Engineering (7pts, 11pts)


Problem
Note: The main parts of the statements of the problems "Reversort" and "Reversort Engineering" are identical, except for the last paragraph. The problems can otherwise be solved independently.

Reversort is an algorithm to sort a list of distinct integers in increasing order. The algorithm is based on the "Reverse" operation. Each application of this operation reverses the order of some contiguous part of the list.

The pseudocode of the algorithm is the following:

Reversort(L):
  for i := 1 to length(L) - 1
    j := position with the minimum value in L between i and length(L), inclusive
    Reverse(L[i..j])
After i−1 iterations, the positions 1,2,…,i−1 of the list contain the i−1 smallest elements of L, in increasing order. During the i-th iteration, the process reverses the sublist going from the i-th position to the current position of the i-th minimum element. That makes the i-th minimum element end up in the i-th position.

For example, for a list with 4 elements, the algorithm would perform 3 iterations. Here is how it would process L=[4,2,1,3]:

i=1, j=3⟶L=[1,2,4,3]
i=2, j=2⟶L=[1,2,4,3]
i=3, j=4⟶L=[1,2,3,4]
The most expensive part of executing the algorithm on our architecture is the Reverse operation. Therefore, our measure for the cost of each iteration is simply the length of the sublist passed to Reverse, that is, the value j−i+1. The cost of the whole algorithm is the sum of the costs of each iteration.

In the example above, the iterations cost 3, 1, and 2, in that order, for a total of 6.

You are given a size N and a cost C. Find a list of N distinct integers between 1 and N such that the cost of applying Reversort to it is exactly C, or say that there is no such list.

Input
The first line of the input gives the number of test cases, T. T lines follow. Each line describes a test case with two integers N and C, the size of the wanted list and the desired cost, respectively.

Output
For each test case, if there is no list of size N such that applying Reversort to it costs exactly C, output one line containing Case #x: IMPOSSIBLE, where x is the test case number (starting from 1). Otherwise, output one line containing Case #x: y1 y2 ... yN, where x is the test case number (starting from 1) and each yi is a distinct integer between 1 and N, representing the i-th element of one such possible list.

If there are multiple solutions, you may output any one of them. (See "What if a test case has multiple correct solutions?" in the Competing section of the FAQ.) This information about multiple solutions will not be explicitly stated in the remainder of the 2021 contest.

Limits
Time limit: 10 seconds.
Memory limit: 1 GB.
1≤T≤100.
1≤C≤1000.
Test Set 1 (Visible Verdict)
2≤N≤7.
Test Set 2 (Visible Verdict)
2≤N≤100.
Sample
Sample Input
save_alt
content_copy
5
4 6
2 1
7 12
7 2
2 1000
Sample Output
save_alt
content_copy
Case #1: 4 2 1 3
Case #2: 1 2
Case #3: 7 6 5 4 3 2 1
Case #4: IMPOSSIBLE
Case #5: IMPOSSIBLE
Sample Case #1 is described in the statement above.

In Sample Case #2, the algorithm runs for only one iteration on the proposed output. In that iteration, reverse is applied to a sublist of size 1, therefore, its cost is 1.

In Sample Case #3, the first iteration reverses the full list, for a cost of 7. After that, the list is already sorted, but there are 5 more iterations, each of which contributes a cost of 1. Another valid output would be 7 5 4 3 2 1 6. For that output, the first iteration has a cost of 6, the last one has a cost of 2, and all others have a cost of 1.

In Sample Case #4, Reversort will necessarily perform 6 iterations, each of which will have a cost of at least 1, so there is no way the total cost can be as low as required.





#include <bits/stdc++.h>
using namespace std;

void solve(int t){
	cout << "Case #" << t << ": ";
	int n, c;
	cin >> n >> c;
	c += 1;
	if(c < n || c > n*(n+1) / 2){
		cout << "IMPOSSIBLE" << '\n';
		return;
	}
	c -= n;
	vector<int> res(n);
	for(int i = 0; i < n; i++) res[i] = i;
	for(int j = n-1; j >= 0; j--){
		int extra = min(c, n-1-j);
		c -= extra;
		reverse(res.begin() + j, res.begin() + j + extra + 1);
	}
	for(int i = 0; i < n; i++){
		cout << (res[i]+1) << " \n"[i == (n-1)];
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++) solve(t);
}








------------------------------------------------------





Median Sort (7pts, 11pts, 10pts)


Problem
You want to sort N distinct items, x1,x2,…,xN. Unfortunately, you do not have a way of comparing two of these items. You only have a way to, given three of them, find out which one is the median, that is, which one is neither the minimum nor the maximum among the three.

For example, suppose N=5 and you know that:

x1 is the median of {x1,x2,x3}
x2 is the median of {x2,x3,x4}
x3 is the median of {x3,x4,x5}
Then, it is guaranteed that the sorted order of the elements is either x4,x2,x1,x3,x5 or its reverse x5,x3,x1,x2,x4. Notice that by knowing only medians, it is impossible to distinguish the order of any list from its reverse, since the median question has the same result for any three elements in both cases.

Your program will have to find the order of T lists of N elements using at most Q median questions in total (or Q/T queries per list on average). In each case, finding either the right order or its reverse is considered correct. The order for each case is generated uniformly at random from all possible orders, and independently of any other information.

Input and output
This is an interactive problem. You should make sure you have read the information in the Interactive Problems section of our FAQ.

Initially, the judge will send you a single line containing three integers T, N, and Q: the number of test cases, the number of elements to sort within each test case, and the total number of questions you are allowed across all test cases, respectively. Then, you must process T test cases. Each test case consists of a series of question exchanges plus an additional exchange to provide the answer.

For a question exchange, your program must print a single line containing three distinct integers i,j,k all between 1 and N, inclusive, which corresponds to asking the judge "which element is the median of the set {xi,xj,xk}?" The judge will respond with a single line containing a single integer L, meaning that the median of that set is xL (L is always equal to one of i, j, or k). If you try to perform a (Q+1)-th question exchange, the judge will simply output -1.

Once you are ready to state the result, print a line containing N integers representing the indices of the elements in sorted or reverse sorted order. The judge will respond with a single integer 1 if your answer is correct or -1 if it is not. After receiving the judge's answer for the T-th case, your program must finish in time in order to not receive a Time Limit Exceeded error. In addition, if you print additional information after receiving the result for the T-th case, you will get a Wrong Answer judgment.

If the judge receives an invalidly formatted line or invalid values from your program at any moment, the judge will print a single number -1. After the judge prints -1 for any of the reasons explained above, it will not print any further output. If your program continues to wait for the judge after receiving a -1, your program will time out, resulting in a Time Limit Exceeded error. Notice that it is your responsibility to have your program exit in time to receive a Wrong Answer judgment instead of a Time Limit Exceeded error. As usual, if the memory limit is exceeded, or your program gets a runtime error, you will receive the appropriate judgment.

Limits
Time limit: 40 seconds.
Memory limit: 1 GB.
T=100.
Test Set 1 (Visible Verdict)
N=10.
Q=300⋅T.
Test Set 2 (Visible Verdict)
N=50.
Q=300⋅T.
Test Set 3 (Hidden Verdict)
N=50.
Q=170⋅T.
Testing Tool
You can use this testing tool to test locally or on our platform. To test locally, you will need to run the tool in parallel with your code; you can use our interactive runner for that. For more information, read the instructions in comments in that file, and also check out the Interactive Problems section of the FAQ.

Instructions for the testing tool are included in comments within the tool. We encourage you to add your own test cases. Please be advised that although the testing tool is intended to simulate the judging system, it is NOT the real judging system and might behave differently. If your code passes the testing tool but fails the real judge, please check the Coding section of the FAQ to make sure that you are using the same compiler as us.

Download testing tool

Sample Interaction
Judge
Solution
Constraints
2 5 600
Judge provides T, N, Q
Case 1
1 2 3
Solution asks for the median of {x1,x2,x3}
2
Judge responds that the median is x2
4 2 3
Solution asks for the median of {x4,x2,x3}
3
Judge responds that the median is x3
5 4 3
Solution asks for the median of {x5,x4,x3}
4
Judge responds that the median is x4
5 4 3 2 1
Solution outputs the sorted list
1
Judge confirms that the answer is correct
Case 2
1 2 3
Solution asks for the median of {x1,x2,x3}
3
Judge responds that the median is x3
2 3 4
Solution asks for the median of {x2,x3,x4}
4
Judge responds that the median is x4
3 4 5
Solution asks for the median of {x3,x4,x5}
5
Judge responds that the median is x5
1 3 5 4 2
Solution outputs the sorted list
1
Judge confirms that the answer is correct






#include <bits/stdc++.h>
using namespace std;

int N, Q;

int ask(int a, int b, int c){
	cout << (a+1) << ' ' << (b+1) << ' ' << (c+1) << '\n';
	cout << flush;
	int res;
	cin >> res;
	if(res == -1) exit(0);
	return (res-1);
}

void solve(){
	vector<int> ord = {0, 1};
	for(int j = 2; j < N; j++){
		int s = 0;
		int e = (int)ord.size()+1;
		while(s + 1 < e){
			int m1 = (s + s + e) / 3;
			int m2 = (s + e + e) / 3;
			if(m1 == 0) m1++;
			while(m2 <= m1) m2++;
			if(m2 == (int)ord.size()+1) m2--;
			while(m1 >= m2) m1--;
			int res = ask(j, ord[m1-1], ord[m2-1]);
			if(res == j){
				s = max(s, m1);
				e = min(e, m2);
			} else if(res == ord[m1-1]){
				e = min(e, m1);
			} else if(res == ord[m2-1]){
				s = max(s, m2);
			}
		}
		ord.insert(ord.begin() + s, j);
	}
	for(int i = 0; i < N; i++){
		cout << (ord[i]+1) << " \n"[i == (N-1)];
	}
	cout << flush;
	int verdict;
	cin >> verdict;
	if(verdict == -1) exit(0);
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T >> N >> Q;
	while(T--) solve();
}







-------------------------------------------------------



Cheating Detection (11pts, 20pts)



Problem
100 players are competing in a 10000-question trivia tournament; the players are numbered from 1 to 100. Player i has a skill level of Si and question j has a difficulty level of Qj. Each skill level and each question difficulty are chosen uniformly at random from the range [−3.00,3.00], and independently of all other choices. For example, a player can have a skill level of 2.47853 and a question can have a difficulty level of −1.4172.

When player i tries to answer question j, the probability that they answer it correctly is f(Si−Qj), where f is the sigmoid function:
f(x)=11+e−x
where e is Euler's number (approximately 2.718...), the mathematical constant. Notice that 0<f(x)<1 for all x, so f(Si−Qj) is always a valid probability. Each of these answer attempts is chosen at random independently of all other choices.

There is one exception: exactly one of the players is a cheater! The cheater is chosen uniformly at random from among all players, and independently of all other choices. The cheater behaves as follows: before answering each question, they flip a fair coin. If it comes up heads, they do not cheat and the rules work as normal. If it comes up tails, they secretly look up the answer on the Internet and answer the question correctly. Formally, they decide whether to cheat at random with 0.5 probability for each question, independently of all other choices.

The results of a tournament consist of only the per-question results (correct or incorrect) for each player. Apart from the general description above, you do not know anything about the skill levels of the players or the difficulties of the questions.

You must correctly identify the cheater in at least P percent of the test cases. That is, you must succeed in at least P⋅T/100 out of T cases.

Input
The first line of the input gives the number of test cases, T. The second line of the input gives the percentage of test cases, P, that you must answer correctly for your solution to be considered correct. T test cases follow. Each case consists of 100 lines of 10000 characters each. The j-th character on the i-th line is 1 if the i-th player answered the j-th question correctly, or 0 if they answered it incorrectly.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of the cheater (with player numbers starting from 1).

Limits
Time limit: 60 seconds.
Memory limit: 1 GB.
T=50.
Test Set 1 (Visible Verdict)
P=10.

Test Set 2 (Visible Verdict)
P=86.
Sample
Sample Input
save_alt
1
0
0011101000101010000010000001000101010000000011000110101000100001100101010000011000010010001000011000010010000000000010010000000000000111000110001010000000011110010000011001111000101011001100010000010000000010000100100000000000001000011010000101010000000000010001001111000100010001000000010011010001001100110000100010001000010100000001001100010000010000011110010000000110000001001100100001000110000001000000100000001011000100010001101000000000000000000000001110010000001010010101101000011000000000000001000100001011000000110100100000000011100000010000000111100001000010000000000000110111101100110000111100100000100000011011010110000011000000001000100101000010000110010010010001000000110101001000001000100000010001010010001000100000000110110001000000110001000000000000000011010000100010000000110100010001001010110000000001000000010000000011100000001010101000000100000110000001000011001100010001111010100101010000000000100000100100000000011101000000000100101100001000000000101000110100000001010001111100001000000100001111000011100001000001100000000011011000001000100110110000000001111000100000001000011011010000000000001011100000000110000011001010000001010000011000100001000001010000010000000001100010000001100000000000001001000010010000000000010000110000000110000000100000100010000100000011010010001000010000001100011001001101110010010110000101111100000011000011011000000010000010101101100100010000001000000101100000010000101000001000100000000100000111010000000011001011011001100010001000000001111000100100001000000010000000100000101000000000000001100000111100100010001010000110000001010100010100011010010000010000100000100000010010010000110000111100100111110000001000100000000001000001000000000000110001100010000000110100001000010011001110010000001000000000000100000010000100000000101000110010001011000001000100111000010101001000011100000010011100000100100111100100000000000011001000110000000000000010110100010001000000000100000100010100001000010000010101000001111000110000010011100000000000000010100000000100000000011010100001100010001000000000111000001100000000010101010000000011001000001010000110110000111010001100000100000001110000000000000001001000000000010001000000000000001100010001100000010000000000000000101000000000000000100010110000010100110001000010010001011100110001000100100000010000001001101010000101000110000101000000010010000000100110000001000000100010000001101001001100010000000100110001100010000000100100001010010000010000001000000000000000001000000001110010010000101110001100010010100000111001000000000000110100110101010100000000101000000001100000000010111001000101010000000001010000000000101000000000010000000000010100101110010100000001101000010100100010000000101000001001100001010110000010000110001000100000000010010001000011011100000001001100100000000111001000100010000011100100000110100001010010001000110001001100100001000000110111010000000001000000000100010100000011010010000000100111000000000000000000010101100011000011101000000000001001000100100010111101000100110111010100010001000000000011011000010000001100000000010100000001001000110001011000100000000011010010000100111101110000011100000110100001000110000100101010100001100010010100000000010001000000001001110000010000000110000100010010000111100100000000000000101000010010001001000110010001001101000001001001000000000100000010001101000000010101010001010001110010100000000010101000011001001100000100101000010000101000001101111001000110000000000001011000011001000000100001000010000000000100000100011001001110010010000111100010000010001000001100010000001000101000010010010000011001101010110001000001001000101110010010100000000000001100010000001010000101000110000001001110010101000000100000000000000010001001000010010000010001001000000000011000110000001000001111000000000000001000101100001000000100010101001111011000100000100000100001110101001000100000000100010011010010000000000000100110000001001010101001110011110000000010001100000101000000000111100000000001100101001000000000000000000000000101000010110000110001000101100000000000000000000100000000001011000011001000000000000011001111001000000001000011000001100011100000000000111100000001000000010001100100000001000010000001010001100010000100001001011101000100100000000011010000100000011001000011101010000010010010100100011000100001000110001110000100100010100100010010110111010001100000100010000000001010111100011001010000000000000100001001011000000100010001111000010000010100001010100001010010101000010100000010001100010000010101000010010100011111110111000010010000010000000000000010100110001000100010000101100100100010001000001000100010000010000101010011000100110000011010000010110000011000000010100010010101100010010000010001101000000000000010001101000000000000000101001000000001011000000000000000101010110001000100000011000000100010000000001101011000000100100000001010000010010010000101000001100001100100110000000100010001010100000011000000001010000000000110010101011000010000000000000100011000000010101011000001011000011000000010000010001010000011100010100000001110000000000001100101000001100110000011000000101000101001000001011000100100000100010100000011100110101000000011010011001100011100011010100010100111100000000010111101000011000010000000001101010100000011000000000000101000000001001000000000100001100001101010001000010001000001000100000000010101000010010000111000010000000000001000000011110011000010010000000000101100000100010001101000000000010110100010100111001000000100000000001100010010000011010110000010100101001000001101000001100001101010000100010011101000000001100100000100010101000000000011000000000100000100010101010010000000010001010000100010000001010000101100001000000001000100000100101101000100111000000000000100110000101001000010000110101000010101000110000010100001000011101111000000110010000110110100000000010000001010001011000100000000000110100000110110010110000100101000000000000001001100010101000000010000000010000110001000000001010001000000101000010010010101101100000001001001001110010001111011000000100000100010000100010111001000000000100010000000110111001001100000000100011100100000000010010001000110010101101011000000100000101011001100000000101000000000010100101100000100110100001000011010010000000000000011101001000111000000000001010001001000000001000000010000000011000000100000110011000001100100010000000100000000010000100000000101010101000001001000011000001010111000000011101101011110000010000000000011000000000100010000110000000010001100011001100000110000000010000000001010011000011010011000010001100000000100011001000010000010010000110100010011000000000000100101000000010111000000000001000001001001010000001000000000000010010000001001001001100010101000000011010010001000100000000100001111000100110000100100000101000100001000001000010000010011000000000100100100010000110000000101001000010100000010000101010000000000101011000000010000000010000000010100001100000000000111000001011101001001000110000100000010000010000100000000010011101000110000010011000100110000100000000000000100100010111010010010010000000111000000001000101110010101000110100111000000001010000100010000000010001000001010000110000100001010011101010010100000000000010100000010000110000010001000001000011000010010000000011100111101011000100010000000000010000000000000100000000100010001110101101010111000000101101100000111001010000000011010110100000000010000000001100000000001000010100100010010000011100001100110100000010100010100000000000010100010001010000110001000000001000010100011000000100000011000100000000100000110000001000101000000011001001010000000101000000001000100010010000100011100001010000001100010000000100000100101100101000000000010001000000111100110000101100000110000000100010000010010010100000111000011001001100000110000100000001101011011010000100000100000100110000100101000010000010100000001001000000100011000000110011001100000010000001001010001000100001000000000100000100001000000001001001001011001010011100100001000101011001001101100110000000000000000000000010000000010001000100010000101101000010001001001111000000001000001110000000001000000000011000011000000000000011000000000000110000000001001101000000100000001000001100010010010000010000000010100010010000011001001010010000000000000000000001100111011000000001010111100000000000000101001010000100100000011000001111000010001000001100010001011000000100110000100000101000000001001000000000010111000100100000100010000000000000010100000100010000000001011010110010101000001000000000000001011011001100000001000000000000000000000101000001001110100000000001000000111101001100000000010011000100010001000001100100100001100100010001100001010101010001010001001000010100000000000000000000000000010100100101000110000001001000001001110110001000001001000000010000111001111001010001101010111000010010001101001000100101100000110000000010010010000100100000000011001001011000001000001110010011000000110000000001010000100001000010010001010111001000001010000001111000100100100000110010000101100000110100000000010000000100100010000010000101110001000000000000100101000000000110011001011100111000001100000001000111000011000000100101000001010010110000000000000110010001010001010110100000001101100111011111000000010000001100001001110001001101011000000000100000010001000000101001001000001000000000000111000100010000000010001000000001000000000000000101000000000000110010100010001001001000001100010000000101100000000000110010000100010000000000010111101110001011100000001011000101011010001100001100101000000000100000000000100000010000100000001000000010001000100100001110100010101100000100010001000010110000000000000101000000000001001000000111001000011011010101110010100000000011110000100000110010000000010011110001011010000000000100011001000000010000010011000000001011000000000000011010001000101000010111000001001001001011000000000000010011000000101000010100100000001011110000100001100010110000011001010001010100000010011101100010000000100100000000101101000100100001000000010001000000000000010100110000000100010110000000000000100001011010001111100000010000011000000110000000000100000100001000100000001001100100101010101010000101000100110
-------------------------------
99 lines of input omitted.
Use the download button above
to view the full sample input.
-------------------------------
Sample Output
save_alt
content_copy
Case #1: 59
Notice that the sample input uses T=1 and P=0 and therefore does not meet the limits of any test set. The sample output for it is the actual cheater.






#include <bits/stdc++.h>
using namespace std;

void solve(int t){
	int n = 100;
	int q = 10000;
	vector<string> a(n);
	for(string& s : a) cin >> s;
	vector<int> psolved(n), qsolved(q);
	for(int i = 0; i < n; i++) for(int j = 0; j < q; j++){
		if(a[i][j] == '1'){
			psolved[i]++;
			qsolved[j]++;
		}
	}
	vector<int> pord(n);
	vector<int> qord(q);
	for(int i = 0; i < n; i++) pord[i] = i;
	for(int i = 0; i < q; i++) qord[i] = i;
	sort(pord.begin(), pord.end(), [&](int x, int y){
		return psolved[x] < psolved[y];
	});
	sort(qord.begin(), qord.end(), [&](int x, int y){
		return qsolved[x] > qsolved[y];
	});
	vector<double> score(n);
	for(int i = 0; i < n; i++){
		int n0 = 0;
		int n1 = 0;
		int inv = 0;
		for(int j = 0; j < q; j++){
			if(a[pord[i]][qord[j]] == '1'){
				n1++;
				inv += n0;
			} else {
				n0++;
			}
		}
		double f = inv;
		f /= n0;
		f /= n1;
		score[i] = f;
	}
	int best = 0;
	for(int i = 0; i < n; i++){
		if(score[i] > score[best]) best = i;
	}
	cout << "Case #" << t << ": ";
	cout << (pord[best] +1) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T, P;
	cin >> T >> P;
	for(int t = 1; t <= T; t++) solve(t);
}



-----------------------------------------------------------











*/