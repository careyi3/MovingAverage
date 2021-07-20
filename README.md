# MovingAverage

This library implements a basic moving average filter for smoothing sensor data over time.

![Sample Data](/docs/sample_outputs.png)

## Usage

``` c++
#include <MovingAverage.h>

double filteredValue;

MovingAverage filter(3);

filteredValue = filter.addSample(1.0); // filteredValue = 0.33
filteredValue = filter.addSample(2.0); // filteredValue = 1.0
filteredValue = filter.addSample(3.0); // filteredValue = 2.0
filteredValue = filter.addSample(4.0); // filteredValue = 3.0
filteredValue = filter.addSample(5.0); // filteredValue = 4.0

```

### API

```c ++
MovingAverage::MovingAverage(int filterLength)
```

Initalises the filter with the specified length setting all values to `0.0`.

```c ++
double MovingAverage::addSample(double newValue)
```

Shifts the existing filter one sample to the right, pushing the last value out of the filter and setting the new value to the first position in the filter. With the newly shifted filter, it computes the average of all the values in the filter, caches the result and returns the value.

```c ++
double MovingAverage::getValue()
```

Returns the last cached value of the filter.

```c ++
void MovingAverage::dumpFilter()
```

Resets all values in the filter to 0.0 and clears the last cached filter value.

## Test & Demo

These are just sample c++ apps to test the code and to generate randomly generated outputs.

Test:

```bash
./script/test
```

Demo:

```bash
./script/demo
```
