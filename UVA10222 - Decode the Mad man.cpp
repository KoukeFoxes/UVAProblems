#include "bits/stdc++.h"

using namespace std;

int main2() {
  string keyboard = "~1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
  string input_str;
  getline(cin,input_str);
  for(auto temp : input_str){
	  if(isspace(temp)){
		  cout << " ";
		  continue;
	  }
	  cout << keyboard[keyboard.find(tolower(temp)) - 2];
  }
} 

int main(){
	string keyboard = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./'";
	string input;
	getline(cin,input);
	for(int i = 0 ; i < input.length() ; i++){
		if(isspace(input[i]))
			cout << " ";
		else
			cout << keyboard[keyboard.find(tolower(input[i])) - 2];
	}
}
