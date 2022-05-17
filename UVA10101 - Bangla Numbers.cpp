/*
UVA10101 - Bangla Numbers

Content
Bangla numbers normally use 'kuti' (10000000), 'lakh' (100000), 'hajar' (1000), 'shata' (100) while expanding and converting to text. You are going to write a program to convert a given number to text with them.
Input
The input file may contain several test cases. Each case will contain a non-negative number <= 999999999999999.
Output
For each case of input, you have to output a line starting with the case number with four digits adjustment followed by the converted text.

Sample Input #1
23764
45897458973958

Sample Output #1
   1. 23 hajar 7 shata 64
   2. 45 lakh 89 hajar 7 shata 45 kuti 89 lakh 73 hajar 9 shata 58


*/

#include "/Users/doeshing/development/stdc++.h"
// #include "bits/stdc++.h"
using namespace std;

void prgress(long long int input)
{ 
  if(input == 0) 
    cout << 0;
  if (input / 10000000)
  {
    prgress(input / 10000000);
    cout << "kuti ";
    input %= 10000000;
  }
  if (input / 100000)
  {
    prgress(input / 100000);
    cout << "lakh ";
    input %= 100000;
  }
  if (input / 1000)
  {
    prgress(input / 1000);
    cout << "hajar ";
    input %= 1000;
  }
  if (input / 100)
  {
    prgress(input / 100);
    cout << "shata ";
    input %= 100;
  }
  if (input)
  {
    cout << input << " ";
  }
  
}

int main()
{
  long long int input;
  int index = 1;
  while(cin >> input){
    cout << fixed << setprecision(4) << index++ << ". ";
    prgress(input);
    cout << endl;    
  }
}
