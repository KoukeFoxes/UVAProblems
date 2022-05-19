/*
UVA10008 - What's Cryptanalysis

原文：
Description

Cryptanalysis is the process of breaking someone else's cryptographic writing. This sometimes involves some kind of statistical analysis of a passage of (encrypted) text. Your task is to write a program which performs a simple analysis of a given text.

Input

The first line of input contains a single positive decimal integer n. This is the number of lines which follow in the input. The next n lines will contain zero or more characters (possibly including whitespace). This is the text which must be analyzed.

Output

Each line of output contains a single uppercase letter, followed by a single space, then followed by a positive decimal integer. The integer indicates how many times the corresponding letter appears in the input text. Upper and lower case letters in the input are to be considered the same. No other characters must be counted. The output must be sorted in descending count order; that is, the most frequent letter is on the first output line, and the last line of output indicates the least frequent letter. If two letters have the same frequency, then the letter which comes first in the alphabet must appear first in the output. If a letter does not appear in the text, then that letter must not appear in the output.



Content
密碼翻譯（cryptanalysis）是指把某個人寫的密文（cryptographic writing）加以分解。這個程序通常會對密文訊息做統計分析。你的任務就是寫一個程式來對密文作簡單的分析。

Input
輸入的第1列有一個正整數n，代表以下有多少列需要作分析的密文。 接下來的n列，每列含有0或多個字元（可能包含空白字元）

Output
每列包含一個大寫字元（A~Z）和一個正整數。這個正整數代表該字元在輸入中出現的次數。輸入中大小寫（例如：A及a）視為相同的字元。輸出時請按照字元出現的次數由大到小排列，如果有2個以上的字元出現次數相同的話，則按照字元的大小（例如：A在H之前）由小到大排列。 請注意：如果某一字元未出現在輸入中，那他也不應出現在輸出中。

Sample Input #1
3
This is a test.
Count me 1 2 3 4 5.
Wow!!!! Is this question easy?

Sample Output #1
S 7
T 6
I 5
E 4
O 3
A 2
H 2
N 2
U 2
W 2
C 1
M 1
Q 1
Y 1

*/

#include "/Users/doeshing/development/stdc++.h"
// #include "bits/stdc++.h"
using namespace std;

int main(){
    int count;
    cin >> count;
    cin.ignore();
    char c;
    string str;
    int num['Z'+1] = {0};

    while(count--){
        getline(cin, str);

        for(char c: str)
            num[toupper(c)]++;
    }

    int max = 0;
    for(int i : num)
        max = max > i ? max : i;


    for(int i = max; i > 0; i--){
        for(int j = 'A'; j <= 'Z'; j++){
            if(num[j] == i){
                cout << (char)j << " " << i << endl;
            }
        }
    }
}
