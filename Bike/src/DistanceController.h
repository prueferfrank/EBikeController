/*
 * DistanceController.h
 *
 *  Created on: 17.09.2019
 *      Author: frankp
 */

#ifndef DISTANCECONTROLLER_H_
#define DISTANCECONTROLLER_H_

class DistanceController {
public:
   /* in millimeter */
   DistanceController(long wheelSize);
   virtual ~DistanceController();

   /* to be called when the wheel sensor sends a signal */
   void isr(long long millis);

   /* in km */
   double getTotalDistance();

   /* gesamte millies-Zeit */
   long long getTime();

   /* gesamte millies-Zeit */
   double getAvgSpeed();


   /* setzen der gesamten Zeit in km */
   void setTotalDistance(double totaldistance);

   /* zurücksetzen von Zeit und weg */
   void clear();


private:
   unsigned long wheelSize; // in mm
   unsigned long long wheelTurns; // total number of wheel turns since start

   long long lastTick;
   long long time;

};

#endif
