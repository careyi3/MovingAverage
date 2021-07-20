
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cmath>
#include <MovingAverage.h>

using namespace std;

int main()
{
  srand((unsigned)time(0));

  double value;
  MovingAverage filter(10);

  printf("sample,raw,filtered\r\n");
  for (int i = 0; i < 200; i++)
  {
    value = (double)(log(i) + (rand() % 10) / 7.5);
    cout << i << ',' << value << ',' << filter.addSample(value) << endl;
  }

  return 0;
}
