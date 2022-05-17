/*
UVA10189 - Minesweeper

Have you ever played Minesweeper? It’s a cute little game which comes within a certain Operating System which name we can’t really remember. Well, the goal of the game is to find where are all the mines within a M × N field. To help you, the game shows a number in a square which tells you how many mines there are adjacent to that square. For instance, supose the following 4 × 4 field with 2 mines (which are represented by an ‘*’ character):
*...
....
.*..
....
If we would represent the same field placing the hint numbers described above, we would end up with:
*100
2210
1*10
1110
As you may have already noticed, each square may have at most 8 adjacent squares.
Input
The input will consist of an arbitrary number of fields. The first line of each field contains two integers n and m (0 < n, m ≤ 100) which stands for the number of lines and columns of the field respectively. The next n lines contains exactly m characters and represent the field.
Each safe square is represented by an ‘.’ character (without the quotes) and each mine square is represented by an ‘*’ character (also without the quotes). The first field line where n = m = 0 represents the end of input and should not be processed.
Output
For each field, you must print the following message in a line alone:
Field #x:
Where x stands for the number of the field (starting from 1). The next n lines should contain the field with the ‘.’ characters replaced by the number of adjacent mines to that square. There must be an empty line between field outputs.
Sample Input
44
*...
....
.*..
....
35
**...
.....
.*...
00

Sample Output
Field #1:
*100
2210
1*10
1110

Field #2:
**100
33200
1*100


*/

#include "/Users/doeshing/development/stdc++.h"
// #include "bits/stdc++.h"
using namespace std;

int main()
{
  int x, y;
  int cases = 1;
  while (cin >> x && cin >> y && (x || y != 0))
  {
    
    char map[x][y];
    char ans_map [x][y];

    for(int i = 0; i < x; i++)
      for(int j = 0; j < y; j++)
        cin >> map[i][j];
    
    for(int i = 0; i < x; i++)
      for(int j = 0; j < y; j++)
        ans_map[i][j] = '0';

    for(int row = 0 ; row < x; row++)
      for(int column = 0 ; column < y; column++){
        if(map[row][column] == '*'){
          ans_map[row][column] = '*';

          for(int i=-1; i< 2; i++)
            for(int j=-1; j< 2; j++)
              if(row+i >=0 && column+j >=0 && row+i < x && column+j < y)
              if(map[row+i][column+j] != '*')
                ans_map[row+i][column+j] += 1;
        }
      }
    
    cout << "Field #"<< cases++ <<":" << endl;
    for(int i = 0; i < x; i++){
      for(int j = 0; j < y; j++)
        cout << ans_map[i][j];
      cout << endl;
    }

  }
  
}
