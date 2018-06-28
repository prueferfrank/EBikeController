/*
 * PedalSensor.cpp
 *
 *  Created on: 21.06.2018
 *      Author: frankp
 */

#include "PedalSensor.h"

PedalSensor::PedalSensor() {
}

PedalSensor::~PedalSensor() {
}

void PedalSensor::interruptServiceRoutine(unsigned long millis) {

   // register next pulse
   iPulses++;

   if (this->iPulses == 1) {
      this->ulLastCrankTurnTime = millis;
   }

   if (this->iPulses >= this->iPulsesPerTurn) {
      // one turn is complete
      iPulses = 0;
      turn(millis);
   }
}

   void PedalSensor::turn(unsigned long millis){
      // calculate time for last turn
      ulLastCrankTurnMillies = millis - ulLastCrankTurnTime;

   }


/** administrative */
void PedalSensor::setPulsesPerTurn(unsigned int pulsesPerTurn) {
   this->iPulsesPerTurn = pulsesPerTurn;
}

/** administrative */
unsigned int PedalSensor::getPulsesPerTurn() {
   return iPulsesPerTurn;
}

/**
 * this function should be called whenever a new trip is started
 */
void PedalSensor::startTrip() {
   this->iTripTurns = 0;
   this->ulTripStartMillies = millis();
   this->tripActive = true;
}

/** this function should be called whenever a trip ends */
void PedalSensor::endTrip() {
   this->tripActive = false;
}

/** set the previous value as the application should save it's state when powered off and recover the value when powered on */
void PedalSensor::initTotalTurns(unsigned long totalTurns) {
   this->iTotalTurns = totalTurns;
}

/** get the current number of crank turns for the current trip*/
unsigned long PedalSensor::getTripTurns() {
   return this->iTripTurns;
}

/** returns the crank speed in 1/minute */
float PedalSensor::getCurrentCrankFrequency() {
   return 0.0;
}
