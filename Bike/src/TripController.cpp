/*
 * TripController.cpp
 *
 *  Created on: 31.08.2018
 *      Author: frankp
 */

#include "TripController.h"
#include <stdio.h>

#define secondsPerDay 86400

void TripController::add(long long tripTime, double tripDistance) {
	// add this distance and time to the trip values
	this->tripDistance += tripDistance;
	this->tripTime += tripTime;
}

void TripController::setInactiveSeconds(unsigned int inactiveSeconds) {

}

unsigned long TripController::getTripSpeed() {
	if (this->tripTime == 0) {
		return 0;
	}
	return (this->tripDistance * 3600) / this->tripTime;
}

unsigned long TripController::getTripTime() {
	return tripTime;
}

double TripController::getTripDistance() {
	return this->tripDistance;
}

void TripController::resetTrip() {
	tripDistance = 0;
	tripTime = 0;
	tripCrankTurns = 0;
	tripCrankTime = 0;
}

const char* TripController::getTripTimeFormatted() {
	//day:hour:min:sec  oder alternativ bei < 7 Tagen hour/min/sec
	// 7 Tage =7 * 24*60*60 = 604800
	// 1Tag = 86400
	// bsp: 69235 = 19:13:55
	//      242035  = 67:13:55
	unsigned long tripSeconds = this->tripTime / 1000;
	if (tripSeconds >= 604800) {
		// longFormat day:hour:min:sec
		int day = tripSeconds / secondsPerDay;
		int rem = tripSeconds - (day * secondsPerDay);// remaining time without days
		int hours = rem / 3600;
		rem = rem - (hours * 3600);
		int mins = rem / 60;
		int secs = rem - (mins * 60);
		sprintf(buffer, "%d:%02d:%02d:%02d", day, hours, mins, secs);
	} else {
		// shortFormat hour/min/sec
		int hours = tripSeconds / 3600;
		int rem = tripSeconds - (hours * 3600);
		int mins = rem / 60;
		int secs = rem - (mins * 60);
		sprintf(buffer, "%d:%02d:%02d", hours, mins, secs);
	}
	return buffer;
}

void TripController::addCrank(unsigned long time, unsigned long turns) {
	// add the values to the trip values
	this->tripCrankTime += time;
	this->tripCrankTurns += turns;
}

unsigned long TripController::getTripCrankTurns() {
	return this->tripCrankTurns;
}

unsigned long TripController::getTripCrankTime() {
	return this->tripCrankTime;
}

double TripController::getCadence() {
	if (getTripCrankTime() == 0) {
		return 0.0;
	}
	return (double) getTripCrankTurns() * 60000 / (double) getTripCrankTime();
}

const char* TripController::getCadenceFormatted() {
	double cadence = getCadence();
	sprintf(buffer, "%d.%1d", (int) (cadence), ((int) (cadence * 10) % 10));
	return buffer;
}
