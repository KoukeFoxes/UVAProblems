#include "/Users/doeshing/development/stdc++.h"

using namespace std;

int main()
{
  int n, m;

  while (cin >> n >> m) // cases
  {
    bool is = true;
    vector<int> v;
    while(n > 0){
      v.push_back(n);
      if (n % m != 0 && n != 1)
        is = false;
      n /=m;
    }
    if (is)
    {
      for (int i = 0; i < v.size(); i++)
      {
        cout << v[i] << " ";
      }
      cout << endl;
    }
    else
    {
      cout << "boring" << endl;
    }
    
  }
}
