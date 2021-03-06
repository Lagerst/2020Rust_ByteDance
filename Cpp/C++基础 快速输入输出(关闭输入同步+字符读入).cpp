#include <iostream>
using namespace std;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  system("pause");
  return 0;
}

int read(int &t) {
  char c = getchar();
  while (c < '0' || c > '9')
    c = getchar();
  int x = 0;
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  t = x;
  return 0;
}

void print(int a) {
  if (a > 9)
    print(a / 10);
  putchar(a % 10 + '0');
}