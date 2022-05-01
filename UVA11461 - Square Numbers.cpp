/*
UVA11461 - Square Numbers

題目大意：
給定兩個整數 a, b，找到 a 和 b 之間的完全平方數個數。

解題過程：
1. 計算 a 及 b 之平方數，並相減算出其個數
（需考慮 a 本身是否為完全平方數，所以用 ceil()計算）



原文：
A square number is an integer number whose square root is also an integer. For example 1, 4, 81 are some square numbers. 
Given two numbers a and b you will have to find out how many square numbers are there between a and b (inclusive).
Input
The input file contains at most 201 lines of inputs. Each line contains two integers a and b (0 < a ≤ b ≤ 100000). 
Input is terminated by a line containing two zeroes. This line should not be processed.
Output
For each line of input produce one line of output. This line contains an integer which denotes how many square numbers are there 
between a and b (inclusive).

Sample Input:
1 4 
1 10
0 0

Sample Output:
2 
3

相關參考：
https://zerojudge.tw

*/

#include "/Users/doeshing/development/stdc++.h"

#define AND &&
#define OR ||

using namespace std;

int main(){

    int a, b;
    
    while(cin >> a >> b AND (a!= 0 OR  b != 0)){
        
        a = int(sqrt(a));
        b = int(sqrt(b));

        cout << abs(b - a) + 1 << endl;
    }
}
