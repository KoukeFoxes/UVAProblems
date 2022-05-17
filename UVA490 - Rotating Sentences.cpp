/*
UVA490 - Rotating Sentences
Content
在這個問題中你必須將數列文字往順時針方向旋轉90度。也就是說將原本由左到右，由上到下的句子輸出成由上到下，由右到左。

Input
輸入最多不會超過100列，每列最多不會超過100個字元。 合法的字元包括：換行，空白，所有的標點符號，數字，以及大小寫字母。（注意：Tabs並不算是合法字元。） 最後一列輸入必須垂直輸出在最左邊一行，輸入的第一列必須垂直輸出在最右邊一行。 請參考sample intput/output。

Sample Input #1
Rene Decartes once said,
"I think, therefore I am."

Sample Output #1
"R
Ie
 n
te
h 
iD
ne
kc
,a
 r
tt
he
es
r 
eo
fn
oc
re
e 
 s
Ia
 i
ad
m,
. 
"

*/


#include "/Users/doeshing/development/stdc++.h"
// #include "bits/stdc++.h"
using namespace std;

int main(){

    string line;
    vector<string> container;

    int max_len = 0;
    while(getline(cin, line)){
    //each line
      while(line.length() < max_len){
          line += " ";
      }
      max_len = line.length();
      container.push_back(line);
    }

    //print result

    for(int index = 0 ; index < max_len ; index++){
      for(int i = container.size() -1 ; i >=0 ; i--)
        cout << container[i][index];
      cout << endl;
    }

}
