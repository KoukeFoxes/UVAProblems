/*
UVA10162 - Last Digit

Give you a integer number N (1 ≤ n ≤ 2 ∗ 10100). Please compute
S = 11 + 22 + 33 + . . . + N
N
Give the last digit of S to me.

Input
Input file consists of several N’s, each N a line. It is ended with N = 0.

Output
For each N give a line containing only one digit, which is the last digit of S.

Sample Input
1
2
3
0

Sample Output
1
5
2

*/

#include "bits/stdc++.h"
using namespace std;

long long int table[100] = {0};

int NpowerOfN(int n){
	int nn = 1;
	for(int i = 1; i <= n ;i++){
		nn *=n;
		nn %= 10;
	}
	return nn;
}


int sumOfN(int n){
	int temp = 0;
	for(int i = 1 ; i <= n ; i++){
		temp += NpowerOfN(i);
		temp %= 10;
	}
	return temp;
}


int main() {
	string str;

	//build table
	for(int i = 0 ; i < 100 ; i++)
		table[i] = sumOfN(i+1);

	cout << endl;
	while(cin >> str && str != "0"){
	
		int index = str[str.size()-1] - '0';
		if(str.size() > 1)
			index += (int)(str[str.size()-2] - '0')*10;

		cout << table[index-1] << endl;
	}
}
