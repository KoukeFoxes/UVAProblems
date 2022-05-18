/*
UVA 11321 - Sort! Sort!! and Sort!!!

先給兩個數 N、M，然後給 N 個數，要你照某些規則排序。利用每個數字除以 M 
的餘數由小到大排，若排序中相鄰的兩數為一奇一偶且兩數除以 M 的餘數相等，
則奇數要在偶數前面。若兩奇數除以 M 餘數大小相等，則原本數值較大的奇數排在前面。
同樣的，若兩偶數除以 M 餘數大小相等，則較小的偶數排在前面。

題目概要:
給你兩個整數 N (0<N<=10000), M (0<M<=10000)，你要依照某些規則排序N個整數。
先利用每個數字除以M的餘數由小到大排，若排序中比較的兩數為一奇一偶且兩數除以M 的餘數相等，則奇數要排在偶數前面。
若兩奇數除以M餘數大小相等，則原本數值較大的奇數排在前面。同樣的，若兩偶數除以M餘數大小相等，則較小的偶數排在前面。
至於負數的餘數計算和 C 語言裡的定義相同，即負數的餘數絕對不會大於零。例如 -100 MOD 3 = -1, -100 MOD 4 = 0 依此類推。

輸入說明:
輸入測資檔包含 20 筆的輸入測資。每組測資一開始包含兩個整數 N, M。
接下來的 N 行裡每一行只包含一個整數。
這些整數保證都可以被存在 32-bit 有號整數裡。
輸入以 N=0, M=0代表結束。

輸出說明:
對於每一組輸入請輸出 N+1 行整數。第一行為兩個整數 N, M。
接下來的 N 行都包含一個整數、及上述的數字按上述規則排列後的結果。
對於輸入測資尾端的兩個 0, 0 請也輸出兩個空白分隔的 0, 0。

CPE 難度：2/5

原文：
Hmm! Here you are asked to do a simple sorting. You will be given N numbers and a positive integer M. 
You will have to sort the N numbers in ascending order of their modulo M value. 
If there is a tie between an odd number and an even number (that is their modulo M value is the same) then 
the odd number will precede the even number. 
If there is a tie between two odd numbers (that is their modulo M value is the same) then the larger odd number 
will precede the smaller odd number and if there is a tie between two even numbers (that is their modulo M value is the same) 
then the smaller even number will precede the larger even number.
For remainder value of negative numbers follow the rule of C programming language: A negative number can never have modulus 
greater than zero. E.g. -100 MOD 3 = -1, -100 MOD 4 = 0, etc.

Input
The input file contains 20 sets of inputs. Each set starts with two integers N (0 < N ≤ 10000) and M (0 < M ≤ 10000) which 
denotes how many numbers are within this set. Each of the next N lines contains one number each. These numbers should all fit 
in 32-bit signed integer. Input is terminated by a line containing two zeroes.

Output
For each set of input produce N + 1 lines of outputs. The first line of each set contains the value of N and M. 
The next N lines contain N numbers, sorted according to the rules mentioned above. Print the last two zeroes of the 
input file in the output file also.

相關參考：
https://zerojudge.tw

*/

#include "/Users/doeshing/development/stdc++.h"

#define AND &&
#define OR ||

using namespace std;

// public variables
int N, M;

bool isOdd(int n) {
    return n % 2 == 1;
}

/* 筆記
N%M 小者前 大者後
餘數同 奇數前 偶數後
皆為奇 大奇前 小奇後
皆為偶 小偶前 大偶後
*/
bool custom_sort(int a, int b) {
    if(a%M == b%M){
        if(isOdd(a) AND !isOdd(b)) //a is odd and b is even
            return true;
        if(!isOdd(a) AND isOdd(b)) //a is even and b is odd
            return false;
        if(isOdd(a) AND isOdd(b)) //a and b are odd
            return a > b;
        if(!isOdd(a) AND !isOdd(b)) //a and b are even
            return a < b;
    }
    return a%M < b%M;
}

int main()
{
    cin >> N >> M;
    cout << N << " " << M << endl;
    while (N != 0 && M != 0){
        vector<int> container(N);
        //將測資輸入至container
        for(int &i : container) 
            cin >> i;
        //將container中的數字排序
        sort(container.begin(), container.end(), custom_sort);
        //將排序後的數字輸出
        for(int i : container) 
            cout << i << endl;
        cout << endl;
        cin >> N >> M; 
    }

}

