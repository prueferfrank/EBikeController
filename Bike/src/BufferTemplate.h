/*
 * BufferTemplate.cpp
 *
 *  Created on: 17.09.2019
 *      Author: frankp
 *
 *      Template class to generate a buffer for values
 */

#include <iostream>
#include <exception>
using namespace std;

#define buffersize 5

#ifndef BUFFERTEMPLATE_H_
#define BUFFERTEMPLATE_H_

template<class T>
class Buffer {

public:
   Buffer() {
   }

    void add(T value) {
      values[startIndex % maxValues] = value;
      startIndex++;
      startIndex = startIndex % maxValues;
      if (count < maxValues) {
         count++;
      };
   }

   /* peek index von 0 - (count-1)*/
   T peek(int index) {
      if (index >= count) {
         throw exception();
      }

      int stdIndex = index;

      if (count >= maxValues) {
         stdIndex = (startIndex + count + index) % maxValues;
      }

      return values[stdIndex];
   }

   int getCount() {
      return count;
   }

   void clear() {
      startIndex = 0;
      count = 0;
   }

   void setMaxValue(int maxValue) {
      this->count = 0;
      this->maxValues = maxValues;
   }

private:

   T values[buffersize];

   int startIndex = 0; // Index des ersten Werts
   int count = 0; // Anzahl Werte im Speicher
   int maxValues = buffersize;
};

#endif

