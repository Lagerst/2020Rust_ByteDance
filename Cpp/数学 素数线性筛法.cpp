// ConsoleApplication2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

int solution1(int n) {
  clock_t start_time = clock();
  cout << start_time << "ms" << endl;
  int sum = 0;
  for (int i = 2; i <= n; i++) {
    int flag = 1;
    for (int j = 2; j <= sqrt(i); j++) {
      if (i % j == 0) {
        flag = 0;
        break;
      }
    }
    sum += flag;
  }
  clock_t end_time = clock();
  cout << end_time << "ms" << endl;
  return sum;
} //暴力O(n^2)

bool flag[1000000] = {0};
int prime[1000000];
int solution2(int n) {
  clock_t start_time = clock();
  cout << start_time << "ms" << endl;
  int sum = 0;
  for (int i = 2; i <= n; i++) {
    if (!flag[i])
      prime[sum++] = i;
    for (int j = 0; j < sum && i * prime[j] <= n; j++) {
      flag[i * prime[j]] = 1;
      if (i % prime[j] == 0) {
        break;
      }
    }
  }
  clock_t end_time = clock();
  cout << end_time << "ms" << endl;
  return sum;
} //线性素数筛法O(n)

int main() {
  int n;
  scanf_s("%d", &n);
  printf_s("%d\n", solution1(n));
  printf_s("%d\n", solution2(n));
  system("pause");
  return 0;
}
