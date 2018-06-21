/*
 * TripController.cpp
 *
 *  Created on: 21.06.2018
 *      Author: frankp
 */

#include "TripController.h"

TripController::TripController() {
}

TripController::~TripController() {
}

void TripController::wheelSignal(unsigned long micros) {
	// wann wurde das letzte mal ein Signal empfangen?
	// ein Trip startet, wenn kein Trip läuft und ein WheelSignal empfangen wurde.
	if (lastTripSignal == -1  ){}

    // ein Trip endet, wenn eine definierte Zeit kein Wheelsignal empfangen wurde.
}

void TripController::pedalSignal(unsigned long micros) {
// wann wurde das letzte mal ein Signal empfangen?
}

void TripController::resetTrip() {
	bTripActive = false;
	lastTripSignal = -1;
}

bool TripController::isTripActive() {
	return bTripActive;
}
