#include "timer.h"
#include "iostream"
#include "Windows.h"

void Test(int x) {
  std::cout << "ExecutedXXX: " << x << std::endl;
}

int main() {
    Timer* t = new Timer();
    for (int i = 0; i < 10; ++i)
        t->SetDelayedTask(std::bind(&Test, i), 500 * (i + 3));
    t->WaitTillEnd();
}