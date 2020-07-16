/*
 * SpeedController.h
 *
 *  Created on: 10.07.2018
 *      Author: Frank
 */

#ifndef SPEEDCONTROLLER_H_
#define SPEEDCONTROLLER_H_

#include "BufferTemplate.h"

/* errechnet aus den ticks und den zeitpunkten die aktuelle,maximale und durchschnitts geschwindikeit*/
class SpeedController {
public:
   SpeedController(long wheelSize);

   /* zu diesem Zeitpunk wird ein Radimpuls aufgezeichnet */
   void isr(long long millis);

   // current speed
   double getCurrentSpeed(); /* berechnet über die Zeit der letzten 3 Wheel impulse, in km/h */
   double getMaxSpeed(); /* berechnet über den kürzesten Abstand zweier Wheel impulse, in km/h*/
   double getAvgSpeed(long long millis); /* berechnet über Zeit zwischen erstem wheel impulse und aktueller Zeit und Anzahl Impulse seit clear , in km/h */

   void clear();

private:
   int wheelSize = 0;

   long long firstTick = -1;
   long long lastTick = -1;
   long long tickCount = 0;
   long long minTimeBetweenTicks = -1;

   double getSpeedFromTickAndTime(int tickCount, long long time); /* berechnet über Zeit zwischen erstem wheel impulse und aktueller Zeit und Anzahl Impulse seit clear , in km/h */

   Buffer<long long> ticks;
};

#endif
