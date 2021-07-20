#include "MovingAverage.h"

double filteredOutput;
long randomNumber;
MovingAverage filter(5);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  randomNumber = random(10, 20);
  filteredOutput = filter.addSample(randomNumber);

  Serial.print('random:');
  Serial.print(randomNumber);
  Serial.print(',');
  Serial.print('filtered:');
  Serial.print(filteredOutput);

  delay(100);
}
