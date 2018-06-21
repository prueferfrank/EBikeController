/*
 * TripController.h
 *
 *  Created on: 21.06.2018
 *      Author: frankp
 */

#ifndef TRIPCONTROLLER_H_
#define TRIPCONTROLLER_H_

class TripController {

private:
	bool bTripActive = false;
	unsigned long lastTripSignal = -1;

	/** this constant defines how long a trip remains active even if no wheelSignal is received.
	 * Every new wheelSignal resets it.
	 * it is in microseconds.  (one minute)*/
	const unsigned long inactivityPeriod = 60 * 1000000;

public:
	TripController();
	virtual ~TripController();

	void wheelSignal(unsigned long micros);
	void pedalSignal(unsigned long micros);

	void resetTrip();

	bool isTripActive();

protected:
};

#endif /* TRIPCONTROLLER_H_ */
