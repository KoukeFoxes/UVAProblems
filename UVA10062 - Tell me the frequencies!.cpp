/*
UVA10062 - Tell me the frequencies!

給你一列文字，請你找出各字元出現的次數。

Input
每筆測試資料一列。每列最大長度為1000。

Output
對每一列輸入，請輸出各字元的ASCII值及其出現的次數。請根據出現的次數由小到大輸出。如果有2個以上的字元有相同的次數，則ASCII值較大的先輸出。 測試資料間請空一列，參考Sample Output

Sample Input #1
AAABBC
122333

Sample Output #1
67 1
66 2
65 3

49 1
50 2
51 3

原文：
Given a line of text you will have to find out the frequencies of the ASCII characters present in it. 
The given lines will contain none of the first 32 or last 128 ASCII characters. Of course lines may end with \n and \r but always keep t
hose out of consideration.

Input:
Several lines of text are given as input. Each line of text is considered as a single input. Maximum length of each line is 1000.

Output:
Print the ASCII value of the ASCII characters which are present and their frequency according to the given format below. 
A blank line should separate each set of output. Print the ASCII characters in the ascending order of their frequencies. 
If two characters are present the same time print the information of the ASCII character with higher ASCII value first. 
Input is terminated by end of file.

相關參考：
https://zerojudge.tw/ShowProblem?problemid=c012

*/

#include "/Users/doeshing/development/stdc++.h"
// #include "bits/stdc++.h"
// #define AND &&
// #define OR ||

using namespace std;
// public variables

int main()
{
    string N;
    while(getline(cin, N)){
        
        int arr['z'+1] = {0};
        int max = 0;

        for(char c : N){
            arr[c]++;
            max = arr[c] > max ? arr[c] : max;
        }
            
        for(int min = 1; min <= max; min++){
            for(char c = 'z'; c >= '0'; c--)
                if(arr[c] == min)
                    cout << (int)c << " " << arr[c] << endl;
        }

    }
    
}
