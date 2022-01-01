/*

PALPALS - Editorial
PROBLEM:
You are given a string SS (consisting of lowercase Latin letters only) and you can rearrange the letters of this string in any way. You have to find out if it is possible to rearrange the letters of string SS to obtain a Palpal string.

A string SS (consisting of lowercase Latin letters only) is called a Palpal string if it can be divided into contiguous substrings such that:

Every Character of the string is present in one and only one substring.
Every Substring is a palindrome of length \ge 2length≥2
EXPLANATION:
Our task is to divide the string into contiguous substring of length greater than or equal to two, such that every substring is a palindrome.

If there is a palindromic substring and we delete the leftmost and the rightmost character from this substring, the resulting substring will remain palindromic. It means to create a palindromic substring of length xx, we need to create a palindromic substring of a smaller length too. Hence the most optimal way to divide the string is in the smallest length possible which is 22.

Dividing the string SS into substrings of length 22 will also increase palindromic substrings which will be useful when we need to insert the odd character in these substrings as explained later.

Now we will try to form palindromic substrings of length 22. We can see that, if any letter is present an odd number of times in this string then a single character of this letter won’t be able to form a palindromic substring of length 22. But all such characters can be inserted in between substring of length 22 since the addition of this character won’t make the substring non-palindromic. It means that there should be enough substrings such that all such characters could be inserted.

Let us suppose the count of such characters is yy. Now if the number of substrings of length 22 is more than or equal to yy, then it is always possible to insert such characters in between the substrings making the substring still palindromic. If such conditions satisfy then it is possible to rearrange the letters of string SS to obtain a Palpal string.

TIME COMPLEXITY:
O(|S|)O(∣S∣) per test case.

 while(T--)
    {
        string s; cin >> s;
        int single = 0, pair = 0;
        vector<int> freq(26);
        for(int i = 0; i < (int)s.size(); i++)
            freq[s[i] - 'a']++;
        for(int i = 0; i < 26; i++)
        {
            pair += freq[i] / 2;
            single += freq[i] % 2;
        }
        if(single <= pair)
            cout << "yeS";
        else
            cout << "No";
        cout << "\n";
    }

--------------------------------------------------------------------------------------------------------

PROBLEM
Given an array AA containing NN integers, find the maximum value of a*b+a-ba∗b+a−b where a, ba,b are distinct elements of array.

QUICK EXPLANATION
Rewriting a*b+a-b = (a-1)*(b+1) +1a∗b+a−b=(a−1)∗(b+1)+1, we can fix aa and see that for bb, we only need to consider either minimum or maximum of all elements of array excluding element aa.
It can be done by computing the minimum, second minimum, maximum and second maximum element of array, or just by simply sorting the array.
EXPLANATION
As mentioned in quick explanation, we can rewrite the expression.
a*b+a-b = a*(b+1) - (b+1)+1 = (a-1)*(b+1)a∗b+a−b=a∗(b+1)−(b+1)+1=(a−1)∗(b+1)

Hence, we need to maximise (a-1)*(b+1)(a−1)∗(b+1) where aa and bb are two distinct elements of array.

Now, a naive way to do this would be to try all pairs of numbers, and taking maximum of value resulted by any pair.

Here, if the elements of array were positive, Just taking the last two elements would have been sufficient. But there are negative elements too, and the product of two negative element can also lead to a higher positive product.

So we try to fix aa. We can see that once aa is fixed, it is optimal to choose bb which would maximise value of (a-1)*(b+1)+1(a−1)∗(b+1)+1. So

if (a-1) > 0(a−1)>0, we’d aim to select the largest element in array, so that the value of b+1b+1 can be maximised, therefore (a-1)*(b+1)+1(a−1)∗(b+1)+1 is maximised.
if (a-1) < 0(a−1)<0, we’d aim to select the smallest element in array, so that the value of b+1b+1 can be minimised, therefore (a-1)*(b+1)+1(a−1)∗(b+1)+1 is maximised.
if (a-1) < 0(a−1)<0, then answer is atleast zero.
Hence, all we need to do is to sort the array, fix aa to be each element one by one, and choose most optimum bb. Taking maximum over all these candidates gives the maximum value of a*b+a-ba∗b+a−b

Bonus
Write a solution for above problem which checks minimum number of pairs.

TIME COMPLEXITY
The time complexity can be O(N)O(N) or O(N*log(N))O(N∗log(N)) depending upon implementation, per test case.
The memory complexity is O(N)O(N) per test case, can be reduced to O(1)O(1).

int main()
{
    int t; cin >> t;
    vector<long long> v;
    while(t--){
        v.clear();
        int n; cin >> n;
        for(int i = 0; i < n; i++){
            int x; cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        long long ans = LLONG_MIN;
        ans = max(ans, (v[0] + 1) * (v[1] - 1) + 1);
        ans = max(ans, (v[n - 2] + 1) * (v[n - 1] - 1) + 1);
        cout << ans << endl;
    }
}
*/
--------------------------------------------------------------------------------------------------

/*
april long learnings...

For any dice,
if 5 faces are visible, then the values should be 6, 5, 4, 3, 2.
if 4 faces are visible, then the values should be 6, 5, 4, 3.
if 3 faces are visible, then the values should be 6, 5, 4.
if 2 faces are visible, then the values should be 6, 5.
.........
*/