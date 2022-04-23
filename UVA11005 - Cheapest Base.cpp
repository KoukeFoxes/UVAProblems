#include "/Users/doeshing/development/stdc++.h"
using namespace std;

int main()
{
  int X; // case
  cin >> X;
  for (int i = 0; i < X; i++)
  {
    int price[36];
    for (int j = 0; j < 36; j++)
      cin >> price[j];
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
      int input_number;
      cin >> input_number;
      vector<int> best_base;
      long cheapest = 9999999999;
      int number = input_number;
      for (int base = 2; base <= 36; base++)
      {
        long sum = 0;
        while (number > 0)
        {
          sum += price[number % base];
          number /= base;
        }
        if (sum < cheapest)
        {
          best_base.clear();
          best_base.push_back(base);
          cheapest = sum;
        }
        else if (sum == cheapest)
        {
          best_base.push_back(base);
        }
        number = input_number;
      }
      cout << endl;
      cout << "Cheapest base(s) for number " << number << ":";
      for (int i = 0; i < best_base.size(); i++)
        cout << " " << best_base[i];
      cout << endl;
    }
  }
}
