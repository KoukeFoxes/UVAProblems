#include "bits/stdc++.h"

using namespace std;
bool findTheSamePoint(double pointArr[4][2], double point[2])
{
  for (int i = 0; i < 4; i++)
  {
    if (pointArr[i][0] == point[0] && pointArr[i][1] == point[1])
    {
      return true;
    }
  }
  return false;
}

int main()
{

  while (true)
  {
    double same[2];
    double point[4][2];
    double temp[2];
    bool isFindTheSamePoint = false;

    // add point to array
    for (int i = 0; i < 4; i++)
    {
      for (int j = 0; j < 2; j++)
      {
        cin >> point[i][j];
      }
      // check point if same or not
      if (findTheSamePoint(point, point[i]) && i != 0 && !isFindTheSamePoint) // call by value
      {
        same[0] = point[i][0];
        same[1] = point[i][1];
        isFindTheSamePoint = true;
      }
    }

    // calculate distance
    double x = 0, y = 0;
    for (int i = 0; i < 4; i++)
    {
      if (point[i][0] != same[0] || point[i][1] != same[1])
      {
        x += point[i][0];
        y += point[i][1];
      }
    }
    
    // print same array
    // cout << same[0] << " " << same[1] << endl;

    cout.setf(ios::fixed);
    cout.precision(3);
    cout << x - same[0] << " " << y - same[1] << endl;
  }
}	
