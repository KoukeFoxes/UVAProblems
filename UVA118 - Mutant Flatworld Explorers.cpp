/*
UVA118 - Mutant Flatworld Explorers
題目大意：
給你一塊矩形土地的長寬，再依序給定每個機器人的初始位置狀況及一連串的指令集，你必須用你的程式求出每個機器人最後的位置狀況。

一個機器人的位置狀況包括了其坐標（ x 坐標， y 坐標），和它面向的方向（用 N , S , E , W 來分別代表北、南、東、西）。
至於一個機器人所收到的指令集，是一個由字母 ' L ' ， ' R ' ， 和 ' F ' 所構成的字串，其分別代表：

左轉（Left）：機器人在原地往左轉 90 度。
右轉（Right）: 機器人在原地往右轉 90 度。
前進（Forward）: 機器人往其面向的方向向前走一格，且不改變其面向之方向。
從坐標 (x,y) 走至 (x,y+1) 的這個方向我們定義為北方。

因為此矩形土地是有邊界的，所以一旦一個機器人走出邊界掉落下去，就相當於永遠消失了。不過這個掉下去的機器人會留下「標記 ( scent ) 」，提醒以後的機器人，
避免他們從同一個地方掉下去。掉下去的機器人會把標記，留在他掉落之前所在的最後一個坐標點。所以對於以後的機器人，當他正位在有標記的地方時，這個機器人就會忽略會讓他掉下去的指令。

Input
輸入裡的第一列有2個正整數，代表這個矩形世界右上角頂點的坐標，其中假設這個世界的左下角頂點坐標為 ( 0 , 0 )。
接下來是若干組有關機器人的初始位置狀況和指令集，每個機器人2列。第一列為位置狀況，包括了兩個整數和一個字元（ N , S , E 或 W ），代表機器人初始的位置坐標以及機器人最初所面對的方向。
第二列則是指令集，是一個由 ' L ' ， ' R ' 和 ' F ' 所組成的字串。輸入以 end-of-file 作為結束。
各機器人是依序動作的，也就是說，直到一個機器人作完他全部的動作，下一個機器人才會開始動作。
所有機器人的初始位置皆會在矩形土地上，不會落在外面。任何坐標的最大值皆不會超過 50 。每個指令集的長度皆不會超過 100 個字元長。

Output
對於每一個機器人，你都必須輸出其最後所在的坐標和面對的方向。如果一個機器人會掉落出此世界外，你必須先輸出他在掉落前，最後的所在位置和面對的方向，再多加一個字： LOST 。

原文：
Robotics, robot motion planning, and machine learning are areas that cross the boundaries of
many of the subdisciplines that comprise Computer Science: artificial intelligence, algorithms and complexity,
electrical and mechanical engineering to name a few. In addition, robots as “turtles” (inspired by work by Papert,
Abelson, and diSessa) and as “beeper-pickers” (inspired by work by Pattis) have been studied and used by students as an
introduction to programming for many years.
This problem involves determining the position of a robot exploring a pre-Columbian flat world.
Given the dimensions of a rectangular grid and a sequence of robot positions and instructions, you are to write a program that determines for each sequence of robot positions and instructions the final position of the robot.
A robot position consists of a grid coordinate (a pair of integers: x-coordinate followed by y- coordinate) and an orientation (N,S,E,W for north, south, east, and west). A robot instruction is a string of the letters ‘L’, ‘R’, and ‘F’ which represent, respectively, the instructions:
• Left: the robot turns left 90 degrees and remains on the current grid point.
• Right: the robot turns right 90 degrees and remains on the current grid point.
• Forward: the robot moves forward one grid point in the direction of the current orientation and mantains the same orientation.
The direction North corresponds to the direction from grid point (x, y) to grid point (x, y + 1).
Since the grid is rectangular and bounded, a robot that moves “off” an edge of the grid is lost forever.
However, lost robots leave a robot “scent” that prohibits future robots from dropping off the world at the same grid point.
The scent is left at the last grid position the robot occupied before disappearing over the edge. An instruction to move “off”
the world from a grid point from which a robot has been previously lost is simply ignored by the current robot.
Input
The first line of input is the upper-right coordinates of the rectangular world, the lower-left coordinates are assumed to be 0,0.
The remaining input consists of a sequence of robot positions and instructions (two lines per robot).
A position consists of two integers specifying the initial coordinates of the robot and an orientation (N,S,E,W),
all separated by white space on one line. A robot instruction is a string of the letters ‘L’, ‘R’, and ‘F’ on one line.
Each robot is processed sequentially, i.e., finishes executing the robot instructions before the next robot begins execution.
Input is terminated by end-of-file.
You may assume that all initial robot positions are within the bounds of the specified grid. The maximum value for any coordinate is 50.
All instruction strings will be less than 100 characters in length.
Output
For each robot position/instruction in the input, the output should indicate the final grid position and orientation of the robot.
If a robot falls off the edge of the grid the word ‘LOST’ should be printed after the position and orientation.

相關參考：
https://zerojudge.tw/ShowProblem?problemid=c082
*/

