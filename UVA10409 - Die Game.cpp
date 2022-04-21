#include "/Users/doeshing/development/stdc++.h"
using namespace std;

void turnNorth(int *arr)
{
  int temp = arr[0];
  arr[0] = arr[4]; // top = south
  arr[4] = arr[1]; // south = bottom
  arr[1] = arr[2]; // bottom = north
  arr[2] = temp;   // north = top 
}

void turnSouth(int *arr){
  int temp = arr[0];
  arr[0] = arr[2]; // top = north
  arr[2] = arr[1]; // north = bottom
  arr[1] = arr[4]; // bottom = south
  arr[4] = temp;   // south = top
}

void turnWest(int *arr){
  int temp = arr[0];
  arr[0] = arr[3]; // top = east
  arr[3] = arr[2]; // east = bottom
  arr[2] = arr[1]; // bottom = west
  arr[1] = temp;   // west = top
}

void turnEast(int *arr){
  int temp = arr[0];
  arr[0] = arr[1]; // top = west
  arr[1] = arr[2]; // west = bottom
  arr[2] = arr[3]; // bottom = east
  arr[3] = temp;   // east = top
}


int main()
{
  int die[6] = {1, 6, 2 ,3 ,5 ,4}; // top, bottom, north ,west , south, east
  int n;
  while (cin >> n && n != 0)
  {
    while (n--)
    {
      string s;
      cin >> s;
      if ("north")
        turnNorth(die);
      else if ("south")
        turnSouth(die);
      else if ("east")
        turnEast(die);
      else if ("west")
        turnWest(die);
      else
        cout << "invalid input" << endl;
    }

    cout << die[0] << endl;
  }
}
