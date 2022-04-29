/*
UVA118 - Mutant Flatworld Explorers

題目大意：
我們命令機器人依照我們的指令在陸地上移動，如果機器人根據我們的指令跳入海裡時，那接下來的機器人會知道那邊是海，而不會執行我們的指令。

舉例：假如向前走會掉入海裡，那則不會執行命令

指令有向左轉與向右轉、往前走，一開始會給你地圖的右上角，之後就是每一個機器人與其需要執行的指令。

題目要求 由於是根據向量座標，於是往北走的座標則為 x,y+1 , 南(x,y-1) , 西(x-1,y) , 東(x+1,y)


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
https://zerojudge.tw

*/

#include "/Users/doeshing/development/stdc++.h"

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
    if (X<0 OR X> upper_right[0] OR Y<0 OR Y> upper_right[1])
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

    for (int &i : upper_right)
        cin >> i;

    while (cin >> X >> Y >> dir)
    {

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
            {
                int last_position[2];
                last_position[0] = X;
                last_position[1] = Y;

                turn(d);

                if (isDown())
                {
                    cout << last_position[0] << " " << last_position[1] << " LOST" << endl;
                }
            }
        }
        cout << X << " " << Y << " " << dir << endl;
    }
}
