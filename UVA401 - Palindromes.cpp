/*
UVA401 - Palindromes

迴文字串是一串數字或字母，從左到右讀取和從右到左讀取相同。
例如，"ABCDEDCBA"是迴文字串。
鏡像字串是一種字串，當該字串的每個元素更改為鏡像(如果它具有鏡像)並且從右到左讀取該字串時，其結果與從左到右讀取原始字串相同。
例如，"3AIAE"是鏡像字符串，因為"A"的鏡像和"I"的鏡像是他們自己，而"3"和"E"為彼此的鏡像。
鏡像迴文是指符合迴文字串標準和鏡像字串標準的字串。
例如，"ATOYOTA"是一個鏡像迴文，"A"、"T"、"O"、"Y"為彼此的鏡像。
該字串從左到右讀取和從右到左讀取相同。
並且每個字元都鏡像替換後從右到左讀取結果，與從左到右讀取原始字串相同。

以下為有效字元鏡像對應表：

字元	鏡像	字元	鏡像	字元	鏡像	字元	鏡像
A	A	J	L	S	2	1	1
B	 	K	 	T	T	2	S
C	 	L	J	U	U	3	E
D	 	M	M	V	V	4	 
E	3	N	 	W	W	5	Z
F	 	O	O	X	X	6	 
G	 	P	 	Y	Y	7	 
H	H	Q	 	Z	5	8	8
I	I	R	 	0	0	9	 
 

請注意，"0"(零)和"O"(字母)被視為相同字符，因此只有字母"O"是有效字符。

*/

#include "/Users/doeshing/development/stdc++.h"
// #include "bits/stdc++.h"
using namespace std;

map<char, char> mirror{
  {'A', 'A'},
  {'E', '3'},
  {'H', 'H'},
  {'I', 'I'},
  {'J', 'L'},
  {'L', 'J'},
  {'M', 'M'},
  {'O', 'O'},
  {'S', '2'},
  {'T', 'T'},
  {'U', 'U'},
  {'V', 'V'},
  {'W', 'W'},
  {'X', 'X'},
  {'Y', 'Y'},
  {'Z', '5'},
  {'1', '1'},
  {'2', 'S'},
  {'3', 'E'},
  {'5', 'Z'},
  {'8', '8'}
};

bool isPalindrome(string str){
  bool isPalindrome = true;
  for(int i=0; i < str.length(); i++){
    if(str[i] != str[str.length()-1-i]){
      isPalindrome = false;
      break;
    }
  }
  return isPalindrome;
}

bool isMirrored(string str){
  bool isMirrored = true;
  for(int i = 0; i < str.length(); i++){
    if(str[i] != mirror[str[str.length()-1-i]]){
      isMirrored = false;
      break;
    }
  }
  return isMirrored;
}

int main(){
  string str;
  while(getline(cin, str)){
    if(isPalindrome(str) && isMirrored(str))
      cout << str << " -- is a mirrored palindrome." << endl;
    else if(isPalindrome(str) && !isMirrored(str))
      cout << str << " -- is a regular palindrome." << endl;
    else if(!isPalindrome(str) && isMirrored(str))
      cout << str << " -- is a mirrored string." << endl;
    else
      cout << str << " -- is not a palindrome. " << endl;
  }
}
