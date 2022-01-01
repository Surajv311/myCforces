/*


A. Déjà Vu
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A palindrome is a string that reads the same backward as forward. For example, the strings "z", "aaa", "aba", and "abccba" are palindromes, but "codeforces" and "ab" are not. You hate palindromes because they give you déjà vu.

There is a string s. You must insert exactly one character 'a' somewhere in s. If it is possible to create a string that is not a palindrome, you should find one example. Otherwise, you should report that it is impossible.

For example, suppose s= "cbabc". By inserting an 'a', you can create "acbabc", "cababc", "cbaabc", "cbabac", or "cbabca". However "cbaabc" is a palindrome, so you must output one of the other options.

Input
The first line contains a single integer t (1≤t≤104) — the number of test cases.

The only line of each test case contains a string s consisting of lowercase English letters.

The total length of all strings does not exceed 3⋅105.

Output
For each test case, if there is no solution, output "NO".

Otherwise, output "YES" followed by your constructed string of length |s|+1 on the next line. If there are multiple solutions, you may print any.

You can print each letter of "YES" and "NO" in any case (upper or lower).

Example
inputCopy
6
cbabc
ab
zza
ba
a
nutforajaroftuna
outputCopy
YES
cbabac
YES
aab
YES
zaza
YES
baa
NO
YES
nutforajarofatuna
Note
The first test case is described in the statement.

In the second test case, we can make either "aab" or "aba". But "aba" is a palindrome, so "aab" is the only correct answer.

In the third test case, "zaza" and "zzaa" are correct answers, but not "azza".

In the fourth test case, "baa" is the only correct answer.

In the fifth test case, we can only make "aa", which is a palindrome. So the answer is "NO".

In the sixth test case, "anutforajaroftuna" is a palindrome, but inserting 'a' elsewhere is valid.





A)

1504A - Déjà Vu
If s is the character 'a' repeated some number of times, there is no solution. Otherwise, I claim either 'a' + s or s + 'a' is a solution (or both).

Let's prove it. Assume for contradiction that 'a' + s and s + 'a' are both palindromes. Then the first and last characters of s are 'a'. Then the second and second to last characters of s are 'a'. Repeating this, we see that all characters of s are 'a', but we assumed we are not in this case. Therefore, the claim is true.

The solution is simply to check if 'a' + s and s + 'a' are palindromes and output the correct one. Complexity is O(n).


#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define pb push_back
#define endl "\n"

const int mod = 1e9 + 7;

bool checkPalindrome(string &s) {
	string rev = s;
	reverse(rev.begin(), rev.end());
	if (s == rev) {
		return true;
	}
	return false;
}


int32_t main()
{
	IOS

	int t;
	cin >> t;
	while (t--) {
		string s, s1, s2;
		cin >> s;
		s1 = 'a' + s;
		s2 = s + 'a';
		if (!checkPalindrome(s1)) {
			cout << "YES" << endl;
			cout << s1 << endl;
		} else if (!checkPalindrome(s2)) {
			cout << "YES" << endl;
			cout << s2 << endl;
		} else {
			cout << "NO" << endl;
		}
	}

    return 0;
}



---------------------------------------------------



B. Flip the Bits
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
There is a binary string a of length n. In one operation, you can select any prefix of a with an equal number of 0 and 1 symbols. Then all symbols in the prefix are inverted: each 0 becomes 1 and each 1 becomes 0.

For example, suppose a=0111010000.

In the first operation, we can select the prefix of length 8 since it has four 0's and four 1's: [01110100]00→[10001011]00.
In the second operation, we can select the prefix of length 2 since it has one 0 and one 1: [10]00101100→[01]00101100.
It is illegal to select the prefix of length 4 for the third operation, because it has three 0's and one 1.
Can you transform the string a into the string b using some finite number of operations (possibly, none)?

Input
The first line contains a single integer t (1≤t≤104) — the number of test cases.

The first line of each test case contains a single integer n (1≤n≤3⋅105) — the length of the strings a and b.

The following two lines contain strings a and b of length n, consisting of symbols 0 and 1.

The sum of n across all test cases does not exceed 3⋅105.

Output
For each test case, output "YES" if it is possible to transform a into b, or "NO" if it is impossible. You can print each letter in any case (upper or lower).

Example
inputCopy
5
10
0111010000
0100101100
4
0000
0000
3
001
000
12
010101010101
100110011010
6
000111
110100
outputCopy
YES
YES
NO
YES
NO
Note
The first test case is shown in the statement.

In the second test case, we transform a into b by using zero operations.

In the third test case, there is no legal operation, so it is impossible to transform a into b.

In the fourth test case, here is one such transformation:

Select the length 2 prefix to get 100101010101.
Select the length 12 prefix to get 011010101010.
Select the length 8 prefix to get 100101011010.
Select the length 4 prefix to get 011001011010.
Select the length 6 prefix to get 100110011010.
In the fifth test case, the only legal operation is to transform a into 111000. From there, the only legal operation is to return to the string we started with, so we cannot transform a into b.




Ans)

Let's call a prefix legal if it contains an equal number of 0 and 1 symbols. The key observation is that applying operations never changes which prefixes are legal. In fact, suppose we apply an operation to a prefix of length i, and consider a prefix of length j. We want to show that if j was legal before, it remains legal. And if it wasn't legal, it won't become legal.

If j<i, then all bits in the length j prefix are inverted. The numbers of 0's and 1's swap, so it cannot change whether they are equal, and hence it cannot change whether j is legal.
If j≥i, then i/2 of the 0 symbols become 1 and i/2 of the 1 symbols become 0. So the numbers of both symbols do not change, so it cannot change whether j is legal.
Using prefix sums, we can determine for each prefix whether it is legal.

Consider an index i. If i=n and an≠bn, then we must flip the length n prefix at some point. If i<n and ai=bi, ai+1≠bi+1, or ai≠bi, ai+1=bi+1, then we must flip the length i prefix at some point. If we flip precisely these prefixes in any order, it will transform a into b. So we should simply check that every prefix that must be flipped is legal.

Complexity is O(n).





#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define pb push_back
#define endl "\n"

const int mod = 1e9 + 7;


int32_t main()
{
	IOS

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s1, s2;
		cin >> s1 >> s2;
		vector<int> pref(n, 0);
		pref[0] = s1[0] == '0' ? -1 : 1;
		for (int i = 1; i < n; i++) {
			if (s1[i] == '0') {
				pref[i] = pref[i-1] - 1;
			} else {
				pref[i] = pref[i-1] + 1;
			}
		}
		int ok = 1;
		int flip = 0;
		for (int i = n - 1; i >= 0; i--) {
			int x = s1[i] - '0' + flip;
			x %= 2;
			int y = s2[i] - '0';
			if (x == y) {
				continue;
			}
			if (pref[i] == 0) {
				flip++;
			} else {
				ok = 0;
				break;
			}
		}
		if (ok) {
			cout << "YES";
		} else {
			cout << "NO";
		}
		cout << endl;
	}

    return 0;
}




---------------------------------------------



C. Balance the Bits
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
A sequence of brackets is called balanced if one can turn it into a valid math expression by adding characters '+' and '1'. For example, sequences '(())()', '()', and '(()(()))' are balanced, while ')(', '(()', and '(()))(' are not.

You are given a binary string s of length n. Construct two balanced bracket sequences a and b of length n such that for all 1≤i≤n:

if si=1, then ai=bi
if si=0, then ai≠bi
If it is impossible, you should report about it.

Input
The first line contains a single integer t (1≤t≤104) — the number of test cases.

The first line of each test case contains a single integer n (2≤n≤2⋅105, n is even).

The next line contains a string s of length n, consisting of characters 0 and 1.

The sum of n across all test cases does not exceed 2⋅105.

Output
If such two balanced bracked sequences exist, output "YES" on the first line, otherwise output "NO". You can print each letter in any case (upper or lower).

If the answer is "YES", output the balanced bracket sequences a and b satisfying the conditions on the next two lines.

If there are multiple solutions, you may print any.

Example
inputCopy
3
6
101101
10
1001101101
4
1100
outputCopy
YES
()()()
((()))
YES
()()((()))
(())()()()
NO
Note
In the first test case, a="()()()" and b="((()))". The characters are equal in positions 1, 3, 4, and 6, which are the exact same positions where si=1.

In the second test case, a="()()((()))" and b="(())()()()". The characters are equal in positions 1, 4, 5, 7, 8, 10, which are the exact same positions where si=1.

In the third test case, there is no solution.







Ans)


1504C - Balance the Bits
Any balanced bracket sequence must begin with '(' and end with ')'. Therefore, a and b must agree in the first and last positions, so we require s1=sn=1 or a solution doesn't exist.

The total number of open brackets in a and b must be n, which is even. Each 1 bit in s creates an even number of open brackets and each 0 bit creates an odd number of open brackets. Therefore, there must be an even number of 0 bits, or a solution doesn't exist. Note that the number of 1 bits also must be even.

Assuming these conditions hold, let's construct a solution. Suppose there are k positions where si=1. We will make the first k2 positions open in both a and b, and we will make the last k2 positions closed in both a and b. Then, the 0 bits in s will alternate between which string gets the open bracket.





#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define pb push_back
#define endl "\n"

const int mod = 1e9 + 7;

bool checkPalindrome(string &s) {
	string rev = s;
	reverse(rev.begin(), rev.end());
	if (s == rev) {
		return true;
	}
	return false;
}


int32_t main()
{
	IOS

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int zeroes = 0, ones = 0;
		int sum = 0;
		for (char ch : s) {
			zeroes += ch == '0';
			ones += ch == '1';
		}
		if (zeroes % 2 || ones % 2 || s[0] == '0' || s[n-1] == '0') {
			cout << "NO" << endl;
			continue;
		}
		string a = "", b = "";
		int suma = 0, sumb = 0;
		int ok = 1;
		int idx0 = 0, idx1 = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				if (idx0 % 2) {
					a += ')';
					b += '(';
					suma--;
					sumb++;
				} else {
					a += '(';
					b += ')';
					suma++;
					sumb--;
				}
				idx0++;
			} else {
				if (idx1 < ones / 2) {
					a += '(';
					b += '(';
					suma++;
					sumb++;
				} else {
					a += ')';
					b += ')';
					suma--;
					sumb--;
				}
				idx1++;
			}
			if (suma < 0 || sumb < 0) {
				ok = 0;
				break;
			}
		}
		if (!ok) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		cout << a << endl;
		cout << b << endl;
	}

    return 0;
}

































*/