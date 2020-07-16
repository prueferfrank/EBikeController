/*
 * SpeedController.cpp
 *
 *  Created on: 10.07.2018
 *      Author: Frank
 */

#include "SpeedController.h"
#include "iostream"

using namespace std;

// minSpeed = 1km/h =>>  16m/min  == 0,26 m / sek  m,it 2,228 m/Umdrehung =  --> 0,7 sek
#define millisBetweenTicks 700

SpeedController::SpeedController(long wheelSize) {
   this->wheelSize = wheelSize;
   ticks.setMaxValue(3);
}

//
//void SpeedController::init(double totalDistance, int wheelSize) {
//	this->totalDistance = totalDistance;
//	this->tripInactiveMinutes = tripInactiveMinutes;
//	this->wheelSize = wheelSize; // in millimeters
//	this->millisForLastTurn = -1;
//}
//
//// wird zyklisch aufgerufen
//void SpeedController::checkSpeedCalculated(unsigned long millis) {
//	// wenn das letzte Signal des Speed Hall Sensors zu lange her ist wird die Berechnung der Geschwindigkeit beendet.
//	if ((lastIsr + millisBetweenTicks) < millis) {
//		// no, last tick is too long ago, stop now
////		clearDeltaTime();
//		lastIsr = -1;
//	}
//}
//

//
void SpeedController::isr(long long millis) {
// every interrupt of the speed sensor is recognized and used to calculate the distance
   tickCount++;
   if (firstTick == -1) firstTick = millis;

   long long lastDiff = millis - lastTick;
   if (lastDiff > 0 && minTimeBetweenTicks) minTimeBetweenTicks = lastDiff;

   lastTick = millis;
   ticks.add(millis);
}

double SpeedController::getMaxSpeed() {
   if (minTimeBetweenTicks <= 0) return 0.0;

   return getSpeedFromTickAndTime(1, minTimeBetweenTicks);
}

double SpeedController::getAvgSpeed(long long millis) {
   if (tickCount == 0 || (lastTick - firstTick) <= 0) return 0.0;

   return getSpeedFromTickAndTime(tickCount - 1, lastTick - firstTick);
}

double SpeedController::getCurrentSpeed() {
   if (ticks.getCount() <= 1) return 0.0;

   long long start = ticks.peek(0);
   long long end = ticks.peek(ticks.getCount() - 1);

   long long time = end - start;
   if (time == 0) {
      return 0.0;
   }
   return getSpeedFromTickAndTime(ticks.getCount() - 1, time);
}

void SpeedController::clear() {
   ticks.clear();
   firstTick = -1;
   lastTick = -1;
   tickCount = 0;
}

double SpeedController::getSpeedFromTickAndTime(int tickCount, long long time) {
   return 3.6 * tickCount * wheelSize / time;
}
