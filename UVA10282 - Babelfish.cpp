#include "bits/stdc++.h"
using namespace std;

int main() {
	map<string, string> dic;
	map<string, string>::iterator iter;

	string str;
	while(getline(cin, str) && str != ""){
		stringstream ss(str);
		string key, value;
		ss >> value >> key;
		dic[key] = value;
	}

	// for(iter = dic.begin(); iter != dic.end(); iter++){
	// 	cout << iter->first << " " << iter->second << endl;
	// }

	
	while(getline(cin, str) && str != ""){
		if(dic.find(str) != dic.end())
			cout << dic[str] << endl;
		else
			cout << "eh" << endl;
	}

}
