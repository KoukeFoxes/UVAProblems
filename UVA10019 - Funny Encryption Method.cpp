/*
UVA10019 - Funny Encryption Method

10019 Funny Encryption Method
A student from ITESM Campus Monterrey plays with a new encryption method for numbers. These
method consist of the following steps:
Steps : Example
1. Read the number N to encrypt : M = 265
2. Interpret N as a decimal number : X1 = 265 (decimal)
3. Convert the decimal interpretation of N to its binary representation : X1 = 100001001 (binary)
4. Let b1 be equal to the number of 1’s in this binary representation : b1 = 3
5. Interpret N as a Hexadecimal number : X2 = 265 (hexadecimal)
6. Convert the hexadecimal interpretation of N to its binary representation : X2 = 1001100101
7. Let b2 be equal to the number of 1’s in the last binary representation : b2 = 5
8. The encryption is the result of M xor (b1 ∗ b2) : 265 xor (3*5) = 262
This student failed Computational Organization, thats why this student asked the judges of ITESM
Campus Monterrey internal ACM programming Contest to ask for the numbers of 1’s bits of this two
representations so that he can continue playing.
You have to write a program that read a Number and give as output the number b1 and b2
Input
The first line will contain a number N which is the number of cases that you have to process. Each
of the following N Lines (0 < N ≤ 1000) will contain the number M (0 < M ≤ 9999, in decimal
representation) which is the number the student wants to encrypt.
Output
You will have to output N lines, each containing the number b1 and b2 in that order, separated by one
space corresponding to that lines number to crypt


Content
一位來自墨西哥蒙特瑞技術研究學院(ITESM Campus Monterrey)的學生想發表一種新的數值加密演算法。
演算法步驟如下：

1. 讀入一個整數N，N為欲加密的數字：N = 265
2. 將N當作十進位的數值：X1 = 265(decimal)
3. 把X1由十進制轉為二進制：X1 = 100001001(binary)
4. 計算二進制的X1有幾個1：b1 = 3
5. 把N當作十六進位數值：X2 = 265(hexadecimal)
6. 把X2由十六進制轉為二進制：X2 = 1001100101(binary)
7. 計算二進制的X2有幾個1：b2 = 5
8. 最後的編碼為N xor (b1*b2)：265 xor (3*5) = 262

這位學生並未通過這次的計算機組識考試，所以他請求校方在ACM的試題上出一題計算共有幾個位元1的題目，好讓他能順利發表他的數值加密演算法。
你必須寫一個程式能讀入一個整數，然後輸出該整數的b1, b2值。

Input
第一行包含一個數字T (0 < T ≤ 1000)，代表有幾組測資。
接下來的T行，每行包含一個數字N (decimal)(0 < N ≤ 9999)，N代表學生要加密的數字。

Output
對於每組測資，輸出數字b1和b2，b1和b2請用空白分隔。

Sample Input #1
3
265
111
1234
Sample Output #1
3 5
6 3
5 5

*/

#include "bits/stdc++.h"
using namespace std;

map<char, string> hex2bin{
    {'0', "0000"},
    {'1', "0001"},
    {'2', "0010"},
    {'3', "0011"},
    {'4', "0100"},
    {'5', "0101"},
    {'6', "0110"},
    {'7', "0111"},
    {'8', "1000"},
    {'9', "1001"},
    {'A', "1010"},
    {'B', "1011"},
    {'C', "1100"},
    {'D', "1101"},
    {'E', "1110"},
    {'F', "1111"},
};

int main(){
    int N;
    cin >> N;
    while(N--){
        int num;
        cin >> num;
        
        //dec to bin
        // string bin = bitset<16>(num).to_string();
        int X1_ = num;
        string X1 = "";
        int a = 0, b = 0;
        while(X1_){
            X1 = to_string((X1_&1)) + X1;
            X1_ >>= 1;
        }

		for(int i = 0; i < X1.size(); i++){
            if(X1[i] == '1') a++;
        }
		
        string X2 = "";
        int X2_ = num;

		for(char c: to_string(X2_)){
			X2 = hex2bin[c] + X2;
		}

		cout << X2 << endl;

        for(int i = 0; i < X2.size(); i++){
            if(X2[i] == '1') b++;
        }
        cout << a << " " << b << endl;


    }
}
