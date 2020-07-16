//============================================================================
// Name        : Hello.cpp
// Author      : frankp
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "SpeedController.h"
#include "TripController.h"
#include "Cadence.h"
#include "DistanceController.h"
#include "Transmitter.h"

using namespace std;

void dataReceiver(unsigned char data[], int len) {
   cout <<"message received " <<len << "bytes" << endl;
}

void sender(char data[], int len) {
   int l = data[1];
   cout << "send <STX>" << l<<" "  ;
   for ( int i = 2; i<(len-1); i++){
      cout << data[i];
   }
   cout <<"<ETX>"<<endl;
 }

int main() {

   SpeedController sc(2228);

//	sc.init(425.22, 2228);
//
//	sc.isr(200);
//
//	sc.isr(400);
//
//	sc.isr(1400);
//
//	for (int t = 0; t<100; t++){
//		sc.isr( 333*t); // 8,2km/h bei 1 tick/sekunde
//	}
//
//	cout << sc.getTotalDistance() << endl;
//
//
   //     cout << "speed"<<sc.getSpeed() << endl;

// Trip Controller speed
//	TripController tc;
//
//	cout << "dist "<<tc.getTripDistance() << endl;
//	cout << "time "<<tc.getTripTime() << endl;
//	tc.add(34704000, 19.0);
//	tc.add(68705000, 12.0);
//	cout << "dist "<<tc.getTripDistance() << endl;
//	cout << "time "<<tc.getTripTime() << endl;
//	cout << "time "<<tc.getTripTimeFormatted() << endl;
//	tc.add(9868708000, 12.0);
//	cout << "time "<<tc.getTripTimeFormatted() << endl;
//	tc.resetTrip();

   // Trip Controller cadence
   //	TripController tc;
//
//	cout << "turns " << tc.getTripCrankTurns() << endl;
//	cout << "time " << tc.getTripCrankTime() << endl;
//	tc.addCrank(60000, 100);
//	tc.addCrank(180000, 100);
//	cout << "turns " << tc.getTripCrankTurns() << endl;
//	cout << "time " << tc.getTripCrankTime() << endl;
//	cout << "cadence " << tc.getCadenceFormatted() << endl;
//	tc.addCrank(986870800, 207650);
//	cout << "cadence " << tc.getCadenceFormatted() << endl;
//	tc.resetTrip();
//	cout << "cadence " << tc.getCadenceFormatted() << endl;

//   TripController tc;

//	for (int  i=0; i<300000; i++){
//       tc.add(7000, 1);
//       cout << "time " << tc.getTripTimeFormatted() << endl;
//	}

//   Cadence cadence(4);
//
//   cadence.add(2, 1000);
//   cout << "lastvalue:" << cadence.peek(0) << " at :" << cadence.peekTick(0) << endl;
//   cadence.add(4, 4000);
//   cout << "lastvalue:" << cadence.peek(1) << " at :" << cadence.peekTick(1) << endl;
//   cadence.add(6, 6000);
//   cout << "lastvalue:" << cadence.peek(2) << " at :" << cadence.peekTick(2) << endl;
//   cadence.add(8, 8000);
//   cout << "lastvalue:" << cadence.peek(3) << " at :" << cadence.peekTick(3) << endl;
//   cadence.add(10, 10000);
//   cout << "lastvalue:" << cadence.peek(4) << " at :" << cadence.peekTick(4) << endl;
//   cadence.add(12, 12000);
//   cout << "lastvalue:" << cadence.peek(0) << " at :" << cadence.peekTick(0) << endl;

//	cout << "value0" << cadence.peek(0) << endl;
//	cout << "value1" << cadence.peek(1) << endl;
//	cout << "value2" << cadence.peek(2) << endl;
//	cout << "value3" << cadence.peek(3) << endl;

//   DistanceController dc(2228);
//   for (int i=0; i<1000; i++){dc.isr( i*500);}
//   cout << "distance: " << dc.getTotalDistance() <<" km" << endl;
//   cout << "time    : " << dc.getTime() <<" millies" << endl;
//
//
//   dc.isr( 600000);
//
//   cout << "distance: " << dc.getTotalDistance() <<" km" << endl;
//   cout << "time    : " << dc.getTime() <<" millies" << endl;

//   for (int i = 0; i < 1000; i++) {
//      sc.isr(i * 1000);
//      cout << "max speed: " << sc.getMaxSpeed() << " km" << endl;
//      cout << "    speed: " << sc.getCurrentSpeed() << " km" << endl;
//      cout << "avg speed: " << sc.getAvgSpeed(i * 1000) << " km" << endl;
//
//   }
//   sc.isr( 2000 );
//
//   cout << "max speed: " << sc.getMaxSpeed()  <<" km" << endl;
//   cout << "    speed: " << sc.getCurrentSpeed()  <<" km" << endl;
//   cout << "avg speed: " << sc.getAvgSpeed(2000)  <<" km" << endl;
//
//   sc.isr( 3000 );
//
//     cout << "max speed: " << sc.getMaxSpeed()  <<" km" << endl;
//     cout << "    speed: " << sc.getCurrentSpeed()  <<" km" << endl;
//     cout << "avg speed: " << sc.getAvgSpeed(3000)  <<" km" << endl;
//
//
//   sc.isr( 4000 );
//
//   cout << "max speed: " << sc.getMaxSpeed()  <<" km" << endl;
//   cout << "    speed: " << sc.getCurrentSpeed()  <<" km" << endl;
//   cout << "avg speed: " << sc.getAvgSpeed(4000)  <<" km" << endl;

//   Cadence cadence(4);
//
//   for (int i = 0; i < 50; i++) {
//      cadence.tick(i * 250);
//   }
//   cout << "cadence : " << cadence.getCurrent() << " 1/min" << endl;

   Transmitter transi;

//   transi.setReceivedChar(0x33);
//
//   transi.setReceivedChar(0x02);
//   transi.setReceivedChar(0x05);
//   transi.setReceivedChar(0x40);
//   transi.setReceivedChar(0x41);
//   transi.setReceivedChar(0x42);
//   transi.setReceivedChar(0x41);
//   transi.setReceivedChar(0x42);
//
//   transi.setReceivedChar(0x03);


   transi.setReceiverMethod(dataReceiver);
   transi.setSenderMethod(sender);

   unsigned char message[] { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x20, 0x30, 0x50, 0xA1, 0xB2, 0xC3, 0xDF, 0xED, 0xC4 };
   transi.sendBinaryMessage(message, 15);

   unsigned char rcvMessage[] { 0x02, 0x04, '0', '1', '2', '4', 'B', '1', 'C', 'C', 0x03, 0x00 };

   transi.setReceiveMessage(rcvMessage);

   return 0;
}
