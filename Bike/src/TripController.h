/*
 * TripController.h
 *
 *  Created on: 31.08.2018
 *      Author: frankp
 */

#ifndef TRIPCONTROLLER_H_
#define TRIPCONTROLLER_H_

class TripController {
public:
	TripController() {
	}
	virtual ~TripController() {
	}

	// allgemein
	void resetTrip();

	// so lange es neue Impulse vom Wheel oder von der Kurbel gibt ist der Trip und wird die gesamte Tripzeit gezählt.
	// bis zu der hier angegebenen Inaktivitätsdauer kann eine Pause dazwischen sein, ohne dass der Trip unterbrochen wird.
    void setInactiveSeconds(unsigned int inactiveSeconds);


	// Speed functions
	void add(long long time, double distance); /* time in millis, distance in km */
	unsigned long getTripSpeed(); /* in km/h */
	unsigned long getTripTime(); /* in millis */
	double getTripDistance(); /* in km */
	const char * getTripTimeFormatted();

	// crank Functions
	void addCrank(unsigned long time, unsigned long turns); /* time in millis, turns without unit */
	unsigned long getTripCrankTurns(); /* without unit */
	unsigned long getTripCrankTime(); /* in millis*/
	double getCadence(); /* in 1/min */
	const char * getCadenceFormatted(); /* mit einer Nachkommastelle */

private:
	double tripDistance = 0; /*in km, 4 digits , stored precision = 1m */
	unsigned long tripTime = 0; /* in seconds */
	char buffer[20] = "";
	unsigned long tripCrankTurns = 0;
	unsigned long tripCrankTime = 0;
};

#endif
