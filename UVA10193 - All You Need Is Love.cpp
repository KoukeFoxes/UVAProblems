/*
UVA10193 - All You Need Is Love

Content
IBM (International Beautiful Machines)公司發明了一種小玩意兒叫做「愛的算命機」。這台機器會回答你是否非常渴望愛情。這機器運作的情形是：請你輸入一僅含0和1的字串（稱為S），機器自己則定義一僅含0和1的字串（稱為L，Love的意思）。然後機器不斷的用S去減L（當然是2進位的減法），如果最後可以得到S=L，代表S是用Love做成的。如果最後L>S，代表S不是用Love做成的。

舉例說明：假設S="11011"，L="11"。如果我們不斷的從S減去L，我們可以得到：11011、11000、10101、10010、1111、1100、1001、110、11。所以我們得到L了，也就是S是用Love做的。由於愛的算命機的某些限制，字串不可以有以0為開頭的，也就是說"0010101"、"01110101"、"011111"這些字串都是不合法的。另外，只有一個位元的字串也是不合法的。

Input
輸入的第一列有一個整數N（N<10000），代表以下有幾組測試資料。每組測試資料2列，代表S1和S2字串，其長度都不會超過30個字元。你可以假設所有的字串都是合法的。
Output
對每一組測試資料輸出以下其中之一：

Pair #p: All you need is love! Pair #p: Love is not all you need!
在這裡p代表這是第幾組測試資料。如果S1和S2至少可以找到一個合法的L，使得S1和S2都可以用Love做成，則輸出第一種訊息。否則，請輸出第二種訊息。請參考Sample Output。

Sample Input #1
5
11011
11000
11011
11001
111111
100
1000000000
110
1010
100

Sample Output #1
Pair #1: All you need is love!
Pair #2: Love is not all you need!
Pair #3: Love is not all you need!
Pair #4: All you need is love!
Pair #5: All you need is love!

*/

#include "bits/stdc++.h"
using namespace std;

int GCD(int a, int b){
	return a ? GCD(b%a,a) : b;
}

int main() {
	int N;
	cin >> N;
	cin.ignore();
	for(int cases = 1 ; cases <= N ; cases++){
		string S1, S2;
		getline(cin , S1);
		getline(cin , S2);

		int a1 = 0, a2 = 0;

		for(int i = S1.size() -1; i >= 0; i--){
			a1 += (S1[i] - '0') * pow(2,S1.size() -1 -i);
		}

		for(int i = S2.size() -1; i >= 0; i--){
			a2 += (S2[i] - '0') * pow(2,S2.size() -1 -i);
		}

		if(GCD(a1, a2) == 1)
			cout << "Pair #"<< cases << ": Love is not all you need!" << endl;
		else
			cout << "Pair #"<< cases << ": All you need is love!" << endl;
	}
	

}
