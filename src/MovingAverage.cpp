#include "MovingAverage.h"

MovingAverage::MovingAverage(int filterLength)
{
  this->filterLength = filterLength;
  this->filterPointer = new double[filterLength];
  this->lastValue = 0.0;
  initFilter();
}

double MovingAverage::addSample(double newValue)
{
  shiftFilter(newValue);
  computeAverage();
  return this->lastValue;
}

double MovingAverage::getValue()
{
  return this->lastValue;
}

void MovingAverage::dumpFilter()
{
  this->lastValue = 0.0;
  initFilter();
}

void MovingAverage::shiftFilter(double nextValue)
{
  for (int i = this->filterLength - 1; i > -1; i--)
  {
    if (i == 0)
    {
      *(filterPointer) = nextValue;
    }
    else
    {
      *(filterPointer + i) = *(filterPointer + (i - 1));
    }
  }
}

void MovingAverage::computeAverage()
{
  double sum = 0.0;
  for (int i = 0; i < this->filterLength; i++)
  {
    sum += *(filterPointer + i);
  }
  this->lastValue = sum / this->filterLength;
}

void MovingAverage::initFilter()
{
  for (int i = 0; i < this->filterLength; i++)
  {
    *(filterPointer + i) = 0.0;
  }
}