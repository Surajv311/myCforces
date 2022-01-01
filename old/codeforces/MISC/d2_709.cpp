/*



A...done!

B)
B. Restore Modulo
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
For the first place at the competition, Alex won many arrays of integers and was assured that these arrays are very expensive. After the award ceremony Alex decided to sell them. There is a rule in arrays pawnshop: you can sell array only if it can be compressed to a generator.

This generator takes four non-negative numbers n, m, c, s. n and m must be positive, s non-negative and for c it must be true that 0≤c<m. The array a of length n is created according to the following rules:

a1=smodm, here xmody denotes remainder of the division of x by y;
ai=(ai−1+c)modm for all i such that 1<i≤n.
For example, if n=5, m=7, c=4, and s=10, then a=[3,0,4,1,5].

Price of such an array is the value of m in this generator.

Alex has a question: how much money he can get for each of the arrays. Please, help him to understand for every array whether there exist four numbers n, m, c, s that generate this array. If yes, then maximize m.

Input
The first line contains a single integer t (1≤t≤105) — the number of arrays.

The first line of array description contains a single integer n (1≤n≤105) — the size of this array.

The second line of array description contains n integers a1,a2,…,an (0≤ai≤109 ) — elements of the array.

It is guaranteed that the sum of array sizes does not exceed 105.

Output
For every array print:

−1, if there are no such four numbers that generate this array;
0, if m can be arbitrary large;
the maximum value m and any appropriate c (0≤c<m) in other cases.
Example
inputCopy
6
6
1 9 17 6 14 3
3
4 2 2
3
7 3 4
3
2 2 4
5
0 1000000000 0 1000000000 0
2
1 1
outputCopy
19 8
-1
-1
-1
2000000000 1000000000
0



ANS: [ Editorial not out yet :-( ]


























































































*/