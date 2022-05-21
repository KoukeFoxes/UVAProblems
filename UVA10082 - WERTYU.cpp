#include "bits/stdc++.h"
using namespace std;

int main() {
	string keyboard = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./'";
	string str;
	
	while(getline(cin , str)){
		for(int i = 0 ; i < str.size(); i++)
			if(isspace(str[i]))
				cout << " ";
			else
				cout << keyboard[keyboard.find(str[i]) - 1];
		cout << endl;
	}
}
