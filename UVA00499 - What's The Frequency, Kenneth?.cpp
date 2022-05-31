#include"bits/stdc++.h"
using namespace std;

int main()
{
    string str;
	
	while(getline(cin, str) && str != ""){
		int counter['z'+1] = {};
		int maxCounter = -1;
		for(char c : str){	
			if(isspace(c) || (c < 'A' || (c > 'Z' && c < 'a') && c > 'Z'))
				continue;
			counter[c]++;
			maxCounter = max(maxCounter, counter[c]);
		}

		for(char i = 'A' ; i <= 'z'; i++){
			if(counter[i] == maxCounter)
				cout << i;
		}

		cout << " " << maxCounter << endl;
	}
	
}

