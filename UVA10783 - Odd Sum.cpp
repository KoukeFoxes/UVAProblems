/*
10783 - Odd Sum

原文：
Given a range [a, b], you are to find the summation of all the odd integers in this range. For example,
the summation of all the odd integers in the range [3,9] is 3+5+7+9 = 24. Input
There can be at multiple test cases. The first line of input gives you the number of test cases, T (1≤T ≤100). ThenTtestcasesfollow. Eachtestcaseconsistsof2integersaandb(0≤a≤b≤100) in two separate lines.
Output
For each test case you are to print one line of output – the serial number of the test case followed by the summation of the odd integers in the range [a, b].

Sample Input
2 
1 
5 
3 
5
Sample Output
Case 1: 9
Case 2: 8

相關參考：
https://zerojudge.tw/
*/

#include "/Users/doeshing/development/stdc++.h"
// #include "bits/stdc++.h"
#define AND &&
#define OR ||

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int a, b;
        cin >> a >> b;
        int sum = 0;
        for(int i = a; i <= b; i++){
            if(i % 2 == 1) sum += i;
        }
        cout << "Case " << T+1 << ": " << sum << endl;
    }
}
