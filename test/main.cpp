#include <iostream>
#include <MovingAverage.h>

using namespace std;

int assertTest(double val1, double val2);

int main()
{
  int status = 0;
  double res = 0;
  MovingAverage filter(3);

  filter.addSample(10.0); // filteredValue = 0.33
  res = filter.getValue();
  status = assertTest(3.3, res);
  res = filter.getValue();
  filter.addSample(5.0); // filteredValue = 5.0
  status = assertTest(5.0, res);
  filter.addSample(12.0); // filteredValue = 9.0
  res = filter.getValue();
  status = assertTest(9.0, res);
  filter.addSample(10.0); // filteredValue = 9.0
  res = filter.getValue();
  status = assertTest(9.0, res);
  filter.addSample(8.0); // filteredValue = 10.0
  res = filter.getValue();
  status = assertTest(10.0, res);
  filter.addSample(8.0); // filteredValue = 8.66
  res = filter.getValue();
  status = assertTest(8.66, res);

  if (status == 0)
  {
    cout << "Success" << endl;
  }
  else
  {
    cout << "Failure" << endl;
  }

  return status;
}

int assertTest(double val1, double val2)
{
  if (int(100 * val1) == int(100 * val2))
  {
    return 0;
  }
  return 1;
}