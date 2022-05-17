/*
UVA10252 - Common Permutation
Content
給定兩個由小寫字母組成的字串a和b。

印出最長的小寫字串x，使得x經過重新排列後為a的子序列，且x經過重新排列後為b的子序列。

Input
輸入包含多行輸入。

連續的兩行為一組，第一行為字串a，第二行為字串b

1~2行為一組輸入，3~4行為一組輸入，依此類推。

每個字串最多包涵1000個小寫字母。

Output
對於每組輸入，輸出本題要求a和b的x

如果有多組符合的x

請印出字母順序由小到大排列的那一個。

Sample Input #1
pretty
women
walking
down
the
street

Sample Output #1
e
nw
et

*/

#include "/Users/doeshing/development/stdc++.h"
// #include "bits/stdc++.h"
using namespace std;

int main()
{

  string input1, input2;
  while (getline(cin, input1))
  {
    
    getline(cin, input2);

    int length = (input1.length() > input2.length()) ? input1.length() : input2.length();

    int same1['z' + 1] = {0};
    int same2['z' + 1] = {0};

    for (char c : input1)
      same1[c]++;
    for (char c : input2)
      same2[c]++;

    for (int i = 'a'; i <= 'z'; i++)
    {
      if (same1[i] > 0 && same2[i] > 0){
        int c = same1[i] < same2[i] ? same1[i] : same2[i];
        while (c--)
            cout << (char)i ;
      }
    }
    cout << endl;
    
  }
}
