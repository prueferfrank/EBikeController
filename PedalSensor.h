/*
 * PedalSensor.h
 *
 *  Created on: 21.06.2018
 *      Author: frankp
 */

#ifndef PEDALSENSOR_H_
#define PEDALSENSOR_H_

class PedalSensor {
private:
   /** configured number of pulses per crank turn, change via #setPulsesPerTurn() */
   unsigned int iPulsesPerTurn = 4;
   unsigned int iTotalTurns = 0;
   unsigned int iTripTurns = 0;

   unsigned long ulTripStartMillies = 0;
   unsigned long ulLastCrankTurnMillies = 0; /** time when the last turn occur */
   unsigned long ulLastCrankTurnTime = 0;

   unsigned int iPulses = 0; // count pulses per turn
   bool tripActive = false;
public:
   PedalSensor();
   virtual ~PedalSensor();

   /**
    * this function is called when the pedaling Hall Sensor recognizes a magnetic pulse.
    * For every turn of the crank I have 4 magnets, this means 4 pulses is exactly one turn of the crank.
    */
   void interruptServiceRoutine();
   void interruptServiceRoutine(unsigned long millis);

   /** administrative */
   void setPulsesPerTurn(unsigned int pulsesPerTurn);
   /** administrative */
   unsigned int getPulsesPerTurn();

   /**
    * this function should be called whenever a new trip is started
    */
   void startTrip();

   /** this function should be called whenever a trip ends */
   void endTrip();

   /** returns the total number of crank turns since starting */
   unsigned long getTotalTurns();

   /** set the previous value as the application should save it's state when powered off and recover the value when powered on */
   void initTotalTurns(unsigned long totalTurns);

   /** get the current number of crank turns for the current trip*/
   unsigned long getTripTurns();

   /** returns the crank speed in 1/minute */
   float getCurrentCrankFrequency();

   /** returns the crank speed in 1/minute */
   float getTripAverageCrankFrequency();
   /** returns the minimum crank speed in 1/minute for the trip */
   float getTripMinCrankFrequency();
   /** returns the maximum crank speed in 1/minute for the trip */
   float getTripMaxCrankFrequency();

   /** optional: returns the average crank speed in 1/minute */
   float getTotalAverageCrankFrequency();
   /** optional: returns the minimum crank speed in 1/minute total */
   float getTotalMinCrankFrequency();
   /** optional: returns the maximum crank speed in 1/minute total */
   float getTotalMaxCrankFrequency();
protected:
   void turn(unsigned long millis);
};

#endif /* PEDALSENSOR_H_ */
