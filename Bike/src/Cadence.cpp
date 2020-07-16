/*
 * Cadence.cpp
 *
 *  Created on: 13.09.2019
 *      Author: frankp
 */
#include <iostream>
#include "Cadence.h"

using namespace std;

/**
 * Cadence (pedalling frequency, crank frequency)
 * The cadence is a numeric value
 * Only valid if last tick is not older than 1 second and speed is 0
 */
Cadence::Cadence(int ticksPerRevolution) {
   this->ticksPerRevolution = ticksPerRevolution;

   // Buffer künstlich vergrößern auf 4 Umdrehungen
   totalTicks = 0;
   lastTick = 0;
}

Cadence::~Cadence() {
}

/* peek index von 0 - (count-1)*/
double Cadence::peek(int index) {
   return values.peek(index);
}

int Cadence::getCount() {
   return values.getCount();
}

void Cadence::tick(long long millis) {
   // zu diesem Zeitpunkt wird ein Tick registriert. Wenn es nicht der erste Tick ist wird die Zeit in die Vaules gespeichert.
   if (lastTick == 0) {
      lastTick = millis;
      return;
   }
   values.add(millis);
}

double Cadence::getCurrent() {
   int cnt = values.getCount() - 1;
   if (cnt < 0) return 0.0;

   return ((double) (cnt - 1) / ticksPerRevolution) * 60000 / (values.peek(cnt) - values.peek(0));
}

void Cadence::clear() {
   values.clear();
}