#include "/Users/doeshing/development/stdc++.h"
// #include "bits/stdc++.h"
#define AND &&
#define OR ||

using namespace std;

// public variables
int X, Y; // position of the robot
char dir; // direction of the robot

int lower_left[] = {0, 0};          // lower-left corner of the grid
int upper_right[2];                 // upper-right corner of the grid
int direction_[4] = {1, 1, -1, -1}; // direction of the robot (N, E, S, W)
int dir_pinter;


bool isDown()
{ // check if the robot is fall down the edge of the grid
    if (X < 0 OR X > upper_right[0] OR Y < 0 OR Y > upper_right[1])
        return true;
    return false;
}

void turn(char d)
{

    switch (d)
    {
    case 'L':
        dir_pinter = (dir_pinter + 3) % 4;
        break;
    case 'R':
        dir_pinter = (dir_pinter + 1) % 4;
        break;
    case 'F':
        switch (dir_pinter)
        {
        case 0:
            Y += direction_[dir_pinter];
            break;
        case 1:
            X += direction_[dir_pinter];
            break;
        case 2:
            Y += direction_[dir_pinter];
            break;
        case 3:
            X += direction_[dir_pinter];
            break;
        }
        break;
    }
}

int main()
{

    int last_position[2];
    int last_direction;

    for (int &i : upper_right)
        cin >> i;
    
    bool map_lost[upper_right[0] + 1][upper_right[1] + 1];

    for(int i = 0 ; i < upper_right[0] + 1 ; i++)
        for(int j = 0 ; j < upper_right[1] + 1 ; j++)
            map_lost[i][j] = false;

    while (cin >> X >> Y >> dir)
    { 

        bool fall = false;

        switch (dir)
        {
        case 'N':
            dir_pinter = 0;
            break;
        case 'E':
            dir_pinter = 1;
            break;
        case 'S':
            dir_pinter = 2;
            break;
        case 'W':
            dir_pinter = 3;
            break;
        }

        // execute the robot
        string instruction;
        cin >> instruction;
        for (char d : instruction)
        {
            
                last_position[0] = X;
                last_position[1] = Y;
                last_direction = dir_pinter;

                turn(d);
                fall = isDown();

                if (fall AND !map_lost[last_position[0]][last_position[1]]) //fall and map is not marked
                {   
                    cout << last_position[0] << " " << last_position[1] << " " <<  ((dir_pinter==0) ? "N" : (dir_pinter==1) ? "E" : (dir_pinter==2) ? "S" : "W")<< " LOST" << endl;
                    map_lost[last_position[0]][last_position[1]] = true;
                    break;

                }else if (fall AND map_lost[last_position[0]][last_position[1]]){ //fall but map is marked
                    
                    //back to last position
                    X = last_position[0];
                    Y = last_position[1];
                    dir_pinter = last_direction;

                    fall = false;
                }
            
        }
        if (!fall)
            cout << X << " " << Y << " " << ((dir_pinter==0) ? "N" : (dir_pinter==1) ? "E" : (dir_pinter==2) ? "S" : "W") << endl;
    }
}
