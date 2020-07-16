/*
 * Transmitter.cpp
 *
 *  Created on: 19.02.2020
 *      Author: frankp
 */

#include "Transmitter.h"

#ifdef DEBUG
#include <iostream>
using namespace std;
#endif

Transmitter::Transmitter() {
   rcvlen = 0;
   rcvIndex = -1;
   dataByteCounter = 0;
   receiveChar = 0;
   funcPtr = 0;
   sendFuncPtr = 0;
}

Transmitter::~Transmitter() {
}

inline unsigned char char2ascii(unsigned char b) {
   return (b < 10 ? 0x30 + b : 0x37 + b);
}

inline unsigned char ascii2char(char data) {
   return (data < 0x40 ? data - 0x30 : data - 0x37);
}

// stx, len und etx sind die einzigen binären daten, alles andere wird ascii übertragen
// der Wert 172 hex0xb2 wird als 2 zeichen übertragen, zuerst das high byte als ASCII 'B' und anschliessend das low byte als ASCII 2,
// oder in der binären Folge 0x42 0x32
void Transmitter::setReceivedChar(unsigned char inputChar) {
   if (rcvIndex == -1) {
      // expected: STX (binary)
      if (inputChar != 0x02) {
#ifdef DEBUG
         cout << "NO STX found" << endl;
#endif
         return;
      }
#ifdef DEBUG
      cout << "STX found" << endl;
#endif
      rcvIndex = 0;
      rcvlen = 0;
      dataByteCounter = 0;
      return;
   } else if (rcvIndex == 0 && rcvlen == 0) {
      // receive len byte (binary)
#ifdef DEBUG
      cout << "len received" << endl;
#endif
      rcvlen = inputChar;
      return;
   }
   if (inputChar == 0x03) {

      if (rcvlen != (dataByteCounter / 2)) {
         // more or less received, ignore message...
         // errr!!!
         return;
      }
      // delivery
#ifdef DEBUG

      cout << "ETX found, deliver message " << rcvlen << endl;

#endif
      // calling the receiver
      if (funcPtr != 0) {
         funcPtr(inputBuffer, rcvlen);
      }
      rcvIndex = -1;
      rcvlen = 0;
      dataByteCounter = 0;
      return;
   }

   // jetzt kommen immer high und low byte abwechselnd
   // zuerst kommt das high-bte, dann das low-byte
   dataByteCounter++;
   if ((dataByteCounter % 2) == 1) {
      // ungerade, high byte
      receiveChar = ascii2char(inputChar) * 0x10;
      return;
   }

   unsigned char c = receiveChar + ascii2char(inputChar);

#ifdef DEBUG
  int v = c;
   cout << "databyte" << v << endl;
#endif
   inputBuffer[rcvlen] = c;

}

void Transmitter::setReceiveMessage(unsigned char message[]) {
   int i = 0;
   while (message[i] != 0x00) {
      setReceivedChar(message[i]);
      i++;
   }
}

void Transmitter::sendBinaryMessage(unsigned char message[], int len) {
   // wir brauchen einen Buffer mit 2*len + 3 bytes...

   char *sendBuffer = new char[2 * len + 4];
   sendBuffer[0] = 0x02;
   sendBuffer[1] = len;

#ifdef DEBUG
   cout << "STX" << endl;
   cout << "LEN" << char2ascii(len / 0x10) << char2ascii(len % 0x10) << endl;
#endif
   for (int i = 0; i < len; i++) {
      unsigned short int data = message[i];
      sendBuffer[2 * i + 2] = char2ascii(data / 0x10);
      sendBuffer[2 * i + 3] = char2ascii(data % 0x10);
#ifdef DEBUG
      cout << char2ascii(data / 0x10) << char2ascii(data % 0x10) << endl;
#endif
   }
   sendBuffer[2 * len + 2] = 0x03;
   sendBuffer[2 * len + 3] = 0x00;
   if (sendFuncPtr != 0) {
      sendFuncPtr(sendBuffer, len * 2 + 3);
   }

#ifdef DEBUG
cout << endl << "ETX" << endl;
#endif
}

