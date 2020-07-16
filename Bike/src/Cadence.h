/*
 * Cadence.h
 *
 *  Created on: 13.09.2019
 *      Author: frankp
 *
 *      Wenn zu lange kein Signal eingegangen ist wird die Startzeit zurückgesetzt
 *
 *
 */

#ifndef CADENCE_H_
#include <cmath>
#include "BufferTemplate.h"
#define CADENCE_H_

class Cadence {
public:
   Cadence(int ticksPerRevolution);
   virtual ~Cadence();

   /* zu diesem Zeitpunkt wird ein Signal (interrupt) verarbeitet */
   void tick(long long millis);

   double getCurrent();
   double getAverage();

   /* peek a value in index von 0 - (count-1)*/
   double peek(int index);
    long long peekTick(int index);
   int getCount();

   void clear();

private:

   int ticksPerRevolution;

   long long lastTick;

   long long totalTicks;

   /** the values contaqins the millis when the isr routine was called */
   Buffer<long long> values;
};

#endif
