/*
UVA10057 A mid-summer night’s dream

尋找中位數進階版，以及符合中位數總數、符合中位數條件。
題目概要：

假如數字為X1、X2、X3...，那麼必須找到一個A，使得( |X1-A| + |X2-A| + |X3-A| + ... + |Xn-A|)為最小。

解題方向：

每個資料的第一個數字為有多少資料需要被處理(cases)，接下來就是資料(X1、X2 ... Xn)。

1. 找出中位數。

2. 計算有幾個和中位數一樣的數字。資料(cases)是偶數個時中位數有2個、資料是奇數個時中位數有1個。

3. 找出可能有幾種最小值(包含不在所輸入的資料裡面)，資料為奇數個時答案為1，資料為偶數個時答案為2個中位數相減加1。

output解說
10 2 1
2 2 1
中位數最小值、符合中位數條件總數、符合中位數條件

原文：
...

相關參考：
https://zerojudge.tw/

*/

#include "/Users/doeshing/development/stdc++.h"
// #include "bits/stdc++.h"
#define AND &&
#define OR ||

using namespace std;
// public variables

int main()
{
    int N;
    while(cin >> N){

        vector<int> v(N);
        for(int &i : v)
            cin >> i;
        
        int number = 0;
        
        switch(N%2){
            case 0: //length is even
                cout << v[N/2 -1] << " ";

                for(int i : v)
                    number += (i==v[N/2 -1]) ? 1 : 0;
                cout << number << " ";

                cout << abs(v[N/2 -1] - v[N/2]) + 1 << endl;
                    
                break;      
            case 1: //length is odd
                cout << v[(N-1)/2] << " ";

                for(int i : v)
                    number += (i==v[(N-1)/2]) ? 1 : 0;
                cout << number << " ";

                cout << abs(v[(N-1)/2] - v[(N-1)/2 + 1]) + 1 << endl;

                break; 
        }

    }

}
