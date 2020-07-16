/*
 * Transmitter.h
 *
 *  Created on: 19.02.2020
 *      Author: frankp
 */

#ifndef TRANSMITTER_H_
#define TRANSMITTER_H_

/*
 * implements a transmission protocol for binary data.
 * All binary data is sent in an ascii representation, except for the stx, etx and len bytes.
 * The len byte defines the number of following data bytes (e.g. 10), but those 10 chars are represented by 20 transmit characters.
 * An ETX follows, but is not part of the len byte.
 * The message is transmitted properly. there is no checksum right now.
 */

class Transmitter {
public:
   Transmitter();
   virtual ~Transmitter();

   void setReceiveMessage(unsigned char message[]);
   void setReceiveMessage(unsigned char message[], int len);

   // this sends a binary message. this message does not contain STX, len and ETX
   void sendBinaryMessage(unsigned char message[], int len);

   void setReceiverMethod(void (*function)(unsigned char[], int)) {
      funcPtr = function;
   }

   void setSenderMethod(void (*function)(char[], int len)) {
      sendFuncPtr = function;
   }

protected:
   // receive a single character
   void setReceivedChar(unsigned char inputChar);
   // Pointer to receive-function. input may come in small ascii packets. it is separated and consolidated into messages
   void (*funcPtr)(unsigned char[], int);
   // pointer to send function: this message contains the complete string to be sent (correct encoding)
   void (*sendFuncPtr)(char[], int);

private:
   int rcvlen;
   int rcvIndex;
   unsigned char inputBuffer[255];
   int dataByteCounter;
   unsigned char receiveChar;
};

#endif /* TRANSMITTER_H_ */
