//============================================================================
// Name        : HelloWorld1.cpp
// Author      : frankp
// Version     :
// Copyright   : (c) 2019 frankp
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <chrono>

using namespace std;

using namespace std::chrono;

//CrankCtrl crankCtrl(4);

int ymain() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!


	uint64_t ms = duration_cast< milliseconds >(    system_clock::now().time_since_epoch()).count();



	//crankCtrl.tick(ms);

	cout << "millies: " << ms<< endl; // prints !!!Hello World!!!


	return 0;
}
