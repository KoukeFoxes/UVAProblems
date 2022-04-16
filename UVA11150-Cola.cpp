#include "/Users/doeshing/development/stdc++.h"
int main()
{

  int cola;

  std::cin >> cola;

  int sum_cola_drinked = 0; //已經喝了的瓶子數
  int sum_cola_empty = 0; //空瓶子數

  while (sum_cola_empty >= 3) //不需借瓶子
  {
    sum_cola_drinked += cola; 
    sum_cola_empty += cola;
    cola = sum_cola_empty / 3; //3個空瓶子換一個可樂
    sum_cola_empty %= 3;
  }
  sum_cola_drinked += cola; //沒辦法借的可樂把它喝完

  if(cola + sum_cola_empty == 2) //最後剩下的
    sum_cola_drinked ++;

  std::cout << sum_cola_drinked << std::endl;
}

int main_()
{
    int n;
    while( cin >> n )
        std::cout << n * 1.5  << endl;
    return 0;
}
