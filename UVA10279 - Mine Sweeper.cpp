// #include "/Users/doeshing/development/stdc++.h"
#include "bits/stdc++.h"
using namespace std;

int main()
{
	int x, y;
	int cases;
	cin >> cases;
	cin.ignore();
	for(int c = 1; c <= cases; c++)
	{
		cin >> x;
			
		y = x;
		
		char map[x][y];
		char ans_map [x][y];
		char map_x [x][y];
		
		for(int i = 0; i < x; i++)
		  for(int j = 0; j < y; j++)
			cin >> map[i][j];
	
		for(int i = 0; i < x; i++)
		  for(int j = 0; j < y; j++)
			cin >> map_x[i][j];
		
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
		
		for(int i = 0; i < x; i++){
		  for(int j = 0; j < y; j++)
			cout << ((toupper(map_x[i][j]) == 'X') ? ans_map[i][j] : '.');
		  cout << endl;
		}
	
	}
  
}
