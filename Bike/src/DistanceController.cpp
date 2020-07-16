/*
 * DistanceController.cpp
 *
 *  Created on: 17.09.2019
 *      Author: frankp
 */

#include "DistanceController.h"

DistanceController::DistanceController(long wheelSize) {
   this->wheelSize = wheelSize;
   this->wheelTurns = 0;
   this->time = 0;
   this->lastTick = -1;
}

DistanceController::~DistanceController() {
}

void DistanceController::isr(long long millis) {
   this->wheelTurns++;

   // automatisches addieren der Fahrzeit. also Zeiten nur dann addieren, wenn das letzte Interval nicht zu lange war
   if (this->lastTick < 0) {
      this->lastTick = millis;
      return;
   }
   long long delta = millis - lastTick;
   if (delta < 1000) {
      time += delta;
   }
   this->lastTick = millis;
}

double DistanceController::getTotalDistance() {
   return (wheelTurns * wheelSize) / 1000000.0;
}

long long DistanceController::getTime() {
   return time;
}

void DistanceController::setTotalDistance(double totaldistance) {
}

double DistanceController::getAvgSpeed() {
   return getTotalDistance() / getTime();
}

void DistanceController::clear() {
   time = 0;
   lastTick = -1;
   wheelTurns = 0;
}
