/*
UVA 10922 - 2 the 9s
Content
我們知道要怎麼確定一個整數是不是 9 的倍數－如果它每位數的總和是9的倍數，那它就是9的倍數。這種檢驗的方法其實是一種遞迴的方法，而且我們把這種方法遞迴的深度稱作 N 的 9-degree 。

你的工作就是，給你一個正整數N，判斷他是不是9的倍數，而且如果他是9的倍數你還需要判斷它的 9-degree。

Input
輸入含有多組測試資料。每組測試資料一列包含一個正數 N。

當 N=0 時代表輸入結束；輸入的數最大可以到1000位數。

Output
對於每一組測試資料，請輸出它是否是 9 的倍數及它的 9-degree。輸出格式請參考Sample Output。

Sample Input #1
999999999999999999999
9
9999999999999999999999999999998
837
0

Sample Output #1
999999999999999999999 is a multiple of 9 and has 9-degree 3.
9 is a multiple of 9 and has 9-degree 1.
9999999999999999999999999999998 is not a multiple of 9.
837 is a multiple of 9 and has 9-degree 2.


原文：
A well-known trick to know if an integer N is a multiple of nine is to compute the sum S of its digits.
If S is a multiple of nine, then so is N. This is a recursive test,
and the depth of the recursion needed to obtain the answer on N is called the 9-degree of N.
Your job is, given a positive number N, determine if it is a multiple of nine and, if it is, its 9-degree. Input
The input is a file such that each line contains a positive number. A line containing the number 0 is the end of the input.
The given numbers can contain up to 1000 digits.
Output
The output of the program shall indicate, for each input number, if it is a multiple of nine, and in case it is,
the value of its nine-degree. See the sample output for an example of the expected formatting of the output.

Sample Input
999999999999999999999
9
9999999999999999999999999999998
0

Sample Output
999999999999999999999 is a multiple of 9 and has 9-degree 3.
9 is a multiple of 9 and has 9-degree 1.
9999999999999999999999999999998 is not a multiple of 9.

相關參考：
https://zerojudge.tw/ShowProblem?problemid=d672
*/

#include "/Users/doeshing/development/stdc++.h"
// #include "bits/stdc++.h"
#define AND &&
#define OR ||

using namespace std;

int calc_degree(string n)
{
    // cout << n << " ";
    int degree = 0;
    int sum_int = stoi(n);

    do
    {   

        if(sum_int == 9){
            degree += 1;

            return degree;
        }else if (sum_int % 9 == 0){
            degree++;
        }

        sum_int = 0;
        for(int i : n)
            sum_int += i - '0';

        n = to_string(sum_int);
        
    } while (sum_int % 9 == 0);

    return degree;
}

int main()
{
    string N;
    while (1)
    {

        cin >> N;
        if (N == "0")
            break;

        long long int sum = 0;

        for (char c : N)
            sum += c - '0';

        bool is9s = sum % 9 == 0;
        int degree = calc_degree(to_string(sum));

        if (is9s)
        {
            cout << N << " is a multiple of 9 and has 9-degree " << degree <<"." << endl;
        }
        else
        {
            cout << N << " is not a multiple of 9." << endl;
        }
    }
}
