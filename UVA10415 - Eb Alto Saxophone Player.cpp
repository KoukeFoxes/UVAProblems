/*
UVA10268 498-bis
給薩克斯風的各種音調的指法，及由這些音調組成的歌曲 ( 假設一個手指頭只能按特定一個按鍵，且不同手指控制不同按鈕 )，求每根手指需要按下的次數，如果某一按鍵在下一音符時不會用到，那麼就會放開，否則就是維持按著的情況。

Input： 第一個整數 T，表示有 T 組測資，後面 T 行每行為一首歌曲，歌曲可能為空。

Output： 對於每組測資，請輸出 10 個數字，代表每個手指的按下次數，數字用空格分隔。

原文：
...

Input
The first line of the input is a single integer t (1 ≤ t ≤ 1000), indicating the number of test cases. For each case, there is only one line containing the song. 
The only allowed characters are {‘c’,‘d’,‘e’,‘f’,‘g’,‘a’,‘b’, ‘C’,‘D’,‘E’,‘F’,‘G’,‘A’,‘B’}. There are at most 200 notes in a song, and the song maybe empty.
Output
For each test case, print 10 numbers indicating the number of presses for each finger. Numbers are separated by a single space.

Sample Input
3
cdefgab
BAGFEDC
CbCaDCbCbCCbCbabCCbCbabae

Sample Output
0111001111 1111001110 1 8 10 2 0 0 2 2 1 0

相關參考：
https://zerojudge.tw/
*/

// #include "/Users/doeshing/development/stdc++.h"
#include "bits/stdc++.h"

using namespace std;

// public variables
map<char, string> map_char_to_string{
    {'c', "0111001111"},
    {'d', "0111001110"},
    {'e', "0111001100"},
    {'f', "0111001000"},
    {'g', "0111000000"},
    {'a', "0110000000"},
    {'b', "0100000000"},
    {'C', "0010000000"},
    {'D', "1111001110"},
    {'E', "1111001100"},
    {'F', "1111001000"},
    {'G', "1111000000"},
    {'A', "1110000000"},
    {'B', "1100000000"}};

int press_count[10] = {0};
string last_state = "0000000000";

void compute(string str1) //輸入現在目前的情況
{
    for (int i = 0; i < str1.length(); i++)
    {
        press_count[i] += (str1[i] ^ last_state[i]) & str1[i]; //判斷有無變化在與結束情況判斷是按住還是放開
    }
    last_state = str1;
}

int main()
{
    int t;
    cin >> t;
	cin.ignore();
    while (t--)
    {
        string note;
		last_state = "0000000000";
        getline(cin, note);
        for (char c : note)
        {
            compute(map_char_to_string[c]);
        }

        for (int i = 0; i < 10; i++)
        {
            cout << press_count[i] << " ";
        }
        cout << endl;

		for(int &i: press_count)
			i = 0;
		//clear
    }
}
