/*
 * PedalSensor.h
 *
 *  Created on: 21.06.2018
 *      Author: frankp
 */

#ifndef PEDALSENSOR_H_
#define PEDALSENSOR_H_

class PedalSensor {
public:
	PedalSensor();
	virtual ~PedalSensor();

	void interruptServiceRoutine();
};

#endif /* PEDALSENSOR_H_ */
