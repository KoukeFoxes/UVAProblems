#include "/Users/doeshing/development/stdc++.h"
using namespace std;

int main()
{
  long tem;
  while (cin >> tem && tem != 0)
  {
    string bin = "";
    int sum_1 = 0;
    while (tem)
    {
      bin = to_string(tem & 1) + bin;
      sum_1 += tem & 1;
      tem >>= 1;
    }
    cout << "The parity of "<< bin << " is " << sum_1 << " (mod 2)." << endl;
  }
}
