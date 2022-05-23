#include "bits/stdc++.h"
using namespace std;

// 1：B、F、P、V
// 2：C、G、J、K、Q、S、X、Z
// 3：D、T
// 4：L
// 5：M、N
// 6：R

string check(char c) {
  switch (c) {
  case 'B':
  case 'F':
  case 'P':
  case 'V':
    return "1";

  case 'C':
  case 'G':
  case 'J':
  case 'K':
  case 'Q':
  case 'S':
  case 'X':
  case 'Z':
    return "2";

  case 'D':
  case 'T':
    return "3";

  case 'L':
    return "4";

  case 'M':
  case 'N':
    return "5";

  case 'R':
    return "6";

  default:
	  return "";
	  
  }
}

int main() {
  string str;
  while (getline(cin, str)) {
    string temp = "";

    for (int i = 0; i < str.size(); i++) {
		
		temp += check(str[i]);
		
		// check if there are cycle
		int move = 0;
		for (int j = 1; (i + j) < str.size() && check(str[i + j]) == check(str[i]); j++, move++);

		i += move;
    }
	cout << temp << endl;
  }
}
